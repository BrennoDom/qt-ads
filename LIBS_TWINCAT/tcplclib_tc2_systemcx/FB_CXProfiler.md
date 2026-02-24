# FB_CXProfiler

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Function Blocks](ms-xhelp:///?Id=beckhoff-ec9d-42ff-9fdd-c53aca476e55)
3. FB\_CXProfiler

# FB\_CXProfiler

![4150710](/tcplclib_tc2_systemcx/1033/Images/png/9007199440650763__Web.png)

The function block FB\_CXProfiler can be used to measure the execution time of the PLC code under Microsoft Windows CE.

|  |  |
| --- | --- |
| 37356392 | For other operating systems, refer to the Profiler function block in the [Tc2\_Utilities](ms-xhelp:///?Id=beckhoff-06b5-46f0-b9a7-c7cbeb6e235d) library. |

Internally, an instance of the GETCPUCOUNTER function block is called. The measurement is started by a rising edge at the bStart input, and is stopped by a falling edge. The measurements are evaluated internally, and are then made available for further processing at the stData output in a structure of type [ST\_CX\_ProfilerStruct](ms-xhelp:///?Id=beckhoff-91a3-4e00-8786-a8496df71de5). As well as the current, minimum and maximum execution times, the function block calculates the mean execution time for the last 100 measurements. The times measured are given in microseconds. The output variable [stData.dwMeasureCycle](ms-xhelp:///?Id=beckhoff-91a3-4e00-8786-a8496df71de5) provides information about the number of measurements that have already been carried out. In order to measure the execution time for a specific segment of the PLC program the measurement must be started by a rising edge at the START input when the segment to be measured starts, and stopped by a falling edge at the START input at the end of the segment. All values at the DATA output can be reset if a rising edge is generated at the RESET input at the same time as the rising edge at START. The measurements in the DATA structure that have already been determined then become invalid, and are re-calculated when the function block is called again.

**Comment:**The determined times can deviate from the actual values, since already for the calls of the GETCPUCOUNTER function block some time is needed. This time depends on the particular computer, and is included in the determined times. Task interruptions, e.g. by the NC, are not detected and lead to longer measuring times.

## VAR\_INPUT

```
VAR_INPUT  
    bStart : BOOL;  
    bReset : BOOL;  
END_VAR
```

**bStart**: A rising edge at this input starts the measurement of the execution time. A falling edge at this input stops the measurement, and causes the current, minimum, maximum and mean execution times to be recalculated. The variable [stData.dwMeasureCycle](ms-xhelp:///?Id=beckhoff-91a3-4e00-8786-a8496df71de5) is incremented at the same time.

**bReset**: A rising edge at this input will reset the variables at the stData output. A rising edge at the this input and simultaneous rising edge at START input will reset the variables at the DATA output.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    stData : ST_CX_ProfilerStruct;  
END_VAR
```

**bBusy**: This output is set at the start of the measuring procedure, and remains set until the time measurement has been completed. Once the bBUSY output has been reset, the latest times are available at the stData output.

**stData**: structure of type [ST\_CX\_ProfilerStruct](ms-xhelp:///?Id=beckhoff-91a3-4e00-8786-a8496df71de5) with the measured times [in µs].

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 | CX (WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
