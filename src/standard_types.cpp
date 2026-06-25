// ADS Qt Monitor — live TwinCAT PLC variable monitor over ADS for Linux.
//
// Copyright (c) 2026 Brenno Domingues <brennohdomingues@gmail.com>
// GitHub: https://github.com/BrennoDom
//
// SPDX-License-Identifier: MIT
// Licensed under the MIT License; see the LICENSE file in the project root.

#include "standard_types.h"

#include <cmath>
#include <cstdlib>
#include <limits>
#include <string>

namespace tc_standard {

static std::string trim_ws(const std::string& s)
{
  auto start = s.find_first_not_of(" \t\r\n");
  auto end = s.find_last_not_of(" \t\r\n");
  if (start == std::string::npos) return std::string();
  return s.substr(start, end - start + 1);
}

static bool parse_int64(const std::string& s, long long& out)
{
  size_t idx = 0;
  try {
    out = std::stoll(s, &idx, 10);
  } catch (...) {
    return false;
  }
  return idx == s.size();
}

static bool parse_uint64(const std::string& s, unsigned long long& out)
{
  if (!s.empty() && s[0] == '-') {
    return false;
  }
  size_t idx = 0;
  try {
    out = std::stoull(s, &idx, 10);
  } catch (...) {
    return false;
  }
  return idx == s.size();
}

static bool parse_double(const std::string& s, double& out)
{
  size_t idx = 0;
  try {
    out = std::stod(s, &idx);
  } catch (...) {
    return false;
  }
  return idx == s.size() && std::isfinite(out);
}

ValidationResult validateInput(const std::string& type, const std::string& value)
{
  const auto v = trim_ws(value);
  if (v.empty()) return { false, "Valor vazio" };

  if (type == "BOOL") {
    const auto up = std::string([&]() {
      std::string tmp = v;
      for (auto& ch : tmp) ch = (char)std::toupper((unsigned char)ch);
      return tmp;
    }());
    if (up == "0" || up == "1" || up == "TRUE" || up == "FALSE") return { true, "" };
    return { false, "BOOL aceita 0/1/TRUE/FALSE" };
  }

  if (type == "SINT") {
    long long x = 0;
    if (!parse_int64(v, x) || x < -128 || x > 127) return { false, "SINT: -128..127" };
    return { true, "" };
  }
  if (type == "USINT" || type == "BYTE") {
    if (!v.empty() && v[0] == '-') return { false, "USINT/BYTE não aceita negativo" };
    unsigned long long x = 0;
    if (!parse_uint64(v, x) || x > 255) return { false, "USINT/BYTE: 0..255" };
    return { true, "" };
  }
  if (type == "INT") {
    long long x = 0;
    if (!parse_int64(v, x) || x < -32768 || x > 32767) return { false, "INT: -32768..32767" };
    return { true, "" };
  }
  if (type == "UINT" || type == "WORD") {
    if (!v.empty() && v[0] == '-') return { false, "UINT/WORD não aceita negativo" };
    unsigned long long x = 0;
    if (!parse_uint64(v, x) || x > 65535) return { false, "UINT/WORD: 0..65535" };
    return { true, "" };
  }
  if (type == "DINT") {
    long long x = 0;
    if (!parse_int64(v, x) || x < std::numeric_limits<int32_t>::min() || x > std::numeric_limits<int32_t>::max()) {
      return { false, "DINT: -2147483648..2147483647" };
    }
    return { true, "" };
  }
  if (type == "UDINT" || type == "DWORD") {
    if (!v.empty() && v[0] == '-') return { false, "UDINT/DWORD não aceita negativo" };
    unsigned long long x = 0;
    if (!parse_uint64(v, x) || x > 4294967295ULL) return { false, "UDINT/DWORD: 0..4294967295" };
    return { true, "" };
  }
  if (type == "LINT") {
    long long x = 0;
    if (!parse_int64(v, x)) return { false, "LINT inválido" };
    return { true, "" };
  }
  if (type == "ULINT") {
    if (!v.empty() && v[0] == '-') return { false, "ULINT não aceita negativo" };
    unsigned long long x = 0;
    if (!parse_uint64(v, x)) return { false, "ULINT inválido" };
    return { true, "" };
  }
  if (type == "REAL" || type == "LREAL") {
    double x = 0.0;
    if (!parse_double(v, x)) return { false, "Número real inválido" };
    return { true, "" };
  }
  if (type.rfind("STRING", 0) == 0) {
    return { true, "" };
  }

  return { false, "Tipo não suportado" };
}

size_t baseTypeSize(const std::string& type)
{
  if (type == "BOOL" || type == "BYTE" || type == "USINT" || type == "SINT" || type == "BIT") return 1;
  if (type == "INT" || type == "UINT" || type == "WORD") return 2;
  if (type == "DINT" || type == "UDINT" || type == "DWORD" || type == "REAL") return 4;
  if (type == "LINT" || type == "ULINT" || type == "LREAL") return 8;
  if (type.rfind("STRING", 0) == 0) {
    size_t lp = type.find('(');
    size_t rp = type.find(')');
    if (lp != std::string::npos && rp != std::string::npos && rp > lp + 1) {
      int len = std::atoi(type.substr(lp + 1, rp - (lp + 1)).c_str());
      return (size_t)len + 1;
    }
  }
  return 4;
}

} // namespace tc_standard
