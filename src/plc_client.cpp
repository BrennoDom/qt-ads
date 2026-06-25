#include "plc_client.h"

#include <cstring>
#include <sstream>
#include <algorithm>

static inline long ads_read_req_ex2(long port, const AmsAddr* addr, uint32_t ig, uint32_t io,
  uint32_t len, void* data, uint32_t* bytes_read)
{
  long (*fn)(long, const AmsAddr*, uint32_t, uint32_t, uint32_t, void*, uint32_t*) = AdsSyncReadReqEx2;
  return fn(port, addr, ig, io, len, data, bytes_read);
}

static inline long ads_read_write_req_ex2(long port, const AmsAddr* addr, uint32_t ig, uint32_t io,
  uint32_t read_len, void* read_data, uint32_t write_len, const void* write_data, uint32_t* bytes_read)
{
  long (*fn)(long, const AmsAddr*, uint32_t, uint32_t, uint32_t, void*, uint32_t, const void*, uint32_t*) = AdsSyncReadWriteReqEx2;
  return fn(port, addr, ig, io, read_len, read_data, write_len, write_data, bytes_read);
}

static inline long ads_write_req_ex(long port, const AmsAddr* addr, uint32_t ig, uint32_t io,
  uint32_t len, const void* data)
{
  long (*fn)(long, const AmsAddr*, uint32_t, uint32_t, uint32_t, const void*) = AdsSyncWriteReqEx;
  return fn(port, addr, ig, io, len, data);
}

static inline long ads_write_control_req_ex(long port, const AmsAddr* addr, uint16_t ads_state,
  uint16_t dev_state, uint32_t len, const void* data)
{
  long (*fn)(long, const AmsAddr*, uint16_t, uint16_t, uint32_t, const void*) = AdsSyncWriteControlReqEx;
  return fn(port, addr, ads_state, dev_state, len, data);
}

PlcClient::PlcClient() : port_(0), connected_(false) {}

PlcClient::~PlcClient()
{
  disconnect();
}

bool PlcClient::connect(const AmsNetId& remoteNetId, const std::string& ip, uint16_t ams_port)
{
  netid_ = remoteNetId;
  ip_ = ip;
  ams_.netId = netid_;
  ams_.port = ams_port;

  long err = AdsAddRoute(netid_, ip_.c_str());
  if (err) {
    last_error_ = "AdsAddRoute failed: " + std::to_string(err);
    return false;
  }

  port_ = AdsPortOpenEx();
  if (!port_) {
    last_error_ = "AdsPortOpenEx failed";
    AdsDelRoute(netid_);
    return false;
  }

  connected_ = true;
  last_error_.clear();
  return true;
}

void PlcClient::disconnect()
{
  if (connected_) {
    AdsPortCloseEx(port_);
    AdsDelRoute(netid_);
  }
  connected_ = false;
  port_ = 0;
  symbols_.clear();
  read_commands_.clear();
  sum_read_response_.clear();
}

bool PlcClient::loadSymbols()
{
  if (!connected_) return false;

  AdsSymbolUploadInfoEx info{};
  long err = ads_read_req_ex2(
    port_, &ams_, ADSIGRP_SYM_UPLOADINFO, 0,
    sizeof(info), &info, nullptr);
  if (err || info.nSymSize == 0) {
    last_error_ = "ADSIGRP_SYM_UPLOADINFO failed: " + std::to_string(err);
    return false;
  }

  std::vector<uint8_t> buffer(info.nSymSize);
  err = ads_read_req_ex2(
    port_, &ams_, ADSIGRP_SYM_UPLOAD, 0,
    buffer.size(), buffer.data(), nullptr);
  if (err) {
    last_error_ = "ADSIGRP_SYM_UPLOAD failed: " + std::to_string(err);
    return false;
  }

  symbols_.clear();
  const uint8_t* ptr = buffer.data();
  const uint8_t* end = buffer.data() + buffer.size();

  while (ptr < end) {
    SymbolEntry ent{};
    ent.entry_length = *((uint32_t*) ptr);
    ent.index_group = *((uint32_t*) (ptr + 4));
    ent.index_offset = *((uint32_t*) (ptr + 8));
    ent.size = *((uint32_t*) (ptr + 12));
    ent.data_type = *((uint32_t*) (ptr + 16));
    ent.flags = *((uint32_t*) (ptr + 20));
    ent.name_length = *((uint16_t*) (ptr + 24));
    ent.type_length = *((uint16_t*) (ptr + 26));
    ent.comment_length = *((uint16_t*) (ptr + 28));
    ent.name = std::string((char*) (ptr + 30));
    ent.type = std::string((char*) (ptr + 30 + ent.name_length + 1));
    ent.comment = std::string((char*) (ptr + 30 + ent.name_length + 1 + ent.type_length + 1));

    symbols_.push_back(ent);
    ptr += ent.entry_length;
  }

  last_error_.clear();
  return !symbols_.empty();
}

