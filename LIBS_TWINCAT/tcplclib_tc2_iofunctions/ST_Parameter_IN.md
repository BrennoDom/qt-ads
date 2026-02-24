# ST_Parameter_IN

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_Parameter\_IN

# ST\_Parameter\_IN

Input data of the ASI terminal.

```
TYPE ST_ParameterBuffer :  
STRUCT  
    iParameterStatus    : WORD;  
    iParameterReadValue : DWORD;  
END_STRUCT  
END_TYPE
```

| Byte Offset | Bit Offset | Description |
| --- | --- | --- |
| 0 | 0-5 | Status bits (as with previous terminals) |
| 0 | 6 | 0: No diagnosis, 1: Diagnosis (as with previous terminals) |
| 0 | 7 | always 0: no register communication |
| 1 | 0-3 | 0-3 reserved for extensions |
| 1 | 4 | Toggle bit for acknowledging order (in case of cyclic, bit 6 is copied from byte 0) |
| 1 | 5 | Receipt (0: NoError, 1: Error) |
| 1 | 6 | 0: Cyclic, 1: Acyclic |
| 1 | 7 | 0: parameter access, 1: ADS |
| 2 |  | Input data (cyclic), parameter value (acyclic) or error number bits 0-7 |
| 3 |  | Input data (cyclic), parameter value (acyclic) or error number bits 8-15 |
| 4 |  | Input data (cyclic), parameter value (acyclic) or error number bits 16-23 |
| 5 |  | Input data (cyclic), parameter value (acyclic) or error number bits 24-31 |

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | ASI master terminal | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
