#include "bhf_registry.h"

#include "AdsLib.h"
#include "standard_types.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace bhf {

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

std::string fix_known_typos(std::string t)
{
  if (t.rfind("NCTPPLC_", 0) == 0) {
    t.replace(0, 8, "NCTOPLC_");
  }
  return t;
}

std::string to_upper_copy(std::string s)
{
  for (auto& c : s) c = (char)std::toupper((unsigned char)c);
  return s;
}

// Scans for the first non-empty, fully-printable ASCII string starting within [d, d+max).
// Returns the string up to its null terminator (or max), or empty if none found.
std::string find_ascii(const uint8_t* d, size_t max)
{
  for (size_t o = 0; o < max; ++o) {
    if (d[o] >= 0x20 && d[o] <= 0x7E) {
      const size_t slen = strnlen((const char*)(d + o), max - o);
      if (slen < 2) continue;
      bool ok = true;
      for (size_t j = 0; j < slen; ++j) {
        if (d[o + j] < 0x20 || d[o + j] > 0x7E) { ok = false; break; }
      }
      if (ok) return std::string((const char*)(d + o), slen);
    }
  }
  return {};
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
  // Cap the chain length so a cyclic alias (A -> B -> A) can't hang here.
  for (int hops = 0; it != types_.end() && it->second.kind == TypeDef::Kind::Alias && hops < 64; ++hops) {
    key = normalizeTypeName(it->second.alias);
    it = types_.find(key);
  }
  return key;
}

