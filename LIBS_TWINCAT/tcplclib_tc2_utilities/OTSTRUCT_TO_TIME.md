# OTSTRUCT_TO_TIME

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# OTSTRUCT\_TO\_TIME

![47787886](/tcplclib_tc2_utilities/1033/Images/gif/35884683__en-US__Web.gif)

The function "OTSTRUCT\_TO\_TIME" can be used to convert a structure with resolved milliseconds, seconds, minutes, hours, days and weeks into a TIME variable.

## FUNCTION OTSTRUCT\_TO\_TIME: TIME

## VAR\_INPUT

```
VAR_INPUT  
    OTIN : OTSTRUCT;  
END_VAR
```

**OTIN**: The structure to be converted (type: [OTSTRUCT](ms-xhelp:///?Id=beckhoff-9b34-4574-a2c7-f7c9d49755c3)).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
