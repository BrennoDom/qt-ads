# MAXSTRING_TO_BYTEARR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# MAXSTRING\_TO\_BYTEARR

![28761840](/tcplclib_tc2_utilities/1033/Images/gif/35881483__en-US__Web.gif)

Converts a string into individual ASCII codes of a byte array.

## FUNCTION MAXSTRING\_TO\_BYTEARR: ARRAY[0..MAX\_STRING\_LENGTH] OF BYTE

## VAR\_INPUT

```
VAR_INPUT  
    in : T_MaxString;  
END_VAR
```

**in**: String to be converted (type: T\_MaxString).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
