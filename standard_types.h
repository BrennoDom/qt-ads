#pragma once

#include <cstddef>
#include <string>

namespace tc_standard {

struct ValidationResult {
  bool ok;
  std::string error;
};

ValidationResult validateInput(const std::string& type, const std::string& value);
size_t baseTypeSize(const std::string& type);

} // namespace tc_standard
