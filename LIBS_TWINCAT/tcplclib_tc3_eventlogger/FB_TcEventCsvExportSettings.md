# FB_TcEventCsvExportSettings

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# FB\_TcEventCsvExportSettings

![13119252](/tcplclib_tc3_eventlogger/1033/Images/png/10363700619__Web.png)

Provides the functionality to specify the csv export.

## Syntax

Definition:

```
FUNCTION_BLOCK FB_TcEventCsvExportSettings EXTENDS FB_TcEventExportSettings IMPLEMENTS I_TcEventCsvExportSettings
```

## 50964406 Methods

| Name | Type | Description |
| --- | --- | --- |
| bWithHeader | BOOL | Determines whether a header should be created. Standard: True |
| nLangId | DINT | Determines the default identifier of the export language. Standard: 1033 |
| sDelimiter | STRING | Defines the CSV delimiter. Standard: Semicolon [;] |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.17 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger (>= v3.1.27.0) |
