# DCTIME_TO_STRING

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME]](ms-xhelp:///?Id=beckhoff-1a45-4d20-9c37-9f6a39f5f5a8)
5. DCTIME\_TO\_STRING

# DCTIME\_TO\_STRING

![66716254](/tcplclib_tc2_ethercat/1033/Images/png/57259019__Web.png)

|  |  |
| --- | --- |
| 63575380 | Outdated function  This function is outdated. Use the function [DCTIME64\_TO\_STRING](ms-xhelp:///?Id=beckhoff-ec69-4c57-932b-c9e647ad43a5) instead. |

The function converts a string to a distributed clock system time variable of type [T\_DCTIME](ms-xhelp:///?Id=beckhoff-27de-43e4-9ec2-613239202c77).

The string resulting the conversion has the following format: **'YYYY-MM-DD-hh:mm:ss.nnnnnnnnn'**

* YYYY: year;
* MM: month;
* DD: day;
* hh: hour;
* mm: minute;
* ss: second;
* nnnnnnnnn: nanoseconds;

## FUNCTION DCTIME\_TO\_STRING: STRING(29)

```
VAR_INPUT  
    in : T_DCTIME;  
END_VAR
```

**in**: The distributed clock system time variable to be converted.

**Example:**

See description of the function [F\_GetCurDcTickTime](ms-xhelp:///?Id=beckhoff-e6f8-45f8-8167-0cbf40626301).

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
