# FB_SoEReadCommandState

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoEReadCommandState

FB\_SoEReadCommandState NetId  T\_AmsNetIDIdn  WORDExecute  BOOLTimeout  TIME↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorE\_SoE\_CmdState  CmdStateUINT  AdsErrIdUINT  SercosErrId

With the FB\_SoEReadCommandState function block the command execution can be checked.

## VAR\_INPUT

```
VAR_INPUT  
    NetId   : T_AmsNetId := '';  
    Idn     : WORD;  
    Execute : BOOL;  
    Timeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NetId**: String containing the AMS network ID of the PC. (type: T\_AmsNetId)

**Idn**: Parameter number to which FB\_SoEReadCommandState\_ByDriveRef refers, e.g. "P\_0\_IDNs + 160" for P-0-0160

**Execute**: The function block is enabled via a positive edge at this input.

**Timeout**: Maximum time allowed for the execution of the function block.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
   Axis : AXIS_REF;  
END_VAR
```

**Axis**: The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other things it contains the current status of the axis such as the position, the velocity and the error state.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Busy        : BOOL;  
    Error       : BOOL;  
    CmdState    : E_SoE_CmdState;  
    AdsErrId    : UINT;  
    SercosErrId : UINT;  
END_VAR
```

**Busy**: This output is set when the function block is activated, and remains set until a feedback is received.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**AdsErrId**: In the case of a set Error output returns the ADS error code of the last executed command.

**SercosErrId**: In the case of a set Error output returns the Sercos error of the last executed command.

**CmdState**: Returns the command status:

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
ReadCommandState   : BOOL;  
Idn                : WORD;  
CmdState           : E_SoE_CmdState;  
(* NcAxis *)  
Axis               : AXIS_REF;   
  
IF ReadCommandState THEN  
 Idn := P_0_IDNs + 160;  
 fbReadCommandState(  
    Axis    := Axis,  
    Execute := TRUE,  
    Timeout := DEFAULT_ADS_TIMEOUT,  
    Idn     := Idn,  
    CmdState => CmdState  
 );  
 IF NOT fbReadCommandState.Busy THEN  
    fbReadCommandState(Axis := Axis, Execute := FALSE);  
    ReadCommandState := FALSE;  
 END_IF  
END_IF 
```
