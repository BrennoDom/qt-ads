# E_SBCSType

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_SBCSType

Windows SBCS (Single Byte Character Set) code page types.

```
TYPE E_SBCSType :  
(  
    eSBCS_WesternEuropean := 1,  
    eSBCS_CentralEuropean := 2  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| eSBCS\_WesternEuropean | Windows 1252 (default) code page |
| eSBCS\_CentralEuropean | Windows 1251 code page |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
