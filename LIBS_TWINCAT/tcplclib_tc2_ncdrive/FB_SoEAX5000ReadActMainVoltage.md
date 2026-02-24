# FB_SoEAX5000ReadActMainVoltage

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-725e-4601-b0fd-30492204b699)
3. [AX5000 SoE](ms-xhelp:///?Id=beckhoff-61dc-403e-a74f-ad29f9c5ba93)
4. FB\_SoEAX5000ReadActMainVoltage

# FB\_SoEAX5000ReadActMainVoltage

![57946857](/tcplclib_tc2_ncdrive/1033/Images/gif/2302053131__Web.gif)

With the FB\_SoEAX5000ReadActMainVoltage function block the current peak value of the mains voltage of the AX5000 (P-0-0200) can be read.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId   : T_AmsNetId := '';  
    bExecute : BOOL;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String containing the AMS network ID of the PC. (Type: T\_AmsNetId)

**bExecute**: The function block is enabled via a positive flank at this input.

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
    bBusy              : BOOL;  
    bError             : BOOL;  
    iAdsErrId          : UINT;  
    iSercosErrId       : UINT;  
    dwAttribute        : DWORD;  
    fActualMainVoltage : LREAL;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until a feedback is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: In the case of a set bError output returns the ADS error code of the last executed command.

**iSercosErrId**: In the case of a set bError output returns the Sercos error of the last executed command.

**dwAttribute**: Returns the attributes of the Sercos parameter.

**fActualMainVoltage**: Returns the peak value of the current mains voltage of the AX5000 (e.g. 303.0 corresponds to 303.0 V).

## Sample

```
fbReadActMainVoltage : FB_SoEAX5000ReadActMainVoltage;  
bReadActMainVoltage : BOOL;  
fActualMainVoltage : REAL;  
(* NcAxis *)  
stNcToPlc AT %I* : NCTOPLC_AXLESTRUCT;   
  
IF bReadActMainVoltage THEN  
   fbReadActMainVoltage(  
     Axis := stNcToPlc,  
     bExecute := TRUE,  
     tTimeout := DEFAULT_ADS_TIMEOUT,  
     fActualMainVoltage=>fActualMainVoltage  
   );  
   IF NOT fbReadActMainVoltage.bBusy THEN  
      fbReadActMainVoltage(Axis := stNcToPlc, bExecute := FALSE);  
      bReadActMainVoltage := FALSE;  
   END_IF  
END_IF
```

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
