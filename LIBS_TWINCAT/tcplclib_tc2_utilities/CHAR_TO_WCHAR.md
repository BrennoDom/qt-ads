# CHAR_TO_WCHAR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# CHAR\_TO\_WCHAR

![41937705](/tcplclib_tc2_utilities/1033/Images/png/3515007627__Web.png)

The function converts a variable of the data type STRING into a variable of the data type WSTRING (with null termination).

## FUNCTION CHAR\_TO\_WCHAR : WSTRING(1)

## VAR\_INPUT

```
VAR_INPUT  
    sTextIn : STRING(1);  
END_VAR
```

**sTextIn:** STRING variable to be converted.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
