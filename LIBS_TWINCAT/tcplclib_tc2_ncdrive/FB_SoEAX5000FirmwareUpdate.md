# FB_SoEAX5000FirmwareUpdate

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-725e-4601-b0fd-30492204b699)
3. [AX5000 SoE](ms-xhelp:///?Id=beckhoff-61dc-403e-a74f-ad29f9c5ba93)
4. FB\_SoEAX5000FirmwareUpdate

# FB\_SoEAX5000FirmwareUpdate

![63183853](/tcplclib_tc2_ncdrive/1033/Images/gif/2301910411__Web.gif)

With the FB\_SoEAX5000FirmwareUpdate function block the Firmware of the AX5000 can be checked and automatically changed to a given version (Revision and Build) or to the current Build of the configured revision.

For the update:

* the configured slave type is determined, e.g. AX5103-0000-0010
* the current slave is determined with the predefined slave address, e.g. AX5103-0000-0009
* the current slave firmware is determined, e.g. v1.05\_b0009
* a comparison of the configuration and the found slave regarding number of channels, current, revision and firmware is made
* the name of the required firmware file is determined and a search for the file performed
* the firmware update is executed (if necessary)
* the current slave with the predefined slave address is determined again
* the slave is switched to the predefined EtherCAT state

A successful update ends with eFwUpdateState = eFwU\_FwUpdateDone.

If the update is not required, this is signaled via eFwUpdateState = eFwU\_NoFwUpdateRequired.

The firmware update takes place via the specified channel (A=0 or B=1) from stDriveRef. In the case of two-channel devices only one of the two channels can be used. The other channel signals eFwUpdateState = eFwU\_UpdateViaOtherChannelActive or eFwUpdateState = eFwU\_UpdateViaOtherChannel.

During the firmware update (eFwUpdateState = eFwU\_FwUpdateInProgress), iLoadProgress signals the progress in percent.

Note

Faulty update due to interruptions

Interruptions during the update may result in it not being executed or executed incorrectly. Afterwards, the terminal may no longer be usable without the appropriate firmware.

The rules during the update are:

* The PLC and TwinCAT must not be stopped.

* The EtherCAT connection must not be interrupted.

* The AX5000 must not be switched off.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId           : T_AmsNetId;  
    bExecute         : BOOL;      
    sFirmwareVersion : STRING(20); (* version string vx.yy_bnnnn, e.g. "v1.05_b0009" for v1.05 Build 0009*)  
    sFirmwarePath    : T_MaxString; (* drive:\path, e.g. "C:\TwinCAT\Io\TcDriveManager\FirmwarePool" *)  
    iReqEcState      : UINT := EC_DEVICE_STATE_OP;  
    tTimeout         : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: AMS-NetID of the controller (IPC).

**bExecute**: The function block is activated by a positive edge at this input.

**sFirmwareVersion**: Specifies the desired firmware version in the form of vx**.**yy**\_**bnnnn, e.g. "v1**.**05**\_**b0009" for Version v1.05 Build 0009.

Release-Builds:

* "v1.05\_b**00**09"    for a specific build, e.g. v1.05 Build 0009
* "v1.05\_b**00**??"    latest build of a specified version, e.g. v1.05
* "v1.??\_b**00**??"    latest build of a specified main version, e.g. v1
* "v?.??\_b**00**??"    latest build of the latest version
* " "            latest build of the latest version

Custom Firmware-Builds:

* "v1.05\_b**10**09"    for a specific build, e.g. v1.05 Build 0009
* "v1.05\_b**10**??"    latest build of a specified version, e.g. v1.05
* "v1.??\_b**10**??"    latest build of a specified main version, e.g. v1
* "v?.??\_b**10**??"    latest build of the latest version

...

* "v1.05\_b**89**09"    for a specific build, e.g. v1.05 Build 8909
* "v1.05\_b**89**??"    latest build of a specified version, e.g. v1.05
* "v1.??\_b**89**??"    latest build of a specified main version, e.g. v1
* "v?.??\_b**89**??"    latest build of the latest version

Debug-Builds:

* "v1.05\_b**90**09"    for a specific build, e.g. v1.05 Build 9009
* "v1.05\_b**90**??"    latest build of a specified version, e.g. v1.05
* "v1.??\_b**90**??"    latest build of a specified main version, e.g. v1
* "v?.??\_b**90**??"    latest build of the latest version

**sFirmwarePath**: Specifies the path for the firmware pool in which the firmware files are located, e.g. *C:\TwinCAT\Io\TcDriveManager\FirmwarePool*.

**iReqEcState**: Desired EtherCAT state after the update (only if an update is actually being executed). The statuses are defined in PLC Lib Tc2\_EtherCAT as global constants.

**tTimeout**: Since the firmware update for large EtherCAT networks can take longer, only the timeout for individual internal ADS instances is specified here.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis : NCTOPLC_AXLESTRUCT;(* reference to NC axis *)  
END_VAR
```

**Axis**: Axis data structure of the type NCTOPLC\_AXIS\_REF

## VAR\_OUTPUT

```
VAR_OUTPUT  
bBusy                 : BOOL;  
bError                : BOOL;  
iAdsErrId             : UINT;  
iSercosErrId          : UINT;  
iDiagNumber           : UDINT;  
eFwUpdateState        : E_FwUpdateState;  
iLoadProgress         : INT;  
sSelectedFirmwareFile : STRING(MAX_STRING_LENGTH); (* found firmware file, e.g. "AX5yxx_xxxx_-0010_v1_05_b0009.efw" *)  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until a feedback is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: In the case of a set bError output returns the ADS error code of the last executed command.

**iSercosErrId**: In the case of a set bError output returns the Sercos error of the last executed command.

**iDiagNumber**: In the case of a set bError output returns the drive error of the last executed firmware update.

**eFwUpdateState**: Returns the status of the firmware update.

**iLoadProgress**: Returns the progress of the actual firmware update as a percentage.

**sSelectedFirmwareFile**: Displays the name of the firmware file being searched for.

## Sample

```
VAR CONSTANT  
 iNumOfDrives : INT := 2;  
END_VAR  
  
VAR  
 fbFirmwareUpdate : ARRAY [1..iNumOfDrives] OF FB_SoEAX5000FirmwareUpdate;  
 stNcToPlc AT %I* : ARRAY [1..iNumOfDrives] OF NCTOPLC_AXLESTRUCT;  
 sFirmwareVersion : ARRAY [1..iNumOfDrives] OF STRING(20)(* := 2('v1.04_b0002')*);  
 eFwUpdateState : ARRAY [1..iNumOfDrives] OF E_FwUpdateState;  
 sSelectedFirmwareFile: ARRAY [1..iNumOfDrives] OF STRING(MAX_STRING_LENGTH);  
 iUpdateState : INT;  
 bExecute : BOOL;  
 sNetIdIPC : T_AmsNetId := '';  
 sFirmwarePath : T_MaxString := 'C:\TwinCAT\Io\TcDriveManager\FirmwarePool';  
 I : INT;  
 bAnyBusy : BOOL;  
 bAnyError : BOOL;  
END_VAR   
  
CASE iUpdateState OF  
0:  
  IF bExecute THEN  
     iUpdateState := 1;  
  END_IF  
1:  
  FOR I := 1 TO iNumOfDrives DO  
    fbFirmwareUpdate[I](  
     Axis := stNcToPlc[I],  
     bExecute := TRUE,  
     tTimeout := T#15s,  
     sFirmwareVersion := sFirmwareVersion[I],  
     sFirmwarePath := sFirmwarePath,  
     sNetId := sNetIdIPC,  
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
     Axis := stNcToPlc[I],  
     eFwUpdateState => eFwUpdateState[I],  
     sSelectedFirmwareFile => sSelectedFirmwareFile[I],  
    );  
    IF NOT fbFirmwareUpdate[I].bBusy THEN  
      fbFirmwareUpdate[I](bExecute := FALSE, Axis := stNcToPlc[I]);  
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

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
