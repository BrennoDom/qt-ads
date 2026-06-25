// ADS Qt Monitor — live TwinCAT PLC variable monitor over ADS for Linux.
//
// Copyright (c) 2026 Brenno Domingues <brennohdomingues@gmail.com>
// GitHub: https://github.com/BrennoDom
//
// SPDX-License-Identifier: MIT
// Licensed under the MIT License; see the LICENSE file in the project root.

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
