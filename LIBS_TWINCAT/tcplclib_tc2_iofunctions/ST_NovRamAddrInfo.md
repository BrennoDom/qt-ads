# ST_NovRamAddrInfo

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_NovRamAddrInfo

# ST\_NovRamAddrInfo

```
TYPE ST_NovRamAddrInfo:  
STRUCT  
    pCardAddress : POINTER TO DWORD;  
    iCardMemSize : UDINT;  
END_STRUCT  
END_TYPE
```

**pCardAddress** : The address pointer of the NOV/DP-RAM.

**iCardMemSize** : The configured NOV/DP-RAM size in bytes.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | All IO devices | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
