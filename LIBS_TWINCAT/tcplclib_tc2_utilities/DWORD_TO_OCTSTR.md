# DWORD_TO_OCTSTR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# DWORD\_TO\_OCTSTR

![60972066](/tcplclib_tc2_utilities/1033/Images/gif/35763083__en-US__Web.gif)

This function converts a decimal number into an octal string (base 8).

## FUNCTION DWORD\_TO\_OCTSTR: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in         : DWORD;  
    iPrecision : INT;  
END_VAR
```

**in**: The decimal number requiring conversion.

**iPrecision**: Minimum number of displayed digits (digits). If the actual number of significant digits is less than the *iPrecision* parameter, the resulting string is filled with zeros from the left. If the number of significant digits is greater than the *iPrecision* parameter, the resulting string is not cut off! If the *iPrecision* parameter and the *in* parameter are zero, the resulting string is empty.

**Example:**

```
PROGRAM MAIN  
VAR  
    s1   : STRING;  
    s2   : STRING;  
    s3   : STRING;  
    nCnt : WORD;  
END_VAR
```

```
nCnt := 43981;  
s1   := DWORD_TO_OCTSTR( nCnt, 1 );  
s2   := DWORD_TO_OCTSTR( nCnt, 10 );  
nCnt := 0;  
s3   := DWORD_TO_OCTSTR( nCnt, 0 );
```

The result:

s1 = '125715'

s2 = '0000125715'

s3 = ''

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
