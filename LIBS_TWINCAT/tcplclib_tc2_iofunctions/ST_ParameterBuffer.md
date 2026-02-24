# ST_ParameterBuffer

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_ParameterBuffer

# ST\_ParameterBuffer

Data buffer for the I/O data of the ASI terminal

```
TYPE ST_ParameterBuffer :  
STRUCT  
    ParameterControl    : ARRAY[0..50] OF WORD;  
    iParametervalue     : ARRAY[0..50] OF DWORD;  
    iParameterStatus    : ARRAY[0..50] OF WORD;  
    iParameterReadValue : ARRAY[0..50] OF DWORD;  
    icounterState       : INT;  
    icounterControl     : INT;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | ASI master terminal | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
