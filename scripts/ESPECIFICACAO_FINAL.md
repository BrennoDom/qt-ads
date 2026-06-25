# Fase Final: Constructor via PLC Runtime (SYM_DT_UPLOAD)

## Objetivo

Substituir completamente o carregamento de tipos do `BHF_context/` (markdown) por carregamento **direto do PLC runtime** via ADS. O PLC já tem todos os tipos do projeto compilado — structs, unions, aliases, enums, subcampos com nomes, tipos, comentários e offsets.

---

## Arquivos que mudam

| Arquivo | Mudança |
|---------|---------|
| `tc2_mc2_types.h` | Adicionar `loadFromPlc()`, remover `loadAll()`, `parseTypeDefinition()`, `injectBuiltinTypes()`, `normalizeTypeName()` |
| `tc2_mc2_types.cpp` | Implementar parser de `SYM_DT_UPLOAD (0xF00E)`. Remover todo parser de markdown (~250 linhas). Manter `fieldOffset()`, `sizeOfType()`, `enumValueToString()` |
| `tc2_mc2_monitor.h` | `loadAll()` → `loadFromPlc(long port, const AmsAddr* addr)` |
| `tc2_mc2_monitor.cpp` | Implementar `loadFromPlc()` que chama `registry_.loadFromPlc()` |
| `plc_monitor_window.cpp` | Chamar `tc2_mc2_monitor_.loadFromPlc()` após conectar |
| `CMakeLists.txt` | Não precisa mudar (já linka com ads) |

Arquivos que **NÃO** mudam: `plc_client.cpp/.h`, `standard_types.cpp/.h`

---

## Protocolo ADS descoberto (testado com PLC real)

### 1. SYM_UPLOADINFO2 (0xF00F) — obter info de tipos

```cpp
uint8_t buffer[32]; uint32_t br;
AdsSyncReadReqEx2(port, addr, 0xF00F, 0, 32, buffer, &br);

// Retorna (little-endian uint32):
buffer[0..3]   nSymbols  (só para referência)
buffer[4..7]   nSymSize  (só para referência)
buffer[8..11]  nTypes    ← NÚMERO DE TIPOS (ex: 119)
buffer[12..15] nDtSize   ← TAMANHO TOTAL DOS DADOS (ex: 80320 bytes)
```

### 2. SYM_DT_UPLOAD (0xF00E) — ler definições de tipos

```cpp
std::vector<uint8_t> buf(nDtSize);
AdsSyncReadReqEx2(port, addr, 0xF00E, 0, nDtSize, buf.data(), &br);
// br == nDtSize
```

### 3. Formato de cada type entry

```
[0..3]    entryLength  → tamanho total desta entrada (ex: 360, 240, 2432...)
[4..7]    flags        → 1 = type definition
[8..11]   typeSize     → 0 para struct/union, >0 para tipos base/ex: WORD=2, DWORD=4
[12..15]  memberCount  → 0 para tipos base, >0 para structs com campos
[16..41]  metadados    → 26 bytes de info adicional
[42..]    typeName     → string nul-terminada (ex: "ST_PNIE_CONTROL_BITS")
[after]   field entries → array de subcampos (se memberCount > 0)
```

### 4. Formato de cada field entry (subcampo)

```
[0..3]    entryLength  → tamanho total deste field (ex: 106, 111, 110...)
[4..7]    flags        → 1
[8..11]   fieldSize    → 0 para BIT, 2 para WORD, 4 para DWORD, etc.
[12..15]  byteOffset   → offset em bytes dentro da struct pai
[16..19]  bitOffset    → offset em bits (apenas para BIT)
[20..31]  metadados
[32..33]  nameLength   → comprimento do nome (ex: 12 para "EnableRobot")
[34..35]  typeLength   → comprimento do tipo (ex: 3 para "BIT")
[36..37]  commentLength→ comprimento do comentário
[38..44]  padding
[45..]    fieldName\0  → nome do campo (nul-terminated)
          fieldType\0  → tipo do campo (nul-terminated)
          comment\0    → comentário (nul-terminated)
```

---

## Implementação em tc2_mc2_types.cpp

### loadFromPlc()

