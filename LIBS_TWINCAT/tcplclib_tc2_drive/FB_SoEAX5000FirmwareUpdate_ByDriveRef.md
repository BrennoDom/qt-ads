# FB_SoEAX5000FirmwareUpdate_ByDriveRef

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [AX5000 SoE](ms-xhelp:///?Id=beckhoff-7af3-4d18-a767-d35b968cc10f)
4. FB\_SoEAX5000FirmwareUpdate\_ByDriveRef

# FB\_SoEAX5000FirmwareUpdate\_ByDriveRef

FB\_SoEAX5000FirmwareUpdate\_ByDriveRef stDriveRef  ST\_DriveRefbExecute  BOOLtTimeout  TIMEsFirmwareVersion  STRING(20)sFirmwarePath  T\_MaxStringsNetIdIPC  T\_AmsNetIDiReqEcState  UINTBOOL  bBusyBOOL  bErrorUINT  iAdsErrIdUINT  iSercosErrIdUDINT  iDiagNumberE\_FwUpdateState  eFwUpdateStateINT  iLoadProgressSTRING(255)  sSelectedFirmwareFile

With the FB\_SoEAX5000FirmwareUpdate\_ByDriveRef function block the Firmware of the AX5000 can be checked and automatically changed to a given version (Revision and Build) or to the current Build of the configured revision.

For the update:

* the configured slave type is determined, e.g. AX5103-0000-0010.
* the current slave with the specified slave address is determined, e.g. AX5103-0000-0009.
* the current slave firmware is determined, e.g. v1.05\_b0009.
* a comparison of the configuration and the found slave regarding number of channels, current, revision and firmware is made.
* the name of the required firmware file is determined and a search for the file performed.
* the firmware update is executed (if necessary).
* the current slave with the specified slave address is determined again.
* the slave is switched to the predefined EtherCAT state.

A successful update ends with eFwUpdateState = eFwU\_FwUpdateDone.

If the update is not required, this is signaled via eFwUpdateState = eFwU\_NoFwUpdateRequired.

The firmware is updated via the specified channel (A = 0 or B = 1) from stDriveRef. In the case of two-channel devices only one of the two channels can be used. The other channel signals eFwUpdateState = eFwU\_UpdateViaOtherChannelActive or eFwUpdateState = eFwU\_UpdateViaOtherChannel.

During the firmware update (eFwUpdateState = eFwU\_FwUpdateInProgress), iLoadProgress signals the progress in percent.

Note

Faulty update due to interruptions

Interruptions during the update may result in it not being executed or executed incorrectly. Afterwards, the drive amplifier may no longer be usable without the appropriate firmware.

The rules during the update are:

* The PLC and TwinCAT must not be stopped.

* The EtherCAT connection must not be interrupted.

* The AX5000 must not be switched off.

## 24443299 Inputs

```
VAR_INPUT  
   stDriveRef       : ST_DriveRef;   
   bExecute         : BOOL;      
   tTimeout         : TIME := DEFAULT_ADS_TIMEOUT;  
   sFirmwareVersion : STRING(20);  (* version string vx_yy_bnnnn, e.g. "v1.05_b0009" for v1.05 Build 0009*)  
   sFirmwarePath    : T_MaxString; (* drive:\path, e.g. "C:\TwinCAT\Io\TcDriveManager\FirmwarePool" *)  
   sNetIdIPC        : T_AmsNetId;  
   iReqEcState      : UINT := EC_DEVICE_STATE_OP;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **stDriveRef** | ST\_DriveRef | Reference to the drive. The reference to the drive can be linked directly to the PLC in the System Manager. To do this, an instance of the structure ST\_PlcDriveRef must be allocated and the NetID must be converted from the byte array into a string. (Type: [ST\_DriveRef](ms-xhelp:///?Id=beckhoff-10c1-4dda-960a-319949064829)) |
| **bExecute** | BOOL | The function block is enabled via a positive edge at this input. |
| **tTimeout** | TIME | Maximum time allowed for the execution of the function block. |
| **sFirmwareVersion** | STRING(20) | Specifies the desired firmware version in the form of vx**.**yy**\_**bnnnn, e.g. „v1**.**05**\_**b0009“ for Version v1.05 Build 0009.  **Release-Builds:**   * "v1.05\_b**00**09" for a specific build, e.g. v1.05 Build 0009 * "v1.05\_b**00**??" latest build of a specified version, e.g. v1.05 * "v1.??\_b**00**??" latest build of a specified main version, e.g. v1 * " " latest build of the latest version   **Customer-specific Firmware-Builds:**   * "v1.05\_b**10**09" for a specific build, e.g. v1.05 Build 0009 * "v1.05\_b**10**??" latest build of a specified version, e.g. v1.05 * "v1.??\_b**10**??" latest build of a specified main version, e.g. v1 * "v?.??\_b**10**??" latest build of the latest version * "v1.05\_b**89**09" for a specific build, e.g. v1.05 Build 8909 * "v1.05\_b**89**??" latest build of a specified version, e.g. v1.05 * "v1.??\_b**89**??" latest build of a specified main version, e.g. v1 * "v?.??\_b**89**??" latest build of the latest version   **Debug-Builds:**   * "v1.05\_b**90**09" for a specific build, e.g. v1.05 Build 9009 * "v1.05\_b**90**??" latest build of a specified version, e.g. v1.05 * "v1.??\_b**90**??" latest build of a specified main version, e.g. v1 * "v?.??\_b**90**??" latest build of the latest version |
| **sFirmwarePath** | T\_MaxString | Specifies the path for the firmware pool in which the firmware files are located, e.g. *C:\TwinCAT\Io\TcDriveManager\FirmwarePool*. |
| **sNetIdIPC** | T\_AmsNetId | AMS-NetID of the controller (IPC) |
| **iReqEcState** | UINT | Desired EtherCAT state after the update, only if an update is actually being executed. The statuses are defined in PLC Lib Tc2\_EtherCAT as global constants. |

## 18663102 Outputs

```
VAR_OUTPUT  
   bBusy                 : BOOL;  
   bError                : BOOL;  
   iAdsErrId             : UINT;  
   iSercosErrId          : UINT;  
   iDiagNumber           : UDINT;  
   eFwUpdateState        : E_FwUpdateState;  
   iLoadProgress         : INT;  
   sSelectedFirmwareFile : STRING(MAX_STRING_LENGTH); (* found firmware file, e.g. "AX5yxx_xxxx_0010_v1_05_b0009.efw" *)  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **bBusy** | BOOL | This output is set when the function block is activated, and remains set until a feedback is received. |
| **bError** | BOOL | This output is set after the bBusy output has been reset when an error occurs in the transmission of the command. |
| **iAdsErrId** | UINT | In the case of a set bError output returns the ADS error code of the last executed command. |
| **iSercosErrId** | UINT | In the case of a set bError output returns the Sercos error of the last executed command. |
| **iDiagNumber** | UDINT | Returns the drive amplifier error of the last firmware update if the bError output is set. |
| **eFwUpdateState** | E\_FwUpdateState | Returns the status of the firmware update (see [E\_FwUpdateState](ms-xhelp:///?Id=beckhoff-b840-490c-b7e9-508c77f0a984)). |
| **iLoadProgress** | INT | Returns the progress of the actual firmware update as a percentage. |
| **sSelectedFirmwareFile** | STRING(MAX\_STRING\_LENGTH) | Displays the name of the firmware file being searched for. |

## Sample

```
VAR CONSTANT  
    iNumOfDrives : INT := 2;  
END_VAR  
  
VAR  
    bInit : ARRAY [1..iNumOfDrives] OF BOOL := 2(TRUE);  
    fbFirmwareUpdate : ARRAY[1..iNumOfDrives] OF FB_SoEAX5000FirmwareUpdate_ByDriveRef;  
    stPlcDriveRef AT %I* : ARRAY[1..iNumOfDrives]OF ST_PlcDriveRef;  
    stDriveRef : ARRAY [1..iNumOfDrives] OF ST_DriveRef;  
    sFirmwareVersion : ARRAY[1..iNumOfDrives] OF STRING(20) := 2('v1.05_b0009');  
    eFwUpdateState : ARRAY[1..iNumOfDrives] OF E_FwUpdateState;  
    sSelectedFirmwareFile: ARRAY [1..iNumOfDrives] OF STRING(MAX_STRING_LENGTH);  
    iUpdateState : INT;  
    bExecute : BOOL;  
    sNetIdIPC : T_AmsNetId := '';  
    sFirmwarePath  : T_MaxString := 'C:\TwinCAT\Io\TcDriveManager\FirmwarePool';  
    I : INT;  
    bAnyInit : BOOL;  
    bAnyBusy : BOOL;  
    bAnyError : BOOL;  
END_VAR  
  
CASE iUpdateState OF  
0:  
  bAnyInit := FALSE;  
  FOR I := 1 TO iNumOfDrives DO  
    IF bInit[I] THEN  
       bAnyInit := TRUE;  
       stDriveRef[I].sNetId := F_CreateAmsNetId(stPlcDriveRef[I].aNetId);  
       stDriveRef[I].nSlaveAddr := stPlcDriveRef[I].nSlaveAddr;  
       stDriveRef[I].nDriveNo   := stPlcDriveRef[I].nDriveNo;  
       stDriveRef[I].nDriveType := stPlcDriveRef[I].nDriveType;  
       IF (stDriveRef[I].sNetId <> '') AND (stDriveRef[I].nSlaveAddr <> 0)  
           THEN bInit[I] := FALSE;  
       END_IF  
    END_IF  
  END_FOR  
  IF NOT bAnyInit AND bExecute THEN  
    iUpdateState := 1;  
  END_IF     
1:  
    FOR I := 1 TO iNumOfDrives DO  
      fbFirmwareUpdate[I](  
        stDriveRef := stDriveRef[I],  
        bExecute := TRUE,  
        tTimeout := T#15s,  
        sFirmwareVersion := sFirmwareVersion[I],  
        sFirmwarePath := sFirmwarePath,  
        sNetIdIPC := sNetIdIPC,  
        iReqEcState := EC_DEVICE_STATE_OP,  
        eFwUpdateState => eFwUpdateState[I],  
      );  
    END_FOR  
    iUpdateState := 2;  
2:  
    bAnyBusy := FALSE;  
    bAnyError:= FALSE;  
    FOR I := 1 TO iNumOfDrives DO  
        fbFirmwareUpdate[I](  
          eFwUpdateState => eFwUpdateState[I],  
          sSelectedFirmwareFile => sSelectedFirmwareFile[I],  
        );  
      IF NOT fbFirmwareUpdate[I].bBusy THEN  
        fbFirmwareUpdate[I](bExecute := FALSE);  
        IF fbFirmwareUpdate[I].bError THEN  
          bAnyError := TRUE;  
        END_IF  
      ELSE  
        bAnyBusy := TRUE;  
      END_IF  
    END_FOR  
    IF NOT bAnyBusy THEN  
      bExecute := FALSE;  
      IF NOT bAnyError THEN  
        iUpdateState := 0; (* OK *)  
      ELSE  
      iUpdateState := 0; (* Error *)  
      END_IF  
    END_IF  
END_CASE
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
