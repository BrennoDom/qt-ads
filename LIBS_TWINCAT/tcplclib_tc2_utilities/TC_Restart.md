# TC_Restart

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# TC\_Restart

![10868702](/tcplclib_tc2_utilities/1033/Images/png/9007199290449675__Web.png)

The function block "TC\_Restart" can be used to restart the TwinCAT system. The function corresponds to the Restart command on the TwinCAT system menu (on the right of the Windows taskbar). Restarting the TwinCAT system involves the TwinCAT system first being stopped, and then immediately started again.

## VAR\_INPUT

```
VAR_INPUT  
    NETID   : T_AmsNetId;  
    RESTART : BOOL;  
    TMOUT   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: It is possible here to provide the AmsNetId of the TwinCAT computer on which the TwinCAT system is to be restarted (type: T\_AmsNetID). If the restart is to take place on the local computer, an empty string can be entered.

**RESTART**: the block is activated by a positive edge at this input.

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
