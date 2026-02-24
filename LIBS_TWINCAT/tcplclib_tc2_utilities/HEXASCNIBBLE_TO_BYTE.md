# HEXASCNIBBLE_TO_BYTE

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# HEXASCNIBBLE\_TO\_BYTE

![30576743](/tcplclib_tc2_utilities/1033/Images/png/9007200188546315__Web.png)

This function converts the ASCII code of a hexadecimal half-byte character into the decimal value.

## FUNCTION HEXASCNIBBLE\_TO\_BYTE: BYTE

## VAR\_INPUT

```
VAR_INPUT  
    asc : BYTE;  
END_VAR
```

**asc**: Ascii-code of a hexadecimal half-byte character (Ascii code from: ‘0’ to ‘9’ or ‘a’ to ‘f’ or ‘A’ to ‘F’).

| Return value | Meaning |
| --- | --- |
| 0 to 15 | Successful, no error. |
| 255 | Error, wrong input parameter value. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
