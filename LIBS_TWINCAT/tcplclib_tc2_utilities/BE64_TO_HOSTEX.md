# BE64_TO_HOSTEX

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# BE64\_TO\_HOSTEX

![57582125](/tcplclib_tc2_utilities/1033/Images/png/9007200300519947__Web.png)

The function performs a network-to-host conversion of a 64-bit number (“native” type: LWORD). See also under: [Byte Order](ms-xhelp:///?Id=beckhoff-1928-452a-9ff0-7363825f50c0).

## FUNCTION BE64\_TO\_HOSTEX: LWORD

## VAR\_INPUT

```
VAR_INPUT  
    in : LWORD;  
END_VAR
```

**in**: Number to be converted.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
