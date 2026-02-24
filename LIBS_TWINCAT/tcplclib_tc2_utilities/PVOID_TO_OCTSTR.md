# PVOID_TO_OCTSTR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# PVOID\_TO\_OCTSTR

![63416368](/tcplclib_tc2_utilities/1033/Images/png/9007199290529675__Web.png)   
 The function converts the value of a pointer variable of type PVOID into an octal string (basis 8).

## FUNCTION PVOID\_TO\_OCTSTR: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in         : PVOID;  
    iPrecision : INT;  
END_VAR
```

**in**: The pointer variable to be converted.

**iPrecision**: Minimum number of displayed digits (digits). If the actual number of significant digits is less than the *iPrecision* parameter, the resulting string is filled with zeros from the left. If the number of significant digits is greater than the *iPrecision* parameter, the resulting string is not cut off! If the *iPrecision* parameter and the *in* parameter are zero, the resulting string is empty.

**Example:**

```
PROGRAM MAIN  
VAR  
    s1   : STRING;  
    s2   : STRING;  
    s3   : STRING;  
    s4   : STRING;  
    s5   : STRING;  
    s6   : STRING;  
    nCnt : WORD;  
    pCnt : PVOID := 0;  
END_VAR
```

```
pCnt := 0;  
s1   := PVOID_TO_OCTSTR( pCnt, 0 );  
s2   := PVOID_TO_OCTSTR( pCnt, 1 );  
s3   := PVOID_TO_OCTSTR( pCnt, 16 );  
  
pCnt := ADR( nCnt );  
s4   := PVOID_TO_OCTSTR( pCnt, 0 );  
s5   := PVOID_TO_OCTSTR( pCnt, 1 );  
s6   := PVOID_TO_OCTSTR( pCnt, 16 );
```

The result:

s1 = ''

s2 = '0'

s3 = '0000000000000000'

s4 = '20767501125' (may vary)

s5 = '20767501125' (may vary)

s6 = '0000020767501125' (may vary)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
