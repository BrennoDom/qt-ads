# F_ToCHR

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [Character functions](ms-xhelp:///?Id=beckhoff-d2b8-420e-976b-e417a722ee8f)
4. F\_ToCHR

# F\_ToCHR

![34246806](/tcplclib_tc2_system/1033/Images/png/9007199286151563__Web.png)

The function converts ASCII Code to STRING.

## FUNCTION F\_ToCHR: STRING

```
VAR_INPUT  
    c : BYTE;  
END_VAR
```

**c**: ASCII-Code to be converted

**Example for a call in FBD:**

```
PROGRAM P_TEST  
VAR  
    sCharacter : STRING(1) := '';  
    cAsciiCode : BYTE := 16#31;  
END_VAR
```

![39785801](/tcplclib_tc2_system/1033/Images/png/31413771__en-US__Web.png)

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