```cpp
void TypeRegistry::loadFromPlc(long port, const AmsAddr* addr) {
    types_.clear();
    enum_values_.clear();
    
    // 1. Ler 0xF00F → nTypes, nDtSize
    uint8_t info[32] = {0}; uint32_t br = 0;
    if (AdsSyncReadReqEx2(port, addr, 0xF00F, 0, 32, info, &br) || br < 16)
        return;
    
    uint32_t nTypes, nDtSize;
    memcpy(&nTypes, info + 8, 4);
    memcpy(&nDtSize, info + 12, 4);
    
    if (nDtSize == 0 || nDtSize > 10 * 1024 * 1024) return;
    
    // 2. Ler 0xF00E
    std::vector<uint8_t> buf(nDtSize);
    if (AdsSyncReadReqEx2(port, addr, 0xF00E, 0, nDtSize, buf.data(), &br))
        return;
    
    // 3. Parsear entradas
    const uint8_t* p = buf.data();
    const uint8_t* end = p + br;
    uint32_t parsed = 0;
    
    while (p + 40 <= end && parsed < nTypes) {
        uint32_t entryLen; memcpy(&entryLen, p, 4);
        if (entryLen < 40 || entryLen > (uint32_t)(end - p)) break;
        
        uint32_t flags; memcpy(&flags, p+4, 4);
        uint32_t typeSize; memcpy(&typeSize, p+8, 4);
        uint32_t memberCount; memcpy(&memberCount, p+12, 4);
        
        // Extrair nome entre os bytes 28-80
        std::string typeName = extractAscii(p, 28, std::min(entryLen, (uint32_t)80) - 28);
        if (!typeName.empty()) {
            TypeDef def;
            def.kind = TypeDef::Kind::Alias; // default
            
            if (typeSize > 0 && memberCount == 0) {
                // Tipo base (WORD, DWORD, etc.) ou alias
                def.kind = TypeDef::Kind::Alias;
                def.alias = typeName; // o próprio nome é o alias
            } else if (memberCount > 0) {
                // Struct, Union, ou tipo com campos
                // Verificar se é union (flags especiais)
                def.kind = TypeDef::Kind::Struct;
                
                // Parse subcampos
                size_t afterName = findAfterName(p, entryLen, typeName);
                if (afterName > 0) {
                    parseFieldEntries(p + afterName, entryLen - afterName, def);
                }
            }
            
            // Verificar se tem parenteses → enum
            if (flags & 0x2) { // flag hipotética para enum
                def.kind = TypeDef::Kind::Alias;
                // Extrair valores enum
            }
            
            std::string key = normalizeTypeName(typeName);
            if (types_.find(key) == types_.end()) {
                types_[key] = def;
            }
        }
        
        p += entryLen;
        parsed++;
    }
    
    // Tipos built-in
    injectBuiltinTypes();
}
```

### parseFieldEntries() — parsing de subcampos

```cpp
void TypeRegistry::parseFieldEntries(const uint8_t* data, uint32_t size, TypeDef& def) {
    uint32_t pos = 0;
    
    while (pos + 40 < size) {
        // Encontrar entryLength válido (pular bytes de padding 0x00)
        uint32_t fLen = 0;
        int shift = 0;
        for (int s = 0; s < 4; s++) {
            memcpy(&fLen, data + pos + s, 4);
            if (fLen >= 40 && fLen <= 10000) { shift = s; break; }
        }
        if (shift == 0 && fLen < 40) { pos++; continue; }
        pos += shift;
        
        memcpy(&fLen, data + pos, 4);
        if (fLen < 40 || fLen > size - pos) break;
        
        uint32_t fSize;     memcpy(&fSize, data+pos+8, 4);
        uint32_t byteOffs;  memcpy(&byteOffs, data+pos+12, 4);
        uint32_t bitOffs;   memcpy(&bitOffs, data+pos+16, 4);
        uint16_t nameLen;   memcpy(&nameLen, data+pos+32, 2);
        uint16_t typeLen;   memcpy(&typeLen, data+pos+34, 2);
        uint16_t cmtLen;    memcpy(&cmtLen, data+pos+36, 2);
        
        // Extrair strings (nome, tipo, comentário)
        std::string fName, fType, fComment;
        size_t strOff = 45; // offset aproximado onde as strings começam
        
        if (strOff + nameLen < fLen) {
            fName = std::string((const char*)(data + pos + strOff), nameLen);
        }
        size_t afterName = strOff + nameLen + 1;
        if (afterName + typeLen < fLen) {
            fType = std::string((const char*)(data + pos + afterName), typeLen);
        }
        size_t afterType = afterName + typeLen + 1;
        if (afterType + cmtLen < fLen) {
            fComment = std::string((const char*)(data + pos + afterType), cmtLen);
        }
        
        if (!fName.empty() && !fType.empty()) {
            TypeField field;
            field.name = fName;
            field.type = fix_known_typos(fType);
            field.array_len = 1;
            field.hidden = false;
            field.is_bit = (fType == "BIT");
            def.fields.push_back(field);
        }
        
        pos += fLen;
    }
}
```

