# ROUTETRANSPORT_TO_STRING

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ROUTETRANSPORT\_TO\_STRING

![66948675](/tcplclib_tc2_utilities/1033/Images/gif/35891083__en-US__Web.gif)

The function converts the AMS message router transport layer ID into a string.

## FUNCTION ROUTETRANSPORT\_TO\_STRING: STRING

## VAR\_INPUT

```
VAR_INPUT  
    eType : E_RouteTransportType;  
END_VAR
```

**eType:** The transport layer ID to be converted (type: [E\_RouteTransportType](ms-xhelp:///?Id=beckhoff-bc21-47c8-a65b-78ccd53a0ab5)).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
