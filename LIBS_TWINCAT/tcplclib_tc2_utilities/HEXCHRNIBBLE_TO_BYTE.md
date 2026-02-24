# HEXCHRNIBBLE_TO_BYTE

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# HEXCHRNIBBLE\_TO\_BYTE

![6755232](/tcplclib_tc2_utilities/1033/Images/png/9007200188563211__Web.png)

This function converts a hexadecimal half-byte character into its decimal value.

## FUNCTION HEXCHRNIBBLE\_TO\_BYTE: BYTE

## VAR\_INPUT

```
VAR_INPUT  
    chr : STRING(1);  
END_VAR
```

**chr**: Hexadecimal half-byte character (‘0’ to ‘9’ or ‘a’ to ‘f’ or ‘A’ to ‘F’).

| Return value | Meaning |
| --- | --- |
| 0 to 15 | Successful, no error. |
| 255 | Error, wrong input parameter value. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
