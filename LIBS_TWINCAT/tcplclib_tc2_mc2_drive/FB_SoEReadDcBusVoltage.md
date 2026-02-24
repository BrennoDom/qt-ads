# FB_SoEReadDcBusVoltage

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoEReadDcBusVoltage

FB\_SoEReadDcBusVoltage NetId  T\_AmsNetIDExecute  BOOLTimeout  TIME↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  SercosErrIdREAL  DcBusVoltageDWORD  Attribute

With the FB\_SoEReadDcBusVoltage function block the Dc-Bus voltage of the drive (S-0-0380) can be read.

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
    Busy         : BOOL;  
    Error        : BOOL;  
    AdsErrId     : UINT;  
    SercosErrId  : UINT;  
    DcBusVoltage : REAL;  
    Attribute    : DWORD;  
END_VAR
```

**Busy**: This output is set when the function block is activated, and remains set until a feedback is received.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**AdsErrId**: In the case of a set Error output returns the ADS error code of the last executed command.

**SercosErrId**: In the case of a set Error output returns the Sercos error of the last executed command.

**Attributes**: Returns the attributes of the Sercos parameter.

**DcBusVoltage**: Returns the DC-Bus voltage (e.g. 294.0 corresponds to 294.0 V).

## Sample

```
fbReadDcBusVoltage : FB_SoEReadDcBusVoltage;  
ReadDcBusVoltage   : BOOL;  
DcBusVoltage       : REAL;  
(* NcAxis *)  
Axis               : AXIS_REF;   
  
IF ReadDcBusVoltage THEN  
 fbReadDcBusVoltage(  
    Axis        := Axis,  
    Execute     := TRUE,  
    Timeout     := DEFAULT_ADS_TIMEOUT,  
    DcBusVoltage => DcBusVoltage  
 );  
 IF NOT fbReadDcBusVoltage.Busy THEN  
    fbReadDcBusVoltage(Axis := Axis, Execute := FALSE);  
    ReadDcBusVoltage := FALSE;  
 END_IF  
END_IF 
```
