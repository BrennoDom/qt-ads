# ST_KL3208InData

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_KL3208InData

# ST\_KL3208InData

Structure for linking in the input process image.

```
TYPE ST_KL3208InData :  
STRUCT  
  iStatus : USINT;  
  iDataIn : INT;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target platform | IO Hardware | PLC libraries to include |
| --- | --- | --- | --- |
| TwinCAT v3.1.4018.26 | PC/CX | KL3208 | Tc2\_IoFunctions from v3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
