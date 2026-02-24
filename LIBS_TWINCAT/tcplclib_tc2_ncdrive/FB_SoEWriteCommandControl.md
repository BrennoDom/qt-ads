# FB_SoEWriteCommandControl

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-725e-4601-b0fd-30492204b699)
3. [General SoE](ms-xhelp:///?Id=beckhoff-6800-459e-a087-89077ab014ae)
4. [Function blocks for commands](ms-xhelp:///?Id=beckhoff-6e8b-469c-bcb0-c9574b914882)
5. FB\_SoEWriteCommandControl

# FB\_SoEWriteCommandControl

![25915775](/tcplclib_tc2_ncdrive/1033/Images/gif/2302062091__Web.gif)

With the FB\_SoEWriteCommandControl function block a command can be prepared, started or canceled.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId      : T_AmsNetId := '';  
    nIdn        : WORD;  
    eCmdControl : E_SoE_CmdControl;  
    bExecute    : BOOL;  
    tTimeout    : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String, which contains the AMS-Network ID of the PC (Type: T\_AmsNetId).

**nIdn**: Parameter number to which FB\_SoEWriteCommandControl refers, e.g. "P\_0\_IDN + 160" for P-0-0160.

**eCmdControl**: Indicates, if a command should be prepared (eSoE\_CmdControl\_Set := 1), executed (eSoE\_CmdControl\_SetAndEnable := 3) or aborted (eSoE\_CmdControl\_Cancel := 0).

**bExecute**: The function block is enabled via a positive edge at this input.

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
    bbBusy       : BOOL;  
    bError       : BOOL;  
    iAdsErrId    : UINT;  
    iSercosErrId : UINT;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until a feedback is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: In the case of a set bError output returns the ADS error code of the last executed command.

**iSercosErrId**: In the case of a set bError output returns the Sercos error of the last executed command.

## Sample

```
fbWriteCommandControl : FB_SoEWriteCommandControl;  
bWriteCommandControl : BOOL;  
nIdn : WORD;  
eCmdControl : E_SoE_CmdControl;  
(* NcAxis *)  
stNcToPlc AT %I* : NCTOPLC_AXLESTRUCT;   
  
IF bWriteCommandControl THEN  
 nIdn := P_0_IDN + 160;  
 fbWriteCommandControl(  
    Axis := stNcToPlc,  
    bExecute := TRUE,  
    tTimeout := DEFAULT_ADS_TIMEOUT,  
    nIdn := nIdn,  
    eCmdControl := eCmdControl  
 );  
 IF NOT fbWriteCommandControl.bBusy THEN  
    fbWriteCommandControl(Axis := stNcToPlc, bExecute := FALSE);  
    bWriteCommandControl := FALSE;  
 END_IF  
END_IF
```

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
