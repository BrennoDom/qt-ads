# FB_SoEReadDiagNumberList_ByDriveRef

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [General SoE](ms-xhelp:///?Id=beckhoff-b808-4a01-96c8-b03785c2f2dd)
4. [Function blocks for diagnostics](ms-xhelp:///?Id=beckhoff-206c-4f60-aa3f-90a2d55769e8)
5. FB\_SoEReadDiagNumberList\_ByDriveRef

# FB\_SoEReadDiagNumberList\_ByDriveRef

FB\_SoEReadDiagNumberList\_ByDriveRef stDriveRef  ST\_DriveRefbExecute  BOOLtTimeout  TIMEpiDiagNumber  Pointer To ST\_SoE\_DiagNumListiSize  UDINTBOOL  bBusyBOOL  bErrorUINT  iAdsErrIdUINT  iSercosErrIdDWORD  dwAttribute

With the FB\_SoEReadDiagNumberList\_ByDriveRef function block a history of the diagnosis numbers can be read as list (S-0-0375).

## 123786 Inputs

```
VAR_INPUT  
    stDriveRef   : ST_DriveRef;   
    bExecute     : BOOL;   
    tTimeout     : TIME := DEFAULT_ADS_TIMEOUT;  
    piDiagNumber : POINTER TO ST_SoE_DiagNumList;  
    iSize        : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **stDriveRef** | ST\_DriveRef | Reference to the drive. The reference to the drive can be linked directly to the PLC in the System Manager. To do this, an instance of the structure ST\_PlcDriveRef must be allocated and the NetID must be converted from the byte array into a string. (Type: [ST\_DriveRef](ms-xhelp:///?Id=beckhoff-10c1-4dda-960a-319949064829)) |
| **bExecute** | BOOL | The function block is enabled via a positive edge at this input. |
| **tTimeout** | TIME | Maximum time allowed for the execution of the function block. |
| **piDiagNumber** | POINTER TO ST\_SoE\_DiagNumList | Pointer to the list of the last max. 30 error numbers. The list consists of the current and maximum number of bytes in the list as well as the 30 list items. |
| **iSize** | UDINT | Size of the list in bytes (as Sizeof()) |

## 1114082 Outputs

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;  
    iAdsErrId    : UINT;  
    iSercosErrId : UINT;  
    dwAttribute  : DWORD;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **bBusy** | BOOL | This output is set when the function block is activated, and remains set until a feedback is received. |
| **bError** | BOOL | This output is set after the bBusy output has been reset when an error occurs in the transmission of the command. |
| **iAdsErrId** | UINT | In the case of a set bError output returns the ADS error code of the last executed command. |
| **iSercosErrId** | UINT | In the case of a set bError output returns the Sercos error of the last executed command. |
| **dwAttribute** | DWORD | Returns the attributes of the Sercos parameter. |

## Sample

```
fbDiagNumberList : FB_SoEReadDiagNumberList_ByDriveRef;  
bDiagNumberList : BOOL;  
stDiagNumberList : ST_SoE_DiagNumList;  
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
  
IF bDiagNumberList AND NOT bInit THEN  
   fbDiagNumberList(  
     stDriveRef := stDriveRef,  
     bExecute := TRUE,  
     tTimeout := DEFAULT_ADS_TIMEOUT,  
     piDiagNumber:= ADR(stDiagNumberList),  
     iSize := SIZEOF(stDiagNumberList),  
   );  
   IF NOT fbDiagNumberList.bBusy THEN  
      fbDiagNumberList(stDriveRef := stDriveRef, bExecute := FALSE);  
      bDiagNumberList := FALSE;  
   END_IF  
END_IF
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
