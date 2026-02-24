# FB_SoEExecuteCommand_ByDriveRef

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [General SoE](ms-xhelp:///?Id=beckhoff-b808-4a01-96c8-b03785c2f2dd)
4. FB\_SoEExecuteCommand\_ByDriveRef

# FB\_SoEExecuteCommand\_ByDriveRef

FB\_SoEExecuteCommand\_ByDriveRef stDriveRef  ST\_DriveRefnIdn  WORDbExecute  BOOLtTimeout  TIMEBOOL  bBusyBOOL  bErrorUINT  iAdsErrIdUINT  iSercosErrId

With the FB\_SoEExecuteCommand\_ByDriveRef function block a command can be executed.

## 49097200 Inputs

```
VAR_INPUT  
    stDriveRef : ST_DriveRef;   
    nIdn       : WORD;   
    bExecute   : BOOL;   
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **stDriveRef** | ST\_DriveRef | Reference to the drive. The reference to the drive can be linked directly to the PLC in the System Manager. To do this, an instance of the structure ST\_PlcDriveRef must be allocated and the NetID must be converted from the byte array into a string. (Type: [ST\_DriveRef](ms-xhelp:///?Id=beckhoff-10c1-4dda-960a-319949064829)) |
| **nIdn** | WORD | Parameter number to which FB\_SoEExecuteCommand\_ByDriveRef refers, e.g. "P\_0\_IDN + 160" for P-0-0160 |
| **bExecute** | BOOL | The function block is enabled via a positive edge at this input. |
| **tTimeout** | TIME | Maximum time (10 s) allowed for the execution of the function block. |

## 39221624 Outputs

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
fbExecuteCommand : FB_SoEExecuteCommand_ByDriveRef;  
bExecuteCommand  : BOOL;  
nIdn : WORD;  
stPlcDriveRef AT %I* : ST_PlcDriveRef;  
stDriveRef : ST_DriveRef;  
  
IF bInit THEN  
   stDriveRef.sNetId := F_CreateAmsNetId(stPlcDriveRef.aNetId);  
   stDriveRef.nSlaveAddr := stPlcDriveRef.nSlaveAddr;  
   stDriveRef.nDriveNo := stPlcDriveRef.nDriveNo;  
   stDriveRef.nDriveType := stPlcDriveRef.nDriveType;  
   IF (stDriveRef.sNetId <> '') AND (stDriveRef.nSlaveAddr <> 0) THEN  
     bInit := FALSE;  
   END_IF  
END_IF  
  
IF bExecuteCommand AND NOT bInit THEN  
  nIdn := P_0_IDN + 160;  
  fbExecuteCommand(  
    stDriveRef := stDriveRef,  
    bExecute := TRUE,  
    tTimeout := DEFAULT_ADS_TIMEOUT,  
    nIdn := nIdn,  
  );  
  IF NOT fbExecuteCommand.bBusy THEN  
    fbExecuteCommand(stDriveRef := stDriveRef, bExecute := FALSE);  
    bExecuteCommand := FALSE;  
  END_IF  
END_IF
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
