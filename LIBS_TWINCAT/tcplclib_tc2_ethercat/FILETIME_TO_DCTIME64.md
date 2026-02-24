# FILETIME_TO_DCTIME64

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. FILETIME\_TO\_DCTIME64

# FILETIME\_TO\_DCTIME64

![51187411](/tcplclib_tc2_ethercat/1033/Images/png/2267458955__Web.png)

The function converts a 64-bit Windows file time variable of type T\_FILETIME to a 64-bit distributed clock system time variable of type [T\_DCTIME64](ms-xhelp:///?Id=beckhoff-61c0-4c24-9dad-22f122397674). In the event of a conversion error the function returns the value zero.

## FUNCTION FILETIME\_TO\_DCTIME64: T\_DCTIME64

```
VAR_INPUT  
    in : T_FILETIME;  
END_VAR
```

**in**: The Windows file time variable to be converted.

**Example:**

```
PROGRAM P_TEST  
VAR  
    fbSysFileTime : GETSYSTEMTIME;  
    ft : T_FILETIME;  
    dct : T_DCTIME64;  
END_VAR  
  
fbSysFileTime(timeLoDW=>ft.dwLowDateTime, timeHiDW=>ft.dwHighDateTime);  
dct := FILETIME_TO_DCTIME64(ft);
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
