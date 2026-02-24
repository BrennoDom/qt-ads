# FB_SoEReadDiagMessage

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoEReadDiagMessage

FB\_SoEReadDiagMessage NetId  T\_AmsNetIDExecute  BOOLTimeout  TIME↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  SercosErrIdST\_SoE\_String  DiagMessageDWORD  Attribute

With the FB\_SoEReadDiagMessage function block the diagnosis message can be read out as a Sercos string (S-0-0095).

## VAR\_INPUT

```
VAR_INPUT  
    NetId   : T_AmsNetId := '';  
    Execute : BOOL;  
    Timeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NetId**: String containing the AMS network ID of the PC. (Type: T\_AmsNetId)

**Execute**: The function block is enabled via a positive flank at this input.

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
    DiagMessage : ST_SoE_String;  
    Attribute   : DWORD;  
END_VAR
```

**Busy**: This output is set when the function block is activated, and remains set until a feedback is received.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**AdsErrId**: In the case of a set Error output returns the ADS error code of the last executed command.

**SercosErrId**: In the case of a set Error output returns the Sercos error of the last executed command.

**Attributes**: Returns the attributes of the Sercos parameter.

**DiagMessage**: Returns the diagnosis message.

## Sample

```
fbDiagMessage : FB_SoEReadDiagMessage;  
bDiagMessage  : BOOL;  
DiagMessage   : ST_SoE_String;  
(* NcAxis *)  
Axis          : AXIS_REF;   
  
IF bDiagMessage THEN  
 fbDiagMessage(  
    Axis       := Axis,  
    Execute    := TRUE,  
    Timeout    := DEFAULT_ADS_TIMEOUT,  
    DiagMessage => DiagMessage  
 );  
 IF NOT fbDiagMessage.Busy THEN  
    fbDiagMessage(Axis := Axis, Execute := FALSE);  
    bDiagMessage := FALSE;  
 END_IF  
END_IF
```
