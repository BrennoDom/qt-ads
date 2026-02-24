# FB_SoEReadDiagNumberList

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-725e-4601-b0fd-30492204b699)
3. [General SoE](ms-xhelp:///?Id=beckhoff-6800-459e-a087-89077ab014ae)
4. [Function blocks for diagnostics](ms-xhelp:///?Id=beckhoff-6eb6-476a-9439-85916a27c0c3)
5. FB\_SoEReadDiagNumberList

# FB\_SoEReadDiagNumberList

![46652504](/tcplclib_tc2_ncdrive/1033/Images/gif/2302083339__Web.gif)

With the FB\_SoEReadDiagNumberList function block a history of the diagnosis numbers can be read out as a list (S-0-0375).

## VAR\_INPUT

```
VAR_INPUT  
    sNetId       : T_AmsNetId := '';  
    bExecute     : BOOL;  
    tTimeout     : TIME := DEFAULT_ADS_TIMEOUT;  
    piDiagNumber : POINTER TO ST_SoE_DiagNumList;  
    iSize        : UDINT;  
END_VAR
```

**sNetId**: String containing the AMS network ID of the PC. (type: T\_AmsNetId)

**bExecute**: The function block is enabled via a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

**piDiagNumber**: Pointer to the list of the last max. 30 error numbers. The list consists of the current and maximum number of bytes in the list as well as the 30 list entries.

**iSize**: Size of the list in bytes (as Sizeof())

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis : NCTOPLC_AXIS_REF;(* reference to NC axis *)  
END_VAR
```

**Axis**: Axis data structure of the type NCTOPLC\_AXIS\_REF

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;  
    iAdsErrId    : UINT;  
    iSercosErrId : UINT;  
    dwAttribute  : DWORD;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until a feedback is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**iSercosErrId**: In the case of a set bError output returns the Sercos error of the last executed command.

**dwAttribute**: Returns the attributes of the Sercos parameter.

## Sample

```
fbDiagNumberList : FB_SoEReadDiagNumberList;  
bDiagNumberList : BOOL;  
stDiagNumberList : ST_SoE_DiagNumList;  
(* NcAxis *)  
stNcToPlc AT %I* : NCTOPLC_AXLESTRUCT;   
  
IF bDiagNumberList THEN  
 fbDiagNumberList(  
    Axis := stNcToPlc,  
    bExecute := TRUE,  
    tTimeout := DEFAULT_ADS_TIMEOUT,  
    piDiagNumber:= ADR(stDiagNumberList),  
    iSize := SIZEOF(stDiagNumberList),  
 );  
 IF NOT fbDiagNumberList.bBusy THEN  
    fbDiagNumberList(Axis := stNcToPlc, bExecute := FALSE);  
    bDiagNumberList := FALSE;  
 END_IF  
END_IF
```

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
