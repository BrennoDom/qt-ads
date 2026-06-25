#pragma once

#include "AdsLib.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace bhf {

struct TypeField {
  std::string name;
  std::string type;
  size_t array_len;
  bool hidden;
  bool is_bit;
  size_t byte_offset = 0;  // offset within parent struct, as reported by the PLC
  size_t field_size = 0;   // element size in bytes, as reported by the PLC (0 = unknown)
};

struct TypeDef {
  enum class Kind { Alias, Struct, Union };
  Kind kind;
  std::string alias;
  std::vector<TypeField> fields;
};

class TypeRegistry {
public:
  void loadFromPlc(long port, const AmsAddr* addr);
  const TypeDef* findType(const std::string& name) const;
  std::string normalizeTypeName(const std::string& name) const;
  std::string resolveAlias(const std::string& name) const;
  size_t sizeOfType(const std::string& name, int depth = 0) const;
  size_t alignmentOfType(const std::string& name, int depth = 0) const;
  bool enumValueToString(const std::string& type, long long value, std::string& out) const;
  bool isEnum(const std::string& type) const;
  size_t fieldOffset(const std::string& typeName, const std::string& fieldName) const;
  bool isLoaded() const { return loaded_; }

private:
  std::unordered_map<std::string, TypeDef> types_;
  std::unordered_map<std::string, std::unordered_map<long long, std::string>> enum_values_;
  bool loaded_ = false;

  void parseFieldEntries(const uint8_t* data, uint32_t size, TypeDef& def);
  // Parse an enum definition: base type string followed by length-prefixed
  // (name, int value) constants. Fills enum_values_[enumKey] and returns the
  // underlying integer type in baseTypeOut. Returns false if not an enum.
  bool parseEnumDef(const uint8_t* data, uint32_t size,
                    const std::string& enumKey, std::string& baseTypeOut);
  static std::string trim(const std::string& s);
};

} // namespace bhf
