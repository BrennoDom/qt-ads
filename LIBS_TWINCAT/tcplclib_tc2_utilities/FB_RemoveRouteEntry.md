# FB_RemoveRouteEntry

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_RemoveRouteEntry

![32787233](/tcplclib_tc2_utilities/1033/Images/png/9007199290315275__Web.png)

The function block can be used to remove an existing connection to a TwinCAT system from the list of AMS router connections (remote routes).

## VAR\_INPUT

```
VAR_INPUT  
    sNetID   : T_AmsNetID;  
    sName    : STRING(MAX_ROUTE_NAME_LEN);  
    bExecute : BOOL;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetID**: Here you can specify a string with the network address of the TwinCAT computer on which the AMS router connection is to be removed (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**sName**: Name of the connection to be removed. The maximum string length is limited by a constant (default: 31 characters).

**bExecute**: the block is activated by a positive edge at this input.

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

**Example:**

The connection with the name "TEST" is to be removed from the list of AMS router connections on the local TwinCAT system. The connection is removed if a rising edge is detected at the bExecute variable.

```
PROGRAM P_TEST2  
VAR  
    fbRemoveRoute  : FB_RemoveRouteEntry;  
    bExecute       : BOOL;  
    bBusy          : BOOL;  
    bError         : BOOL;  
    nErrID         : UDINT;  
END_VAR
```

![26649649](/tcplclib_tc2_utilities/1033/Images/gif/35577483__en-US__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
