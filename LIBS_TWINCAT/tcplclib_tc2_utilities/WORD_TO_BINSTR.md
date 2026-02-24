# WORD_TO_BINSTR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# WORD\_TO\_BINSTR

![58281439](/tcplclib_tc2_utilities/1033/Images/png/9007200188752523__Web.png)

This function converts a decimal number into a binary string (base 2).

## FUNCTION WORD\_TO\_BINSTR: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in         : WORD;  
    iPrecision : INT;  
END_VAR
```

**in**: The decimal number requiring conversion.

**iPrecision**: Minimum number of displayed digits (digits). If the actual number of significant digits is less than the *iPrecision* parameter, the resulting string is filled with zeros from the left. If the number of significant digits is greater than the *iPrecision* parameter, the resulting string is not cut off! If the *iPrecision* parameter and the *in* parameter are zero, the resulting string is empty.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
