# FB_SoEReadClassXDiag_ByDriveRef

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [General SoE](ms-xhelp:///?Id=beckhoff-b808-4a01-96c8-b03785c2f2dd)
4. [Function blocks for diagnostics](ms-xhelp:///?Id=beckhoff-206c-4f60-aa3f-90a2d55769e8)
5. FB\_SoEReadClassXDiag\_ByDriveRef

# FB\_SoEReadClassXDiag\_ByDriveRef

FB\_SoEReadClassXDiag\_ByDriveRef stDriveRef  ST\_DriveRefbExecute  BOOLiDiagClass  USINTtTimeout  TIMEBOOL  bBusyBOOL  bErrorUINT  iAdsErrIdUINT  iSercosErrIdDWORD  dwAttributeWORD  wClassXDiag

With the FB\_SoEReadClassXDiag\_ByDriveRef function block the current class 1 diagnosis (S-0-0011) ... class 3 diagnosis (S-0-0013) can be read as WORD. For the evaluation of the class 1 diagnosis as structure [ST\_AX5000\_C1D](ms-xhelp:///?Id=beckhoff-f8f9-40b3-8ab3-59ee6f9756c4) there is a conversion function [F\_ConvWordToSTAX5000C1D](ms-xhelp:///?Id=beckhoff-e067-420d-99be-fbc844cd37d0).

## 10026740 Inputs

```
VAR_INPUT  
    stDriveRef : ST_DriveRef;   
    bExecute   : BOOL;   
    iDiagClass : USINT:= 1; (* 1: C1D (S-0-0011) is default, 2: C2D (S-0-0012), 3: C3D (S-0-0013) *)  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **stDriveRef** | ST\_DriveRef | Reference to the drive. The reference to the drive can be linked directly to the PLC in the System Manager. To do this, an instance of the structure ST\_PlcDriveRef must be allocated and the NetID must be converted from the byte array into a string. (Type: [ST\_DriveRef](ms-xhelp:///?Id=beckhoff-10c1-4dda-960a-319949064829)) |
| **bExecute** | BOOL | The function block is enabled via a positive edge at this input. |
| **iDiagClass** | USINT | Specifies which diagnosis should be read. The diagnostics parameters may vary from vendor to vendor. All diagnostics parameters (C1D ... C3D) or all bits are not always implemented in them.  1: Error: Class 1 Diag (S-0-0011)  2: Warnings: Class 2 Diag (S-0-0012)  3: Information: Class 3 Diag (S-0-0013) |
| **tTimeout** | TIME | Maximum time allowed for the execution of the function block. |

## 23131803 Outputs

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;  
    iAdsErrId    : UINT;  
    iSercosErrId : UINT;  
    dwAttribute  : DWORD;  
    wClassXDiag  : WORD;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **bBusy** | BOOL | This output is set when the function block is activated, and remains set until a feedback is received. |
| **bError** | BOOL | This output is set after the bBusy output has been reset when an error occurs in the transmission of the command. |
| **iAdsErrId** | UINT | In the case of a set bError output returns the ADS error code of the last executed command. |
| **iSercosErrId** | UINT | In the case of a set bError output returns the Sercos error of the last executed command. |
| **dwAttribute** | DWORD | Returns the attributes of the Sercos parameter. |
| **wClassXDiag** | WORD | Returns the current Class X diagnosis. |

## Sample

```
fbClassXDiag : FB_SoEReadClassXDiag_ByDriveRef;  
bClassXDiag  : BOOL;  
iDiagClass   : USINT := 1;  
wClass1Diag  : WORD;  
stAX5000C1D  : ST_AX5000_C1D;  
wClass2Diag  : WORD;  
bInit : BOOL := TRUE;  
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
  
IF bClassXDiag AND NOT bInit THEN  
   fbClassXDiag(  
     stDriveRef := stDriveRef,  
     bExecute := TRUE,  
     iDiagClass := iDiagClass,  
     tTimeout   := DEFAULT_ADS_TIMEOUT  
   );  
   IF NOT fbClassXDiag.bBusy THEN  
     fbClassXDiag(stDriveRef := stDriveRef, bExecute := FALSE);  
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

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
