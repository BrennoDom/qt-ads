# F_GetMappingPartner

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. F\_GetMappingPartner

# F\_GetMappingPartner

![50810959](/tcplclib_tc2_system/1033/Images/png/2311244427__Web.png)

The function F\_GetMappingPartner returns the object ID (data type: OTCID) of the partner side of the mapping.

## FUNCTION F\_GetMappingPartner: OTCID

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
