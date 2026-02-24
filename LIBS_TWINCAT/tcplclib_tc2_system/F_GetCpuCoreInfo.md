# F_GetCpuCoreInfo

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. F\_GetCpuCoreInfo

# F\_GetCpuCoreInfo

![28015283](/tcplclib_tc2_system/1033/Images/png/8831035147__Web.png)

The function F\_GetCpuCoreInfo returns information about the CPU core whose index is passed to the function. The information that is read out includes the base time and the core limit for the specified CPU core.

The CPU core index to be passed can be determined with the function [F\_GetCpuCoreIndex](ms-xhelp:///?Id=beckhoff-6466-4db4-b70d-5fed23f00c2a).

The CPU core index corresponds to the value of the **Core** column that is displayed in the **Real-time** sub-node below the SYSTEM node. The information that can be read via the CPU core via the function F\_GetCpuCoreInfo is also displayed in this view.

The function returns an error code as HRESULT (see also [ADS Return Codes](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4)). It indicates whether the function call was successful. If an invalid CPU core index is passed, the function returns an error (0x9811070B = invalid parameter values).

## FUNCTION F\_GetCpuCoreInfo: HRESULT

```
VAR_INPUT  
    nCpuCoreIndex : DINT;  
    pInfo         : POINTER TO ST_CpuCoreInfo;  
END_VAR
```

**nCpuCoreIndex**: Index of the CPU core whose information is to be read.

**pInfo**: Address of the variable that is to receive the read data. The address must point to an instance of type [ST\_CpuCoreInfo](ms-xhelp:///?Id=beckhoff-9711-4013-b34b-badf0a002f59).

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.11 | PC or CX (x86, x64, ARM) | Tc2\_System (System) >= 3.4.24.0 |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
