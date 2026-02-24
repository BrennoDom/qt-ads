# ST_CouplerDiag

## Library
tcplclib_tc2_coupler

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
2. [Data types](ms-xhelp:///?Id=beckhoff-dbaa-40e2-8db0-78236880fde1)
3. ST\_CouplerDiag

# ST\_CouplerDiag

```
TYPE ST_CouplerDiag :  
STRUCT  
    eErrType    : E_CouplerErrType;  
    stFlashCode : ST_FlashCode;  
END_STRUCT  
END_TYPE
```

**eErrType** : General Error type (type: [E\_CouplerErrType](ms-xhelp:///?Id=beckhoff-56d7-41be-be2f-7131059ce8ac))

**stFlashCode** : The first and second sequence of the code of flash (type: [ST\_FlashCode](ms-xhelp:///?Id=beckhoff-f15d-406a-b20c-152aa7a41f92))

## Requirements

| Development environment | Target system type | PLC libraries to include (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Coupler (IO) |

[TwinCAT 3 | PLC Library: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
