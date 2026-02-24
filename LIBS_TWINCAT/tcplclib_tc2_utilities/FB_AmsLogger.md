# FB_AmsLogger

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_AmsLogger

![55305800](/tcplclib_tc2_utilities/1033/Images/png/9007199290187275__Web.png)

The "TwinCAT AMS Logger" is a component of the "TwinCAT ADS Monitor" (..\TwinCAT\AdsMonitor\Logger\**TcAmsLog.exe**). The logger records the AMS/ADS commands on the data storage device. The recording can subsequently be displayed and analyzed with the "TwinCAT AMS ADS Viewer", e.g. for troubleshooting.  
 The FB\_AmsLogger function block can be used to start or stop the recording from a PLC program. The FB\_AmsLogger function block can only communicate with an existing/running instance of TcAmsLog.exe. In other words, TcAmsLog.exe must already have been started, e.g. manually via the Start menu or via the [NT\_StartProcess](ms-xhelp:///?Id=beckhoff-1fb6-43a8-bf24-b62e3196ce0b) block.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId       : T_AmsNetId := '';  
    eMode        : E_AmsLoggerMode := AMSLOGGER_RUN;  
    sCfgFilePath : T_MaxString := '';  
    bExecute     : BOOL;  
    tTimeout     : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: Here you can specify the AmsNetID of the TwinCAT computer on which the status of the "TwinCAT AMS Logger" (type: T\_AmsNetID). An empty string can be specified for the logger on the local computer.

**eMode**: The new status to which the "TwinCAT AMS Logger" is to be set (type: [E\_AmsLoggerMode](ms-xhelp:///?Id=beckhoff-7358-4c88-96a3-cf921784a8cd), start/stop recording).

**sCfgFilePath**: (Optional) path for a "TwinCAT AMS Logger" configuration file (type: T\_MaxString). Currently not yet implemented and reserved for future applications (Please enter an empty string).

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

**bError**: If an error should occur during the transfer of the command, then this output is set once the bBusy output was reset.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the bError output is set.

**Example:**

When the PLC program starts an instance of TcAmsLog.exe is started on a local system. When the bRecord variable is set to TRUE, the recording of the AMS/ADS command is started. It is stopped when the variable is reset to FALSE.

Declaration part:

```
PROGRAM MAIN  
VAR  
    bRecord        : BOOL := TRUE;(* TRUE => start recording, FALSE => stop recording *)  
    fbStartProcess : NT_StartProcess := ( NETID := '', PATHSTR: = 'c:\TwinCAT\AdsMonitor\Logger\TcAmsLog.exe',  
                                      DIRNAME:= 'c:\TwinCAT\AdsMonitor\Logger', COMNDLINE := '', TMOUT := DEFAULT_ADS_TIMEOUT );  
    fbAmsLogger    : FB_AmsLogger := ( sNetID := '', eMode := AMSLOGGER_STOP, sCfgFilePath := '', tTimeout := DEFAULT_ADS_TIMEOUT );  
    state          : BYTE;  
    bBusy          : BOOL;  
    bError         : BOOL;  
    nErrID         : UDINT;  
    eCurrMode      : E_AmsLoggerMode := AMSLOGGER_STOP;(* Current mode/state *)  
    eNewMode       : E_AmsLoggerMode := AMSLOGGER_STOP;(* New mode/state *)  
    timer          : TON := ( PT := T#5s );  
END_VAR
```

Implementation:

```
CASE state OF  
0:(* Start instance of TcAmsLogger.exe *)  
    fbStartProcess( START := FALSE );  
    fbStartProcess( START:= TRUE );  
    state := 1;  
  
1:(* Wait until command execution started *)  
    fbStartProcess( START := FALSE, BUSY=>bBusy, ERR=>bError, ERRID=>nErrID );  
    IF NOT bBusy THEN  
        IF NOT bError THEN(* Success *)  
            state := 2;  
        ELSE(* Error *)  
            state := 100;  
        END_IF  
    END_IF  
  
2:(*Wait until instance started or new AMS logger mode/state set *)  
    timer( IN := TRUE );  
    IF timer.Q THEN  
        timer( IN := FALSE );  
        state := 3;  
    END_IF  
  
3:(* Change TcAmsLog.exe mode/state *)  
    eNewMode := SEL( bRecord, AMSLOGGER_STOP, AMSLOGGER_RUN);  
    IF ( eNewMode <> eCurrMode ) THEN  
        fbAmsLogger( bExecute := FALSE );  
        fbAmsLogger( eMode:= eNewMode, bExecute := TRUE );  
        state := 4;  
    END_IF  
  
4:(* Wait until command execution started *)  
    fbAmsLogger( bExecute := FALSE, bBusy=>bBusy, bError=>bError, nErrID=>nErrID );  
    IF NOT bBusy THEN  
        IF NOT bError THEN(* Success *)  
            eCurrMode := eNewMode;  
            state := 2;  
        ELSE(* Error *)  
            state := 100;  
        END_IF  
    END_IF  
  
100:(* Error state *)  
    ;  
END_CASE
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
