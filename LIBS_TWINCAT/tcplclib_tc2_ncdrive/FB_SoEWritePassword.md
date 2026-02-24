# FB_SoEWritePassword

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-725e-4601-b0fd-30492204b699)
3. [General SoE](ms-xhelp:///?Id=beckhoff-6800-459e-a087-89077ab014ae)
4. FB\_SoEWritePassword

# FB\_SoEWritePassword

![61629280](/tcplclib_tc2_ncdrive/1033/Images/gif/2302088203__Web.gif)

With the FB\_SoEWritePassword function block (S-0-0267) the drive password can be set.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId    : T_AmsNetId := '';  
    bExecute  : BOOL;  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT;  
    sPassword : ST_SoE_String;  
END_VAR
```

**sNetId**: String containing the AMS network ID of the PC. (type: T\_AmsNetId)

**bExecute**: The function block is enabled via a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

**sPassword**: Password as a Sercos string

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis : NCTOPLC_AXIS_REF;(* reference to NC axis *)  
END_VAR
```

**Axis**: Axis data structure of the type NCTOPLC\_AXIS\_REF.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;  
    iAdsErrId    : UINT;  
    iSercosErrId : UINT;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: In the case of a set bError output returns the ADS error code of the last executed command.

**iSercosErrId**: In the case of a set bError output returns the Sercos error of the last executed command.

## Sample

```
fbWritePassword : FB_SoEWritePassword;  
bWritePassword : BOOL;  
sPassword : ST_SoE_String;  
(* NcAxis *)  
stNcToPlc AT %I* : NCTOPLC_AXLESTRUCT;   
  
IF bWritePassword THEN  
  fbWritePassword(  
    Axis := stNcToPlc,  
    bExecute := TRUE,  
    tTimeout := DEFAULT_ADS_TIMEOUT,  
    sPassword := sPassword  
  );  
  IF NOT fbWritePassword.bBusy THEN  
    fbWritePassword(Axis := stNcToPlc, bExecute := FALSE);  
    bWritePassword := FALSE;  
  END_IF  
END_IF 
```

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
