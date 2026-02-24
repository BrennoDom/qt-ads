# ST_RAIDInfo

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_RAIDInfo

# ST\_RAIDInfo

```
TYPE ST_RAIDInfo :  
STRUCT  
    nNumRAIDSets     : UDINT;  
    nMaxDrivesPerSet : UDINT;  
    bReserved        : ARRAY [1..92] OF BYTE;  
END_STRUCT  
END_TYPE
```

**nNumRAIDSets:** Number of currently defined RAID sets. 0 is returned if no sets have been defined yet.

**nMaxDriverPerSet:** Maximum number of physical drives in a logical RAID set. This can be an absolute maximum or the maximum currently defined for all sets.

**bReserved:** Reserved for internal purposes.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
