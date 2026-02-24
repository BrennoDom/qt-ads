# WORD_TO_OCTSTR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# WORD\_TO\_OCTSTR

![65325544](/tcplclib_tc2_utilities/1033/Images/png/9007200188777611__Web.png)

This function converts a decimal number into an octal string (base 8).

## FUNCTION WORD\_TO\_OCTSTR: T\_MaxString

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
