# DCTIME_TO_DCTIMESTRUCT

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME]](ms-xhelp:///?Id=beckhoff-1a45-4d20-9c37-9f6a39f5f5a8)
5. DCTIME\_TO\_DCTIMESTRUCT

# DCTIME\_TO\_DCTIMESTRUCT

![13491266](/tcplclib_tc2_ethercat/1033/Images/png/57268619__Web.png)

|  |  |
| --- | --- |
| 54312533 | Outdated function  This function is outdated. Use the function [DCTIME64\_TO\_DCTIMESTRUCT](ms-xhelp:///?Id=beckhoff-02db-4364-945a-9582e1d0c450) instead. |

The function converts a 64-bit distributed clock system time variable of type [T\_DCTIME](ms-xhelp:///?Id=beckhoff-27de-43e4-9ec2-613239202c77) to a structured variable of type [DCTIMESTRUCT](ms-xhelp:///?Id=beckhoff-8f59-4ff7-aabf-851c8fa233f6).

## FUNCTION DCTIME\_TO\_DCTIMESTRUCT: DCTIMESTRUCT

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
    dcStruct : DCTIMESTRUCT;  
    dcTime : T_DCTIME;  
END_VAR  
  
dcTime := F_GetCurDcTickTime();  
dcStruct := DCTIME_TO_DCTIMESTRUCT(dcTime);
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