### Função auxiliar extractAscii()

```cpp
static std::string extractAscii(const uint8_t* data, size_t offset, size_t maxLen) {
    for (size_t i = offset; i < offset + maxLen && i < offset + 200; ++i) {
        if (data[i] >= 0x20 && data[i] <= 0x7E) {
            auto s = std::string((const char*)(data + i));
            if (s.size() >= 2) return s;
        }
    }
    return {};
}
```

---

## O que REMOVER do tc2_mc2_types.cpp

Remover **TUDO** relacionado a parser de markdown:
- `normalize_nbsp()` — converte &nbsp;
- `parse_array_type()` — para ARRAY[0..5] OF BYTE em markdown
- `fix_known_typos()` — corrige NCTPPLC → NCTOPLC
- `normalize_type_name()` — extrai nome após "TYPE "
- `parse_enum_value()`, `parse_enum_entries()`, `parse_enum_base_type()` — parsers de enum
- `TypeRegistry::loadAll()` — loader recursivo de .md
- `TypeRegistry::parseTypeDefinition()` — parser de TYPE STRUCT
- `TypeRegistry::injectBuiltinTypes()` — exceto ST_AdsAddress
- `TypeDef fallbackPlcToNc()`, `fallbackNcToPlc()`, `fallbackAdsAddress()`

**Estes já foram removidos nas fases anteriores mas verificar se ainda existem.**

---

## O que MANTER

- `namespace bhf`
- `TypeRegistry::findType()`, `sizeOfType()`, `alignmentOfType()`, `resolveAlias()`
- `TypeRegistry::fieldOffset()` — calcula offset percorrendo fields
- `TypeRegistry::normalizeTypeName()` — upper case + fix typos (ainda útil)
- `TypeDef`, `TypeField` structs
- `enumValueToString()` — se enums existirem
- `trim()`, `trim_local()` — utilitários

---

## tc2_mc2_monitor.cpp

```cpp
// ANTES:
void Tc2Mc2Monitor::loadAll(const std::string& root) {
    registry_.loadAll(root);
}

// DEPOIS:
void Tc2Mc2Monitor::loadFromPlc(long port, const AmsAddr* addr) {
    registry_.loadFromPlc(port, addr);
}
```

---

## plc_monitor_window.cpp

```cpp
// ANTES (linha 320):
tc2_mc2_monitor_.loadAll("/home/Administrator/qt-ads/include/BHF_context");

// DEPOIS: após connect() bem-sucedido:
tc2_mc2_monitor_.loadFromPlc(client_.port_, &client_.ams_);
```

---

## Verificação

Após as mudanças:

1. O programa conecta ao PLC
2. Carrega símbolos via `SYM_UPLOAD (0xF00B)` (já funciona)
3. Carrega tipos via `SYM_DT_UPLOAD (0xF00E)` (NOVO)
4. TypeRegistry tem todos os 119 tipos do projeto PLC
5. Qualquer struct como `ST_PNIE_CONTROL_BITS` é expandida na árvore com seus campos (EnableRobot : BIT, MotionAllowed : BIT, ...)
6. Tipos customizados do usuário (`U_PNIE_CONTROL_WORD`, `E_PNIE_COMMAND_CODE`, etc.) aparecem corretamente
7. Sem arquivos .md, sem BHF_context, sem fallbacks hardcoded
