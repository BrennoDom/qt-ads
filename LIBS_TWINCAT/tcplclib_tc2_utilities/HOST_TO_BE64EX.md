# HOST_TO_BE64EX

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# HOST\_TO\_BE64EX

![66450672](/tcplclib_tc2_utilities/1033/Images/png/9007200300554635__Web.png)

The function performs a host-to-network conversion of a 64-bit number (“native” type: LWORD). See also under: [Byte Order](ms-xhelp:///?Id=beckhoff-1928-452a-9ff0-7363825f50c0).

## FUNCTION HOST\_TO\_BE64EX: LWORD

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
