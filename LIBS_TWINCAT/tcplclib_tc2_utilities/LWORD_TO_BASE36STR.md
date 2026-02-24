# LWORD_TO_BASE36STR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# LWORD\_TO\_BASE36STR

This function converts a decimal number into a Base36 string (base 16). For numbers with base 16, the letters A-Z are used in addition to the digits 0-9.

## FUNCTION LWORD\_TO\_BASE36STR : T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in          : LWORD;  
    iPrecision  : INT;  
    bLoCase     : BOOL;  
END_VAR
```

**in**: The decimal number to be converted.

**iPrecision**: Minimum number of displayed digits. If the actual number of significant digits is less than the *iPrecision* parameter, the resulting string is filled with zeros from the left. If the number of significant digits is greater than the *iPrecision* parameter, the resulting string is not cut off! If the *iPrecision* parameter and the *in* parameter are zero, the resulting string is empty.

**bLoCase**: This parameter determines whether lower or upper case letters are used in the conversion. FALSE => "ABCDEFXY", TRUE => "abcdefxy".

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
s1   := LWORD_TO_BASE36STR( nCnt, 1, FALSE );  
s2   := LWORD_TO_BASE36STR( nCnt, 1, TRUE );  
nCnt := 15;  
s3   := LWORD_TO_BASE36STR( nCnt, 4, FALSE );  
nCnt := 0;  
s4   := LWORD_TO_BASE36STR( nCnt, 0, FALSE );
```

The result:

s1 = 'XXP'

s2 = 'xxp'

s3 = '000F'

s4 = ''

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.47.0 |
