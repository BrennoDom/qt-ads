# BYTEARR_TO_MAXSTRING

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# BYTEARR\_TO\_MAXSTRING

![52179558](/tcplclib_tc2_utilities/1033/Images/gif/35724683__en-US__Web.gif)

Converts the individual ASCII codes of a byte array into a string.

## FUNCTION BYTEARR\_TO\_MAXSTRING: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in : ARRAY[0..MAX_STRING_LENGTH] OF BYTE;  
END_VAR
```

**in**: Byte-Array variable ( MAX\_STRING\_LENGTH default value: 255).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
