# Profiler

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Profiler

|  |  |
| --- | --- |
| 11720763 | This functionality is not available in the PLC under Windows CE! |

![38378011](/tcplclib_tc2_utilities/1033/Images/png/9007199290414475__Web.png)

The "Profiler" function block can be used to allow the execution time of PLC code to be measured. Internally, an instance of the GETCPUACCOUNT function block is called. The measurement is started by a rising edge at the START input, and is stopped by a falling edge. The measurements are evaluated internally, and are then made available for further processing at the DATA output in a structure of type [PROFILERSTRUCT](ms-xhelp:///?Id=beckhoff-c7d4-4028-ab5b-570c64f04e68). As well as the current, minimum and maximum execution times, the function block calculates the mean execution time for the last 10 measurements. The number of averaged measured values can be configured via the global variable [MAX\_AVERAGE\_MEASURES](ms-xhelp:///?Id=beckhoff-597c-4742-8455-9ba22eeabe7c) between 2 and 100. The times measured are given in microseconds. The output variable [DATA.MeasureCycle](ms-xhelp:///?Id=beckhoff-c7d4-4028-ab5b-570c64f04e68) provides information about the number of measurements that have already been carried out. In order to measure the execution time for a specific segment of the PLC program the measurement must be started by a rising edge at the START input when the segment to be measured starts, and stopped by a falling edge at the START input at the end of the segment. All values at the DATA output can be reset if a rising edge is generated at the RESET input at the same time as the rising edge at START. The old measured values are then reset when a new measurement starts and are recalculated from the subsequent calls of the function block.

**Comment:**

The times measured can differ from the actual values, since a certain amount of time is needed just for the call of the GETCPUACCOUNT function block. This time depends on the particular computer, and is included in the times that are found.

## VAR\_INPUT

```
VAR_INPUT  
    START  : BOOL;  
    RESET  : BOOL;  
END_VAR
```

**START**: A rising edge at this input starts the measurement of the execution time. A falling edge at this input stops the measurement, and causes the current, minimum, maximum and mean execution times to be recalculated. The variable [DATA.MeasureCycle](ms-xhelp:///?Id=beckhoff-c7d4-4028-ab5b-570c64f04e68) is incremented at the same time.

**RESET**: All variables at the DATA output are reset if a rising edge is generated at this input at the same time as a rising edge at the START input. The old values for the current, minimum, maximum and mean execution times are reset, and are re-calculated for following measurements.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY  : BOOL;  
    DATA  : PROFILERSTRUCT;  
END_VAR
```

**BUSY**: This input is set at the start of the measuring procedure, and remains set until the time measurement has been completed. Once the BUSY output has been reset, the latest times are available at the DATA output.

**DATA**: structure of type [PROFILERSTRUCT](ms-xhelp:///?Id=beckhoff-c7d4-4028-ab5b-570c64f04e68) with the measured times [in µs].

**Example 1:**

```
PROGRAM ProfilerTest_ST  
VAR  
   Profiler1     : PROFILER;  
   ProfilerData  : PROFILERSTRUCT;  
   a             : LREAL;  
END_VAR
```

**Online display of the measured times:**

![9857780](/tcplclib_tc2_utilities/1033/Images/gif/35676683__en-US__Web.gif)

**Example 2:**

```
PROGRAM ProfilerTest_FUP  
VAR  
   Profiler2      :PROFILER;  
   Profiler2_Busy :BOOL;  
   Profiler2_Data :PROFILERSTRUCT;  
   b              :LREAL;  
END_VAR
```

**Online display of the measured times:**

![21611161](/tcplclib_tc2_utilities/1033/Images/gif/35679883__en-US__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64) | Tc2\_Utilities (System) |
