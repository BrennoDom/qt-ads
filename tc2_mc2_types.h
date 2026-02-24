#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace tc2_mc2 {

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
  void load(const std::string& root);
  const TypeDef* findType(const std::string& name) const;
  std::string normalizeTypeName(const std::string& name) const;
  std::string resolveAlias(const std::string& name) const;
  size_t sizeOfType(const std::string& name) const;
  size_t alignmentOfType(const std::string& name) const;
  bool enumValueToString(const std::string& type, long long value, std::string& out) const;

  TypeDef fallbackPlcToNc() const;
  TypeDef fallbackNcToPlc() const;
  TypeDef fallbackAdsAddress() const;

private:
  std::unordered_map<std::string, TypeDef> types_;
  std::unordered_map<std::string, std::unordered_map<long long, std::string>> enum_values_;

  static std::string trim(const std::string& s);
};

} // namespace tc2_mc2
