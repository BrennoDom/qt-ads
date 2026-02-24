# RTC

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# RTC

![60282721](/tcplclib_tc2_utilities/1033/Images/png/9007199290424075__Web.png)

The function block "RTC" (Real Time Clock) can be used to realize an internal software clock in the TwinCAT PLC. The clock must be initialized with a starting date and time. After the initialization the time and date are updated with each call of the function block. A CPU system clock is used to calculate the current time and date. The function block should be called in every PLC cycle, so that the current time can be calculated. The current date and time are available in the usual DATE\_AND\_TIME (DT) format at the function block's output. Multiple instances of the RTC function block can be created within one PLC program.

|  |  |
| --- | --- |
| 5673583 | RTC time can differ from the reference time  The way the system works means that the RTC time can differ from the reference time. The difference depends on the PLC's cycle time, the value of the basic system ticks, and on the hardware being used.  In order to avoid larger deviations the RTC instance should be synchronized cyclically (e.g. with a radio clock or with the local Windows system time). The local Windows system time you can be synchronized with a reference time via the SNTP protocol. |

## VAR\_INPUT

```
VAR_INPUT  
   EN  : BOOL;  
   PDT : DATE_AND_TIME;  
END_VAR
```

**EN**: The function block is re-initialized with a specified date and time by a rising edge at this input.

**PDT**: (Preset Date and Time) The initialisation values for the function block's date and time. A rising edge at the EN input will cause the function block to adopt this value.

## VAR\_OUTPUT

```
VAR_OUTPUT  
   Q    : BOOL;  
   CDT  : DATE_AND_TIME;  
END_VAR
```

**Q**: This output is set if the function block has been initialized at least once. If the output is set, the values for the date and time at the PDT output are valid.

**CDT**: Current date and time of the RTC instance. The CDT output is only updated when the function block is called. For this reason, instances of the function block should be called once in each PLC cycle.

**Example:**

See: [Example: Software clocks (RTC, RTC\_EX, RTC\_EX2).](ms-xhelp:///?Id=beckhoff-17d7-43b3-b210-58197fb4d298)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
