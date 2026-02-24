# FB_SoEReadCommandState

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-725e-4601-b0fd-30492204b699)
3. [General SoE](ms-xhelp:///?Id=beckhoff-6800-459e-a087-89077ab014ae)
4. [Function blocks for commands](ms-xhelp:///?Id=beckhoff-6e8b-469c-bcb0-c9574b914882)
5. FB\_SoEReadCommandState

# FB\_SoEReadCommandState

![31915390](/tcplclib_tc2_ncdrive/1033/Images/gif/2302060171__Web.gif)

With the FB\_SoEReadCommandState function block the command execution can be checked.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId   : T_AmsNetId := '';  
    nIdn     : WORD;  
    bExecute : BOOL;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String, which contains the AMS-Network ID of the PC (Type: T\_AmsNetId).

**Idn**: Parameter number to which FB\_SoEReadCommandState refers, e.g. "P\_0\_IDN + 160" for P-0-0160.

**bExecute**: The function block is enabled via a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis : NCTOPLC_AXIS_REF;(* reference to NC axis *)  
END_VAR
```

**Axis**: Axis data structure of the type NCTOPLC\_AXIS\_REF

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;  
    eCmdState    : E_SoE_CmdState;  
    iAdsErrId    : UINT;  
    iSercosErrId : UINT;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until a feedback is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: In the case of a set bError output returns the ADS error code of the last executed command.

**iSercosErrId**: In the case of a set bError output returns the Sercos error of the last executed command:

**eCmdState**: Returns the command status:

```
eSoE_CmdState_NotSet = 0  
- kein Kommando aktiv  
  
eSoE_CmdState_Set = 1  
- Kommando gesetzt (vorbereitet) aber (noch) nicht ausgeführt  
  
eSoE_CmdState_Executed = 2  
- Kommando wurde ausgeführt  
  
eSoE_CmdState_SetEnabledExecuted = 3   
- Kommando gesetzt (vorbereitet) und ausgeführt  
  
eSoE_CmdState_SetAndInterrupted = 5  
- Kommando wurde gesetzt aber unterbrochen  
  
eSoE_CmdState_SetEnabledNotExecuted = 7  
- Kommandoausführung ist noch aktiv  
  
eSoE_CmdState_Error = 15  
- Fehler bei der Kommandoausführung, es wurde in den Fehlerstate gewechselt
```

## Sample

```
fbReadCommandState : FB_SoEReadCommandState;  
bReadCommandState : BOOL;  
nIdn : WORD;  
eCmdState : E_SoE_CmdState;  
(* NcAxis *)  
stNcToPlc AT %I* : NCTOPLC_AXLESTRUCT;   
  
IF bReadCommandState THEN  
 nIdn := P_0_IDN + 160;  
 fbReadCommandState(  
    Axis := stNcToPlc,  
    bExecute := TRUE,  
    tTimeout := DEFAULT_ADS_TIMEOUT,  
    nIdn := nIdn,  
    eCmdState => eCmdState  
 );  
 IF NOT fbReadCommandState.bBusy THEN  
    fbReadCommandState(Axis := stNcToPlc, bExecute := FALSE);  
    bReadCommandState := FALSE;  
 END_IF  
END_IF
```

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
