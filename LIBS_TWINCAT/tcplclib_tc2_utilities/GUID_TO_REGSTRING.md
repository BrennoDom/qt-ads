# GUID_TO_REGSTRING

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# GUID\_TO\_REGSTRING

![12837735](/tcplclib_tc2_utilities/1033/Images/png/9007200188538123__Web.png)

This function converts a structured [GUID](ms-xhelp:///?Id=beckhoff-7f71-4e6d-8084-282179f8e0ac) variable into a registry GUID string variable (enclosed in curly brackets).

## FUNCTION GUID\_TO\_REGSTRING: STRING(38)

## VAR\_INPUT

```
VAR_INPUT  
    in : GUID;  
END_VAR
```

| Return value | Meaning |
| --- | --- |
| '{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}' | No error (‘x’ is a hexadecimal half-byte) |
| '{00000000-0000-0000-0000-000000000000}' | No error, GUID has the initial value (all bytes are zero) |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
