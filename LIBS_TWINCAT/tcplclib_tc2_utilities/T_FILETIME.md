# T_FILETIME

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# T\_FILETIME

Variables of this type are 64-bit numbers. The value corresponds to the number of 100-nanosecond intervals since 1 January 1601 (UTC).

```
TYPE T_FILETIME :  
STRUCT  
    dwLowDateTime  : DWORD;  
    dwHighDateTime : DWORD;  
END_STRUCT  
END_TYPE
```

**dwLowDateTime**: Lower 32 bits.

**dwHighDateTime**: Upper 32 bits.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
