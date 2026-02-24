# TC_CpuUsage

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# TC\_CpuUsage

![40730901](/tcplclib_tc2_utilities/1033/Images/png/9007199290443275__Web.png)

The "TC\_CpuUsage" function block allows the current CPU loading of a TwinCAT system to be determined. This function corresponds to the display of CPU loading in the TwinCAT system menu under the real-time settings.

## VAR\_INPUT

```
VAR_INPUT  
    NETID : T_AmsNetId;  
    START : BOOL;  
    TMOUT : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: It is possible here to provide the AmsNetId of the TwinCAT computer whose CPU loading is to be determined (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY  : BOOL;  
    ERR   : BOOL;  
    ERRID : UDINT;  
    USAGE : UDINT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the ERR output is set.

**USAGE**: The current CPU loading of a TwinCAT system in %.

**Example:**

```
PROGRAM MAIN  
VAR  
    TC_CpuUsage1       : TC_CpuUsage;  
    Start_TC_CpuUsage  : BOOL;  
    TC_CpuUsage_Busy   : BOOL;  
    TC_CpuUsage_Err    : BOOL;  
    TC_CpuUsage_ErrId  : UDINT;  
    CpuUsage           : UDINT;  
END_VAR
```

![31033795](/tcplclib_tc2_utilities/1033/Images/gif/35705483__en-US__Web.gif)

In the example the TwinCAT system is using 35% of the total available CPU computing time.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
