# ST_CouplerReg

## Library
tcplclib_tc2_coupler

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
2. [Data types](ms-xhelp:///?Id=beckhoff-dbaa-40e2-8db0-78236880fde1)
3. ST\_CouplerReg

# ST\_CouplerReg

```
TYPE ST_CouplerReg  
STRUCT  
    Lo  : BYTE;  
    Hi  : BYTE;  
END_STRUCT  
END_TYPE
```

A Coupler register has the size of one word. The parameterisation and the configuration of the coupler is discarded in the register.

## Requirements

| Development environment | Target system type | PLC libraries to include (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Coupler (IO) |

[TwinCAT 3 | PLC Library: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
