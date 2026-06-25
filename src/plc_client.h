// ADS Qt Monitor — live TwinCAT PLC variable monitor over ADS for Linux.
//
// Copyright (c) 2026 Brenno Domingues <brennohdomingues@gmail.com>
// GitHub: https://github.com/BrennoDom
//
// SPDX-License-Identifier: MIT
// Licensed under the MIT License; see the LICENSE file in the project root.

#pragma once

#include "AdsLib.h"

#include <cstdint>
#include <string>
#include <vector>

struct SymbolEntry {
  uint32_t entry_length;
  uint32_t index_group;
  uint32_t index_offset;
  uint32_t size;
  uint32_t data_type;
  uint32_t flags;
  uint16_t name_length;
  uint16_t type_length;
  uint16_t comment_length;
  std::string name;
  std::string type;
  std::string comment;
};

struct ReadSubCommand {
  uint32_t index_group;
  uint32_t index_offset;
  uint32_t read_length;
};

struct AdsSymbolUploadInfoEx {
  uint32_t nSymbols;
  uint32_t nSymSize;
};

class PlcClient {
public:
  enum class RuntimeState { Run, Config };

  PlcClient();
  ~PlcClient();

  bool connect(const AmsNetId& remoteNetId, const std::string& ip, uint16_t ams_port);
  void disconnect();

  bool loadSymbols();
  void setReadLengthOverrides(const std::vector<uint32_t>& overrides);
  bool buildSumRead();
  bool readAll(std::vector<std::string>& values, std::string& error);
  bool readAllDetailed(std::vector<std::string>& values,
                       std::vector<std::vector<uint8_t>>& raw,
                       std::string& error);
  bool writeValue(size_t symbolIndex, const std::string& value, std::string& error,
                  bool isArrayElement = false, long long elementOffset = 0, const std::string& elementType = "");
  bool writeByOffset(size_t symbolIndex, size_t byteOffset, size_t fieldSize,
                     const std::string& type, const std::string& value, std::string& error);
  bool setRuntimeState(RuntimeState state, std::string& error);

  std::string formatTypeValue(const std::string& type, const uint8_t* data, uint32_t len) const;

  bool isConnected() const { return connected_; }
  const std::string& lastError() const { return last_error_; }
  long port() const { return port_; }
  const AmsAddr& ams() const { return ams_; }

  const std::vector<SymbolEntry>& symbols() const { return symbols_; }

private:
  std::string formatValue(const SymbolEntry& ent, const uint8_t* data, uint32_t len) const;
  bool parseValue(const std::string& type, const std::string& value, std::vector<uint8_t>& out, std::string& error) const;
  static size_t elementSize(const std::string& t);

  long port_;
  AmsAddr ams_{};
  AmsNetId netid_{};
  std::string ip_;
  bool connected_;

  std::vector<SymbolEntry> symbols_;
  std::vector<ReadSubCommand> read_commands_;
  std::vector<uint32_t> read_length_overrides_;
  std::vector<uint8_t> sum_read_response_;
  std::string last_error_;
};
