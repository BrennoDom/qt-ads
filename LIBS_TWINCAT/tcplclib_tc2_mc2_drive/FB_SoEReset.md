# FB_SoEReset

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoEReset

FB\_SoEReset NetId  T\_AmsNetIDExecute  BOOLTimeout  TIME↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  SercosErrId

The drive (S-0-0099) can be reset with the function block FB\_SoEReset. In the case of multiple-channel devices if necessary, both channels will have to perform a reset. The timeout time must be 10 s, as the reset can take up to 10 s depending on the error. The flag "Wait For WcState is OK" must be enabled in the advanced EtherCAT settings for the AX5000.

![30060365](/tcplclib_tc2_mc2_drive/1033/Images/png/2353217419__Web.png)

An NC reset will not be performed. If an NC reset is necessary, it can be executed via the function block MC\_Reset from the Tc2\_MC2 PLC library.

## VAR\_INPUT

```
VAR_INPUT  
    NetId   : T_AmsNetId := '';  
    Execute : BOOL;  
    Timeout : TIME := T#10s;  
END_VAR
```

**NetId**: String containing the AMS network ID of the PC. (type: T\_AmsNetId)

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
fbSoEReset : FB_SoEReset;  
SoEReset   : BOOL;  
(* NcAxis *)  
Axis       : AXIS_REF;   
  
IF SoEReset THEN  
 fbSoEReset(  
    Axis    := Axis,  
    Execute := TRUE,  
 );  
 IF NOT fbSoEReset.Busy THEN  
    fbSoEReset(Axis := Axis, Execute := FALSE);  
    SoEReset := FALSE;  
 END_IF  
END_IF 
```
