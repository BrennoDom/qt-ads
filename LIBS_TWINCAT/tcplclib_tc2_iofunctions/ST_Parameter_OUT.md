# ST_Parameter_OUT

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_Parameter\_OUT

# ST\_Parameter\_OUT

Output data to the ASI terminal.

```
TYPE ST_ParameterBuffer :  
STRUCT  
    ParameterControl : WORD;  
    iParametervalue  : DWORD;  
END_STRUCT  
END_TYPE
```

| Byte Offset | Bit Offset | Description |
| --- | --- | --- |
| 0 | 0-5 | Parameter number bits 0-5 (or parameter offset) |
| 0 | 6 | In case of acyclic: 0: Read, 1: Write, in case of cyclic (always read/write) the bit is copied into the input data in order to have a direct allocation (the cyclic data could then also be modified) |
| 0 | 7 | 0: parameter access, 1: Register communication |
| 1 | 0-5 | Parameter number bits 6-11 (or parameter page) |
| 1 | 6 | 0: Cyclic, 1: Acyclic |
| 1 | 7 | 0: parameter access, 1: ADS |
| 2 |  | Output data (cyclic) or parameter value (acyclic) bits 0-7 |
| 3 |  | Output data (cyclic) or parameter value (acyclic) bits 8-15 |
| 4 |  | Output data (cyclic) or parameter value (acyclic) bits 16-23 |
| 5 |  | Output data (cyclic) or parameter value (acyclic) bits 24-32 |

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | ASI master terminal | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
