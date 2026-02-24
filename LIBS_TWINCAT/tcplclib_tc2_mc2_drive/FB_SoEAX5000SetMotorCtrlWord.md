# FB_SoEAX5000SetMotorCtrlWord

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoEAX5000SetMotorCtrlWord

FB\_SoEAX5000SetMotorCtrlWord NetId  T\_AmsNetIDExecute  BOOLTimeout  TIMEForceLock  BOOLForceUnlock  BOOL↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  SercosErrId

With the FB\_SoEAX5000SetMotorCtrlWord function block the ForceLock bit (Bit 0) or the ForceUnlock bit can be set in the Motor Control Word (P-0-0096) to activate or release the brake. Normally the brake is automatically controlled via the Enable of the drive.

With the ForceLock bit, the brake can be activated independently from the Enable, with the ForceUnlock bit, the brake can be released independently from the Enable. In the case of simultaneously set ForceLock and ForceUnlock, ForceLock (Brake activated) has the higher priority.

## VAR\_INPUT

```
VAR_INPUT  
    NetId       : T_AmsNetId := '';  
    Execute     : BOOL;   
    Timeout     : TIME := DEFAULT_ADS_TIMEOUT;  
    ForceLock   : BOOL;  
    ForceUnlock : BOOL;  
END_VAR
```

**NetId**: String containing the AMS network ID of the PC. (type: T\_AmsNetId)

**Execute**: The function block is enabled via a positive edge at this input.

**Timeout**: Maximum time allowed for the execution of the function block.

**ForceLock**: Activates the brake independently of the enable.

**ForceUnlock**: Releases the brake independently of the enable.

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
fbSetMotorCtrlWord : FB_SoEAX5000SetMotorCtrlWord;  
SetMotorCtrlWord   : BOOL;  
ForceLock          : BOOL;  
ForceUnlock        : BOOL;  
(* NcAxis *)  
Axis               : AXIS_REF;   
  
IF SetMotorCtrlWord THEN  
 fbSetMotorCtrlWord(  
    Axis        := Axis,  
    Execute     := TRUE,  
    Timeout     := DEFAULT_ADS_TIMEOUT,  
    ForceLock   := ForceLock,  
    ForceUnlock := ForceUnlock  
 );  
 IF NOT fbSetMotorCtrlWord.Busy THEN  
    fbSetMotorCtrlWord(Axis := Axis, Execute := FALSE);  
    SetMotorCtrlWord := FALSE;  
 END_IF  
END_IF
```
