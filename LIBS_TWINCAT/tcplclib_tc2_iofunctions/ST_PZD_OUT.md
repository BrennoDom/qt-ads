# ST_PZD_OUT

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_PZD\_OUT

# ST\_PZD\_OUT

Data words from the PLC to the drive.

```
TYPE ST_PZD_OUT :  
STRUCT  
    wCtrlW :WORD;  
    PZD2   :WORD;  
    PZD3   :WORD;  
    PZD4   :WORD;  
    PZD5   :WORD;  
    PZD6   :WORD;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | AX2000 Profibus box | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
