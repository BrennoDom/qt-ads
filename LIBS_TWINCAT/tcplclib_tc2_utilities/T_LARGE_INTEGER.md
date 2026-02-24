# T_LARGE_INTEGER

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# T\_LARGE\_INTEGER

Variables of this type represent a TwinCAT 2 signed 64-bit number (“legacy” type).

```
TYPE T_LARGE_INTEGER :  
STRUCT  
    dwLowPart  : DWORD;  
    dwHighPart : DWORD;  
END_STRUCT  
END_TYP
```

**dwLowPart**: Lower 32 bits.

**dwHighPart**: Upper 32 bits.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
