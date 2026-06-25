# Fase 2 + 3 — Constructor Beckhoff Universal

## Objetivo

Modificar o código C++ do qt-ads para que o `TypeRegistry` carregue **todas as 85 bibliotecas** do `include/BHF_context/` recursivamente, eliminando todos os fallbacks hardcoded e usando os dados reais dos tipos.

---

## Arquivos que mudam

| Arquivo | Mudança |
|---------|---------|
| `tc2_mc2_types.h` | Renomear namespace para `bhf`, adicionar `loadAll()`, remover fallbacks |
| `tc2_mc2_types.cpp` | `loadAll()` recursivo, remover ~200 linhas hardcoded, parser aceitar VAR_INPUT/VAR_OUTPUT |
| `tc2_mc2_monitor.h` | Apenas rename de namespace |
| `tc2_mc2_monitor.cpp` | Substituir `fallbackPlcToNc()` por `findType("PLCTONC_AXIS_REF")`, etc. |
| `plc_monitor_window.cpp` | Trocar caminho de `LIBS_TWINCAT/...` para `include/BHF_context` |

Arquivos que **NÃO** mudam:
- `plc_client.cpp/.h` — comunicação ADS pura, não usa TypeRegistry
- `standard_types.cpp/.h` — validação de entrada, não usa TypeRegistry
- `CMakeLists.txt` — sem novas dependências

---

## 1. tc2_mc2_types.h — interface

```cpp
// ANTES:
namespace tc2_mc2 {
class TypeRegistry {
public:
    void load(const std::string& root);       // diretório único
    const TypeDef* findType(const std::string& name) const;
    std::string normalizeTypeName(const std::string& name) const;
    std::string resolveAlias(const std::string& name) const;
    size_t sizeOfType(const std::string& name) const;
    size_t alignmentOfType(const std::string& name) const;
    bool enumValueToString(const std::string& type, long long value, std::string& out) const;

    TypeDef fallbackPlcToNc() const;           // ← REMOVER
    TypeDef fallbackNcToPlc() const;           // ← REMOVER
    TypeDef fallbackAdsAddress() const;        // ← REMOVER
};
}

// DEPOIS:
namespace bhf {
class TypeRegistry {
public:
    void loadAll(const std::string& root);    // recursivo: escaneia árvore
    const TypeDef* findType(const std::string& name) const;
    std::string normalizeTypeName(const std::string& name) const;
    std::string resolveAlias(const std::string& name) const;
    size_t sizeOfType(const std::string& name) const;
    size_t alignmentOfType(const std::string& name) const;
    bool enumValueToString(const std::string& type, long long value, std::string& out) const;
    size_t fieldOffset(const std::string& typeName, const std::string& fieldName) const;  // NOVO
};
}
```

**Mudanças:**
- `load(dir)` → `loadAll(root)` — escaneia recursivamente
- Remove `fallbackPlcToNc()`, `fallbackNcToPlc()`, `fallbackAdsAddress()`
- Adiciona `fieldOffset(typeName, fieldName)` — calcula offset de um campo dentro de um STRUCT
- Namespace `tc2_mc2` → `bhf` (mais genérico, já que agora cobre qualquer lib Beckhoff)

---

## 2. tc2_mc2_types.cpp — parser

### 2.1 loadAll() recursivo

Substituir o `load_dir` atual (que só lê um diretório + "overrides") por:

```cpp
void TypeRegistry::loadAll(const std::string& root)
{
    types_.clear();
    enum_values_.clear();

    const std::filesystem::path root_path(root);
    if (!std::filesystem::exists(root_path)) return;

    // Escaneia recursivamente TODOS os .md em qualquer subdiretório
    for (const auto& entry : std::filesystem::recursive_directory_iterator(root_path)) {
        if (!entry.is_regular_file()) continue;
        if (entry.path().extension() != ".md") continue;
        
        std::ifstream in(entry.path());
        if (!in) continue;
        std::stringstream buffer;
        buffer << in.rdbuf();
        
        parseTypeDefinition(normalize_nbsp(buffer.str()));
    }

    // Tipos built-in que não existem nos .md (são da arquitetura TwinCAT,
    // não de uma biblioteca PLC específica)
    injectBuiltinTypes();
}
```

### 2.2 Extrair parseTypeDefinition() do loop

O parser atual está dentro de uma lambda no `load()`. Extrair para método separado:

