# DCTIME_TO_FILETIME

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME]](ms-xhelp:///?Id=beckhoff-1a45-4d20-9c37-9f6a39f5f5a8)
5. DCTIME\_TO\_FILETIME

# DCTIME\_TO\_FILETIME

![19050756](/tcplclib_tc2_ethercat/1033/Images/png/57262219__Web.png)

|  |  |
| --- | --- |
| 37239078 | Outdated function  This function is outdated. Use the function [DCTIME64\_TO\_FILETIME](ms-xhelp:///?Id=beckhoff-91a5-41d3-9f1b-a672cebd2493) instead. |

The function converts a 64-bit distributed clock system time variable of type [T\_DCTIME](ms-xhelp:///?Id=beckhoff-27de-43e4-9ec2-613239202c77) to a 64-bit Windows file time variable of type T\_FILETIME.

## FUNCTION DCTIME\_TO\_FILETIME: T\_FILETIME

```
VAR_INPUT  
    in : T_DCTIME;  
END_VAR
```

**in**: The distributed clock system time variable to be converted.

**Example:**

```
PROGRAM P_TEST  
VAR  
    ft  : T_FILETIME;  
    dct : T_DCTIME;  
END_VAR  
  
dct := F_GetCurDcTickTime();  
ft  := DCTIME_TO_FILETIME(dct);
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
