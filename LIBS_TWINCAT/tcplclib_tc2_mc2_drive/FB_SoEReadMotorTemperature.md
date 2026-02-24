# FB_SoEReadMotorTemperature

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoEReadMotorTemperature

FB\_SoEReadMotorTemperature NetId  T\_AmsNetIDExecute  BOOLTimeout  TIME↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  SercosErrIdREAL  MotorTemperatureDWORD  Attribute

With the function block FB\_SoEReadMotorTemperature the temperature of the motor (S-0-0383) can be read. If the motor does not contain a temperature sensor, this is 0.0, i.e. 0.0 °C.

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
    Busy             : BOOL;  
    Error            : BOOL;  
    AdsErrId         : UINT;  
    SercosErrId      : UINT;  
    MotorTemperature : REAL;  
    Attribute        : DWORD;  
END_VAR
```

**Busy**: This output is set upon the activation of the function block and remains set until feedback occurs.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**AdsErrId**: In the case of a set Error output returns the ADS error code of the last executed command.

**SercosErrId**: In the case of a set Error output returns the Sercos error of the last executed command.

**Attributes**: Returns the attributes of the Sercos parameter.

**MotorTemperature**: Returns the motor temperature (e.g. 30.5 corresponds to 30.5 °C). If the motor does not contain a temperature sensor, this is 0.0, i.e. 0.0 °C.

## Sample

```
fbReadMotorTemp  : FB_SoEReadMotorTemperature;  
ReadMotorTemp    : BOOL;  
MotorTemperature : REAL;  
(* NcAxis *)  
Axis             : AXIS_REF;   
  
IF ReadMotorTemp THEN  
 fbReadMotorTemp(  
    Axis            := Axis,  
    Execute         := TRUE,  
    Timeout         := DEFAULT_ADS_TIMEOUT,  
    MotorTemperature => MotorTemperature  
 );  
 IF NOT fbReadMotorTemp.Busy THEN  
    fbReadMotorTemp(Axis := Axis, Execute := FALSE);  
    ReadMotorTemp := FALSE;  
 END_IF  
END_IF 
```