bool PlcClient::buildSumRead()
{
  if (!connected_ || symbols_.empty()) return false;

  read_commands_.clear();
  read_commands_.reserve(symbols_.size());
  uint32_t total_read_data_size = 0;

  for (size_t i = 0; i < symbols_.size(); ++i) {
    const auto& ent = symbols_[i];
    uint32_t read_len = ent.size ? ent.size : sizeof(uint32_t);
    if (i < read_length_overrides_.size() && read_length_overrides_[i] > read_len) {
      read_len = read_length_overrides_[i];
    }
    if (read_len > 1024) read_len = 1024;
    read_commands_.push_back({ ent.index_group, ent.index_offset, read_len });
    total_read_data_size += read_len;
  }

  size_t sum_read_response_size = (symbols_.size() * sizeof(uint32_t)) + total_read_data_size;
  sum_read_response_.assign(sum_read_response_size, 0);
  last_error_.clear();
  return true;
}

void PlcClient::setReadLengthOverrides(const std::vector<uint32_t>& overrides)
{
  read_length_overrides_ = overrides;
}

bool PlcClient::readAll(std::vector<std::string>& values, std::string& error)
{
  std::vector<std::vector<uint8_t>> raw;
  return readAllDetailed(values, raw, error);
}

bool PlcClient::readAllDetailed(std::vector<std::string>& values,
                                std::vector<std::vector<uint8_t>>& raw,
                                std::string& error)
{
  if (!connected_ || symbols_.empty() || read_commands_.empty()) {
    error = "Not connected or symbols not loaded";
    last_error_ = error;
    return false;
  }

  long err = ads_read_write_req_ex2(
    port_, &ams_,
    0xF080,
    symbols_.size(),
    sum_read_response_.size(), sum_read_response_.data(),
    read_commands_.size() * sizeof(ReadSubCommand), read_commands_.data(),
    nullptr);

  if (err) {
    error = "Sum-Up Read failed: " + std::to_string(err);
    last_error_ = error;
    return false;
  }

  values.clear();
  raw.clear();
  values.reserve(symbols_.size());
  raw.reserve(symbols_.size());

  size_t result_offset = 0;
  size_t data_offset = symbols_.size() * sizeof(uint32_t);

  for (size_t i = 0; i < symbols_.size(); ++i) {
    uint32_t result = 0;
    memcpy(&result, sum_read_response_.data() + result_offset, sizeof(result));
    result_offset += sizeof(result);

    uint32_t read_len = read_commands_[i].read_length;
    if (result == 0) {
      values.push_back(formatValue(symbols_[i], sum_read_response_.data() + data_offset, read_len));
      raw.emplace_back(sum_read_response_.data() + data_offset,
                       sum_read_response_.data() + data_offset + read_len);
    } else {
      values.push_back("ERR" + std::to_string(result));
      raw.emplace_back();
    }
    data_offset += read_len;
  }

  return true;
}

bool PlcClient::writeValue(size_t symbolIndex, const std::string& value, std::string& error,
                           bool isArrayElement, long long elementOffset, const std::string& elementType)
{
  if (!connected_ || symbolIndex >= symbols_.size()) {
    error = "Invalid symbol index or not connected";
    last_error_ = error;
    return false;
  }

  const auto& sym = symbols_[symbolIndex];
  std::string type = sym.type;
  uint32_t size = sym.size;
  uint32_t offset = sym.index_offset;

  if (isArrayElement) {
    type = elementType;
    size_t elem_size = elementSize(type);
    if (elem_size == 0) {
      error = "Unsupported array element type";
      last_error_ = error;
      return false;
    }
    size = static_cast<uint32_t>(elem_size);
    offset = sym.index_offset + static_cast<uint32_t>(elementOffset * (long long)elem_size);
  }

  std::vector<uint8_t> bytes;
  if (!parseValue(type, value, bytes, error)) {
    last_error_ = error;
    return false;
  }

  if (bytes.size() > size) {
    error = "Value exceeds symbol size";
    last_error_ = error;
    return false;
  }

  if (bytes.size() < size) {
    bytes.resize(size, 0);
  }

  long err = ads_write_req_ex(
    port_, &ams_, sym.index_group, offset, bytes.size(), bytes.data());
  if (err) {
    error = "Write failed: " + std::to_string(err);
    last_error_ = error;
    return false;
  }

  last_error_.clear();
  return true;
}

