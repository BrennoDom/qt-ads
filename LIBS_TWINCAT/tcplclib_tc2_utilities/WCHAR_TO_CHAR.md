# WCHAR_TO_CHAR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# WCHAR\_TO\_CHAR

![49289224](/tcplclib_tc2_utilities/1033/Images/png/3515026827__Web.png)

The function converts a variable of the data type WSTRING into a variable of the data type STRING (with null termination). The conversion is possible only if the WSTRING character corresponds to the STRING character. Otherwise no character is returned.

## FUNCTION WCHAR\_TO\_CHAR : STRING(1)

## VAR\_INPUT

```
VAR_INPUT  
    sTextIn : WSTRING(1);  
END_VAR
```

**sTextIn:** WSTRING variable to be converted.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
