# SYSTEMTIME_TO_DCTIME

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME]](ms-xhelp:///?Id=beckhoff-1a45-4d20-9c37-9f6a39f5f5a8)
5. SYSTEMTIME\_TO\_DCTIME

# SYSTEMTIME\_TO\_DCTIME

![62582666](/tcplclib_tc2_ethercat/1033/Images/png/57278219__Web.png)

|  |  |
| --- | --- |
| 26373084 | Outdated function  This function is outdated. Use the function [SYSTEMTIME\_TO\_DCTIME64](ms-xhelp:///?Id=beckhoff-15f7-484f-b50f-24a0d8e7e3d1) instead. |

The function converts a structured Windows system time variable of type TIMESTRUCT to a 64-bit distributed clock system time variable of type [T\_DCTIME](ms-xhelp:///?Id=beckhoff-27de-43e4-9ec2-613239202c77). In the event of a conversion error the function returns the value zero.

## FUNCTION SYSTEMTIME\_TO\_DCTIME: T\_DCTIME

```
VAR_INPUT  
    in : TIMESTRUCT;  
    micro : WORD(0..999); (* Microseconds: 0..999 *)  
    nano : WORD(0..999); (* Nanoseconds: 0..999 *)  
END_VAR
```

**in**: The Windows system time variable to be converted.

**micro**: Microseconds.

**nano**: Nanoseconds.

**Example:**

```
PROGRAM P_TEST  
VAR  
    syst : TIMESTRUCT := ( wYear := 2009, wMonth := 9, wDay := 16, wHour := 12, wMinute := 22, wSecond := 44, wMilliseconds := 123 );  
END_VAR  
  
dct := SYSTEMTIME_TO_DCTIME( syst, 456, 789 );
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
