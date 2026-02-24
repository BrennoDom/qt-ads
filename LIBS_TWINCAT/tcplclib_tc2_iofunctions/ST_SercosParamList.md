# ST_SercosParamList

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_SercosParamList

# ST\_SercosParamList

```
TYPE ST_SercosParamList :  
STRUCT  
    iActCount    : UINT;  
    iMaxCount    : UINT;  
    iList        : ARRAY [0..2047] OF UINT;  
END_STRUCT  
END_TYPE
```

**iActCount**: The current number of parameters in a list \* 2. Sercos saves the number of bytes here; a parameter number consists of two bytes, e.g. 6 means 3 parameters.

**iMaxCount**: The maximum number of parameters in a list \* 2. Sercos saves the number of bytes here; a parameter number consists of two bytes, e.g. 6 means 3 parameters.

**iList**: A field of up to 2048 parameter numbers.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC (x86) | Sercans SCS-P ISA; Sercans SCS-P PCI; Beckhoff FC750x PCI | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
