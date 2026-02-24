# FILETIME64_TO_DCTIME64

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [DCTIME64](ms-xhelp:///?Id=beckhoff-4896-4dc7-a801-9f7bad5a1eb8)
4. FILETIME64\_TO\_DCTIME64

# FILETIME64\_TO\_DCTIME64

![30479771](/tcplclib_tc2_ethercat/1033/Images/png/2267458955__Web.png)

The function converts a 64-bit "Windows File Time" variable of type T\_FILETIME64 to a 64-bit "Distributed Clock System Time" variable of type [T\_DCTIME64](ms-xhelp:///?Id=beckhoff-61c0-4c24-9dad-22f122397674). In the event of a conversion error the function returns the value zero.

## FUNCTION FILETIME64\_TO\_DCTIME64: T\_DCTIME64

```
VAR_INPUT  
    in : T_FILETIME64;  
END_VAR
```

**in**: the "Windows File Time" variable to be converted.

**Sample**:

```
PROGRAM P_TEST  
VAR  
    ft : T_FILETIME64;  
    dct : T_DCTIME64;  
END_VAR  
  
ft := F_GetSystemTime();  
dct := FILETIME64_TO_DCTIME64(ft);
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT >= 3.3.16.0 |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
