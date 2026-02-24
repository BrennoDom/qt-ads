# ST_RAIDConfigReq

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_RAIDConfigReq

# ST\_RAIDConfigReq

```
TYPE ST_RAIDConfigReq :  
STRUCT  
    nRAIDCntlrID  : UDINT;  
    nRAIDSetIndex : UDINT;  
END_STRUCT  
END_TYPE
```

**nRAIDCntlrID:** ID of the RAID controller

**nRAIDSetIndex:** Contains the number of the RAID set for which information is being requested. Please note that the set begins with index 0 in the case of Beckhoff CBx051 boards.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