size_t TypeRegistry::sizeOfType(const std::string& name, int depth) const
{
  // Guard against self-referential / cyclic PLC types (e.g. a struct with a
  // POINTER TO / REFERENCE TO field that resolves back to itself), which would
  // otherwise recurse until the stack overflows.
  if (depth > 64) return 0;
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
      return sizeOfType(elem_type, depth + 1) * array_len;
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
      const size_t align = alignmentOfType(f.type, depth + 1);
      if (align > max_align) max_align = align;
      offset = (offset + align - 1) / align * align;
      const size_t elem = sizeOfType(f.type, depth + 1);
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
      const size_t elem = sizeOfType(f.type, depth + 1) * f.array_len;
      if (elem > max_size) max_size = elem;
      const size_t align = alignmentOfType(f.type, depth + 1);
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

size_t TypeRegistry::alignmentOfType(const std::string& name, int depth) const
{
  // Mirror the sizeOfType cycle guard. Return 1 (not 0) on overflow: alignment is
  // used as a divisor when rounding offsets, so it must never be zero.
  if (depth > 64) return 1;
  const auto base = resolveAlias(name);
  auto it = types_.find(base);
  if (it == types_.end()) {
    size_t array_len = 1;
    std::string elem_type;
    if (parse_array_type(base, array_len, elem_type)) {
      const auto elem_base = resolveAlias(elem_type);
      if (elem_base == "BIT") return 1;
      return alignmentOfType(elem_type, depth + 1);
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
      const size_t align = alignmentOfType(f.type, depth + 1);
      if (align > max_align) max_align = align;
    }
    return max_align;
  }
  return alignmentOfType(it->second.alias, depth + 1);
}

const TypeDef* TypeRegistry::findType(const std::string& name) const
{
  const auto key = normalizeTypeName(name);
  auto it = types_.find(key);
  if (it == types_.end()) return nullptr;
  return &it->second;
}

size_t TypeRegistry::fieldOffset(const std::string& typeName, const std::string& fieldName) const
{
  const auto key = normalizeTypeName(typeName);
  auto it = types_.find(key);
  if (it == types_.end()) return 0;
  const auto& def = it->second;

  if (def.kind == TypeDef::Kind::Union) return 0;

  size_t offset = 0;
  size_t bit_count = 0;
  for (const auto& f : def.fields) {
    const auto base_type = resolveAlias(f.type);
    const bool is_bit = (base_type == "BIT") || f.is_bit;

    if (is_bit) {
      if (f.name == fieldName) return offset + (bit_count / 8);
      bit_count += f.array_len;
      if (bit_count >= 8) {
        offset += bit_count / 8;
        bit_count = bit_count % 8;
      }
      continue;
    }

    if (bit_count > 0) {
      offset += (bit_count + 7) / 8;
      bit_count = 0;
    }

    const size_t align = alignmentOfType(f.type);
    if (align > 1) {
      offset = (offset + align - 1) / align * align;
    }

    if (f.name == fieldName) return offset;

    offset += sizeOfType(f.type) * f.array_len;
  }
  return 0;
}

void TypeRegistry::parseFieldEntries(const uint8_t* data, uint32_t size, TypeDef& def)
{
  uint32_t pos = 0;
  while (pos + 40 < size) {
    // Slide up to 4 bytes to find a valid entryLength
    uint32_t fLen = 0;
    int shift = 0;
    for (int s = 0; s < 4; ++s) {
      if (pos + (uint32_t)s + 4 > size) break;
      memcpy(&fLen, data + pos + s, 4);
      if (fLen >= 40 && fLen <= 10000) { shift = s; break; }
      fLen = 0;
    }
    if (fLen < 40) { pos++; continue; }
    pos += (uint32_t)shift;
    memcpy(&fLen, data + pos, 4);
    if (fLen < 40 || pos + fLen > size) break;

    // Extract the field name and type as the first two runs of printable ASCII
    // after the binary field header. The header's explicit length fields proved
    // unreliable on real PLC data, so we walk the nul-separated strings directly.
    // A whole printable run is taken (spaces included), so a type such as
    // "ARRAY [0..9] OF ST_X" is captured intact. Runs shorter than 2 chars are
    // skipped as header-byte noise.
    std::string fName, fType;
    {
      auto is_ascii = [](uint8_t c) { return c >= 0x20 && c <= 0x7E; };
      std::string* targets[2] = { &fName, &fType };
      int got = 0;
      uint32_t sc = 20;
      while (sc < fLen && got < 2) {
        while (sc < fLen && !is_ascii(data[pos + sc])) ++sc;
        const uint32_t rs = sc;
        while (sc < fLen && is_ascii(data[pos + sc])) ++sc;
        if (sc - rs >= 2) {
          targets[got]->assign((const char*)(data + pos + rs), sc - rs);
          ++got;
        }
      }
    }

    if (!fName.empty() && !fType.empty()) {
      size_t array_len = 1;
      std::string elem_type;
      if (parse_array_type(fType, array_len, elem_type)) {
        elem_type = fix_known_typos(elem_type);
      } else {
        elem_type = fix_known_typos(fType);
        array_len = 1;
      }
      TypeField field;
      field.name = fName;
      field.type = elem_type;
      field.array_len = array_len;
      field.hidden = false;
      field.is_bit = (elem_type == "BIT");
      def.fields.push_back(field);
    }

    pos += fLen;
  }
}

void TypeRegistry::loadFromPlc(long port, const AmsAddr* addr)
{
  loaded_ = false;
  types_.clear();
  enum_values_.clear();

  // Read upload info: nTypes at +8, nDtSize at +12
  uint8_t info[32] = {};
  uint32_t br = 0;
  if (AdsSyncReadReqEx2(port, addr, 0xF00F, 0, 32, info, &br) || br < 16)
    return;

  uint32_t nTypes = 0, nDtSize = 0;
  memcpy(&nTypes, info + 8, 4);
  memcpy(&nDtSize, info + 12, 4);
  if (nDtSize == 0 || nDtSize > 10u * 1024u * 1024u) return;

  // Read all type definitions
  std::vector<uint8_t> buf(nDtSize);
  br = 0;
  if (AdsSyncReadReqEx2(port, addr, 0xF00E, 0, nDtSize, buf.data(), &br))
    return;

  const uint8_t* p = buf.data();
  const uint8_t* end = p + br;
  uint32_t parsed = 0;

  while (p + 16 <= end && parsed < nTypes) {
    uint32_t entryLen = 0;
    memcpy(&entryLen, p, 4);
    if (entryLen == 0 || entryLen > (uint32_t)(end - p)) break;

    // Scan for type name in bytes 28..min(entryLen,80)
    const size_t scanMax = (entryLen < 80) ? entryLen : 80;
    const std::string typeName = find_ascii(p + 28, scanMax - 28);

    if (!typeName.empty()) {
      TypeDef def{};

      // Locate the type name string, then skip its trailing nul padding to reach
      // the field-entry region.
      size_t nameOff = 0;
      for (size_t o = 28; o < scanMax; ++o) {
        if (p[o] >= 0x20 && p[o] <= 0x7E &&
            o + typeName.size() < entryLen &&
            memcmp(p + o, typeName.c_str(), typeName.size()) == 0) {
          nameOff = o;
          break;
        }
      }
      size_t afterName = nameOff + typeName.size() + 1;
      while (afterName < entryLen && p[afterName] == 0) afterName++;

      // Classify by what actually follows the name rather than the memberCount
      // header field (which is unreliable across TwinCAT versions / type kinds):
      // if real field entries parse, it is a struct/union; otherwise an alias.
      if (afterName < entryLen) {
        parseFieldEntries(p + afterName, entryLen - (uint32_t)afterName, def);
      }
      if (!def.fields.empty()) {
        def.kind = TypeDef::Kind::Struct;
      } else {
        def.kind = TypeDef::Kind::Alias;
        def.alias = typeName;
      }

      const std::string key = normalizeTypeName(typeName);
      if (types_.find(key) == types_.end()) {
        types_[key] = def;
      }
    }

    p += entryLen;
    parsed++;
  }

  // Inject ST_AdsAddress if not provided by the PLC
  const auto st_ads_key = normalizeTypeName("ST_AdsAddress");
  if (types_.find(st_ads_key) == types_.end()) {
    TypeDef def;
    def.kind = TypeDef::Kind::Struct;
    def.fields = {
      {"NetId", "T_AmsNetId", 1, false, false},
      {"Port", "UINT", 1, false, false},
      {"Channel", "UINT", 1, false, false},
    };
    types_[st_ads_key] = def;
  }
  loaded_ = true;

  if (std::getenv("BHF_DEBUG")) {
    size_t structs = 0, withFields = 0, aliases = 0;
    for (const auto& kv : types_) {
      if (kv.second.kind == TypeDef::Kind::Alias) { ++aliases; continue; }
      ++structs;
      if (!kv.second.fields.empty()) ++withFields;
    }
    fprintf(stderr, "[BHF] parsed %zu types (%zu struct/union, %zu with fields, %zu alias)\n",
            types_.size(), structs, withFields, aliases);
    int shown = 0;
    for (const auto& kv : types_) {
      if (kv.second.kind == TypeDef::Kind::Alias) continue;
      fprintf(stderr, "[BHF] type '%s' kind=%d fields=%zu\n",
              kv.first.c_str(), (int)kv.second.kind, kv.second.fields.size());
      for (const auto& f : kv.second.fields) {
        fprintf(stderr, "        .%s : %s  x%zu%s%s\n",
                f.name.c_str(), f.type.c_str(), f.array_len,
                f.is_bit ? " [bit]" : "", f.hidden ? " [hidden]" : "");
      }
      if (++shown >= 12) { fprintf(stderr, "[BHF] ...(more types omitted)\n"); break; }
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

} // namespace bhf
