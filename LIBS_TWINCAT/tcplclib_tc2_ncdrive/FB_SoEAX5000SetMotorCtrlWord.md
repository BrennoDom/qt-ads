# FB_SoEAX5000SetMotorCtrlWord

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-725e-4601-b0fd-30492204b699)
3. [AX5000 SoE](ms-xhelp:///?Id=beckhoff-61dc-403e-a74f-ad29f9c5ba93)
4. FB\_SoEAX5000SetMotorCtrlWord

# FB\_SoEAX5000SetMotorCtrlWord

![51759670](/tcplclib_tc2_ncdrive/1033/Images/gif/2302055051__Web.gif)

With the function block FB\_SoEAX5000SetMotorCtrlWord the ForceLock bit (Bit 0) or the ForceUnlock bit can be set in the Motor Control Word (P-0-0096) to activate or release the brake. Normally the brake is automatically controlled via the Enable of the drive.

With the ForceLock bit, the brake can be activated independently from the Enable, with the ForceUnlock bit, the brake can be released independently from the Enable. In the case of simultaneously set ForceLock and ForceUnlock, ForceLock (Brake activated) has the higher priority.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId       : T_AmsNetId := '';  
    bExecute     : BOOL;   
    tTimeout     : TIME := DEFAULT_ADS_TIMEOUT;  
    bForceLock   : BOOL;  
    bForceUnlock : BOOL;  
END_VAR
```

**sNetId**: String containing the AMS network ID of the PC. (type: T\_AmsNetId)

**bExecute**: The function block is enabled via a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

**bForceLock**: Activates the brake independently of the enable.

**bForceUnlock**: Releases the brake independently of the enable.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis : NCTOPLC_AXIS_REF;(* reference to NC axis *)  
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
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until a feedback is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: In the case of a set bError output returns the ADS error code of the last executed command.

**iSercosErrId**: In the case of a set bError output returns the Sercos error of the last executed command.

## Sample

```
fbSetMotorCtrlWord : FB_SoEAX5000SetMotorCtrlWord;  
bSetMotorCtrlWord : BOOL;  
bForceLock : BOOL;  
bForceUnlock : BOOL;  
(* NcAxis *)  
stNcToPlc AT %I* : NCTOPLC_AXLESTRUCT;   
  
IF bSetMotorCtrlWord THEN  
   fbSetMotorCtrlWord(  
     Axis := stNcToPlc,  
     bExecute := TRUE,  
     tTimeout := DEFAULT_ADS_TIMEOUT,  
     bForceLock := bForceLock,  
     bForceUnlock:= bForceUnlock  
   );  
   IF NOT fbSetMotorCtrlWord.bBusy THEN  
      fbSetMotorCtrlWord(Axis := stNcToPlc, bExecute := FALSE);  
      bSetMotorCtrlWord := FALSE;  
   END_IF  
END_IF 
```

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
