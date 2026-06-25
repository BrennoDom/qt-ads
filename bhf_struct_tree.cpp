#include "bhf_struct_tree.h"

#include <QString>
#include <cctype>

namespace {
bool ends_with(const std::string& s, const std::string& suffix)
{
  return s.size() >= suffix.size() && s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
}

QTreeWidgetItem* find_child(QTreeWidgetItem* parent, const QString& name)
{
  if (!parent) return nullptr;
  for (int i = 0; i < parent->childCount(); ++i) {
    auto* child = parent->child(i);
    if (child && child->text(0) == name) return child;
  }
  return nullptr;
}

bool struct_field_offset(const bhf::TypeRegistry& registry,
                         const bhf::TypeDef& def,
                         const std::string& field,
                         size_t& out_offset)
{
  size_t offset = 0;
  size_t bit_count = 0;
  for (const auto& f : def.fields) {
    const auto base_type = registry.resolveAlias(f.type);
    const bool is_bit = (base_type == "BIT") || f.is_bit;

    if (def.kind == bhf::TypeDef::Kind::Union) {
      if (f.name == field) {
        out_offset = 0;
        return true;
      }
      continue;
    }

    if (is_bit) {
      if (f.name == field) {
        out_offset = offset + (bit_count / 8);
        return true;
      }
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

    const size_t align = registry.alignmentOfType(f.type);
    if (align > 1) {
      offset = (offset + align - 1) / align * align;
    }

    if (f.name == field) {
      out_offset = offset;
      return true;
    }

    offset += registry.sizeOfType(f.type) * f.array_len;
  }
  return false;
}

size_t struct_size_with_pack(const bhf::TypeRegistry& registry,
                             const bhf::TypeDef& def,
                             size_t pack)
{
  size_t offset = 0;
  size_t max_align = 1;
  size_t bit_count = 0;

  for (const auto& f : def.fields) {
    const auto base_type = registry.resolveAlias(f.type);
    const bool is_bit = (base_type == "BIT") || f.is_bit;
    if (is_bit) {
      bit_count += f.array_len;
      continue;
    }

    if (bit_count > 0) {
      offset += (bit_count + 7) / 8;
      bit_count = 0;
    }

    size_t align = registry.alignmentOfType(f.type);
    if (pack > 0 && align > pack) align = pack;
    if (align > max_align) max_align = align;
    if (align > 1) {
      offset = (offset + align - 1) / align * align;
    }

    offset += registry.sizeOfType(f.type) * f.array_len;
  }

  if (bit_count > 0) {
    offset += (bit_count + 7) / 8;
  }
  if (max_align > 1) {
    offset = (offset + max_align - 1) / max_align * max_align;
  }
  return offset;
}

bool struct_field_offset_with_pack(const bhf::TypeRegistry& registry,
                                   const bhf::TypeDef& def,
                                   const std::string& field,
                                   size_t pack,
                                   size_t& out_offset)
{
  size_t offset = 0;
  size_t bit_count = 0;
  for (const auto& f : def.fields) {
    const auto base_type = registry.resolveAlias(f.type);
    const bool is_bit = (base_type == "BIT") || f.is_bit;

    if (def.kind == bhf::TypeDef::Kind::Union) {
      if (f.name == field) {
        out_offset = 0;
        return true;
      }
      continue;
    }

    if (is_bit) {
      if (f.name == field) {
        out_offset = offset + (bit_count / 8);
        return true;
      }
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

    size_t align = registry.alignmentOfType(f.type);
    if (pack > 0 && align > pack) align = pack;
    if (align > 1) {
      offset = (offset + align - 1) / align * align;
    }

    if (f.name == field) {
      out_offset = offset;
      return true;
    }

    offset += registry.sizeOfType(f.type) * f.array_len;
  }
  return false;
}

size_t pick_pack_for_struct(const bhf::TypeRegistry& registry,
                            const bhf::TypeDef& def,
                            size_t ads_size)
{
  const size_t packs[] = {1, 2, 4, 8};
  size_t best_pack = 0;
  size_t best_diff = static_cast<size_t>(-1);
  for (size_t pack : packs) {
    const size_t size = struct_size_with_pack(registry, def, pack);
    const size_t diff = size > ads_size ? size - ads_size : ads_size - size;
    if (diff < best_diff) {
      best_diff = diff;
      best_pack = pack;
    }
    if (diff == 0) {
      return pack;
    }
  }
  return best_pack;
}

struct AdsLayoutInfo {
  size_t netid_off = 0;
  size_t netid_len = 0;
  size_t port_off = 0;
  size_t channel_off = 0;
  size_t struct_size = 0;
  bool valid = false;
};

AdsLayoutInfo get_ads_layout(const bhf::TypeRegistry& registry)
{
  AdsLayoutInfo info;
  const auto* def = registry.findType("ST_AdsAddress");
  if (!def) return info;

  size_t netid_off = 0;
  size_t port_off = 0;
  size_t channel_off = 0;
  if (!struct_field_offset(registry, *def, "NetId", netid_off)) return info;
  if (!struct_field_offset(registry, *def, "Port", port_off)) return info;
  if (!struct_field_offset(registry, *def, "Channel", channel_off)) return info;

  std::string netid_type;
  for (const auto& f : def->fields) {
    if (f.name == "NetId") {
      netid_type = f.type;
      break;
    }
  }
  if (netid_type.empty()) return info;

  info.netid_off = netid_off;
  info.port_off = port_off;
  info.channel_off = channel_off;
  info.netid_len = registry.sizeOfType(netid_type);
  info.struct_size = registry.sizeOfType("ST_AdsAddress");
  info.valid = info.netid_len > 0 && info.struct_size >= info.netid_len;
  return info;
}

bool is_printable(uint8_t c)
{
  return c >= 0x20 && c <= 0x7E;
}

bool find_ads_offset_in_buffer(const std::vector<uint8_t>& buf,
                               size_t expected,
                               const AdsLayoutInfo& layout,
                               size_t& out_offset)
{
  if (!layout.valid || layout.struct_size == 0 || buf.size() < layout.struct_size) return false;

  const size_t window = 128;
  size_t start = expected > window ? expected - window : 0;
  size_t end = expected + window;
  if (end + layout.struct_size > buf.size()) {
    end = buf.size() - layout.struct_size;
  }

  int best_score = -1;
  size_t best_offset = expected;

  for (size_t off = start; off <= end; ++off) {
    const size_t netid_pos = off + layout.netid_off;
    const size_t port_pos = off + layout.port_off;
    const size_t channel_pos = off + layout.channel_off;
    if (channel_pos + 2 > buf.size()) continue;

    bool printable = true;
    bool has_null = false;
    size_t len = 0;
    for (size_t i = 0; i < layout.netid_len; ++i) {
      const uint8_t c = buf[netid_pos + i];
      if (c == 0) {
        has_null = true;
        break;
      }
      if (!is_printable(c)) {
        printable = false;
        break;
      }
      ++len;
    }
    if (!printable || len == 0) continue;

    const uint16_t port = (uint16_t)(buf[port_pos] | (buf[port_pos + 1] << 8));
    const uint16_t channel = (uint16_t)(buf[channel_pos] | (buf[channel_pos + 1] << 8));

    int score = 0;
    if (printable) score += 5;
    if (has_null) score += 5;
    if (len >= 6) score += 2;
    if (port <= 50000) score += 1;
    if (channel <= 1000) score += 1;
    if (off >= expected ? (off - expected) <= 8 : (expected - off) <= 8) score += 2;

    if (score > best_score) {
      best_score = score;
      best_offset = off;
    }
  }

  if (best_score >= 8) {
    out_offset = best_offset;
    return true;
  }
  return false;
}

int find_child_symbol_index(const std::vector<SymbolEntry>& syms,
                            const std::string& base,
                            const std::string& child)
{
  std::string base_lower = base;
  std::string child_lower = child;
  for (auto& c : base_lower) c = (char)std::tolower((unsigned char)c);
  for (auto& c : child_lower) c = (char)std::tolower((unsigned char)c);

  const std::string prefix = base_lower + ".";
  for (size_t i = 0; i < syms.size(); ++i) {
    std::string name_lower = syms[i].name;
    for (auto& c : name_lower) c = (char)std::tolower((unsigned char)c);
    if (name_lower.rfind(prefix, 0) != 0) continue;
    const auto rest = name_lower.substr(prefix.size());
    if (rest == child_lower) return static_cast<int>(i);
  }
  return -1;
}

bool iequals(const std::string& a, const std::string& b)
{
  if (a.size() != b.size()) return false;
  for (size_t i = 0; i < a.size(); ++i) {
    if (std::tolower((unsigned char)a[i]) != std::tolower((unsigned char)b[i])) return false;
  }
  return true;
}

int find_child_symbol_index_by_type(const std::vector<SymbolEntry>& syms,
                                    const std::string& base,
                                    const std::string& type)
{
  std::string base_lower = base;
  for (auto& c : base_lower) c = (char)std::tolower((unsigned char)c);
  const std::string prefix = base_lower + ".";

  for (size_t i = 0; i < syms.size(); ++i) {
    std::string name_lower = syms[i].name;
    for (auto& c : name_lower) c = (char)std::tolower((unsigned char)c);
    if (name_lower.rfind(prefix, 0) != 0) continue;
    const auto rest = name_lower.substr(prefix.size());
    if (rest.find('.') != std::string::npos) continue; // only direct children
    if (iequals(syms[i].type, type)) return static_cast<int>(i);
  }
  return -1;
}

size_t effective_size(const bhf::TypeRegistry& registry,
                      const std::string& type_name,
                      size_t ads_size)
{
  const size_t expected = registry.sizeOfType(type_name);
  return expected > ads_size ? expected : ads_size;
}

bool parse_array_alias(const std::string& type, size_t& array_len, std::string& elem_type)
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
  elem_type = type.substr(of + 2);
  while (!elem_type.empty() && (elem_type.front() == ' ' || elem_type.front() == '\t')) elem_type.erase(elem_type.begin());
  return true;
}
}

void StructTree::loadFromPlc(long port, const AmsAddr* addr)
{
  registry_.loadFromPlc(port, addr);
}

void StructTree::clear(size_t symbol_count)
{
  struct_children_items_.assign(symbol_count, {});
}

bool StructTree::shouldSkipSymbol(const std::vector<SymbolEntry>& syms,
                                  const std::unordered_map<std::string, int>& name_to_index,
                                  int sym_index) const
{
  const auto& sym_name = syms[sym_index].name;
  if (!ends_with(sym_name, ".PlcToNc") && !ends_with(sym_name, ".NcToPlc") && !ends_with(sym_name, ".ADS")) {
    return false;
  }
  const auto base = sym_name.substr(0, sym_name.rfind('.'));
  auto it = name_to_index.find(base);
  if (it == name_to_index.end()) return false;
  const auto& base_type = syms[it->second].type;
  return base_type == "AXIS_REF" || base_type.find("AXIS_REF") != std::string::npos;
}

bool StructTree::addChildrenForSymbol(const std::vector<SymbolEntry>& syms,
                                      const std::unordered_map<std::string, int>& name_to_index,
                                      int sym_index,
                                      QTreeWidgetItem* item)
{
  const auto& type = syms[sym_index].type;
  if (ends_with(syms[sym_index].name, ".Status")) {
    const auto* status_def = registry_.findType("ST_AxisStatus");
    if (status_def) {
      item->setFlags(item->flags() & ~Qt::ItemIsEditable);
      addStructChildren(item, 0, sym_index,
        effective_size(registry_, "ST_AxisStatus", syms[sym_index].size),
        *status_def);
      item->setExpanded(false);
      return true;
    }
  }

  if (ends_with(syms[sym_index].name, ".DriveAddress")) {
    const auto* drive_def = registry_.findType("ST_DriveAddress");
    if (drive_def) {
      item->setFlags(item->flags() & ~Qt::ItemIsEditable);
      addStructChildren(item, 0, sym_index,
        effective_size(registry_, "ST_DriveAddress", syms[sym_index].size),
        *drive_def);
      item->setExpanded(false);
      return true;
    }
  }

  const auto norm_type = registry_.normalizeTypeName(type);
  const auto* def = registry_.findType(norm_type);

  if (def && (def->kind == bhf::TypeDef::Kind::Struct || def->kind == bhf::TypeDef::Kind::Union) &&
      norm_type != "AXIS_REF") {
    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
      const size_t pack = pick_pack_for_struct(registry_, *def, syms[sym_index].size);
          addStructChildren(item, 0, sym_index,
        effective_size(registry_, norm_type, syms[sym_index].size),
        *def,
        true,
        std::string(),
        pack);
    item->setExpanded(false);
    return true;
  }

  // Array whose element type is a struct/union: expand each element into its own
  // struct subtree. Each element's fields are bound at idx * element-stride within
  // the symbol's raw buffer. (Primitive-element arrays return false and are handled
  // by the caller's leaf path, which keeps per-element editing.)
  if (type.rfind("ARRAY", 0) == 0) {
    size_t count = 0;
    std::string elem_type;
    if (parse_array_alias(type, count, elem_type) && count > 0) {
      const auto elem_norm = registry_.normalizeTypeName(elem_type);
      const auto* elem_def = registry_.findType(elem_norm);
      if (elem_def && (elem_def->kind == bhf::TypeDef::Kind::Struct ||
                       elem_def->kind == bhf::TypeDef::Kind::Union)) {
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        const size_t source_size = syms[sym_index].size;
        // Element stride: derive from the real array size when possible (exact wire
        // layout incl. padding); fall back to the computed type size otherwise.
        const size_t elem_size = (source_size >= count) ? source_size / count
                                                        : registry_.sizeOfType(elem_type);
        const size_t pack = pick_pack_for_struct(registry_, *elem_def, elem_size);
        for (size_t idx = 0; idx < count; ++idx) {
          auto* elem_item = new QTreeWidgetItem(item);
          elem_item->setText(0, QString::fromStdString("[" + std::to_string(idx) + "]"));
          elem_item->setText(1, QString::fromStdString(elem_type));
          elem_item->setText(2, QStringLiteral(""));
          elem_item->setText(3, QStringLiteral(""));
          elem_item->setFlags(elem_item->flags() & ~Qt::ItemIsEditable);
          addStructChildren(elem_item, idx * elem_size, sym_index, source_size,
                            *elem_def, true, std::string(), pack);
        }
        item->setExpanded(false);
        return true;
      }
    }
    return false;
  }

  if (type == "AXIS_REF" || type.find("AXIS_REF") != std::string::npos) {
    item->setFlags(item->flags() & ~Qt::ItemIsEditable);


    auto* plc_to_nc = find_child(item, "PlcToNc");
    if (!plc_to_nc) {
      plc_to_nc = new QTreeWidgetItem(item);
      plc_to_nc->setText(0, "PlcToNc");
      plc_to_nc->setText(1, "PLCTONC_AXIS_REF");
      plc_to_nc->setText(2, QStringLiteral(""));
      plc_to_nc->setText(3, QStringLiteral(""));
      plc_to_nc->setFlags(plc_to_nc->flags() & ~Qt::ItemIsEditable);
    }

    auto* nc_to_plc = find_child(item, "NcToPlc");
    if (!nc_to_plc) {
      nc_to_plc = new QTreeWidgetItem(item);
      nc_to_plc->setText(0, "NcToPlc");
      nc_to_plc->setText(1, "NCTOPLC_AXIS_REF");
      nc_to_plc->setText(2, QStringLiteral(""));
      nc_to_plc->setText(3, QStringLiteral(""));
      nc_to_plc->setFlags(nc_to_plc->flags() & ~Qt::ItemIsEditable);
    }

    auto* ads = find_child(item, "ADS");
    if (!ads) {
      ads = new QTreeWidgetItem(item);
      ads->setText(0, "ADS");
      ads->setText(1, "ST_AdsAddress");
      ads->setText(2, QStringLiteral(""));
      ads->setText(3, QStringLiteral(""));
      ads->setFlags(ads->flags() & ~Qt::ItemIsEditable);
    }

    auto* status = find_child(item, "Status");
    if (!status) {
      status = new QTreeWidgetItem(item);
      status->setText(0, "Status");
      status->setText(1, "ST_AxisStatus");
      status->setText(2, QStringLiteral(""));
      status->setText(3, QStringLiteral(""));
      status->setFlags(status->flags() & ~Qt::ItemIsEditable);
    }

    auto* drive = find_child(item, "DriveAddress");
    if (!drive) {
      drive = new QTreeWidgetItem(item);
      drive->setText(0, "DriveAddress");
      drive->setText(1, "ST_DriveAddress");
      drive->setText(2, QStringLiteral(""));
      drive->setText(3, QStringLiteral(""));
      drive->setFlags(drive->flags() & ~Qt::ItemIsEditable);
    }

    int plc_index = find_child_symbol_index(syms, syms[sym_index].name, "PlcToNc");
    int nc_index = find_child_symbol_index(syms, syms[sym_index].name, "NcToPlc");
    int ads_index = find_child_symbol_index(syms, syms[sym_index].name, "ADS");
    int status_index = find_child_symbol_index(syms, syms[sym_index].name, "Status");
    int drive_index = find_child_symbol_index(syms, syms[sym_index].name, "DriveAddress");

    if (plc_index < 0) {
      plc_index = find_child_symbol_index_by_type(syms, syms[sym_index].name, "PLCTONC_AXIS_REF");
    }
    if (nc_index < 0) {
      nc_index = find_child_symbol_index_by_type(syms, syms[sym_index].name, "NCTOPLC_AXIS_REF");
    }
    if (ads_index < 0) {
      ads_index = find_child_symbol_index_by_type(syms, syms[sym_index].name, "ST_AdsAddress");
    }
    if (status_index < 0) {
      status_index = find_child_symbol_index_by_type(syms, syms[sym_index].name, "ST_AxisStatus");
    }
    if (drive_index < 0) {
      drive_index = find_child_symbol_index_by_type(syms, syms[sym_index].name, "ST_DriveAddress");
    }

    const bool plc_has_symbol = plc_index >= 0;
    const bool nc_has_symbol = nc_index >= 0;
    const bool ads_has_symbol = ads_index >= 0;
    const bool status_has_symbol = status_index >= 0;
    const bool drive_has_symbol = drive_index >= 0;

    size_t plc_base = 0;
    size_t nc_base = 0;
    size_t ads_base = 0;
    size_t status_base = 0;
    size_t drive_base = 0;
    const auto* axis_def = registry_.findType("AXIS_REF");
    size_t axis_pack = 0;
    if (axis_def) {
      axis_pack = pick_pack_for_struct(registry_, *axis_def, syms[sym_index].size);
      if (!plc_has_symbol) struct_field_offset_with_pack(registry_, *axis_def, "PlcToNc", axis_pack, plc_base);
      if (!nc_has_symbol) struct_field_offset_with_pack(registry_, *axis_def, "NcToPlc", axis_pack, nc_base);
      if (!ads_has_symbol) struct_field_offset_with_pack(registry_, *axis_def, "ADS", axis_pack, ads_base);
      if (!status_has_symbol) struct_field_offset_with_pack(registry_, *axis_def, "Status", axis_pack, status_base);
      if (!drive_has_symbol) struct_field_offset_with_pack(registry_, *axis_def, "DriveAddress", axis_pack, drive_base);
    }

    const int plc_source = plc_has_symbol ? plc_index : sym_index;
    const int nc_source = nc_has_symbol ? nc_index : sym_index;
    const int ads_source = ads_has_symbol ? ads_index : sym_index;
    const int status_source = status_has_symbol ? status_index : sym_index;
    const int drive_source = drive_has_symbol ? drive_index : sym_index;

    const size_t plc_source_size = syms[plc_source].size;
    const size_t nc_source_size = syms[nc_source].size;
    const size_t ads_source_size = syms[ads_source].size;
    const size_t status_source_size = syms[status_source].size;
    const size_t drive_source_size = syms[drive_source].size;

    const auto* plc_def = registry_.findType("PLCTONC_AXIS_REF");
    const auto* nc_def = registry_.findType("NCTOPLC_AXIS_REF");
    const auto* ads_def = registry_.findType("ST_AdsAddress");
    const auto* status_def = registry_.findType("ST_AxisStatus");
    const auto* drive_def = registry_.findType("ST_DriveAddress");

    if (plc_def && plc_to_nc->childCount() == 0) {
      const size_t pack = pick_pack_for_struct(registry_, *plc_def, plc_source_size);
      addStructChildren(plc_to_nc, plc_has_symbol ? 0 : plc_base, plc_source,
                        plc_source_size,
                        *plc_def,
                        true,
                        std::string(),
                        pack);
    }

    if (nc_def && nc_to_plc->childCount() == 0) {
      const size_t pack = pick_pack_for_struct(registry_, *nc_def, nc_source_size);
      addStructChildren(nc_to_plc, nc_has_symbol ? 0 : nc_base, nc_source,
                        nc_source_size,
                        *nc_def,
                        true,
                        std::string(),
                        pack);
    }

    if (ads_def && ads->childCount() == 0) {
      const size_t pack = pick_pack_for_struct(registry_, *ads_def, ads_source_size);
      addStructChildren(ads, ads_has_symbol ? 0 : ads_base, ads_source,
                        ads_source_size,
                        *ads_def,
                        true,
                        ads_has_symbol ? std::string() : "AXIS_REF.ADS",
                        pack);
    }

    if (status_def && status->childCount() == 0) {
      const size_t pack = pick_pack_for_struct(registry_, *status_def, status_source_size);
      addStructChildren(status, status_has_symbol ? 0 : status_base, status_source,
                        status_source_size,
                        *status_def,
                        true,
                        status_has_symbol ? std::string() : "AXIS_REF.Status",
                        pack);
    }
    if (drive_def) {
      if (!(drive_has_symbol && drive->childCount() > 0)) {
        if (drive->childCount() == 0) {
          const size_t pack = pick_pack_for_struct(registry_, *drive_def, drive_source_size);
          addStructChildren(drive, drive_has_symbol ? 0 : drive_base, drive_source,
                            drive_source_size,
                            *drive_def,
                            true,
                            drive_has_symbol ? std::string() : "AXIS_REF.DriveAddress",
                            pack);
        }
      }
    }

    item->setExpanded(false);
    return true;
  }

  return false;
}

void StructTree::addStructChildren(QTreeWidgetItem* parent,
                                   size_t base_offset,
                                   int source_index,
                                   size_t source_size,
                                   const bhf::TypeDef& def,
                                   bool bind_values,
                                   const std::string& group_tag,
                                   size_t pack,
                                   int depth)
{
  // Stop descending into self-referential / cyclic types (or pathologically deep
  // nesting). Without this, a struct that contains its own type — directly or
  // through a zero-size field where the byte-offset guard never advances —
  // recurses until the stack overflows and the app crashes before the window shows.
  if (depth > 64) return;
  size_t offset = 0;
  int bit_index = 0;
  for (const auto& f : def.fields) {
    size_t field_array_len = f.array_len;
    std::string field_type = f.type;
    if (field_array_len == 1) {
      size_t alias_len = 1;
      std::string alias_elem;
      const auto resolved = registry_.resolveAlias(f.type);
      if (parse_array_alias(resolved, alias_len, alias_elem)) {
        field_array_len = alias_len;
        field_type = alias_elem;
      }
    }

    const auto base_type = registry_.resolveAlias(field_type);
    const bool is_bit = (base_type == "BIT") || f.is_bit;
    const size_t elem_size = registry_.sizeOfType(field_type);
    const auto* field_def = registry_.findType(base_type);
    const bool is_complex = field_def && (field_def->kind == bhf::TypeDef::Kind::Struct ||
                                          field_def->kind == bhf::TypeDef::Kind::Union);

    if (f.hidden) {
      if (is_bit) {
        for (size_t i = 0; i < field_array_len; ++i) {
          ++bit_index;
          if (bit_index >= 8) {
            offset += 1;
            bit_index = 0;
          }
        }
      } else if (def.kind != bhf::TypeDef::Kind::Union) {
        if (bit_index > 0) {
          offset += (bit_index + 7) / 8;
          bit_index = 0;
        }
        size_t align = registry_.alignmentOfType(field_type);
        if (pack > 0 && align > pack) align = pack;
        if (align > 1) {
          offset = (offset + align - 1) / align * align;
        }
        offset += elem_size * field_array_len;
      }
      continue;
    }

    if (!is_bit && def.kind != bhf::TypeDef::Kind::Union) {
      if (bit_index > 0) {
        offset += (bit_index + 7) / 8;
        bit_index = 0;
      }
      size_t align = registry_.alignmentOfType(field_type);
      if (pack > 0 && align > pack) align = pack;
      if (align > 1) {
        offset = (offset + align - 1) / align * align;
      }
    }

    if (bind_values && def.kind != bhf::TypeDef::Kind::Union && base_offset + offset >= source_size) {
      break;
    }

    QTreeWidgetItem* array_parent = parent;
    const bool is_array = field_array_len > 1;
    if (is_array) {
      auto* arr_item = new QTreeWidgetItem(parent);
      arr_item->setText(0, QString::fromStdString(f.name));
      arr_item->setText(1, QStringLiteral("ARRAY"));
      arr_item->setText(2, QStringLiteral(""));
      arr_item->setText(3, QStringLiteral(""));
      arr_item->setFlags(arr_item->flags() & ~Qt::ItemIsEditable);
      array_parent = arr_item;
    }

    for (size_t idx = 0; idx < field_array_len; ++idx) {
      auto* child = new QTreeWidgetItem(array_parent);
      const auto name = is_array ? ("[" + std::to_string(idx) + "]") : f.name;
      child->setText(0, QString::fromStdString(name));
      child->setText(1, QString::fromStdString(field_type));
      child->setText(2, QStringLiteral(""));
      child->setText(3, QStringLiteral(""));
      if (is_bit) {
        if (bind_values && def.kind != bhf::TypeDef::Kind::Union && base_offset + offset >= source_size) {
          break;
        }
        child->setData(0, kStructRole, bind_values);
        child->setFlags(child->flags() & ~Qt::ItemIsEditable);
        if (bind_values) {
          child->setFlags(child->flags() | Qt::ItemIsEditable);
          const size_t field_offset = (def.kind == bhf::TypeDef::Kind::Union) ? 0 : offset;
          struct_children_items_[source_index].push_back(
            { child, base_offset + field_offset, 1, "BIT", source_index, true, bit_index, base_offset, group_tag });
        } else {
          child->setText(2, QStringLiteral("N/A"));
        }
        ++bit_index;
        if (bit_index >= 8) {
          offset += 1;
          bit_index = 0;
        }
      } else if (is_complex) {
        if (bind_values && def.kind != bhf::TypeDef::Kind::Union &&
            base_offset + offset + idx * elem_size + elem_size > source_size) {
          break;
        }
        child->setFlags(child->flags() & ~Qt::ItemIsEditable);
        const size_t field_offset = (def.kind == bhf::TypeDef::Kind::Union) ? 0 : (offset + idx * elem_size);
        addStructChildren(child, base_offset + field_offset, source_index, source_size, *field_def, bind_values, group_tag, pack, depth + 1);
      } else {
        if (bind_values && def.kind != bhf::TypeDef::Kind::Union &&
            base_offset + offset + idx * elem_size + elem_size > source_size) {
          break;
        }
        child->setData(0, kStructRole, bind_values);
        child->setFlags(child->flags() & ~Qt::ItemIsEditable);
        if (bind_values) {
          child->setFlags(child->flags() | Qt::ItemIsEditable);
          const size_t field_offset = (def.kind == bhf::TypeDef::Kind::Union) ? 0 : (offset + idx * elem_size);
          struct_children_items_[source_index].push_back(
            { child, base_offset + field_offset, elem_size, field_type, source_index, false, 0, base_offset, group_tag });
        } else {
          child->setText(2, QStringLiteral("N/A"));
        }
      }
    }
    if (!is_bit) {
      if (def.kind != bhf::TypeDef::Kind::Union) {
        offset += elem_size * field_array_len;
      }
      bit_index = 0;
    }
  }
}

void StructTree::maybeFixAxisAdsOffsets(const std::vector<std::vector<uint8_t>>& raw)
{
  const auto layout = get_ads_layout(registry_);
  if (!layout.valid) return;

  for (int i = 0; i < (int)struct_children_items_.size(); ++i) {
    if (axis_ads_offset_fixed_.count(i) > 0) continue;
    if (i >= (int)raw.size() || raw[i].empty()) continue;

    size_t ads_base = 0;
    bool has_ads_group = false;
    for (const auto& child : struct_children_items_[i]) {
      if (child.group_tag == "AXIS_REF.ADS") {
        ads_base = child.group_base;
        has_ads_group = true;
        break;
      }
    }
    if (!has_ads_group) continue;

    size_t actual_offset = ads_base;
    if (!find_ads_offset_in_buffer(raw[i], ads_base, layout, actual_offset)) {
      continue;
    }
    if (actual_offset == ads_base) {
      axis_ads_offset_fixed_.insert(i);
      continue;
    }

    const long long delta = (long long)actual_offset - (long long)ads_base;
    for (auto& child : struct_children_items_[i]) {
      if (child.group_tag == "AXIS_REF.ADS" ||
          child.group_tag == "AXIS_REF.Status" ||
          child.group_tag == "AXIS_REF.DriveAddress") {
        const long long rel = (long long)child.offset - (long long)child.group_base;
        child.group_base = (size_t)((long long)child.group_base + delta);
        child.offset = (size_t)((long long)child.group_base + rel);
      }
    }
    axis_ads_offset_fixed_.insert(i);
  }
}

void StructTree::updateValues(const std::vector<std::vector<uint8_t>>& raw, PlcClient& client)
{
  maybeFixAxisAdsOffsets(raw);
  for (auto& per_symbol : struct_children_items_) {
    for (auto& child : per_symbol) {
      if (!child.item) continue;
      // Skip rows that aren't currently visible (an ancestor is collapsed). This
      // keeps each poll cheap regardless of how many struct fields exist; the row
      // refreshes on the next tick once the user expands its parent.
      bool visible = true;
      for (QTreeWidgetItem* a = child.item->parent(); a; a = a->parent()) {
        if (!a->isExpanded()) { visible = false; break; }
      }
      if (!visible) continue;
      const int src = child.source_index;
      if (src < 0 || src >= (int)raw.size() || raw[src].empty()) {
        child.item->setText(2, QStringLiteral("N/A"));
        continue;
      }
      const auto& buf = raw[src];
      if (child.offset + child.size > buf.size()) {
        child.item->setText(2, QStringLiteral("N/A"));
        continue;
      }
      if (child.is_bit) {
        const uint8_t byte = buf[child.offset];
        const bool bit = (byte >> child.bit_index) & 0x1;
        child.item->setText(2, bit ? "TRUE" : "FALSE");
      } else {
        long long enum_val = 0;
        bool enum_ok = false;
        if (child.size == 1) {
          int8_t v = 0; memcpy(&v, buf.data() + child.offset, 1);
          enum_val = v; enum_ok = true;
        } else if (child.size == 2) {
          int16_t v = 0; memcpy(&v, buf.data() + child.offset, 2);
          enum_val = v; enum_ok = true;
        } else if (child.size == 4) {
          int32_t v = 0; memcpy(&v, buf.data() + child.offset, 4);
          enum_val = v; enum_ok = true;
        } else if (child.size == 8) {
          int64_t v = 0; memcpy(&v, buf.data() + child.offset, 8);
          enum_val = v; enum_ok = true;
        }

        std::string enum_name;
        if (enum_ok && registry_.enumValueToString(child.type, enum_val, enum_name)) {
          child.item->setText(2, QString::fromStdString(enum_name));
        } else {
          const auto resolved_type = registry_.resolveAlias(child.type);
          const auto val = client.formatTypeValue(resolved_type, buf.data() + child.offset, child.size);
          child.item->setText(2, QString::fromStdString(val));
        }
      }
    }
  }
}

bool StructTree::isStructItem(QTreeWidgetItem* item) const
{
  return item && item->data(0, kStructRole).toBool();
}

std::string StructTree::resolveTypeName(const std::string& type) const
{
  return registry_.resolveAlias(type);
}

bool StructTree::formatEnumValue(const std::string& type, const uint8_t* data,
                                 size_t size, std::string& out) const
{
  if (!registry_.isLoaded() || data == nullptr) return false;
  if (!registry_.isEnum(type)) return false;
  const size_t tsize = registry_.sizeOfType(type);
  const size_t n = tsize ? tsize : size;
  if (n == 0 || n > size || n > 8) return false;
  long long val = 0;
  if (n == 1) { int8_t v = 0; memcpy(&v, data, 1); val = v; }
  else if (n == 2) { int16_t v = 0; memcpy(&v, data, 2); val = v; }
  else if (n == 4) { int32_t v = 0; memcpy(&v, data, 4); val = v; }
  else if (n == 8) { int64_t v = 0; memcpy(&v, data, 8); val = v; }
  else return false;
  return registry_.enumValueToString(type, val, out);
}

bool StructTree::handleEdit(QTreeWidgetItem* item,
                            PlcClient& client,
                            const std::vector<std::vector<uint8_t>>& raw,
                            std::string& error)
{
  StructChild meta{};
  bool found = false;
  for (const auto& vec : struct_children_items_) {
    for (const auto& child : vec) {
      if (child.item == item) {
        meta = child;
        found = true;
        break;
      }
    }
    if (found) break;
  }
  if (!found) return false;

  if (meta.is_bit) {
    const int src = meta.source_index;
    if (src < 0 || src >= (int)raw.size() || raw[src].empty()) {
      error = "Bitfield source not available";
      return false;
    }
    const auto& buf = raw[src];
    if (meta.offset + meta.size > buf.size()) {
      error = "Bitfield offset out of range";
      return false;
    }
    uint8_t byte = buf[meta.offset];
    const auto v = item->text(2).trimmed().toUpper();
    bool set = (v == "1" || v == "TRUE");
    if (set) byte |= (uint8_t)(1u << meta.bit_index);
    else byte &= (uint8_t)~(1u << meta.bit_index);
    return client.writeByOffset((size_t)meta.source_index, meta.offset, 1, "BYTE", std::to_string(byte), error);
  }

  const auto resolved_type = registry_.resolveAlias(meta.type);
  std::string value = item->text(2).toStdString();
  // For an enum field the cell holds the state name; write its integer value.
  long long ev = 0;
  if (registry_.isEnum(meta.type) && registry_.enumNameToValue(meta.type, value, ev)) {
    value = std::to_string(ev);
  }
  return client.writeByOffset((size_t)meta.source_index, meta.offset, meta.size, resolved_type, value, error);
}

size_t StructTree::typeSize(const std::string& type) const
{
  return registry_.sizeOfType(type);
}
