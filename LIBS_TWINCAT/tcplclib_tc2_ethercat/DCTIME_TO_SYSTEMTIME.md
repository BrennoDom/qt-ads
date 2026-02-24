# DCTIME_TO_SYSTEMTIME

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME]](ms-xhelp:///?Id=beckhoff-1a45-4d20-9c37-9f6a39f5f5a8)
5. DCTIME\_TO\_SYSTEMTIME

# DCTIME\_TO\_SYSTEMTIME

![35307513](/tcplclib_tc2_ethercat/1033/Images/png/57265419__Web.png)

|  |  |
| --- | --- |
| 49332166 | Outdated function  This function is outdated. Use the function [DCTIME64\_TO\_SYSTEMTIME](ms-xhelp:///?Id=beckhoff-c97f-49e7-b860-a203fed2dcb5) instead. |

The function converts a 64-bit distributed clock system time variable of type [T\_DCTIME](ms-xhelp:///?Id=beckhoff-27de-43e4-9ec2-613239202c77) to a structured Windows system time variable of type TIMESTRUCT.

## FUNCTION DCTIME\_TO\_SYSTEMTIME: TIMESTRUCT

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
    syst : TIMESTRUCT;  
END_VAR  
  
syst := DCTIME_TO_SYSTEMTIME( F_GetCurDcTickTime() );
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
