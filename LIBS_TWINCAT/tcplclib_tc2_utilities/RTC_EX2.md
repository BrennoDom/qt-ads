# RTC_EX2

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# RTC\_EX2

![42401657](/tcplclib_tc2_utilities/1033/Images/png/9007199290430475__Web.png)

The "RTC\_EX2" (Extended Real Time Clock) function block allows an internal Software clock to be implemented in TwinCAT PLC. The clock must be initialized with a starting date and time. After the initialization the time and date are updated with each call of the function block. A CPU system clock is used to calculate the current time and date. The function block should be called in every PLC cycle, so that the current time can be calculated. At the function block output the current date and time is available in the Windows system time format. In contrast to the [RTC](ms-xhelp:///?Id=beckhoff-2d6e-4437-8c41-351693b53644) function block, RTC\_EX2 offers microsecond accuracy. Multiple instances of the RTC\_EX2 function block can be created within one PLC program.

|  |  |
| --- | --- |
| 46070597 | RTC\_EX2 time can differ from the reference time  The way the system works means that the RTC\_EX2 time can differ from the reference time. The difference depends on the PLC's cycle time, the value of the basic system ticks, and on the hardware being used.  In order to avoid larger deviations the RTC\_EX2 instance should be synchronized cyclically (e.g. with a radio clock or with the local Windows system time). The local Windows system time you can be synchronized with a reference time via the SNTP protocol. |

## VAR\_INPUT

```
VAR_INPUT  
   EN      : BOOL;  
   PDT     : TIMESTRUCT;  
   PMICRO  : DWORD;  
END_VAR
```

**EN**: The RTC\_EX2 function block is re-initialized with a specified date, time and millisecond by a rising edge at this input.

**PDT**: (Preset Date and Time ) The initialisation values for the function block's date and time (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)). A rising edge at the EN input will cause the function block to adopt this value.

**PMICRO**: (Preset Milliseconds) The initialisation value for the milliseconds. A rising edge at the EN input will cause the function block to adopt this value.

## VAR\_OUTPUT

```
VAR_OUTPUT  
   Q      : BOOL;  
   CDT    : TIMESTRUCT;  
   CMICRO : DWORD;  
END_VAR
```

**Q**: This output is set if the function block has been initialized at least once. If the output is set, the values for the date, time and milliseconds at the PDT and CMICRO outputs are valid.

**CDT**: Current date and time of the RTC\_EX2 instance (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)). The CDT output is only updated when the function block is called. For this reason, instances of the function block should be called once in each PLC cycle.

**CMICRO**: (Current Microseconds) The microseconds output.

**Example:**

See: [Example: Software clocks (RTC, RTC\_EX, RTC\_EX2).](ms-xhelp:///?Id=beckhoff-17d7-43b3-b210-58197fb4d298)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
