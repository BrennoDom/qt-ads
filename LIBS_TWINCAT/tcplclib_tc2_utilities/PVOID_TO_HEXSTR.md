# PVOID_TO_HEXSTR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# PVOID\_TO\_HEXSTR

![29415884](/tcplclib_tc2_utilities/1033/Images/png/9007199290526475__Web.png)

The function converts the value of a pointer variable of type PVOID into a hexadecimal string (basis 16).

## FUNCTION PVOID\_TO\_HEXSTR: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in          : PVOID;  
    iPrecision  : INT;  
    bLoCase     : BOOL;  
END_VAR
```

**in**: The pointer variable to be converted.

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
    s5   : STRING;  
    s6   : STRING;  
    s7   : STRING;  
    s8   : STRING;  
    s9   : STRING;  
    s10  : STRING;  
    s11  : STRING;  
    s12  : STRING;  
    nCnt : WORD;  
    pCnt : PVOID := 0;  
END_VAR
```

```
pCnt := 0;  
s1   := PVOID_TO_HEXSTR( pCnt, 0, FALSE );  
s2   := PVOID_TO_HEXSTR( pCnt, 0, TRUE );  
  
s3   := PVOID_TO_HEXSTR( pCnt, 1, FALSE );  
s4   := PVOID_TO_HEXSTR( pCnt, 1, TRUE );  
  
s5   := PVOID_TO_HEXSTR( pCnt, 16, FALSE );  
s6   := PVOID_TO_HEXSTR( pCnt, 16, TRUE );  
  
pCnt := ADR( nCnt );  
s7   := PVOID_TO_HEXSTR( pCnt, 0, FALSE );  
s8   := PVOID_TO_HEXSTR( pCnt, 0, TRUE );  
  
s9   := PVOID_TO_HEXSTR( pCnt, 1, FALSE );  
s10  := PVOID_TO_HEXSTR( pCnt, 1, TRUE );  
  
s11  := PVOID_TO_HEXSTR( pCnt, 16, FALSE );  
s12  := PVOID_TO_HEXSTR( pCnt, 16, TRUE );
```

The result:

s1 = ''

s2 = ''

s3 = '0'

s4 = '0'

s5 = '0000000000000000'

s6 = '0000000000000000'

s7 = '87CBC255' (may vary)

s8 = '87cbc255' (may vary)

s9 = '87CBC255' (may vary)

s10 = '87cbc255' (may vary)

s11 = '0000000087CBC255' (may vary)

s12 = '0000000087cbc255' (may vary)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
