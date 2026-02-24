# GETBIT32

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. GETBIT32

# GETBIT32

![27220025](/tcplclib_tc2_system/1033/Images/png/9007199286058763__Web.png)

The function returns the status of the bit specified by a bit number in the 32 bit value that is passed to it as a boolean resulting value. The input value is not altered.

## FUNCTION GETBIT32 : BOOL

```
VAR_INPUT  
    inVal32 : DWORD;  
    bitNo   : SINT;  
END_VAR
```

**inVal32**: 32 bit value

**bitNo**: Number of the bit to be read (0-31). This number is internally converted to a modulo 32 value prior to execution.

**Example of calling the function in FBD:**

![43653635](/tcplclib_tc2_system/1033/Images/png/31320971__en-US__Web.png)

Bit 2 in the input value 16#04 is queried and assigned to the boolean variable aGetBitResultVar. The query returns TRUE in this example.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