```cpp
void TypeRegistry::parseTypeDefinition(const std::string& content)
{
    auto type_pos = content.find("TYPE ");
    if (type_pos == std::string::npos) return;
    auto type_end = content.find('\n', type_pos);
    if (type_end == std::string::npos) return;
    std::string type_name = normalize_type_name(content.substr(type_pos + 5, type_end - (type_pos + 5)));
    type_name = normalizeTypeName(type_name);

    TypeDef def{};
    // Aceitar STRUCT, VAR_INPUT, VAR_OUTPUT como struct
    if (content.find("STRUCT", type_end) != std::string::npos ||
        content.find("VAR_INPUT", type_end) != std::string::npos) {
        def.kind = TypeDef::Kind::Struct;
    } else if (content.find("UNION", type_end) != std::string::npos) {
        def.kind = TypeDef::Kind::Union;
    } else {
        def.kind = TypeDef::Kind::Alias;
    }

    // ... resto do parser existente (field parsing loop)
    // MAS adicionar VAR_INPUT e VAR_OUTPUT como STRUCT-equivalent no loop:
    // if (line.find("STRUCT") ... || line.find("VAR_INPUT") ... || line.find("VAR_OUTPUT") ...)
}
```

### 2.3 PATCH no loop de parse de fields

No loop que varre as linhas (linha 438), adicionar:

```cpp
// ANTES:
if (line.find("STRUCT") != std::string::npos || line.find("UNION") != std::string::npos) {
    in_struct = true;
    continue;
}

// DEPOIS:
if (line.find("STRUCT") != std::string::npos || line.find("UNION") != std::string::npos ||
    line.find("VAR_INPUT") != std::string::npos || line.find("VAR_OUTPUT") != std::string::npos) {
    in_struct = true;
    continue;
}
```

Isso faz o parser entender `AXIS_REF` que usa `VAR_INPUT`/`VAR_OUTPUT` em vez de `STRUCT`.

### 2.4 Remover ~200 linhas de fallbacks

Remover **TUDO** deste bloco em `load()` (linhas 489-600+):

```cpp
// REMOVER:
const auto st_ads_key = normalizeTypeName("ST_AdsAddress");
if (types_.find(st_ads_key) == types_.end()) {
    types_[st_ads_key] = fallbackAdsAddress();   // ← REMOVER
}
// ... TUDO até o final dos enums e types hardcoded
```

Isso inclui:
- `fallbackPlcToNc()` definição completa (~30 linhas)
- `fallbackNcToPlc()` definição completa (~50 linhas)
- `fallbackAdsAddress()` definição completa (~10 linhas)
- Bloco `ST_AdsAddress` inline (~4 linhas)
- Bloco `T_AmsNetId` inline (~8 linhas)
- Bloco `T_AmsNetIdArr` inline (~8 linhas)
- Bloco `T_AmsPort` inline (~8 linhas)
- Bloco `MC_AxisStates` enum inline (~20 linhas)
- Bloco `NCTOPLC_AXIS_REF_CAMCOUPLINGSTATE` inline (~15 linhas)
- Bloco `NCTOPLC_AXIS_REF_STATE2_FLAGS` inline (~15 linhas)
- Bloco `NCTOPLC_AXIS_REF_STATE2` inline (~8 linhas)
- Loop de duplicação uppercase (~15 linhas)

Total: **~200 linhas eliminadas**.

### 2.5 injectBuiltinTypes()

Tipos que são da arquitetura TwinCAT mas não existem como .md em nenhuma biblioteca:

```cpp
void TypeRegistry::injectBuiltinTypes()
{
    const auto st_ads_key = normalizeTypeName("ST_AdsAddress");
    if (types_.find(st_ads_key) == types_.end()) {
        TypeDef def;
        def.kind = TypeDef::Kind::Struct;
        def.fields = {
            {"NetId", "T_AmsNetId", 1, false, false},
            {"Port", "UINT", 1, false, false},
            {"Channel", "UINT", 1, false, false},
        };
        types_[st_ads_key] = def;
    }
}
```

Apenas `ST_AdsAddress` precisa ser built-in. Todos os outros tipos (`T_AmsNetId`, `T_AmsPort`, `T_AmsNetIdArr`, `MC_AxisStates`, `NCTOPLC_AXIS_REF_STATE2`, etc.) agora vêm dos .md gerados nas bibliotecas:
- `tcplclib_tc2_system/T_AmsNetId.md`
- `tcplclib_tc2_system/T_AmsPort.md`
- `tcplclib_tc2_system/T_AmsNetIdArr.md`
- `tcplclib_tc2_mc2/MC_AxisStates.md`
- `tcplclib_tc2_mc2/NCTOPLC_AXIS_REF_STATE2.md`
- etc.

### 2.6 fieldOffset() — novo método

```cpp
size_t TypeRegistry::fieldOffset(const std::string& typeName, const std::string& fieldName) const
{
    const auto* def = findType(typeName);
    if (!def || def->kind != TypeDef::Kind::Struct) return (size_t)-1;

    size_t offset = 0;
    size_t bit_count = 0;
    for (const auto& f : def->fields) {
        const bool is_bit = (resolveAlias(f.type) == "BIT") || f.is_bit;
        if (is_bit) {
            if (f.name == fieldName) return offset + (bit_count / 8);
            bit_count += f.array_len;
            if (bit_count >= 8) { offset += bit_count / 8; bit_count = 0; }
            continue;
        }
        if (bit_count > 0) { offset += (bit_count + 7) / 8; bit_count = 0; }
        const size_t align = alignmentOfType(f.type);
        if (align > 1) offset = (offset + align - 1) / align * align;
        if (f.name == fieldName) return offset;
        offset += sizeOfType(f.type) * f.array_len;
    }
    return (size_t)-1;
}
```

