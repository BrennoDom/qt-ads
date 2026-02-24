# FILETIME_TO_DCTIME

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME]](ms-xhelp:///?Id=beckhoff-1a45-4d20-9c37-9f6a39f5f5a8)
5. FILETIME\_TO\_DCTIME

# FILETIME\_TO\_DCTIME

![59907344](/tcplclib_tc2_ethercat/1033/Images/png/57275019__Web.png)

|  |  |
| --- | --- |
| 2295192 | Outdated function  The function is outdated. Use the function [FILETIME\_TO\_DCTIME64](ms-xhelp:///?Id=beckhoff-4232-4682-b831-28f81efcbc90) instead. |

The function converts a 64-bit Windows file time variable of type T\_FILETIME to a 64-bit distributed clock system time variable of type [T\_DCTIME](ms-xhelp:///?Id=beckhoff-27de-43e4-9ec2-613239202c77). In the event of a conversion error the function returns the value zero.

## FUNCTION FILETIME\_TO\_DCTIME: T\_DCTIME

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
    dct : T_DCTIME;  
END_VAR  
  
fbSysFileTime(timeLoDW=>ft.dwLowDateTime, timeHiDW=>ft.dwHighDateTime);  
dct := FILETIME_TO_DCTIME(ft);
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
