# STRING_TO_PVOID

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# STRING\_TO\_PVOID

![17440495](/tcplclib_tc2_utilities/1033/Images/png/9007199290536075__Web.png)

The function converts a string variable into a pointer variable of type PVOID. The function returns zero if the input string contains incorrect characters and cannot be interpreted as an address.

## FUNCTION STRING\_TO\_PVOID: PVOID

## VAR\_INPUT

```
VAR_INPUT  
    in  : STRING;  
END_VAR
```

**in**: String variable to be converted.

**Example:**

```
PROGRAM MAIN  
VAR  
    sP1 : STRING := '16#89345678';  
    sP2 : STRING := '8#21115053170';  
    sP3 : STRING := '2#10001001001101000101011001111000';  
    sP4 : STRING := '2301908600';  
    sP5 : STRING := '';  
    pP1 : PVOID := 0;  
    pP2 : PVOID := 0;  
    pP3 : PVOID := 0;  
    pP4 : PVOID := 0;  
    pP5 : PVOID := 0;  
END_VAR
```

```
pP1 := STRING_TO_PVOID( sP1 );  
pP2 := STRING_TO_PVOID( sP2 );  
pP3 := STRING_TO_PVOID( sP3 );  
pP4 := STRING_TO_PVOID( sP4 );  
pP5 := STRING_TO_PVOID( sP5 );
```

The result:

pP1 = 2301908600

pP2 = 2301908600

pP3 = 2301908600

pP4 = 2301908600

pP5 = 0

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
