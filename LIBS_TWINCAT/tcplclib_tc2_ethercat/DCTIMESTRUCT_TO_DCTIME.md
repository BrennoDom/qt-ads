# DCTIMESTRUCT_TO_DCTIME

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME]](ms-xhelp:///?Id=beckhoff-1a45-4d20-9c37-9f6a39f5f5a8)
5. DCTIMESTRUCT\_TO\_DCTIME

# DCTIMESTRUCT\_TO\_DCTIME

![41336317](/tcplclib_tc2_ethercat/1033/Images/png/57281419__Web.png)

|  |  |
| --- | --- |
| 36482533 | Outdated function  This function is outdated. Use the function [DCTIMESTRUCT\_TO\_DCTIME64](ms-xhelp:///?Id=beckhoff-b615-4373-b366-9288559ab2d0) instead. |

The function converts a structured variable of type [DCTIMESTRUCT](ms-xhelp:///?Id=beckhoff-8f59-4ff7-aabf-851c8fa233f6) to a 64-bit distributed clock system time variable of type [T\_DCTIME](ms-xhelp:///?Id=beckhoff-27de-43e4-9ec2-613239202c77).  
The structure components wDayofWeek is ignored in the conversion. The structure components wYear must be greater than or equal to 2000 and less than 2584. For invalid values of the structure components the function returns the value zero.

## FUNCTION DCTIMESTRUCT\_TO\_DCTIME: T\_DCTIME

```
VAR_INPUT  
    in : DCTIMESTRUCT;  
END_VAR
```

**in**: The structured variable to be converted.

**Example:**

```
PROGRAM P_TEST  
VAR  
    dcStruct : DCTIMESTRUCT := ( wYear := 2008, wMonth := 3, wDay := 13,  
                                 wHour := 1, wMinute := 2, wSecond :=3,  
                                 wMilliseconds := 123, wMicroseconds := 456, wNanoseconds := 789 );  
    dc64 : T_DCTIME;  
END_VAR  
  
dc64 := DCTIMESTRUCT_TO_DCTIME( dcStruct );
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
