# F_GetMappingStatus

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. F\_GetMappingStatus

# F\_GetMappingStatus

![54645451](/tcplclib_tc2_system/1033/Images/png/2311246347__Web.png)

The function F\_GetMappingStatus returns the current mapping status of a PLC variable. The function returns an ENUM value (data type: [EPlcMappingStatus](ms-xhelp:///?Id=beckhoff-b8eb-4930-9a9a-54126fa2af60)) with the values MS\_Unmapped, MS\_Mapped or MS\_Partial.

## FUNCTION F\_GetMappingStatus: EPlcMappingStatus

```
VAR_INPUT  
    p : PVOID;  
    n : UDINT;  
END_VAR
```

**p**: Memory address of the variable

**n**: Size of the variable in bytes

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4020 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
