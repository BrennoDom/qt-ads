# FB_SoEReadDiagNumberList

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_SoEReadDiagNumberList

FB\_SoEReadDiagNumberList NetId  T\_AmsNetIDExecute  BOOLTimeout  TIMEpDiagNumber  Pointer To ST\_SoE\_DiagNumListSize  UDINT↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  SercosErrIdDWORD  Attribute

With the FB\_SoEReadDiagNumberList function block a history of the diagnosis numbers can be read out as a list (S-0-0375).

## VAR\_INPUT

```
VAR_INPUT  
    NetId       : T_AmsNetId := '';  
    Execute     : BOOL;  
    Timeout     : TIME := DEFAULT_ADS_TIMEOUT;  
    pDiagNumber : POINTER TO ST_SoE_DiagNumList;  
    Size        : UDINT;  
END_VAR
```

**NetId**: String containing the AMS network ID of the PC. (type: T\_AmsNetId)

**Execute**: The function block is enabled via a positive edge at this input.

**Timeout**: Maximum time allowed for the execution of the function block.

**pDiagNumber**: Pointer to the list of the last max. 30 error numbers. The list consists of the current and maximum number of bytes in the list as well as the 30 list entries.

**Size**: Size of the list in bytes (as Sizeof())

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
    busy        : BOOL;  
    Error       : BOOL;  
    AdsErrId    : UINT;  
    SercosErrId : UINT;  
    Attribute   : DWORD;  
END_VAR
```

**Busy**: This output is set when the function block is activated, and remains set until a feedback is received.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**AdsErrId**: Supplies the ADS error code associated with the most recently executed command if the Error output is set.

**SercosErrId**: In the case of a set Error output returns the Sercos error of the last executed command.

**Attributes**: Returns the attributes of the Sercos parameter.

## Sample

```
fbDiagNumberList : FB_SoEReadDiagNumberList;  
DiagNumberList   : BOOL;  
stDiagNumberList : ST_SoE_DiagNumList;  
(* NcAxis *)  
Axis             : AXIS_REF;   
  
IF DiagNumberList THEN  
 fbDiagNumberList(  
    Axis        := Axis,  
    Execute     := TRUE,  
    Timeout     := DEFAULT_ADS_TIMEOUT,  
    pDiagNumber := ADR(stDiagNumberList),  
    Size        := SIZEOF(stDiagNumberList),  
 );  
 IF NOT fbDiagNumberList.Busy THEN  
    fbDiagNumberList(Axis := Axis, Execute := FALSE);  
    DiagNumberList := FALSE;  
 END_IF  
END_IF
```
