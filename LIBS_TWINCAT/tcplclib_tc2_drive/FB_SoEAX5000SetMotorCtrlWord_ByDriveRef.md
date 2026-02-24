# FB_SoEAX5000SetMotorCtrlWord_ByDriveRef

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [AX5000 SoE](ms-xhelp:///?Id=beckhoff-7af3-4d18-a767-d35b968cc10f)
4. FB\_SoEAX5000SetMotorCtrlWord\_ByDriveRef

# FB\_SoEAX5000SetMotorCtrlWord\_ByDriveRef

FB\_SoEAX5000SetMotorCtrlWord\_ByDriveRef stDriveRef  ST\_DriveRefbExecute  BOOLtTimeout  TIMEbForceLock  BOOLbForceUnlock  BOOLBOOL  bBusyBOOL  bErrorUINT  iAdsErrIdUINT  iSercosErrId

With the FB\_SoEAX5000SetMotorCtrlWord\_ByDriveRef function block the ForceLock bit (Bit 0) and the ForceUnlock bit in the Motor Control Word (P-0-0096) can be set, in order to activate or release the brake. Normally the brake is automatically controlled via the Enable of the drive.

With the ForceLock-Bit, the brake can be activated independently from the Enable, with the ForceUnlock bit, the brake can be released independently from the Enable. In the case of simultaneously set ForceLock and ForceUnlock, ForceLock (Brake activated) has the higher priority.

## 19357372 Inputs

```
VAR_INPUT  
    stDriveRef   : ST_DriveRef;   
    bExecute     : BOOL;   
    tTimeout     : TIME := DEFAULT_ADS_TIMEOUT;bForceLock   : BOOL;  
    bForceUnlock : BOOL  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **stDriveRef** | ST\_DriveRef | Reference to the drive. The reference to the drive can be linked directly to the PLC in the System Manager. To do this, an instance of the structure ST\_PlcDriveRef must be allocated and the NetID must be converted from the byte array into a string. (Type: [ST\_DriveRef](ms-xhelp:///?Id=beckhoff-10c1-4dda-960a-319949064829)) |
| **bExecute** | BOOL | The function block is enabled via a positive edge at this input. |
| **tTimeout** | TIME | Maximum time allowed for the execution of the function block. |
| **bForceLock** | BOOL | Activates the brake independently of the enable. |
| **bForceUnlock** | BOOL | Releases the brake independently of the enable. |

## 39998624 Outputs

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;  
    iAdsErrId    : UINT;  
    iSercosErrId : UINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **bBusy** | BOOL | This output is set when the function block is activated, and remains set until a feedback is received. |
| **bError** | BOOL | This output is set after the bBusy output has been reset when an error occurs in the transmission of the command. |
| **iAdsErrId** | UINT | In the case of a set bError output returns the ADS error code of the last executed command. |
| **iSercosErrId** | UINT | In the case of a set bError output returns the Sercos error of the last executed command. |

## Sample

```
fbSetMotorCtrlWord : FB_SoEAX5000SetMotorCtrlWord_ByDriveRef;  
bSetMotorCtrlWord  : BOOL;  
bForceLock         : BOOL;  
bForceUnlock       : BOOL;  
stPlcDriveRef AT %I* : ST_PlcDriveRef;  
stDriveRef        : ST_DriveRef;  
  
IF bInit THEN  
   stDriveRef.sNetId := F_CreateAmsNetId(stPlcDriveRef.aNetId);  
   stDriveRef.nSlaveAddr := stPlcDriveRef.nSlaveAddr;  
   stDriveRef.nDriveNo := stPlcDriveRef.nDriveNo;  
   stDriveRef.nDriveType := stPlcDriveRef.nDriveType;  
   IF (stDriveRef.sNetId <> '') AND (stDriveRef.nSlaveAddr <> 0) THEN  
       bInit := FALSE;  
   END_IF  
END_IF  
  
IF bSetMotorCtrlWord AND NOT bInit THEN  
   fbSetMotorCtrlWord(  
      stDriveRef := stDriveRef,  
      bExecute := TRUE,  
      tTimeout := DEFAULT_ADS_TIMEOUT,  
      bForceLock := bForceLock,  
      bForceUnlock:= bForceUnlock  
   );  
   IF NOT fbSetMotorCtrlWord.bBusy THEN  
      fbSetMotorCtrlWord(stDriveRef := stDriveRef, bExecute := FALSE);  
      bSetMotorCtrlWord := FALSE;  
   END_IF  
END_IF
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