---

## 3. tc2_mc2_monitor.cpp — substituir fallbacks

O código atual em `addChildrenForSymbol()` usa fallbacks quando `findType()` retorna nullptr:

```cpp
// ANTES (tc2_mc2_monitor.cpp:572-581):
if (plc_def) {
    // usa plc_def...
} else {
    const auto fallback = registry_.fallbackPlcToNc();  // ← REMOVER
    // usa fallback...
}
```

**Nova lógica:** Se `findType("PLCTONC_AXIS_REF")` retornar null, o tipo não existe — não usar fallback. O código fica mais simples:

```cpp
// DEPOIS:
if (plc_def && plc_to_nc->childCount() == 0) {
    const size_t pack = pick_pack_for_struct(registry_, *plc_def, plc_source_size);
    addStructChildren(plc_to_nc, plc_has_symbol ? 0 : plc_base, plc_source,
                      plc_source_size, *plc_def,
                      true, std::string(), pack);
}
// Sem else — se não achar o tipo, não expande (a célula mostra o raw)
```

Aplicar o mesmo padrão para:
- `NCTOPLC_AXIS_REF` (fallbackNcToPlc)
- `ST_AdsAddress` (fallbackAdsAddress)

**Nota:** Como agora `ST_AdsAddress` é injetado como built-in, `findType("ST_AdsAddress")` sempre vai achar, então o fallback nunca será chamado de qualquer forma.

---

## 4. plc_monitor_window.cpp — trocar caminho

```cpp
// ANTES (linha 320):
tc2_mc2_monitor_.load("/home/Administrator/ADS/example/qt_gui/LIBS_TWINCAT/tcplclib_tc2_mc2");

// DEPOIS:
tc2_mc2_monitor_.loadAll("/home/Administrator/qt-ads/include/BHF_context");
```

E também atualizar o header em `plc_monitor_window.h`:

```cpp
// ANTES:
#include "tc2_mc2_monitor.h"   // namespace tc2_mc2

// DEPOIS:
#include "tc2_mc2_monitor.h"   // namespace bhf
```

---

## 5. Atualizações de namespace

Arquivos que referenciam `tc2_mc2::`:

| Arquivo | Ocorrências | Mudança |
|---------|-------------|---------|
| `tc2_mc2_monitor.h` | `class Tc2Mc2Monitor` | Manter nome da classe, mudar namespace `tc2_mc2` → `bhf` |
| `tc2_mc2_monitor.cpp` | `using namespace tc2_mc2` | Mudar para `bhf` |
| `tc2_mc2_types.h` | `namespace tc2_mc2` | Mudar para `bhf` |
| `tc2_mc2_types.cpp` | `namespace tc2_mc2` | Mudar para `bhf` |
| `plc_monitor_window.h` | `Tc2Mc2Monitor tc2_mc2_monitor_` | Manter (classe não muda de nome) |
| `plc_monitor_window.cpp` | `tc2_mc2_monitor_.load(...)` | Mudar para `loadAll(...)` |

---

## 6. Resumo das linhas alteradas

| Arquivo | Inserções | Remoções |
|---------|-----------|----------|
| `tc2_mc2_types.h` | ~5 | ~6 |
| `tc2_mc2_types.cpp` | ~40 | ~200 |
| `tc2_mc2_monitor.h` | ~1 | ~1 |
| `tc2_mc2_monitor.cpp` | ~6 | ~15 |
| `plc_monitor_window.cpp` | ~1 | ~1 |
| `plc_monitor_window.h` | ~1 | ~1 |
| **Total** | **~54** | **~224** |

---

## 7. Verificação

Após as mudanças, o fluxo deve funcionar assim:

```
plc_monitor_window.cpp:
  tc2_mc2_monitor_.loadAll("include/BHF_context");
    └── TypeRegistry::loadAll()
         ├── recursive_directory_iterator → 5584 .md files
         ├── find("TYPE ") → parse → types_[]
         ├── todos os 1530 tipos carregados
         └── injectBuiltinTypes() → ST_AdsAddress

Quando o PLC devolve type="AXIS_REF":
  registry_.findType("AXIS_REF")
    → TypeDef {kind=Struct, fields=[PlcToNc, NcToPlc, ADS, Status, DriveAddress]}
    → resolve cada campo recursivamente

Quando o PLC devolve type="UDINT":
  registry_.sizeOfType("UDINT") → 4 (via baseTypeSize)
  Sem precisar de STRUCT
```

Nenhum `if(type == "AXIS_REF")` ou fallback hardcoded permanece.
