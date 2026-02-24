# Overview

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. Overview

# Overview

|  |  |
| --- | --- |
| 46808346 | The Tc2\_Drive library should no longer be used in newer projects. Please use the Tc2\_MC2\_Drive library instead (see documentation [TwinCAT 3 PLC Lib Tc2\_MC2\_Drive](ms-xhelp:///?Id=beckhoff-4b94-4c92-a9c4-2eef4688f69f)). |

The Tc2\_Drive library includes functions and function blocks for SoE drives that access the drive via a drive reference.

## Drive libraries

The three drive libraries Tc2\_Drive, Tc2\_NcDrive and Tc2\_MC2\_Drive were developed for different functional purposes, but are almost identical in their functionality. The function blocks of the libraries Tc2\_NcDrive and Tc\_MC2\_Drive form wrapper function blocks around the function blocks of the Tc2\_Drive library.

| Drive library | Use | Access to the drive | Note |
| --- | --- | --- | --- |
| **Tc2\_Drive**  See documentation [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787) | Use the Tc2\_Drive library if you use the drive entirely from the PLC (i.e. without NC). | The drive is accessed via a drive reference. Within the library, the ST\_DriveRef structure is used for this with the NetID as a string. For linking purposes, a structure called ST\_PlcDriveRef is also provided with the NetID as a byte array.  (See [Drive reference ST\_DriveRef](ms-xhelp:///?Id=beckhoff-10c1-4dda-960a-319949064829)) | If you want to access parameters in the drive for which no special function block has been implemented, use the function blocks FB\_SoERead\_ByDriveRef and FB\_SoEWrite\_ByDriveRef. These function blocks are implemented in the PLC Lib Tc2\_EtherCAT in the SoE Interface folder. |
| **Tc2\_NcDrive**  See documentation [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354) | Use the Tc2\_NcDrive library if you are using the drive via the NC with the Tc2\_Nc libraries. | The drive is accessed via the NC axis structure (NC\_TO\_PLC). The function blocks of the Tc2\_NcDrive library independently determine the access data to the drive (NetID, address and channel number) via the NC axis ID from the NC axis structure. | If you want to access parameters in the drive for which no special function block has been implemented, use the function blocks FB\_SoERead and FB\_SoEWrite. |
| **Tc2\_MC2\_Drive**  See: [TwinCAT 3 PLC Lib Tc2\_MC2\_Drive](ms-xhelp:///?Id=beckhoff-4b94-4c92-a9c4-2eef4688f69f) documentation | Use the Tc2\_MC2\_Drive library if you are using the drive via the NC with the Tc2\_MC2 library. | The drive is accessed via the MC2 axis reference (AXIS\_REF). The function blocks of the Tc2\_MC2\_Drive library independently determine the access data to the drive (NetID, address and channel number) via the NC axis ID from the MC2 axis reference. | If you want to access parameters in the drive for which no special function block has been implemented, use the function blocks FB\_SoERead and FB\_SoEWrite. |

|  |  |
| --- | --- |
| 18621933 | Note the differences when using the drive libraries with AX5000 and Bosch Rexroth IndraDrive CS (see [Samples](ms-xhelp:///?Id=beckhoff-fb15-4107-af57-dbb9b974f5f0)) |

## Functions

| Name | Description |
| --- | --- |
| [F\_GetVersionTcDrive](ms-xhelp:///?Id=beckhoff-d0b2-47da-9037-d40cae46d75e) | Reads version information from the PLC library. The function will be replaced by the global structure stLibVersion\_Tc2\_Drive. |
| [F\_ConvWordToSTAX5000C1D](ms-xhelp:///?Id=beckhoff-e067-420d-99be-fbc844cd37d0) | Converts the C1D word (S-0-0011) of the AX5000 to a structure [ST\_AX5000\_C1D for Class 1 diagnosis](ms-xhelp:///?Id=beckhoff-f8f9-40b3-8ab3-59ee6f9756c4) |
| [F\_ConvWordToSTAX5000DriveStatus](ms-xhelp:///?Id=beckhoff-0a9f-483b-811f-f3cb6d2870f3) | Converts the Drive status word (S-0-0135) of the AX5000 into the structure [ST\_AX5000DriveStatus](ms-xhelp:///?Id=beckhoff-da82-4ca2-8a78-5087524fd70a) |
| [F\_ConvWordToSTIndraDriveCsC1D](ms-xhelp:///?Id=beckhoff-4e68-4cea-9880-1650968d86d2) | Converts the C1D word (S-0-0011) of the IndraDrive Cs into the structure [ST\_IndraDriveCs\_C1D for Class 1 diagnosis](ms-xhelp:///?Id=beckhoff-2217-461a-9cc1-73a419519da6) |
| [F\_ConvWordToSTIndraDriveCsDriveStatus](ms-xhelp:///?Id=beckhoff-f5ae-4a00-857a-490762c87af2) | Converts the drive status word (S-0-0135) of the IndraDrive Cs into a structure [ST\_IndraDriveCsDriveStatus](ms-xhelp:///?Id=beckhoff-d04c-4a7a-8886-7ab8941ed1c0) |

## Function blocks

| Name | Description |
| --- | --- |
| [FB\_SoEReset\_ByDriveRef](ms-xhelp:///?Id=beckhoff-a71b-4a9e-80dc-f3d739fc854d) | Resets the drive (S-0-0099). |
| [FB\_SoEWritePassword\_ByDriveRef](ms-xhelp:///?Id=beckhoff-8ef9-4501-80e8-41ad1dc12b07) | Sets the drive password (S-0-0267). |
| [FB\_SoEExecuteCommand\_ByDriveRef](ms-xhelp:///?Id=beckhoff-93d8-4839-983a-dd8038f99488) | Executes a command. |
|  |  |
| [FB\_SoEReadDiagMessage\_ByDriveRef](ms-xhelp:///?Id=beckhoff-bfb6-47d8-98e2-d688a392eb61) | Reads the diagnostic message (S-0-0095). |
| [FB\_SoEReadDiagNumber\_ByDriveRef](ms-xhelp:///?Id=beckhoff-6cfc-4a42-a2ec-5758f2330da0) | Reads the diagnostic number (S-0-0390). |
| [FB\_SoEReadDiagNumberList\_ByDriveRef](ms-xhelp:///?Id=beckhoff-3b44-4481-b672-a8cc2635d53d) | Reads the diagnostic number list (up to 30 entries) (S-0-0375). |
| [FB\_SoEReadClassXDiag\_ByDriveRef](ms-xhelp:///?Id=beckhoff-47dc-470a-90a1-c65d035b9aef) | Reads Class 1 diagnosis (S-0-0011) ... Class 3 diagnosis (S-0-0013). |
|  |  |
| [FB\_SoEWriteCommandControl\_ByDriveRef](ms-xhelp:///?Id=beckhoff-b949-4d42-8429-777de3a0998f) | Sets the Command Control. |
| [FB\_SoEReadCommandState\_ByDriveRef](ms-xhelp:///?Id=beckhoff-6fb1-45e1-a91c-f253b5712c77) | Checks the command status. |
|  |  |
| FB\_SoERead\_ByDriveRef | Reads a parameter (see PLC Lib Tc2\_EtherCAT). |
| FB\_SoEWrite\_ByDriveRef | Writes a parameter (see PLC Lib Tc2\_EtherCAT). |
|  |  |
| [FB\_SoEReadAmplifierTemperature\_ByDriveRef](ms-xhelp:///?Id=beckhoff-41d3-4882-996b-5c402b324a21) | Reads the drive temperature (S-0-0384). |
| [FB\_SoEReadMotorTemperature\_ByDriveRef](ms-xhelp:///?Id=beckhoff-b9ae-417b-9d69-0a354219ec52) | Reads the motor temperature (S-0-0383). |
| [FB\_SoEReadDcBusCurrent\_ByDriveRef](ms-xhelp:///?Id=beckhoff-ef23-4fa5-9ee5-056c20a68609) | Reads the DC bus current (S-0-0381). |
| [FB\_SoEReadDcBusVoltage\_ByDriveRef](ms-xhelp:///?Id=beckhoff-3f92-4481-9c38-4a60cf390d70) | Reads the DC bus voltage (S-0-0380). |
|  |  |
| [FB\_SoEAX5000ReadActMainVoltage\_ByDriveRef](ms-xhelp:///?Id=beckhoff-bef6-484c-9843-f55e79ad5bea) | Reads the mains voltage (P-0-0200). |
| [FB\_SoEAX5000SetMotorCtrlWord\_ByDriveRef](ms-xhelp:///?Id=beckhoff-5dbd-444e-b5d5-dc23e6647f4e) | Sets the Motor Control Word (P-0-0096). |
| [FB\_SoEAX5000FirmwareUpdate\_ByDriveRef](ms-xhelp:///?Id=beckhoff-8df8-40f6-a5d3-9433bb4948cb) | Executes an automatic firmware update for the AX5000. |
|  |  |
| [FB\_CoEDriveEnable](ms-xhelp:///?Id=beckhoff-c6e6-4ad3-a27f-3e197cc0fc2f) | Enables a CoE drive. |
| [FB\_CoEDriveMoveVelocity](ms-xhelp:///?Id=beckhoff-e3ae-44bf-90c3-921f66b078e1) | Generates a simple three-phase velocity profile that can be used to supply a CoE drive directly. |
| [FB\_SoEDriveEnable](ms-xhelp:///?Id=beckhoff-a6d1-4fb1-b4e1-c33b7688077d) | Enables a SoE drive. |
| [FB\_SoEDriveMoveVelocity](ms-xhelp:///?Id=beckhoff-4850-4b6e-8ac5-f3d3df3419aa) | Generates a simple three-phase velocity profile that can be used to supply a SoE drive directly. |

## Requirements

| Component | Version |
| --- | --- |
| TwinCAT on the development computer | 3.1 Build 4016 or higher |
| TwinCAT on the Windows CE-Image | 3.1 Build 4016 or higher |
| TwinCAT on the Windows XP-Image | 3.1 Build 4016 or higher |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
