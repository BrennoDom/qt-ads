# FB_SoEWriteCommandControl_ByDriveRef

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [General SoE](ms-xhelp:///?Id=beckhoff-b808-4a01-96c8-b03785c2f2dd)
4. [Function blocks for commands](ms-xhelp:///?Id=beckhoff-04fc-4efb-97d4-0e96d6e4ed92)
5. FB\_SoEWriteCommandControl\_ByDriveRef

# FB\_SoEWriteCommandControl\_ByDriveRef

FB\_SoEWriteCommandControl\_ByDriveRef stDriveRef  ST\_DriveRefnIdn  WORDeCmdControl  E\_SoE\_CmdControlbExecute  BOOLtTimeout  TIMEBOOL  bBusyBOOL  bErrorUINT  iAdsErrIdUINT  iSercosErrId

With the FB\_SoEWriteCommandControl\_ByDriveRef function block a command can either be prepared, started or aborted.

## 17450296 Inputs

```
VAR_INPUT  
    stDriveRef : ST_DriveRef;   
    nIdn       : WORD;   
    eCmdControl: E_SoE_CmdControl;  
    bExecute   : BOOL;   
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **stDriveRef** | ST\_DriveRef | Reference to the drive. The reference to the drive can be linked directly to the PLC in the System Manager. To do this, an instance of the structure ST\_PlcDriveRef must be allocated and the NetID must be converted from the byte array into a string. (Type: [ST\_DriveRef](ms-xhelp:///?Id=beckhoff-10c1-4dda-960a-319949064829)) |
| **nIdn** | WORD | Parameter number to which FB\_SoEReadCommandState\_ByDriveRef refers, e.g. "P\_0\_IDN + 23" for P-0-0023. |
| **eCmdControl** | E\_SoE\_CmdControl | Indicates, if a command should be prepared (eSoE\_CmdControl\_Set := 1), executed (eSoE\_CmdControl\_SetAndEnable := 3) or aborted (eSoE\_CmdControl\_Cancel := 0). |
| **bExecute** | BOOL | The function block is enabled via a positive edge at this input. |
| **tTimeout** | TIME | Maximum time (10 s) allowed for the execution of the function block. |

## 22834938 Outputs

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
fbWriteCommandControl : FB_SoEWriteCommandControl_ByDriveRef;  
bWriteCommandControl  : BOOL;  
nIdn                  : WORD;  
eCmdControl           : E_SoE_CmdControl;  
  
stPlcDriveRef AT %I* : ST_PlcDriveRef;  
stDriveRef           : ST_DriveRef;  
IF bInit THEN  
    stDriveRef.sNetId     := F_CreateAmsNetId(stPlcDriveRef.aNetId);  
    stDriveRef.nSlaveAddr := stPlcDriveRef.nSlaveAddr;  
    stDriveRef.nDriveNo   := stPlcDriveRef.nDriveNo;  
    stDriveRef.nDriveType := stPlcDriveRef.nDriveType;  
  
    IF (stDriveRef.sNetId <> '') AND (stDriveRef.nSlaveAddr <> 0) THEN  
        bInit := FALSE;  
    END_IF  
END_IF  
  
IF bWriteCommandControl AND NOT bInit THEN  
    nIdn := P_0_IDN + 160;  
    fbWriteCommandControl(  
        stDriveRef := stDriveRef,  
        bExecute := TRUE,  
        tTimeout := DEFAULT_ADS_TIMEOUT,  
        nIdn := nIdn,  
        eCmdControl := eCmdControl  
    );  
    IF NOT fbWriteCommandControl.bBusy THEN  
        fbWriteCommandControl(stDriveRef := stDriveRef, bExecute := FALSE);  
        bWriteCommandControl := FALSE;  
    END_IF  
END_IF
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
