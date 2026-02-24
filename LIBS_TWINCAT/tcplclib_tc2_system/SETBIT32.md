# SETBIT32

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. SETBIT32

# SETBIT32

![33256841](/tcplclib_tc2_system/1033/Images/png/9007199286045963__Web.png)

The function sets the bit specified by a bit number in the 32 bit value that is passed to it and returns the resulting value.

## FUNCTION SETBIT32 : DWORD

```
VAR_INPUT  
    inVal32 : DWORD;  
    bitNo   : SINT;  
END_VAR
```

**inVal32**: 32 bit value that is to be modified

**bitNo**: Number of the bit that is to be set (0-31). This number is internally converted to a modulo 32 value prior to execution

**Example of calling the function in FBD:**

![30876117](/tcplclib_tc2_system/1033/Images/gif/31308171__en-US__Web.gif)

This sets bit 31 of the input value 0. The result is the (hex) value “80000000”.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
