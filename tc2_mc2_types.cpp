#include "tc2_mc2_types.h"

#include "standard_types.h"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <cstdlib>

namespace tc2_mc2 {

namespace {
std::string trim_local(const std::string& s)
{
  const auto start = s.find_first_not_of(" \t\r\n");
  if (start == std::string::npos) return std::string();
  const auto end = s.find_last_not_of(" \t\r\n");
  return s.substr(start, end - start + 1);
}

bool parse_array_type(const std::string& type, size_t& array_len, std::string& elem_type)
{
  if (type.rfind("ARRAY", 0) != 0) return false;
  size_t lb = type.find('[');
  size_t dots = type.find("..", lb);
  size_t rb = type.find(']', dots);
  size_t of = type.find("OF", rb);
  if (lb == std::string::npos || dots == std::string::npos || rb == std::string::npos || of == std::string::npos) {
    return false;
  }
  int lo = std::atoi(type.substr(lb + 1, dots - (lb + 1)).c_str());
  int hi = std::atoi(type.substr(dots + 2, rb - (dots + 2)).c_str());
  if (hi < lo) return false;
  array_len = static_cast<size_t>(hi - lo + 1);
  elem_type = trim_local(type.substr(of + 2));
  return true;
}

std::string normalize_nbsp(std::string s)
{
  for (size_t i = 0; i + 1 < s.size(); ++i) {
    const unsigned char c1 = static_cast<unsigned char>(s[i]);
    const unsigned char c2 = static_cast<unsigned char>(s[i + 1]);
    if (c1 == 0xC2 && c2 == 0xA0) {
      s[i] = ' ';
      s.erase(i + 1, 1);
    }
  }
  return s;
}

std::string fix_known_typos(std::string t)
{
  if (t.rfind("NCTPPLC_", 0) == 0) {
    t.replace(0, 8, "NCTOPLC_");
  }
  return t;
}

std::string normalize_type_name(std::string t)
{
  t = trim_local(t);
  if (!t.empty() && t.back() == ':') {
    t.pop_back();
  }
  return trim_local(t);
}

long long parse_enum_value(const std::string& token)
{
  std::string s = trim_local(token);
  if (s.empty()) return 0;
  auto hash = s.find('#');
  if (hash != std::string::npos) {
    const auto base_str = s.substr(0, hash);
    const auto val_str = s.substr(hash + 1);
    int base = std::atoi(base_str.c_str());
    if (base == 16 || base == 10 || base == 2 || base == 8) {
      return std::strtoll(val_str.c_str(), nullptr, base);
    }
  }
  return std::strtoll(s.c_str(), nullptr, 10);
}

std::unordered_map<long long, std::string> parse_enum_entries(const std::string& content)
{
  std::unordered_map<long long, std::string> map;
  auto enum_start = content.find('(');
  auto enum_end = content.find(')', enum_start);
  if (enum_start == std::string::npos || enum_end == std::string::npos || enum_end <= enum_start) {
    return map;
  }
  std::string body = content.substr(enum_start + 1, enum_end - enum_start - 1);
  for (char& c : body) {
    if (c == '\n' || c == '\r' || c == '\t') c = ' ';
  }
  std::stringstream ss(body);
  std::string token;
  while (std::getline(ss, token, ',')) {
    auto assign = token.find(":=");
    if (assign == std::string::npos) continue;
    const auto name = trim_local(token.substr(0, assign));
    const auto value_str = token.substr(assign + 2);
    if (name.empty()) continue;
    const long long value = parse_enum_value(value_str);
    map[value] = name;
  }
  return map;
}

std::string parse_enum_base_type(const std::string& content)
{
  auto enum_start = content.find('(');
  auto enum_end = content.find(')', enum_start);
  if (enum_start == std::string::npos || enum_end == std::string::npos || enum_end <= enum_start) {
    return "INT";
  }
  auto semi = content.find(';', enum_end);
  std::string tail = (semi == std::string::npos)
    ? content.substr(enum_end + 1)
    : content.substr(enum_end + 1, semi - enum_end - 1);
  tail = trim_local(tail);
  if (tail.empty()) return "INT";
  return fix_known_typos(tail);
}

std::string to_upper_copy(std::string s)
{
  for (auto& c : s) c = (char)std::toupper((unsigned char)c);
  return s;
}
} // namespace

std::string TypeRegistry::trim(const std::string& s)
{
  const auto start = s.find_first_not_of(" \t\r\n");
  if (start == std::string::npos) return std::string();
  const auto end = s.find_last_not_of(" \t\r\n");
  return s.substr(start, end - start + 1);
}

std::string TypeRegistry::normalizeTypeName(const std::string& name) const
{
  auto pos = name.rfind('.');
  if (pos != std::string::npos) {
    return to_upper_copy(fix_known_typos(name.substr(pos + 1)));
  }
  return to_upper_copy(fix_known_typos(name));
}

std::string TypeRegistry::resolveAlias(const std::string& name) const
{
  std::string key = normalizeTypeName(name);
  auto it = types_.find(key);
  while (it != types_.end() && it->second.kind == TypeDef::Kind::Alias) {
    key = normalizeTypeName(it->second.alias);
    it = types_.find(key);
  }
  return key;
}

size_t TypeRegistry::sizeOfType(const std::string& name) const
{
  const auto base = resolveAlias(name);
  auto it = types_.find(base);
  if (it == types_.end()) {
    size_t array_len = 1;
    std::string elem_type;
    if (parse_array_type(base, array_len, elem_type)) {
      const auto elem_base = resolveAlias(elem_type);
      if (elem_base == "BIT") {
        return (array_len + 7) / 8;
      }
      return sizeOfType(elem_type) * array_len;
    }
    return tc_standard::baseTypeSize(base);
  }
  if (it->second.kind == TypeDef::Kind::Struct) {
    size_t offset = 0;
    size_t max_align = 1;
    size_t bit_count = 0;
    for (const auto& f : it->second.fields) {
      const auto base_type = resolveAlias(f.type);
      const bool is_bit = (base_type == "BIT") || f.is_bit;
      if (is_bit) {
        bit_count += f.array_len;
        continue;
      }
      if (bit_count > 0) {
        offset += (bit_count + 7) / 8;
        bit_count = 0;
      }
      const size_t align = alignmentOfType(f.type);
      if (align > max_align) max_align = align;
      offset = (offset + align - 1) / align * align;
      const size_t elem = sizeOfType(f.type);
      offset += elem * f.array_len;
    }
    if (bit_count > 0) {
      offset += (bit_count + 7) / 8;
    }
    if (max_align > 1) {
      offset = (offset + max_align - 1) / max_align * max_align;
    }
    return offset;
  }
  if (it->second.kind == TypeDef::Kind::Union) {
    size_t max_size = 0;
    size_t max_align = 1;
    for (const auto& f : it->second.fields) {
      const size_t elem = sizeOfType(f.type) * f.array_len;
      if (elem > max_size) max_size = elem;
      const size_t align = alignmentOfType(f.type);
      if (align > max_align) max_align = align;
    }
    if (max_align > 1) {
      max_size = (max_size + max_align - 1) / max_align * max_align;
    }
    return max_size;
  }
  size_t array_len = 1;
  std::string elem_type;
  if (parse_array_type(base, array_len, elem_type)) {
    const auto elem_base = resolveAlias(elem_type);
    if (elem_base == "BIT") {
      return (array_len + 7) / 8;
    }
    return sizeOfType(elem_type) * array_len;
  }
  return tc_standard::baseTypeSize(base);
}

size_t TypeRegistry::alignmentOfType(const std::string& name) const
{
  const auto base = resolveAlias(name);
  auto it = types_.find(base);
  if (it == types_.end()) {
    size_t array_len = 1;
    std::string elem_type;
    if (parse_array_type(base, array_len, elem_type)) {
      const auto elem_base = resolveAlias(elem_type);
      if (elem_base == "BIT") return 1;
      return alignmentOfType(elem_type);
    }
    if (base == "BOOL" || base == "BYTE" || base == "USINT" || base == "SINT" || base == "BIT") return 1;
    if (base == "INT" || base == "UINT" || base == "WORD") return 2;
    if (base == "DINT" || base == "UDINT" || base == "DWORD" || base == "REAL") return 4;
    if (base == "LINT" || base == "ULINT" || base == "LREAL") return 8;
    if (base.rfind("STRING", 0) == 0) return 1;
    return 4;
  }
  if (it->second.kind == TypeDef::Kind::Struct || it->second.kind == TypeDef::Kind::Union) {
    size_t max_align = 1;
    for (const auto& f : it->second.fields) {
      const size_t align = alignmentOfType(f.type);
      if (align > max_align) max_align = align;
    }
    return max_align;
  }
  return alignmentOfType(it->second.alias);
}

const TypeDef* TypeRegistry::findType(const std::string& name) const
{
  const auto key = normalizeTypeName(name);
  auto it = types_.find(key);
  if (it == types_.end()) return nullptr;
  return &it->second;
}

TypeDef TypeRegistry::fallbackPlcToNc() const
{
  TypeDef def;
  def.kind = TypeDef::Kind::Struct;
  def.fields = {
    {"ControlDWord", "DWORD", 1, false, false},
    {"Override", "UDINT", 1, false, false},
    {"AxisModeRequest", "UDINT", 1, false, false},
    {"AxisModeDWord", "UDINT", 1, false, false},
    {"AxisModeLReal", "LREAL", 1, false, false},
    {"PositionCorrection", "LREAL", 1, false, false},
    {"ExtSetPos", "LREAL", 1, false, false},
    {"ExtSetVelo", "LREAL", 1, false, false},
    {"ExtSetAcc", "LREAL", 1, false, false},
    {"ExtSetDirection", "DINT", 1, false, false},
    {"_reserved1", "UDINT", 1, true, false},
    {"ExtControllerOutput", "LREAL", 1, false, false},
    {"GearRatio1", "LREAL", 1, false, false},
    {"GearRatio2", "LREAL", 1, false, false},
    {"GearRatio3", "LREAL", 1, false, false},
    {"GearRatio4", "LREAL", 1, false, false},
    {"MapState", "BOOL", 1, false, false},
    {"PlcCycleControl", "BYTE", 1, false, false},
    {"PlcCycleCount", "BYTE", 1, false, false},
    {"_reserved2", "USINT", 5, true, false},
    {"ExtTorque", "LREAL", 1, false, false},
    {"_reserved3", "USINT", 8, true, false},
  };
  return def;
}

TypeDef TypeRegistry::fallbackNcToPlc() const
{
  TypeDef def;
  def.kind = TypeDef::Kind::Struct;
  def.fields = {
    {"StateDWord", "NCTOPLC_AXIS_REF_STATE", 1, false, false},
    {"ErrorCode", "DWORD", 1, false, false},
    {"AxisState", "DWORD", 1, false, false},
    {"AxisModeConfirmation", "DWORD", 1, false, false},
    {"HomingState", "DWORD", 1, false, false},
    {"CoupleState", "DWORD", 1, false, false},
    {"SvbEntries", "DWORD", 1, false, false},
    {"SafEntries", "DWORD", 1, false, false},
    {"AxisId", "DWORD", 1, false, false},
    {"OpModeDWord", "NCTOPLC_AXIS_REF_OPMODE", 1, false, false},
    {"ActPos", "LREAL", 1, false, false},
    {"ModuloActPos", "LREAL", 1, false, false},
    {"ActiveControlLoopIndex", "WORD", 1, false, false},
    {"ControlLoopIndex", "WORD", 1, false, false},
    {"ModuloActTurns", "DINT", 1, false, false},
    {"ActVelo", "LREAL", 1, false, false},
    {"PosDiff", "LREAL", 1, false, false},
    {"SetPos", "LREAL", 1, false, false},
    {"SetVelo", "LREAL", 1, false, false},
    {"SetAcc", "LREAL", 1, false, false},
    {"TargetPos", "LREAL", 1, false, false},
    {"ModuloSetPos", "LREAL", 1, false, false},
    {"ModuloSetTurns", "DINT", 1, false, false},
    {"CmdNo", "WORD", 1, false, false},
    {"CmdState", "WORD", 1, false, false},
    {"SetJerk", "LREAL", 1, false, false},
    {"SetTorque", "LREAL", 1, false, false},
    {"ActTorque", "LREAL", 1, false, false},
    {"StateDWord2", "NCTOPLC_AXIS_REF_STATE2", 1, false, false},
    {"StateDWord3", "DWORD", 1, false, false},
    {"TouchProbeState", "DWORD", 1, false, false},
    {"TouchProbeCounter", "DWORD", 1, false, false},
    {"CamCouplingState", "NCTOPLC_AXIS_REF_CAMCOUPLINGSTATE", 8, false, false},
    {"CamCouplingTableID", "UINT", 8, false, false},
    {"ActTorqueDerivative", "LREAL", 1, false, false},
    {"SetTorqueDerivative", "LREAL", 1, false, false},
    {"AbsPhasingPos", "LREAL", 1, false, false},
    {"TorqueOffset", "LREAL", 1, false, false},
    {"ActPosWithoutPosCorrection", "LREAL", 1, false, false},
    {"ActAcc", "LREAL", 1, false, false},
    {"DcTimeStamp", "UDINT", 1, false, false},
    {"_reserved2", "USINT", 12, true, false},
    {"UserData", "LREAL", 1, false, false},
  };
  return def;
}

TypeDef TypeRegistry::fallbackAdsAddress() const
{
  TypeDef def;
  def.kind = TypeDef::Kind::Struct;
  def.fields = {
    {"NetId", "STRING(23)", 1, false, false},
    {"Port", "UINT", 1, false, false},
    {"Channel", "UINT", 1, false, false},
  };
  return def;
}

void TypeRegistry::load(const std::string& root)
{
  types_.clear();
  enum_values_.clear();
  auto load_dir = [&](const std::filesystem::path& dir) {
    if (!std::filesystem::exists(dir)) return;
    for (const auto& entry : std::filesystem::directory_iterator(dir)) {
      if (!entry.is_regular_file()) continue;
      if (entry.path().extension() != ".md") continue;
      std::ifstream in(entry.path());
      if (!in) continue;
      std::stringstream buffer;
      buffer << in.rdbuf();
      std::string content = normalize_nbsp(buffer.str());

      auto type_pos = content.find("TYPE ");
      if (type_pos == std::string::npos) continue;
      auto type_end = content.find('\n', type_pos);
      if (type_end == std::string::npos) continue;
      std::string type_name = normalize_type_name(content.substr(type_pos + 5, type_end - (type_pos + 5)));
      type_name = normalizeTypeName(type_name);

      TypeDef def{};
      if (content.find("STRUCT", type_end) != std::string::npos) {
        def.kind = TypeDef::Kind::Struct;
      } else if (content.find("UNION", type_end) != std::string::npos) {
        def.kind = TypeDef::Kind::Union;
      } else {
        def.kind = TypeDef::Kind::Alias;
      }

      if (def.kind == TypeDef::Kind::Alias) {
        auto colon = content.find(':', type_pos);
        auto semi = content.find(';', colon);
        if (colon != std::string::npos && semi != std::string::npos) {
          def.alias = trim(content.substr(colon + 1, semi - colon - 1));
          if (def.alias.find('(') != std::string::npos) {
            def.alias = parse_enum_base_type(content);
            types_[type_name] = def;
            const auto entries = parse_enum_entries(content);
            if (!entries.empty()) {
              enum_values_[type_name] = entries;
            }
          } else {
            def.alias = fix_known_typos(def.alias);
            types_[type_name] = def;
          }
        } else {
          auto enum_start = content.find('(', type_end);
          auto enum_end = content.find(')', enum_start);
          if (enum_start != std::string::npos && enum_end != std::string::npos) {
            def.alias = parse_enum_base_type(content);
            types_[type_name] = def;
            const auto entries = parse_enum_entries(content);
            if (!entries.empty()) {
              enum_values_[type_name] = entries;
            }
          }
        }
        continue;
      }

      std::istringstream lines(content);
      std::string line;
      bool in_struct = false;
      bool next_hidden = false;
      while (std::getline(lines, line)) {
        line = normalize_nbsp(line);
        if (line.find("{attribute 'hide'}") != std::string::npos) {
          next_hidden = true;
          continue;
        }
        if (line.find("STRUCT") != std::string::npos || line.find("UNION") != std::string::npos) {
          in_struct = true;
          continue;
        }
        if (!in_struct) continue;
        if (line.find("END_STRUCT") != std::string::npos || line.find("END_TYPE") != std::string::npos) {
          break;
        }
        if (line.find(":") == std::string::npos) continue;

        auto comment = line.find("(*");
        if (comment != std::string::npos) {
          line = line.substr(0, comment);
        }

        auto colon = line.find(':');
        auto semi = line.find(';', colon);
        if (semi == std::string::npos) continue;
        std::string name = trim(line.substr(0, colon));
        std::string type = trim(line.substr(colon + 1, semi - colon - 1));

        size_t array_len = 1;
        auto arr = type.find("ARRAY");
        if (arr != std::string::npos) {
          auto lb = type.find('[', arr);
          auto dots = type.find("..", lb);
          auto rb = type.find(']', dots);
          auto of = type.find("OF", rb);
          if (lb != std::string::npos && dots != std::string::npos && rb != std::string::npos && of != std::string::npos) {
            int lo = std::atoi(type.substr(lb + 1, dots - (lb + 1)).c_str());
            int hi = std::atoi(type.substr(dots + 2, rb - (dots + 2)).c_str());
            if (hi >= lo) array_len = (size_t)(hi - lo + 1);
            type = trim(type.substr(of + 2));
          }
        }

        type = fix_known_typos(type);

        TypeField field{name, type, array_len, next_hidden, type == "BIT"};
        def.fields.push_back(field);
        next_hidden = false;
      }

      types_[type_name] = def;
    }
  };

  const std::filesystem::path dir(root);
  load_dir(dir);
  load_dir(dir / "overrides");

  const auto st_ads_key = normalizeTypeName("ST_AdsAddress");
  if (types_.find(st_ads_key) == types_.end()) {
    types_[st_ads_key] = fallbackAdsAddress();
  }

  const auto netid_key = normalizeTypeName("T_AmsNetId");
  if (types_.find(netid_key) == types_.end()) {
    TypeDef def;
    def.kind = TypeDef::Kind::Alias;
    def.alias = "STRING(23)";
    types_[netid_key] = def;
  }
  const auto netid_arr_key = normalizeTypeName("T_AmsNetIdArr");
  if (types_.find(netid_arr_key) == types_.end()) {
    TypeDef def;
    def.kind = TypeDef::Kind::Alias;
    def.alias = "ARRAY[0..5] OF BYTE";
    types_[netid_arr_key] = def;
  }
  const auto amsport_key = normalizeTypeName("T_AmsPort");
  if (types_.find(amsport_key) == types_.end()) {
    TypeDef def;
    def.kind = TypeDef::Kind::Alias;
    def.alias = "UINT";
    types_[amsport_key] = def;
  }

  const auto mc_axis_key = normalizeTypeName("MC_AxisStates");
  if (types_.find(mc_axis_key) == types_.end()) {
    TypeDef def;
    def.kind = TypeDef::Kind::Alias;
    def.alias = "INT";
    types_[mc_axis_key] = def;
  }
  if (enum_values_.find(mc_axis_key) == enum_values_.end()) {
    enum_values_[mc_axis_key] = {
      {0, "MC_AXISSTATE_UNDEFINED"},
      {1, "MC_AXISSTATE_DISABLED"},
      {2, "MC_AXISSTATE_STANDSTILL"},
      {3, "MC_AXISSTATE_ERRORSTOP"},
      {4, "MC_AXISSTATE_STOPPING"},
      {5, "MC_AXISSTATE_HOMING"},
      {6, "MC_AXISSTATE_DISCRETEMOTION"},
      {7, "MC_AXISSTATE_CONTINOUSMOTION"},
      {8, "MC_AXISSTATE_SYNCHRONIZEDMOTION"}
    };
  }



  if (types_.find("NCTOPLC_AXIS_REF_CAMCOUPLINGSTATE") == types_.end()) {
    TypeDef def;
    def.kind = TypeDef::Kind::Struct;
    def.fields = {
      {"CamActivationPending", "BIT", 1, false, true},
      {"CamDeactivationPending", "BIT", 1, false, true},
      {"CamActive", "BIT", 1, false, true},
      {"_reserved1", "BIT", 1, true, true},
      {"_reserved2", "BIT", 1, true, true},
      {"_reserved3", "BIT", 1, true, true},
      {"CamDataQueued", "BIT", 1, false, true},
      {"CamScalingPending", "BIT", 1, false, true},
    };
    types_["NCTOPLC_AXIS_REF_CAMCOUPLINGSTATE"] = def;
  }

  if (types_.find("NCTOPLC_AXIS_REF_STATE2_FLAGS") == types_.end()) {
    TypeDef def;
    def.kind = TypeDef::Kind::Struct;
    def.fields = {
      {"AvoidingCollision", "BIT", 1, false, true},
      {"_reserved1", "BIT", 1, true, true},
      {"_reserved2", "BIT", 1, true, true},
      {"_reserved3", "BIT", 1, true, true},
      {"_reserved4", "BIT", 1, true, true},
      {"_reserved5", "BIT", 1, true, true},
      {"_reserved6", "BIT", 1, true, true},
      {"_reserved7", "BIT", 1, true, true},
      {"_reserved8", "USINT", 3, true, false},
    };
    types_["NCTOPLC_AXIS_REF_STATE2_FLAGS"] = def;
  }

  if (types_.find("NCTOPLC_AXIS_REF_STATE2") == types_.end()) {
    TypeDef def;
    def.kind = TypeDef::Kind::Union;
    def.fields = {
      {"Value", "DWORD", 1, false, false},
      {"Flags", "NCTOPLC_AXIS_REF_STATE2_FLAGS", 1, false, false},
    };
    types_["NCTOPLC_AXIS_REF_STATE2"] = def;
  }

  std::vector<std::string> type_keys;
  type_keys.reserve(types_.size());
  for (const auto& kv : types_) type_keys.push_back(kv.first);
  for (const auto& key : type_keys) {
    const auto upper = to_upper_copy(key);
    if (types_.find(upper) == types_.end()) {
      types_[upper] = types_[key];
    }
  }

  std::vector<std::string> enum_keys;
  enum_keys.reserve(enum_values_.size());
  for (const auto& kv : enum_values_) enum_keys.push_back(kv.first);
  for (const auto& key : enum_keys) {
    const auto upper = to_upper_copy(key);
    if (enum_values_.find(upper) == enum_values_.end()) {
      enum_values_[upper] = enum_values_[key];
    }
  }
}

bool TypeRegistry::enumValueToString(const std::string& type, long long value, std::string& out) const
{
  const auto key = normalizeTypeName(type);
  auto it = enum_values_.find(key);
  if (it == enum_values_.end()) return false;
  auto vit = it->second.find(value);
  if (vit == it->second.end()) return false;
  out = vit->second;
  return true;
}

} // namespace tc2_mc2