bool PlcClient::writeByOffset(size_t symbolIndex, size_t byteOffset, size_t fieldSize,
                              const std::string& type, const std::string& value, std::string& error)
{
  if (!connected_ || symbolIndex >= symbols_.size()) {
    error = "Invalid symbol index or not connected";
    last_error_ = error;
    return false;
  }

  const auto& sym = symbols_[symbolIndex];
  std::vector<uint8_t> bytes;
  if (!parseValue(type, value, bytes, error)) {
    last_error_ = error;
    return false;
  }

  if (fieldSize == 0) {
    error = "Invalid field size";
    last_error_ = error;
    return false;
  }

  if (bytes.size() > fieldSize) {
    error = "Value exceeds field size";
    last_error_ = error;
    return false;
  }

  if (bytes.size() < fieldSize) {
    bytes.resize(fieldSize, 0);
  }

  const uint32_t offset = sym.index_offset + static_cast<uint32_t>(byteOffset);
  long err = ads_write_req_ex(
    port_, &ams_, sym.index_group, offset, bytes.size(), bytes.data());
  if (err) {
    error = "Write failed: " + std::to_string(err);
    last_error_ = error;
    return false;
  }

  last_error_.clear();
  return true;
}

bool PlcClient::setRuntimeState(RuntimeState state, std::string& error)
{
  if (!connected_) {
    error = "Not connected";
    last_error_ = error;
    return false;
  }

  const uint16_t ads_state = (state == RuntimeState::Run) ? 2 : 16;
  const uint16_t dev_state = ADSSTATE_INVALID;
  std::vector<uint16_t> ports;
  ports.push_back(10000);
  if (ams_.port != 10000) {
    ports.push_back(ams_.port);
  }

  long err = 0;
  for (auto port : ports) {
    AmsAddr ctrl_addr = ams_;
    ctrl_addr.port = port;
    err = ads_write_control_req_ex(port_, &ctrl_addr, ads_state, dev_state, 0, nullptr);
    if (!err || err == 1861) {
      last_error_.clear();
      return true;
    }
  }

  error = "WriteControl failed: " + std::to_string(err);
  if (err == 1793) {
    error += " (service not supported)";
  }
  last_error_ = error;
  return false;

  last_error_.clear();
  return true;
}

std::string PlcClient::formatValue(const SymbolEntry& ent, const uint8_t* data, uint32_t len) const
{
  std::ostringstream out;
  const std::string& t = ent.type;

  if (t == "BOOL") {
    out << (data[0] ? "TRUE" : "FALSE");
  } else if (t == "BYTE" || t == "USINT") {
    out << static_cast<unsigned>(data[0]);
  } else if (t == "SINT") {
    out << static_cast<int>(*(int8_t*)data);
  } else if (t == "INT" || t == "WORD" || t == "UINT") {
    uint16_t v = 0; memcpy(&v, data, sizeof(v));
    if (t == "INT") out << static_cast<int16_t>(v);
    else out << v;
  } else if (t == "DINT" || t == "DWORD" || t == "UDINT") {
    uint32_t v = 0; memcpy(&v, data, sizeof(v));
    if (t == "DINT") out << static_cast<int32_t>(v);
    else out << v;
  } else if (t == "LINT") {
    int64_t v = 0; memcpy(&v, data, sizeof(v));
    out << v;
  } else if (t == "ULINT") {
    uint64_t v = 0; memcpy(&v, data, sizeof(v));
    out << v;
  } else if (t == "REAL") {
    float v = 0; memcpy(&v, data, sizeof(v));
    out << v;
  } else if (t == "LREAL") {
    double v = 0; memcpy(&v, data, sizeof(v));
    out << v;
  } else if (t == "AXIS_REF") {
    out << "AXIS_REF{";
    for (uint32_t b = 0; b < len; ++b) {
      out << std::hex << std::uppercase << (int)data[b];
      if (b + 1 < len) out << ' ';
    }
    if (len == sizeof(uint64_t)) {
      uint64_t v = 0;
      memcpy(&v, data, sizeof(v));
      out << std::dec << ", u64=" << v;
    }
    out << "}";
  } else if (t.rfind("STRING", 0) == 0) {
    out << std::string((const char*)data, strnlen((const char*)data, len));
  } else if (t.rfind("ARRAY", 0) == 0) {
    int64_t lower = 0;
    int64_t upper = -1;
    size_t lb = t.find('[');
    size_t rb = t.find(']');
    size_t dots = t.find("..", lb);
    if (lb != std::string::npos && rb != std::string::npos && dots != std::string::npos) {
      lower = std::strtoll(t.substr(lb + 1, dots - (lb + 1)).c_str(), nullptr, 10);
      upper = std::strtoll(t.substr(dots + 2, rb - (dots + 2)).c_str(), nullptr, 10);
    }

    std::string elem_type;
    size_t of_pos = t.find("OF ");
    if (of_pos != std::string::npos) {
      elem_type = t.substr(of_pos + 3);
    }

    size_t elem_size = elementSize(elem_type);
    int64_t count = (upper >= lower) ? (upper - lower + 1) : 0;
    if (elem_size == 0 || count <= 0) {
      for (uint32_t b = 0; b < len; ++b) {
        out << std::hex << std::uppercase << (int)data[b];
        if (b + 1 < len) out << ' ';
      }
      return out.str();
    }

    size_t max_count = len / elem_size;
    if ((int64_t)max_count < count) count = (int64_t)max_count;

    for (int64_t idx = 0; idx < count; ++idx) {
      size_t off = (size_t)idx * elem_size;
      out << '[' << (lower + idx) << "]=";
      SymbolEntry tmp = ent;
      tmp.type = elem_type;
      out << formatValue(tmp, data + off, (uint32_t)elem_size);
      if (idx + 1 < count) out << ", ";
    }
  } else {
    for (uint32_t b = 0; b < len; ++b) {
      out << std::hex << std::uppercase << (int)data[b];
      if (b + 1 < len) out << ' ';
    }
  }

  return out.str();
}

