# STRING_TO_DCTIME

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME]](ms-xhelp:///?Id=beckhoff-1a45-4d20-9c37-9f6a39f5f5a8)
5. STRING\_TO\_DCTIME

# STRING\_TO\_DCTIME

![20656733](/tcplclib_tc2_ethercat/1033/Images/png/57271819__Web.png)

|  |  |
| --- | --- |
| 51692872 | Outdated function  This function is outdated. Use the function [STRING\_TO\_DCTIME64](ms-xhelp:///?Id=beckhoff-c7b4-4847-a712-a92e762d3928) instead. |

The function converts a string to a distributed clock system time variable of type [T\_DCTIME](ms-xhelp:///?Id=beckhoff-27de-43e4-9ec2-613239202c77).

## FUNCTION STRING\_TO\_DCTIME: T\_DCTIME

```
VAR_INPUT  
    in : STRING(29);  
END_VAR
```

**in**: The string to be converted.

The string must have the following format: **'YYYY-MM-DD-hh:mm:ss.nnnnnnnnn'**

* YYYY: year;
* MM: month;
* DD: day;
* hh: hour;
* mm: minute;
* ss: second;
* nnnnnnnnn: nanoseconds;

**Example:**

See description of the function [F\_GetCurDcTickTime](ms-xhelp:///?Id=beckhoff-e6f8-45f8-8167-0cbf40626301).

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
