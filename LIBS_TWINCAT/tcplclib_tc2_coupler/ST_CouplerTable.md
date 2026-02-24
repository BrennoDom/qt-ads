# ST_CouplerTable

## Library
tcplclib_tc2_coupler

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
2. [Data types](ms-xhelp:///?Id=beckhoff-dbaa-40e2-8db0-78236880fde1)
3. ST\_CouplerTable

# ST\_CouplerTable

```
TYPE ST_CouplerTable : ARRAY[ 0..255 ] OF ST_CouplerReg;  
END_TYPE
```

The parameters and configuration of the coupler are stored in the coupler's EEPROM. The memory is divided into tables (Type [ST\_CouplerReg](ms-xhelp:///?Id=beckhoff-a8e5-4da5-a304-dd66424d0966)). Each table possesses a maximum of 256 registers.

## Requirements

| Development environment | Target system type | PLC libraries to include (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Coupler (IO) |

[TwinCAT 3 | PLC Library: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
