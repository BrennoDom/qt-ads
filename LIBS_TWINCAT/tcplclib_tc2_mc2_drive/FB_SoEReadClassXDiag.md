# FB_SoEReadClassXDiag

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoEReadClassXDiag

FB\_SoEReadClassXDiag NetId  T\_AmsNetIDExecute  BOOLDiagClass  USINTTimeout  TIME↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  SercosErrIdWORD  ClassXDiagDWORD  Attribute

With the function block FB\_SoEReadClassXDiag, the current Class 1 diagnosis (S-0-0011) ... Class 3 diagnosis (S-0-0013) can be read out as WORD. There is the conversion function F\_ConvWordToSTAX5000C1D for the evaluation of the Class 1 diagnosis as a structure ST\_AX5000\_C1D, (see TwinCAT 3 PLC Lib Tc2\_Drive documentation).

## VAR\_INPUT

```
VAR_INPUT  
    NetId     : T_AmsNetId := '';   
    Execute   : BOOL;   
    DiagClass : USINT:= 1; (* 1: C1D (S-0-0011) is default, 2: C2D (S-0-0012), 3: C3D (S-0-0013) *)  
    Timeout   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NetId**: String containing the AMS network ID of the PC. (Type T\_AmsNetId)

**Execute**: The function block is enabled via a positive edge at this input.

**DiagClass**: Specifies which diagnosis should be read. The diagnostics parameters may vary from vendor to vendor. All diagnostics parameters (C1D ... C3D) or all bits are not always implemented in them.

1: Error: Class 1 Diag (S-0-0011)

2: Warnings: Class 2 Diag (S-0-0012)

3: Information messages: Class 3 Diag (S-0-0013)

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
    ClassXDiag  : WORD;  
    Attribute   : DWORD;  
END_VAR
```

**Busy**: This output is set when the function block is activated, and remains set until a feedback is received.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**AdsErrId**: In the case of a set Error output returns the ADS error code of the last executed command.

**SercosErrId**: In the case of a set Error output returns the Sercos error of the last executed command.

**ClassXDiag**: Returns the current Class X diagnosis.

**Attributes**: Returns the attributes of the Sercos parameter.

## Sample

```
fbClassXDiag : FB_SoEReadClassXDiag;  
bClassXDiag  : BOOL;  
DiagClass    : USINT := 1;  
Class1Diag   : WORD;  
stAX5000C1D  : ST_AX5000_C1D;  
Class2Diag   : WORD;  
(* NcAxis *)  
Axis         : AXIS_REF;   
  
IF bClassXDiag THEN  
 fbClassXDiag(  
    Axis      := Axis,  
    Execute   := TRUE,  
    DiagClass := DiagClass,  
    Timeout   := DEFAULT_ADS_TIMEOUT  
 );  
 IF NOT fbClassXDiag.Busy THEN  
    fbClassXDiag(Axis := Axis, Execute := FALSE);  
    bClassXDiag := FALSE;  
    CASE fbClassXDiag.DiagClass OF  
    1:  
     Class1Diag  := fbClassXDiag.ClassXDiag;  
     stAX5000C1D := F_ConvWordToSTAX5000C1D(Class1Diag);  
    2:  
     Class2Diag  := fbClassXDiag.ClassXDiag;  
    END_CASE  
 END_IF  
END_IF 
```
