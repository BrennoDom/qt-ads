# LPTSIGNAL

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. LPTSIGNAL

# LPTSIGNAL

![57980147](/tcplclib_tc2_system/1033/Images/png/18014398540812555__Web.png)

This function sets a defined output bit in a Centronics interface to a logical high or low level, and can, for example, be used for run-time measurements with an oscilloscope.

## FUNCTION LPTSIGNAL: BOOL

```
VAR_INPUT  
    PortAddr : UINT;  
    PinNo    : INT;  
    OnOff    : BOOL;  
END_VAR
```

**PortAddr**: Address of the port which is available for the desired LPT interface.

**PinNo**: Number of the pin (Pin 0 .. 7 ) which is to be written by the PLC.

**OnOff**: State which is to be written to that pin.

**Example of calling the function in FBD:**

![52059282](/tcplclib_tc2_system/1033/Images/gif/31333771__en-US__Web.gif)

In the example, bit 7 of port 378 (hex) is set to 1.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
