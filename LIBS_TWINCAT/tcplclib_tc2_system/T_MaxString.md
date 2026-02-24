# T_MaxString

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. T\_MaxString

# T\_MaxString

The variable of this type is PLC string with the maximal length. Longer strings are allowed, but the string functions are limited to 255 characters.

```
TYPE T_MaxString : STRING(MAX_STRING_LENGTH);  
END_TYPE
```

```
VAR_GLOBAL CONSTANT  
    MAX_STRING_LENGTH : UDINT := 255;  
ENd_VAR
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
