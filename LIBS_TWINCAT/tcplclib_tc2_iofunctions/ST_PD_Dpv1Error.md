# ST_PD_Dpv1Error

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_PD\_Dpv1Error

# ST\_PD\_Dpv1Error

```
TYPE ST_PD_Dpv1Error :  
STRUCT  
    bError   : BOOL;  
    eErrorId : E_PD_Dpv1Error;  
END_STRUCT  
END_TYPE
```

**bError**: Error flag (TRUE => error, FALSE => no error).

**eErrorID**: Error code. (Type: [E\_PD\_Dpv1Error](ms-xhelp:///?Id=beckhoff-208f-483d-a740-580a52c08a48)).

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Beckhoff FC310x PCI, CX1500-M310, EL6731, EL6632 | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
