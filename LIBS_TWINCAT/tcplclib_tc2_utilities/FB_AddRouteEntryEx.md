# FB_AddRouteEntryEx

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_AddRouteEntryEx

![55364084](/tcplclib_tc2_utilities/1033/Images/png/9007199290180875__Web.png)

The function block can be used to add a new AMS router connection (remote route) to a TwinCAT system.

The function block supports the AmsNAT functionality with the virtual AmsNetId. This enables creation of routes to two or more controllers that have the same AmsNetId.

|  |  |
| --- | --- |
| 28514710 | AMS router connection list  Both communication partners of an AMS router connection have an AMS router connection list. These lists contain AMS router connections. An AMS router connection is functional when both communication partners have entered each other in their respective connection list. When the function block is used, the list of only one communication partner is extended. |

## VAR\_INPUT

```
VAR_INPUT  
    sNetID   : T_AmsNetID;  
    stRoute  : ST_AmsRouteEntryEx;  
    bExecute : BOOL;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetID**: Here you can specify a string with the network address of the TwinCAT computer on which a new connection is to be added to the AMS router connection list (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**stRoute**: Structural element with parameters for the new connection (type: [ST\_AmsRouteEntryEx](ms-xhelp:///?Id=beckhoff-a05c-4a4a-88db-c9ae8a628e16)).

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the *bError* output is set.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (system)   >= v3.3.41.0 |
