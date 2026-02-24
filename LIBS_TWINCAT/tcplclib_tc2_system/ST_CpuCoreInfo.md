# ST_CpuCoreInfo

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. ST\_CpuCoreInfo

# ST\_CpuCoreInfo

A variable of this type contains information about a CPU core. The information can be read for a particular CPU core with the aid of the function [F\_GetCpuCoreInfo](ms-xhelp:///?Id=beckhoff-cacb-406a-a4f6-afa3c78faef6) and the corresponding CPU core index.

```
TYPE ST_CpuCoreInfo :  
STRUCT  
    bRTCore       : BOOL;  
    bIsolatedCore : BOOL;  
    nBaseTime     : UDINT;  
    nCoreLimit    : UDINT;   
END_STRUCT  
END_TYPE
```

**bRTCore**: This variable has a value of TRUE if it is a real-time core.

**bIsolatedCore**: This variable has a value of TRUE if it is an isolated core.

**nBaseTime**: Base time of the CPU core, specified as a multiple of 100 ns.

**nCoreLimit**: Core limit of the CPU core, specified in %.

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.11 | PC or CX (x86, x64, ARM) | Tc2\_System (System) >= 3.4.24.0 |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
