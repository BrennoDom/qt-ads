# LWORD_TO_HEXSTR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# LWORD\_TO\_HEXSTR

![64149930](/tcplclib_tc2_utilities/1033/Images/png/9007199290513675__Web.png)

This function converts a decimal number into a hexadecimal string (base 16).

## FUNCTION LWORD\_TO\_HEXSTR: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in          : LWORD;  
    iPrecision  : INT;  
    bLoCase     : BOOL;  
END_VAR
```

**in**: The decimal number requiring conversion.

**iPrecision**: Minimum number of displayed digits (digits). If the actual number of significant digits is less than the *iPrecision* parameter, the resulting string is filled with zeros from the left. If the number of significant digits is greater than the *iPrecision* parameter, the resulting string is not cut off! If the *iPrecision* parameter and the *in* parameter are zero, the resulting string is empty.

**bLoCase**: This parameter determines whether lower or upper case letters are used in the conversion. FALSE => "ABCDEF", TRUE => "abcdef".

**Example:**

```
PROGRAM MAIN  
VAR  
    s1   : STRING;  
    s2   : STRING;  
    s3   : STRING;  
    s4   : STRING;  
    nCnt : LWORD;  
END_VAR
```

```
nCnt := 43981;  
s1   := LWORD_TO_HEXSTR( nCnt, 1, FALSE );  
s2   := LWORD_TO_HEXSTR( nCnt, 1, TRUE );  
nCnt := 15;  
s3   := LWORD_TO_HEXSTR( nCnt, 4, FALSE );  
nCnt := 0;  
s4   := LWORD_TO_HEXSTR( nCnt, 0, FALSE );
```

The result:

s1 = 'ABCD'

s2 = 'abcd'

s3 = '000F'

s4 = ''

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
