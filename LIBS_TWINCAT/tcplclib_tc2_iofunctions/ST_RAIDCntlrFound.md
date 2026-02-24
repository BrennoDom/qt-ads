# ST_RAIDCntlrFound

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_RAIDCntlrFound

# ST\_RAIDCntlrFound

```
TYPE ST_RAIDCntlrFound :  
STRUCT  
    nRAIDCntlrCount : UDINT;  
    nRAIDCntlrIds   : ARRAY [1..g_nMAX_NUMBER_OF_RAID_CNTLRS] OF UDINT;  
END_STRUCT  
END_TYPE
```

**nRAIDCntlrCount:** Number of RAID controllers

**nRAIDCntlrIds:** ID of each RAID controller (default value is 4294967295 and therefore invalid).

**g\_nMAX\_NUMBER\_OF\_RAID\_CNTLRS** is the maximum number of RAID controllers and is defined as a global constant = 10.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
