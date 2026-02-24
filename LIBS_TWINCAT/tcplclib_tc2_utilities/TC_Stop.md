# TC_Stop

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# TC\_Stop

![30709455](/tcplclib_tc2_utilities/1033/Images/png/9007199290452875__Web.png)

The function block "TC\_Stop" can be used to stop the TwinCAT system. The function corresponds to the Stop command on the TwinCAT system menu (on the right of the Windows taskbar).

## VAR\_INPUT

```
VAR_INPUT  
    NETID  : T_AmsNetId;  
    STOP   : BOOL;  
    TMOUT  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: It is possible here to provide the AmsNetId of the TwinCAT computer on which the TwinCAT system is to be stopped (type: T\_AmsNetID). If the TwinCAT system to be stopped is on the local computer, an empty string can be entered.

**STOP**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY  : BOOL;  
    ERR   : BOOL;  
    ERRID : UDINT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the ERR output is set.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
