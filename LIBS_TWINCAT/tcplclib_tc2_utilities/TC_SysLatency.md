# TC_SysLatency

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# TC\_SysLatency

![7949639](/tcplclib_tc2_utilities/1033/Images/png/9007199290456075__Web.png)

The function block "TC\_SysLatency" can be used to determine the current and maximum latency time of a TwinCAT system. The function corresponds to the TwinCAT latency time display in the TwinCAT system menu under real-time settings.

## VAR\_INPUT

```
VAR_INPUT  
    NETID  : T_AmsNetId;  
    START  : BOOL;  
    TMOUT  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: This parameter can be used to specify the AmsNetID of the TwinCAT computer whose latency time is to be determined (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY    : BOOL;  
    ERR     : BOOL;  
    ERRID   : UDINT;  
    ACTUAL  : UDINT;  
    MAXIMUM : UDINT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the ERR output is set.

**ACTUAL:** The current latency time of a TwinCAT system in µs.

**MAXIMUM**: The maximum latency time of a TwinCAT system in µs (maximum latency time since the TwinCAT system was last started).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
