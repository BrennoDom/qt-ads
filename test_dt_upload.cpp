#include "TwinCAT/AdsDef.h"
#include <TcAdsAPI.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>

namespace bhf { namespace ads { long AddLocalRoute(const AmsNetId, const char*); }}

static std::string find_ascii(const uint8_t* d, size_t max) {
  for (size_t o = 0; o < max; ++o) {
    if (d[o] >= 0x20 && d[o] <= 0x7E) {
      auto s = std::string((const char*)(d + o), strnlen((const char*)(d + o), max - o));
      if (s.size() >= 2) { bool ok = true;
        for (auto c : s) if (c < 0x20 || c > 0x7E) { ok = false; break; }
        if (ok) return s; }
    }
  }
  return {};
}

int main() {
  AmsNetId netid{}; memcpy(netid.b, ((uint8_t[]){127,0,0,1,1,1}), 6);
  bhf::ads::AddLocalRoute(netid, "127.0.0.1");
  ads_i32 p = AdsPortOpenEx(); if (!p) return 1;
  AmsAddr a{}; a.netId = netid; a.port = 851;
  ads_ui32 br; ads_i32 e;

  // Info de tipos
  ads_ui8 ib[32]={0}; br=0;
  e = AdsSyncReadReqEx2(p, &a, 0xF00F, 0, 32, ib, &br);
  if (e) { printf("0xF00F failed: %ld\n", (long)e); return 1; }
  ads_ui32 nTypes, nDtSize;
  memcpy(&nTypes, ib+8, 4); memcpy(&nDtSize, ib+12, 4);
  printf("nTypes=%u nDtSize=%u\n", nTypes, nDtSize);

  // Ler tipos
  std::vector<uint8_t> buf(nDtSize); br=0;
  e = AdsSyncReadReqEx2(p, &a, 0xF00E, 0, nDtSize, buf.data(), &br);
  if (e) { printf("0xF00E failed: %ld\n", (long)e); return 1; }

  // Indexar
  struct Entry { const uint8_t* d; ads_ui32 len; std::string name; };
  std::map<std::string, Entry> entries;
  const uint8_t* pp = buf.data();
  const uint8_t* end = pp + br;
  ads_ui32 parsed = 0;
  while (pp + 16 <= end && parsed < nTypes) {
    ads_ui32 eL; memcpy(&eL, pp, 4);
    if (eL == 0 || eL > (ads_ui32)(end - pp)) break;
    auto name = find_ascii(pp + 28, (eL > 48 ? 48 : eL) - 28);
    if (!name.empty()) entries[name] = {pp, eL, name};
    pp += eL; parsed++;
  }
  printf("Indexed %zu types\n\n", entries.size());

  // Analisar ST_PNIE_CONTROL_BITS fields
  auto it = entries.find("ST_PNIE_CONTROL_BITS");
  if (it == entries.end()) { printf("ST_PNIE_CONTROL_BITS not found\n"); return 1; }
  const auto& e2 = it->second;

  size_t name_off = 0;
  for (size_t o = 28; o < 48 && o < e2.len; ++o)
    if (e2.d[o] == 'S' && memcmp(e2.d+o, "ST_PNIE_CONTROL_BITS", 20) == 0) { name_off = o; break; }

  size_t after = name_off + e2.name.size() + 1;
  while (after < e2.len && e2.d[after] == 0) after++;

  printf("ST_PNIE_CONTROL_BITS fields at offset %zu\n\n", after);
  printf("Header pre-field bytes:");
  for (size_t i = 0; i < 8 && after + i < e2.len; ++i)
    printf(" %02X", e2.d[after + i]);
  printf("\n\n");

  // Skip the first entry to find the subfield
  size_t pos = after;
  int fld = 0;
  while (pos + 40 < e2.len) {
    // Read field entry length
    ads_ui32 fLen; 
    // Try at pos, pos+1, pos+2 to find valid entry
    int shift = 0;
    for (int s = 0; s < 4; s++) {
      memcpy(&fLen, e2.d + pos + s, 4);
      if (fLen >= 40 && fLen <= 300) { shift = s; break; }
    }
    if (shift == 0 && fLen < 40) { pos++; continue; }
    pos += shift;
    memcpy(&fLen, e2.d + pos, 4);
    if (fLen < 40 || fLen > e2.len - pos) break;

    ads_ui32 fFlags; memcpy(&fFlags, e2.d+pos+4, 4);
    ads_ui32 fSize;  memcpy(&fSize,  e2.d+pos+8, 4);
    ads_ui32 fOffs;  memcpy(&fOffs,  e2.d+pos+12, 4);
    ads_ui32 fExtra; memcpy(&fExtra, e2.d+pos+16, 4);

    // Find name, type, comment strings
    std::string fName, fType, fComment;
    for (size_t sc = 20; sc < fLen - 2; ++sc) {
      auto s = find_ascii(e2.d + pos + sc, fLen - sc);
      if (s.empty()) continue;
      if (fName.empty()) fName = s;
      else if (fType.empty()) fType = s;
      else if (fComment.empty()) { fComment = s; break; }
      if (sc + s.size() < fLen) sc += s.size();
      else break;
    }

    printf("F[%2d]: len=%3u flags=0x%X size=%3u byteOffs=%3u extra=0x%X",
           fld, fLen, fFlags, fSize, fOffs, fExtra);
    if (!fName.empty()) printf(" '%s'", fName.c_str());
    if (!fType.empty()) printf(" : %s", fType.c_str());
    if (!fComment.empty()) printf(" /* %s */", fComment.c_str());
    printf("\n");

    pos += fLen; fld++;
    if (fld > 40) break;
  }

  AdsPortCloseEx(p);
  return 0;
}
