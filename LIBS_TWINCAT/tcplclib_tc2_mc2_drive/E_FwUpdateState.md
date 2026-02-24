# E_FwUpdateState

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# E\_FwUpdateState

The enumeration E\_FwUpdateState describes the state of a firmware update.

```
TYPE E_SoE_CmdState :(  
 (* update states *)  
 eFwU_NoError := 0,  
 eFwU_CheckCfgIdentity,  
 eFwU_CheckSlaveCount,  
 eFwU_CheckFindSlavePos,  
 eFwU_WaitForScan,  
 eFwU_ScanningSlaves,  
 eFwU_CheckScannedIdentity,  
 eFwU_CheckScannedFirmware,  
 eFwU_FindFirmwareFile,  
 eFwU_WaitForUpdate,  
 eFwU_WaitForSlaveState,  
 eFwU_StartFwUpdate,  
 eFwU_FwUpdateInProgress,  
 eFwU_FwUpdateDone,  
 eFwU_NoFwUpdateRequired,  
  
 (* not updating via this channel *)  
 eFwU_UpdateViaOtherChannelActive,  
 eFwU_UpdatedViaOtherChannel,  
  
 (* error states *)  
 eFwU_GetSlaveIdentityError := -1,  
 eFwU_GetSlaveCountError    := -2,  
 eFwU_GetSlaveAddrError     := -3,  
 eFwU_StartScanError        := -4,  
 eFwU_ScanStateError        := -5,  
 eFwU_ScanIdentityError     := -6,  
 eFwU_GetSlaveStateError    := -7,  
 eFwU_ScanFirmwareError     := -8,  
 eFwU_FindFileError         := -9,  
 eFwU_CfgTypeInNoAX5xxx     := -10,  
 eFwU_ScannedTypeInNoAX5xxx := -11,  
 eFwU_ChannelMismatch       := -12,  
 eFwU_ChannelMismatch_1Cfg_2Scanned := -13,  
 eFwU_ChannelMismatch_2Cfg_1Scanned := -14,  
 eFwU_CurrentMismatch       := -15,  
 eFwU_FwUpdateError         := -16,  
 eFwU_ReqSlaveStateError    := -17   
);  
END_TYPE
```

**Update Status**

|  |  |
| --- | --- |
| eFwU\_NoError | Initial state |
| eFwU\_CheckCfgIdentity | Read the configured slave types (number of channels, current, revision). |
| eFwU\_CheckSlaveCount | Determine the configured number of slaves. |
| eFwU\_CheckFindSlavePos | Search for the slave address in the master object directory. |
| eFwU\_WaitForScan | Wait for online scan. |
| eFwU\_ScanningSlaves | Online scan of the slaves. |
| eFwU\_CheckScannedIdentity | Read the scanned slave types (number of channels, current, revision). |
| eFwU\_CheckScannedFirmware | Read the firmware version. |
| eFwU\_FindFirmwareFile | Search for the selected firmware file. |
| eFwU\_WaitForUpdate | Wait for status of the update. |
| eFwU\_WaitForSlaveState | Determine the EtherCAT slave status. |
| eFwU\_StartFwUpdate | Start the firmware update. |
| eFwU\_FwUpdateInProgress | Firmware update active. |
| eFwU\_FwUpdateDone | Firmware update successfully completed. |
| eFwU\_NoFwUpdateRequired | No firmware update required. |
| eFwU\_UpdateViaOtherChannelActive | Update takes place via the other axis channel. |
| eFwU\_UpdatedViaOtherChannel | Update took place via the other axis channel. |

**Update error**

|  |  |
| --- | --- |
| eFwU\_GetSlaveIdentityError | Reading of the configured slave type failed (see iAdsErrId). |
| eFwU\_GetSlaveCountError | Determination of the configured number of slaves failed (see iAdsErrId). |
| eFwU\_GetSlaveAddrError | Search for the slave address in the master object directory failed (see iAdsErrId). |
| eFwU\_StartScanError | Start of the online scan failed (see iAdsErrId). |
| eFwU\_ScanStateError | Online scan failed (see iAdsErrId). |
| eFwU\_ScanIdentityError | Reading of the scanned slave types (number of channels, current, revision) failed (see iAdsErrId). |
| eFwU\_GetSlaveStateError | Determination of the EtherCAT slave status failed (see iAdsErrId). |
| eFwU\_ScanFirmwareError | Reading of the firmware version failed (see iAdsErrId + iSercosErrId). |
| eFwU\_FindFileError | Search for the selected firmware file failed (see iAdsErrId). |
| eFwU\_CfgTypeInNoAX5xxx | The configured slave is not an AX5000. |
| eFwU\_ScannedTypeInNoAX5xxx | The scanned slave is not an AX5000. |
| eFwU\_ChannelMismatch | The number of configured and found channels of the AX5000 do not match. |
| eFwU\_ChannelMismatch\_1Cfg\_2Scanned | Single-channel device configured, but two-channel device found. |
| eFwU\_ChannelMismatch\_2Cfg\_1Scanned | Two-channel device configured, but single-channel device found. |
| eFwU\_CurrentMismatch | AX5000 type does not match in terms of current, e.g. AX5103 (3 A) configured, but AX5106 (6 A) found. |
| eFwU\_FwUpdateError | General update error (see iAdsErrId) |
| eFwU\_ReqSlaveStateError | Switching to the desired EtherCAT status failed. |
