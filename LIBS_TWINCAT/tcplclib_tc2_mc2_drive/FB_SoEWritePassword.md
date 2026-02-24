# FB_SoEWritePassword

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoEWritePassword

FB\_SoEWritePassword NetId  T\_AmsNetIDExecute  BOOLTimeout  TIMEPassword  ST\_SoE\_String↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  SercosErrId

With the FB\_SoEWritePassword function block (S-0-0267) the drive password can be set.

## VAR\_INPUT

```
VAR_INPUT  
    NetId    : T_AmsNetId := '';  
    Execute  : BOOL;  
    Timeout  : TIME := DEFAULT_ADS_TIMEOUT;  
    Password : ST_SoE_String;  
END_VAR
```

**NetId**: String containing the AMS network ID of the PC. (type: T\_AmsNetId)

**Execute**: The function block is enabled via a positive edge at this input.

**Timeout**: Maximum time allowed for the execution of the function block.

**Password**: Password as a Sercos string.

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
fbWritePassword : FB_SoEWritePassword;  
WritePassword   : BOOL;  
Password        : ST_SoE_String;  
(* NcAxis *)  
Axis            : AXIS_REF;   
  
IF WritePassword THEN  
 fbWritePassword(  
    Axis     := Axis,  
    Execute  := TRUE,  
    Timeout  := DEFAULT_ADS_TIMEOUT,  
    Password := Password  
 );  
 IF NOT fbWritePassword.Busy THEN  
    fbWritePassword(Axis := Axis, Execute := FALSE);  
    WritePassword := FALSE;  
 END_IF  
END_IF 
```
