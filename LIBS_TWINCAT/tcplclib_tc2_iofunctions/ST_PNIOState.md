# ST_PNIOState

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_PNIOState

# ST\_PNIOState

```
TYPE ST_PNIOState :  
STRUCT  
    bInDataExchange : BOOL; (* bit 0 *)  
    bApplRunning    : BOOL; (* bit 2 *)  
    bDiagIndicator  : BOOL; (* bit 3 *)  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | Beckhoff EL6632 | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
