# FB_AddRouteEntry

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_AddRouteEntry

![46564252](/tcplclib_tc2_utilities/1033/Images/png/9007199290180875__Web.png)

The function block can be used to add a new AMS router connection (remote route) to a TwinCAT system.

|  |  |
| --- | --- |
| 16425092 | AMS Router connection list  Both communication partners of an AMS Router connection have an AMS Router connection list. These lists contain AMS router connections. The functionality of an AMS router connection is given if both communication partners have entered each other in their connection list. When using the function block, the list of only one communication partner is extended. |

## VAR\_INPUT

```
VAR_INPUT  
    sNetID   : T_AmsNetID;  
    stRoute  : ST_AmsRouteEntry;  
    bExecute : BOOL;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetID**: Here you can specify a string with the network address of the TwinCAT computer on which a new connection is to be added to the AMS router connection list (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**stRoute**: Structure element with parameters for the new connection (type: [ST\_AmsRouteEntry](ms-xhelp:///?Id=beckhoff-4831-40ac-af33-243627af1c25)).

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

On the local TwinCAT system a new AMS router connection is to be added with the connection name: "TEST", TwinCAT network address: "172.16.6.111.1.1", IP address: "172.16.6.111" and transport route: "TCP/IP".

```
PROGRAM P_TEST3  
VAR  
    fbAddRoute  : FB_AddRouteEntry;  
    bExecute    : BOOL;  
    bBusy       : BOOL;  
    bError      : BOOL;  
    nErrID      : UDINT;  
    stRoute     : ST_AmsRouteEntry := ( sName := 'TEST',  
                                        sNetID := '172.16.6.111.1.1',  
                                        sAddress := '172.16.6.111',  
                                        eTransport := eRouteTransport_TCP_IP );  
END_VAR
```

The required connection parameters are already initialized in the declaration part. The new connection is added if a rising edge is detected at the bExecute variable.

![13608105](/tcplclib_tc2_utilities/1033/Images/gif/35443083__en-US__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
