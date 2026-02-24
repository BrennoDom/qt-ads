# CSETBIT32

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. CSETBIT32

# CSETBIT32

![9449599](/tcplclib_tc2_system/1033/Images/png/9007199286052363__Web.png)

The function sets/resets the bit specified by a bit number in the 32 bit value that is passed to it and returns the resulting value.

## FUNCTION CSETBIT32 : DWORD

```
VAR_INPUT  
    inVal32 : DWORD;  
    bitNo   : SINT;  
    bitVal  : BOOL;  
END_VAR
```

**inVal32**: 32 bit value

**bitNo**: Number of the bit to be set or reset (0-31). This number is internally converted to a modulo 32 value prior to execution.

**bitVal**: Value to which the bit is to be set or reset (TRUE = 1, FALSE = 0)

**Example of calling the function in FBD:**

![17937528](/tcplclib_tc2_system/1033/Images/png/31314571__en-US__Web.png)

Bit 15 in the input value 16#80000000 is set to 1. The result (16#80008000) is assigned to the variable CSetBitResultVal.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
