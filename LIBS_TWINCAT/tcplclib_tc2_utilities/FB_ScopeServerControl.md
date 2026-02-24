# FB_ScopeServerControl

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_ScopeServerControl

[This documentation is preliminary and subject to modifications]

![38520254](/tcplclib_tc2_utilities/1033/Images/png/9007199290433675__Web.png)

The function block "FB\_ScopeServerControl" enables the PLC to collect data for subsequent display with TwinCAT Scope 2.

## VAR\_INPUT

```
VAR_INPUT  
   sNetId      : T_AmsNetId;  
   eReqState   : E_ScopeServerState := SCOPE_SERVER_IDLE;  
   sConfigFile : STRING;  
   sSaveFile   : STRING;  
   tTimeout    : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId:** This parameter can be used to specify a string containing the network address of the TwinCAT target system (type: T\_AmsNetID). For the local computer this string may be empty.

**eReqState:**: Requested scope server status (type: [E\_ScopeServerState](ms-xhelp:///?Id=beckhoff-b904-484b-81e5-cd6b825ba6d4)).

**sConfigFile:**: Full path with the name of the configuration file (e.g.: 'C:\TwinCAT\TwinCATScope2\First.sv2' ).

**sSaveFile:** Full path with the name of data file (e.g: 'C:\TwinCAT\TwinCATScope2\First.svd').

**tTimeout:**: Maximum permitted time for the internal ADS commands

## VAR\_OUTPUT

```
VAR_OUTPUT  
   bBusy    : BOOL;  
   bDone    : BOOL  
   bError   : BOOL;  
   nErrorId : UDINT;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bDone:** Is set if the requested status was activated.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrorId**: Shows the error number if the error output bError is set. As a rule this can be an [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) or a [specific error code](ms-xhelp:///?Id=beckhoff-1f2c-46df-a442-f231cb1b5b1c) of this library.

|  |  |
| --- | --- |
| 11137969 | Only one target system is permitted for the configuration file (\*.sv2). |

## State diagram:

![33132859](/tcplclib_tc2_utilities/1033/Images/gif/35695883__en-US__Web.gif)

\*) to reset State Change is always possible

This state diagram shows the possible transitions for eReqState. If there is an other state change requested bError will be set.

## TYPE E\_ScopeServerState

```
TYPE E_ScopeServerState  
(  
   SCOPE_SERVER_IDLE,  
   SCOPE_SERVER_CONNECT,  
   SCOPE_SERVER_START,  
   SCOPE_SERVER_STOP,  
   SCOPE_SERVER_SAVE,  
   SCOPE_SERVER_DISCONNECT,  
   SCOPE_SERVER_RESET  
);
```

**Example:**

Declaration part:

```
FUNCTION_BLOCK FB_ScopeServerSample  
VAR_INPUT  
    bExternalTriggerEvent: BOOL := FALSE;  
END_VAR  
VAR_OUTPUT  
END_VAR  
VAR  
    fbScopeServerControl: FB_ScopeServerControl;  
    eReqState: E_ScopeServerState := SCOPE_SERVER_IDLE;  
    bBusy: BOOL := FALSE;  
    bDone: BOOL := FALSE;  
    bError: BOOL := FALSE;  
    nErrorId: UDINT := 0;  
    fbTimer: TON;  
    bTriggerTimer: BOOL := FALSE;  
    nState: UDINT := 0;  
END_VAR
```

Implementation of the FB\_ScopeServerSample

```
CASE nState OF  
0:  
    eReqState := SCOPE_SERVER_START;  
    nState := 10;  
10:  
    IF fbScopeServerControl.bDone AND bExternalTriggerEvent  
    THEN  
        bTriggerTimer := TRUE;  
        nState := 20;  
    END_IF  
20:  
    IF fbTimer.Q THEN  
        eReqState := SCOPE_SERVER_SAVE;  
        bTriggerTimer := FALSE;  
        nState := 30;  
    END_IF  
30:  
    IF fbScopeServerControl.bDone THEN  
        eReqState := SCOPE_SERVER_DISCONNECT;  
    END_IF  
END_CASE  
fbTimer(IN:=bTriggerTimer, PT:=t#10s);  
fbScopeServerControl( sNetId:= '',  
                      eReqState:= eReqState,  
                      sConfigFile:= 'C:\twinCat\scope\test.sv2',  
                      sSaveFile:= 'C:\twinCat\scope\test.svd',  
                      tTimeout:= t#5s,  
                      bBusy=>bBusy,  
                      bDone=>bDone,  
                      bError=>bError,  
                      nErrorId=>nErrorId);
```

This example demonstrates a long-term recording with the Scope Server.

The existing configuration (Test.sv2) is loaded for this purpose. In this example Test.sv2 was stored in order to run in the ring buffer. Data logging will not finish until FB\_ScopeServerControl becomes active. If an internal trigger event (e.g. an error event) occurs, a timer is started, and 10 seconds later the data are saved in Test.svd. In this way the data file contains information from before and after the trigger event.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
