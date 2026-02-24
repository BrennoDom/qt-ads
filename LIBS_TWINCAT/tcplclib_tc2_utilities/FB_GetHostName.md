# FB_GetHostName

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetHostName

![27220025](/tcplclib_tc2_utilities/1033/Images/png/9007199290251275__Web.png)

This function block can be used to read the host name of a TwinCAT PC.

## VAR\_INPUT

```
VAR_INPUT  
    sNetID   : T_AmsNetId;  
    bExecute : BOOL;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetID**: This parameter can be used to specify the network address of the TwinCAT computer whose host name is to be read (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**bExecute**: the block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded during execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     : BOOL;  
    bError    : BOOL;  
    nErrID    : UDINT;  
    sHostName : T_MaxString;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the *bError* output is set.

**sHostName**: Host name as string (type: T\_MaxString).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7, TC/BSD: TC RT x64, TC OS ARMT2) | Tc2\_Utilities (System) |
