# FB_SoEReadClassXDiag

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-725e-4601-b0fd-30492204b699)
3. [General SoE](ms-xhelp:///?Id=beckhoff-6800-459e-a087-89077ab014ae)
4. [Function blocks for diagnostics](ms-xhelp:///?Id=beckhoff-6eb6-476a-9439-85916a27c0c3)
5. FB\_SoEReadClassXDiag

# FB\_SoEReadClassXDiag

![17219353](/tcplclib_tc2_ncdrive/1033/Images/gif/2302064779__Web.gif)

With the FB\_SoEReadClassXDiag function block the current class 1 diagnosis (S-0-0011) ... class 3 diagnosis (S-0-0013) can be read as WORD. There is the conversion function F\_ConvWordToSTAX5000C1D for the evaluation of the Class 1 diagnosis as a structure ST\_AX5000\_C1D, (see TwinCAT 3 PLC Lib Tc2\_Drive documentation).

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId := '';   
    bExecute   : BOOL;   
    iDiagClass : USINT:= 1; (* 1: C1D (S-0-0011) is default, 2: C2D (S-0-0012), 3: C3D (S-0-0013) *)  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String containing the AMS network ID of the PC. (Type T\_AmsNetId)

**bExecute**: The function block is enabled via a positive edge at this input.

**iDiagClass**: Specifies which diagnosis should be read. The diagnostics parameters may vary from vendor to vendor. All diagnostics parameters (C1D ... C3D) or all bits are not always implemented in them.

1: Error: Class 1 Diag (S-0-0011)

2: Warnings: Class 2 Diag (S-0-0012)

3: Information messages: Class 3 Diag (S-0-0013)

**tTimeout**: Maximum time allowed for the execution of the function block.

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
    wClassXDiag  : WORD;  
    dwAttribute  : DWORD;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until a feedback is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: In the case of a set bError output returns the ADS error code of the last executed command.

**iSercosErrId**: In the case of a set bError output returns the Sercos error of the last executed command.

**wClassXDiag**: Returns the current Class X diagnosis.

**dwAttribute**: Returns the attributes of the Sercos parameter.

## Sample

```
fbClassXDiag : FB_SoEReadClassXDiag;  
bClassXDiag : BOOL;  
iDiagClass : USINT := 1;  
wClass1Diag : WORD;  
stAX5000C1D : ST_AX5000_C1D;  
wClass2Diag : WORD;  
(* NcAxis *)  
stNcToPlc AT %I* : NCTOPLC_AXLESTRUCT;  
  
IF bClassXDiag THEN  
 fbClassXDiag(  
    Axis := stNcToPlc,  
    bExecute := TRUE,  
    iDiagClass := iDiagClass,  
    tTimeout := DEFAULT_ADS_TIMEOUT  
 );  
 IF NOT fbClassXDiag.bBusy THEN  
    fbClassXDiag(Axis := stNcToPlc, bExecute := FALSE);  
    bClassXDiag := FALSE;  
    CASE fbClassXDiag.iDiagClass OF  
    1:  
     wClass1Diag := fbClassXDiag.wClassXDiag;  
     stAX5000C1D := F_ConvWordToSTAX5000C1D(wClass1Diag);  
    2:  
     wClass2Diag := fbClassXDiag.wClassXDiag;  
    END_CASE  
 END_IF  
END_IF
```

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
