# ST_AmsAddr

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. ST\_AmsAddr

# ST\_AmsAddr

A variable of this type contains the TwinCAT Ams network ID address.

```
TYPE ST_AmsAddr :  
STRUCT  
    netId   : T_AmsNetIdArr;  
    port    : T_AmsPort;  
END_STRUCT  
END_TYPE
```

**netId**: Ams network ID address (type: [T\_AmsNetIdArr](ms-xhelp:///?Id=beckhoff-df02-4290-a2ea-8872fba602a2));

**port**: Ams port number (type: [T\_AmsPort](ms-xhelp:///?Id=beckhoff-8526-4c85-aeea-045be9df1824));

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
