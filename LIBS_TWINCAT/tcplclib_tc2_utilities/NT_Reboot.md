# NT_Reboot

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# NT\_Reboot

![47812724](/tcplclib_tc2_utilities/1033/Images/png/9007199290366475__Web.png)

The Windows NT operating system can be restarted with the aid of the "NT\_Reboot" function block. The function largely corresponds to the Restart command on the Windows taskbar. A delay before execution of the Restart command can be defined via the DELAY parameter.

## VAR\_INPUT

```
VAR_INPUT  
    NETID  : T_AmsNetId;  
    DELAY  : DWORD;  
    START  : BOOL;  
    TMOUT  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: It is possible here to provide the AmsNetId of the TwinCAT computer that is to be re-booted (type: T\_AmsNetID). If the restart is to take place on the local computer, an empty string can be entered.

**DELAY**: The delay time, in seconds, before the Restart command is executed.

**START**: the block is activated by a positive edge at this input.

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
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7) | Tc2\_Utilities (System) |
