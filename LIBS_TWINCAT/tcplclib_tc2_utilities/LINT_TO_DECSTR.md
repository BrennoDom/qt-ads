# LINT_TO_DECSTR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# LINT\_TO\_DECSTR

![25617672](/tcplclib_tc2_utilities/1033/Images/png/9007199290539275__Web.png)

This function converts a signed decimal number into a decimal string (base 10).

## FUNCTION LINT\_TO\_DECSTR: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in         : LINT;  
    iPrecision : INT;  
END_VAR
```

**in**: The decimal number requiring conversion.

**iPrecision**: Minimum number of displayed digits (digits). If the actual number of significant digits is less than the *iPrecision* parameter, the resulting string is filled with zeros from the left. If the number of significant digits is greater than the *iPrecision* parameter, the resulting string is not cut off! If the *iPrecision* parameter and the *in* parameter are zero, the resulting string is empty. For negative numbers, the negative sign will appear in the resulting string.

**Example:**

```
PROGRAM MAIN  
VAR  
    s1   : STRING;  
    s2   : STRING;  
    s3   : STRING;  
    s4   : STRING;  
    iCnt : LINT;  
END_VAR
```

```
iCnt := -1234;  
s1   := LINT_TO_DECSTR( iCnt, 1 );  
s2   := LINT_TO_DECSTR( iCnt, 10 );  
iCnt := 0;  
s3   := LINT_TO_DECSTR( iCnt, 0 );  
iCnt := 1234;  
s4   := LINT_TO_DECSTR( iCnt, 10 );
```

The result:

s1 = '-1234

s2 = '-0000001234'

s3 = ''

s4 = '0000001234'

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
