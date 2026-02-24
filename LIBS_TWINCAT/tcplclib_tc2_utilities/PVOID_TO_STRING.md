# PVOID_TO_STRING

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# PVOID\_TO\_STRING

![33876408](/tcplclib_tc2_utilities/1033/Images/png/9007199290532875__Web.png)

The function converts the value of a pointer variable of type PVOID into a hexadecimal string (basis 16). The hexadecimal string has the PLC prefix: '16#'. The resolution is fixed at 8 digits in a 32-bit system and 16 digits in 64-bit system.

## FUNCTION PVOID\_TO\_STRING: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    in : PVOID;  
END_VAR
```

**in**: The pointer variable to be converted.

**Example:**

```
PROGRAM MAIN  
VAR  
    s1   : STRING;  
    s2   : STRING;  
    nCnt : BYTE;  
    p1   : POINTER TO BYTE := 0;  
    p2   : POINTER TO BYTE := ADR( nCnt );  
END_VAR
```

```
s1 := PVOID_TO_STRING( p1 );  
s2 := PVOID_TO_STRING( p2 );
```

The result on a 32-bit system:

s1 = '16#00000000'

s2 = ''16#87DE0255' (may vary)

The result on a 64-bit system:

s1 = '16#0000000000000000'

s2 = ''16#8734651087DE0255' (may vary)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
