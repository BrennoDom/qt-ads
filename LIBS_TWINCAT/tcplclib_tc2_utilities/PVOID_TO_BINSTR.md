# PVOID_TO_BINSTR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# PVOID\_TO\_BINSTR

![57529969](/tcplclib_tc2_utilities/1033/Images/png/9007199290520075__Web.png)

The function converts the value of a pointer variable of type PVOID into a binary string (basis 2).

## FUNCTION PVOID\_TO\_BINSTR: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in          : PVOID;  
    iPrecision  : INT;  
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
    nCnt : BYTE;  
    pCnt : PVOID := 0;  
END_VAR
```

```
pCnt := 0;  
s1   := PVOID_TO_BINSTR( pCnt, 0 );  
s2   := PVOID_TO_BINSTR( pCnt, 1 );  
s3   := PVOID_TO_BINSTR( pCnt, 32 );  
  
pCnt := ADR( nCnt );  
s4   := PVOID_TO_BINSTR( pCnt, 0 );  
s5   := PVOID_TO_BINSTR( pCnt, 1 );  
s6   := PVOID_TO_BINSTR( pCnt, 32 );
```

The result:

s1 = ''

s2 = '0'

s3 = '00000000000000000000000000000000'

s4 = '10000111110111100000001001010101' (may vary)

s5 = '10000111110111100000001001010101' (may vary)

s6 = '10000111110111100000001001010101' (may vary)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