std::string PlcClient::formatTypeValue(const std::string& type, const uint8_t* data, uint32_t len) const
{
  SymbolEntry tmp{};
  tmp.type = type;
  return formatValue(tmp, data, len);
}

bool PlcClient::parseValue(const std::string& type, const std::string& value,
                           std::vector<uint8_t>& out, std::string& error) const
{
  out.clear();

  auto trim = [](const std::string& s) {
    auto start = s.find_first_not_of(" \t\r\n");
    auto end = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos) return std::string();
    return s.substr(start, end - start + 1);
  };

  const std::string v = trim(value);
  if (type == "BOOL") {
    uint8_t b = (v == "1" || v == "TRUE" || v == "true") ? 1 : 0;
    out.assign(&b, &b + 1);
  } else if (type == "BYTE" || type == "USINT") {
    uint8_t u = static_cast<uint8_t>(std::stoul(v));
    out.assign(&u, &u + 1);
  } else if (type == "SINT") {
    int8_t s = static_cast<int8_t>(std::stol(v));
    out.assign(reinterpret_cast<uint8_t*>(&s), reinterpret_cast<uint8_t*>(&s) + 1);
  } else if (type == "INT") {
    int16_t s = static_cast<int16_t>(std::stol(v));
    out.resize(sizeof(s));
    memcpy(out.data(), &s, sizeof(s));
  } else if (type == "WORD" || type == "UINT") {
    uint16_t u = static_cast<uint16_t>(std::stoul(v));
    out.resize(sizeof(u));
    memcpy(out.data(), &u, sizeof(u));
  } else if (type == "DINT") {
    int32_t s = static_cast<int32_t>(std::stol(v));
    out.resize(sizeof(s));
    memcpy(out.data(), &s, sizeof(s));
  } else if (type == "DWORD" || type == "UDINT") {
    uint32_t u = static_cast<uint32_t>(std::stoul(v));
    out.resize(sizeof(u));
    memcpy(out.data(), &u, sizeof(u));
  } else if (type == "LINT") {
    int64_t s = static_cast<int64_t>(std::stoll(v));
    out.resize(sizeof(s));
    memcpy(out.data(), &s, sizeof(s));
  } else if (type == "ULINT") {
    uint64_t u = static_cast<uint64_t>(std::stoull(v));
    out.resize(sizeof(u));
    memcpy(out.data(), &u, sizeof(u));
  } else if (type == "REAL") {
    float f = std::stof(v);
    out.resize(sizeof(f));
    memcpy(out.data(), &f, sizeof(f));
  } else if (type == "LREAL") {
    double d = std::stod(v);
    out.resize(sizeof(d));
    memcpy(out.data(), &d, sizeof(d));
  } else if (type.rfind("STRING", 0) == 0) {
    size_t max_len = elementSize(type);
    if (max_len == 0) {
      error = "Unsupported STRING length";
      return false;
    }
    out.resize(max_len, 0);
    const size_t copy_len = std::min(max_len - 1, v.size());
    memcpy(out.data(), v.data(), copy_len);
  } else {
    error = "Unsupported type for write";
    return false;
  }

  return true;
}

size_t PlcClient::elementSize(const std::string& t)
{
  if (t == "BOOL" || t == "BYTE" || t == "USINT" || t == "SINT") return 1;
  if (t == "INT" || t == "UINT" || t == "WORD") return 2;
  if (t == "DINT" || t == "UDINT" || t == "DWORD" || t == "REAL") return 4;
  if (t == "LINT" || t == "ULINT" || t == "LREAL") return 8;
  if (t.rfind("STRING", 0) == 0) {
    size_t lp = t.find('(');
    size_t rp = t.find(')');
    if (lp != std::string::npos && rp != std::string::npos && rp > lp + 1) {
      int len = std::atoi(t.substr(lp + 1, rp - (lp + 1)).c_str());
      return (size_t)len + 1;
    }
  }
  return 0;
}
