# FB_SoEWriteCommandControl

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoEWriteCommandControl

FB\_SoEWriteCommandControl NetId  T\_AmsNetIDIdn  WORDCmdControl  E\_SoE\_CmdControlExecute  BOOLTimeout  TIME↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  SercosErrId

With the FB\_SoEWriteCommandControl function block a command can be prepared, started or canceled.

## VAR\_INPUT

```
VAR_INPUT  
    NetId      : T_AmsNetId := '';  
    Idn        : WORD;  
    CmdControl : E_SoE_CmdControl;  
    Execute    : BOOL;  
    Timeout    : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NetId**: String, which contains the AMS-Network ID of the PC (Type: T\_AmsNetId).

**Idn**: Parameter number to which FB\_SoEWriteCommandControl refers, e.g. "P\_0\_IDNs + 160" for P-0-0160.

**CmdControl**: Indicates, if a command should be prepared (eSoE\_CmdControl\_Set := 1), executed (eSoE\_CmdControl\_SetAndEnable := 3) or aborted (eSoE\_CmdControl\_Cancel := 0).

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
    AdsErrId    : UINT;  
    SercosErrId : UINT;  
END_VAR
```

**Busy**: This output is set when the function block is activated, and remains set until a feedback is received.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**AdsErrId**: In the case of a set Error output returns the ADS error code of the last executed command.

**SercosErrId**: In the case of a set Error output returns the Sercos error of the last executed command.

## Sample

```
fbWriteCommandControl : FB_SoEWriteCommandControl;  
WriteCommandControl   : BOOL;  
Idn                   : WORD;  
CmdControl            : E_SoE_CmdControl;  
(* NcAxis *)  
Axis                  : AXIS_REF;   
  
IF WriteCommandControl THEN  
 Idn := P_0_IDNs + 160;  
 fbWriteCommandControl(  
    Axis       := Axis,  
    Execute    := TRUE,  
    Timeout    := DEFAULT_ADS_TIMEOUT,  
    Idn        := Idn,  
    CmdControl := CmdControl  
 );  
 IF NOT fbWriteCommandControl.Busy THEN  
    fbWriteCommandControl(Axis := Axis, Execute := FALSE);  
    WriteCommandControl := FALSE;  
 END_IF  
END_IF 
```
