# TIME_TO_OTSTRUCT

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# TIME\_TO\_OTSTRUCT

![19572825](/tcplclib_tc2_utilities/1033/Images/gif/35916683__en-US__Web.gif)

The function "TIME\_TO\_OTSTRUCT" can be used to convert a TIME constant or variable into a structure with the resolved milliseconds, seconds, minutes, hours, days and weeks.

## FUNCTION TIME\_TO\_OTSTRUCT: [OTSTRUCT](ms-xhelp:///?Id=beckhoff-9b34-4574-a2c7-f7c9d49755c3)

## VAR\_INPUT

```
VAR_INPUT  
    TIN : TIME;  
END_VAR
```

**TIN**: The TIME variable to be converted.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
