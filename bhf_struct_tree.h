#pragma once

#include <QTreeWidgetItem>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "plc_client.h"
#include "bhf_registry.h"

class StructTree {
public:
  static constexpr int kStructRole = Qt::UserRole + 6;

  struct StructChild {
    QTreeWidgetItem* item;
    size_t offset;
    size_t size;
    std::string type;
    int source_index;
    bool is_bit;
    int bit_index;
    size_t group_base;
    std::string group_tag;
  };

  void loadFromPlc(long port, const AmsAddr* addr);
  void clear(size_t symbol_count);
  bool isLoaded() const { return registry_.isLoaded(); }

  bool shouldSkipSymbol(const std::vector<SymbolEntry>& syms,
                        const std::unordered_map<std::string, int>& name_to_index,
                        int sym_index) const;

  bool addChildrenForSymbol(const std::vector<SymbolEntry>& syms,
                            const std::unordered_map<std::string, int>& name_to_index,
                            int sym_index,
                            QTreeWidgetItem* item);

  void updateValues(const std::vector<std::vector<uint8_t>>& raw, PlcClient& client);
  std::string resolveTypeName(const std::string& type) const;

  bool isStructItem(QTreeWidgetItem* item) const;

  bool handleEdit(QTreeWidgetItem* item,
                  PlcClient& client,
                  const std::vector<std::vector<uint8_t>>& raw,
                  std::string& error);

  size_t typeSize(const std::string& type) const;

private:
  bhf::TypeRegistry registry_;
  std::vector<std::vector<StructChild>> struct_children_items_;
  std::unordered_set<int> axis_ads_offset_fixed_;

  void addStructChildren(QTreeWidgetItem* parent,
                         size_t base_offset,
                         int source_index,
                         size_t source_size,
                         const bhf::TypeDef& def,
                         bool bind_values = true,
                         const std::string& group_tag = std::string(),
                         size_t pack = 0,
                         int depth = 0);

  void maybeFixAxisAdsOffsets(const std::vector<std::vector<uint8_t>>& raw);
};
