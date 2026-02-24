# PLC_Stop

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# PLC\_Stop

![46041549](/tcplclib_tc2_utilities/1033/Images/png/9007199290395275__Web.png)

The function block "PLC\_Stop" can be used to stop a PLC run-time system on a TwinCAT computer. The function block can, for instance, be used to stop the PLC on a remote or a local PC.

## VAR\_INPUT

```
VAR_INPUT  
    NETID  : T_AmsNetId;  
    PORT   : T_AmsPort;  
    STOP   : BOOL;  
    TMOUT  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: This parameter can be used to specify the AmsNetID of the TwinCAT computer on which the PLC is to be stopped (type: T\_AmsNetID). If the PLC to be stopped is on the local computer, an empty string can be entered.

**PORT**: Contains the ADS port number of the PLC run-time system that is to be stopped (type: T\_AmsPort).

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
