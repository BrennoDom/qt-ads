# E_CouplerErrType

## Library
tcplclib_tc2_coupler

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
2. [Data types](ms-xhelp:///?Id=beckhoff-dbaa-40e2-8db0-78236880fde1)
3. E\_CouplerErrType

# E\_CouplerErrType

```
TYPE E_CouplerErrType :  
(  
    CPLERR_NONE     := 0, (* No error *)  
    CPLERR_FIELDBUS := 1, (* Fieldbus error *)  
    CPLERR_KBUS     := 2, (* Terminal bus error (KBus)*)  
    CPLERR_TERM_IO  := 4, (* Terminal IO error *)  
    CPLERR_COUPLER  := 8 (* Coupler error *)  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Coupler (IO) |

[TwinCAT 3 | PLC Library: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
