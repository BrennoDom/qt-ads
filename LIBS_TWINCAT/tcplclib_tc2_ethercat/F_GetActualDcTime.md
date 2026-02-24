# F_GetActualDcTime

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME and T\_LARGE\_INTEGER]](ms-xhelp:///?Id=beckhoff-d3df-4f17-b490-c93b45508d82)
5. F\_GetActualDcTime

# F\_GetActualDcTime

![621706](/tcplclib_tc2_ethercat/1033/Images/png/57310219__Web.png)

|  |  |
| --- | --- |
| 5595356 | Outdated function  This function is outdated. Use the function [F\_GetActualDcTime64](ms-xhelp:///?Id=beckhoff-2913-4123-9a54-d73facff2315) instead. |

This function returns the current time in TwinCAT distributed clock system time format ([T\_DCTIME](ms-xhelp:///?Id=beckhoff-27de-43e4-9ec2-613239202c77)).

## FUNCTION F\_GetActualDcTime: T\_DCTIME

```
VAR_INPUT  
(*none*)  
END_VAR
```

**Example:**

```
PROGRAM MAIN  
VAR  
    actDC : T_DCTIME;  
    sAct : STRING;  
END_VAR  
  
actDC := F_GetActualDcTime();  
sAct := DCTIME_TO_STRING( actDC );
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
