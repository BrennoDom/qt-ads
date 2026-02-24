# ST_SercosParamErrList

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_SercosParamErrList

# ST\_SercosParamErrList

```
TYPE ST_SercosParamErrList :  
STRUCT  
    iActCount    : UINT;  
    iMaxCount    : UINT;  
    iList        : ARRAY [0..2047] OF UINT;  
    iError       : ARRAY [0..2047] OF UDINT;  
END_STRUCT  
END_TYPE
```

**iActCount**: The number of parameters skipped (in this case 3 = 3 parameter errors).

**iMaxCount**: The number of parameters skipped (in this case 3 = 3 parameter errors).

**iList**: A field of up to 2048 parameter numbers where access errors occurred.

**iError**: A field of up to 2048 access error numbers.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC (x86) | Sercans SCS-P ISA; Sercans SCS-P PCI; Beckhoff FC750x PCI | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
