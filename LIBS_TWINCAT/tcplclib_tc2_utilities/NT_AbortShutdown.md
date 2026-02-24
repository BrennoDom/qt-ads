# NT_AbortShutdown

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# NT\_AbortShutdown

![43884268](/tcplclib_tc2_utilities/1033/Images/png/9007199290356875__Web.png)

The "NT\_AbortShutdown" function block can be used to abort a shutdown command that has previously been called with the [NT\_Shutdown](ms-xhelp:///?Id=beckhoff-c7cf-4bea-8c4d-74084f597347) function block.

When calling the [NT\_Shutdown](ms-xhelp:///?Id=beckhoff-c7cf-4bea-8c4d-74084f597347) function block, a delay period can be given as a parameter. The remaining time is indicated in a message window.

![59414099](/tcplclib_tc2_utilities/1033/Images/gif/35619083__en-US__Web.gif)

Only after the delay time has elapsed is the operating system shut down. During this time, the shutdown process can be interrupted from the PLC with the aid of the "NT\_AbortShutdown" function block.

## VAR\_INPUT

```
VAR_INPUT  
    NETID  : T_AmsNetId;  
    START  : BOOL;  
    TMOUT  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: It is possible here to provide the AmsNetId of the TwinCAT computer on which the shutdown process is to be aborted (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY   : BOOL;  
    ERR    : BOOL;  
    ERRID  : UDINT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the ERR output is set.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7) | Tc2\_Utilities (System) |
