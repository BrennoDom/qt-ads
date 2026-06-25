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
  size_t fieldOffset(const std::string& typeName, const std::string& fieldName) const;
  bool isLoaded() const { return loaded_; }

private:
  std::unordered_map<std::string, TypeDef> types_;
  std::unordered_map<std::string, std::unordered_map<long long, std::string>> enum_values_;
  bool loaded_ = false;

  void parseFieldEntries(const uint8_t* data, uint32_t size, TypeDef& def);
  static std::string trim(const std::string& s);
};

} // namespace bhf
