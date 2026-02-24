# Overview

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. Overview

# Overview

|  |  |
| --- | --- |
| 10493555 | The Tc2\_NcDrive library should no longer be used in newer projects. Please use the Tc2\_MC2\_Drive library instead (see documentation [TwinCAT 3 PLC Lib Tc2\_MC2\_Drive](ms-xhelp:///?Id=beckhoff-4b94-4c92-a9c4-2eef4688f69f)). |

The Tc2\_NcDrive library includes functions and function blocks for SoE drives that access the drive by MC2 axis structure (AXIS\_REF).

## Drive libraries

The three drive libraries Tc2\_Drive, Tc2\_NcDrive and Tc2\_MC2\_Drive were developed for different functional purposes, but are almost identical in their functionality. The function blocks of the libraries Tc2\_NcDrive and Tc\_MC2\_Drive form wrapper function blocks around the function blocks of the Tc2\_Drive library.

| Drive library | Use | Access to the drive | Note |
| --- | --- | --- | --- |
| **Tc2\_Drive**  See documentation [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787) | Use the Tc2\_Drive library if you use the drive entirely from the PLC (i.e. without NC). | The drive is accessed via a drive reference. Within the library, the ST\_DriveRef structure is used for this with the NetID as a string. For linking purposes, a structure called ST\_PlcDriveRef is also provided with the NetID as a byte array.  (See Drive reference ST\_DriveRef) | If you want to access parameters in the drive for which no special function block has been implemented, use the function blocks FB\_SoERead\_ByDriveRef and FB\_SoEWrite\_ByDriveRef. These function blocks are implemented in the PLC Lib Tc2\_EtherCAT in the SoE Interface folder. |
| **Tc2\_NcDrive**  See documentation [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354) | Use the Tc2\_NcDrive library if you are using the drive via the NC with the Tc2\_Nc libraries. | The drive is accessed via the NC axis structure (NC\_TO\_PLC). The function blocks of the Tc2\_NcDrive library independently determine the access data to the drive (NetID, address and channel number) via the NC axis ID from the NC axis structure. | If you want to access parameters in the drive for which no special function block has been implemented, use the function blocks FB\_SoERead and FB\_SoEWrite. |
| **Tc2\_MC2\_Drive**  See: [TwinCAT 3 PLC Lib Tc2\_MC2\_Drive](ms-xhelp:///?Id=beckhoff-4b94-4c92-a9c4-2eef4688f69f) documentation | Use the Tc2\_MC2\_Drive library if you are using the drive via the NC with the Tc2\_MC2 library. | The drive is accessed via the MC2 axis reference (AXIS\_REF). The function blocks of the Tc2\_MC2\_Drive library independently determine the access data to the drive (NetID, address and channel number) via the NC axis ID from the MC2 axis reference. | If you want to access parameters in the drive for which no special function block has been implemented, use the function blocks FB\_SoERead and FB\_SoEWrite. |

|  |  |
| --- | --- |
| 27333131 | Note the differences when using the drive libraries with AX5000 and Bosch Rexroth IndraDrive CS (see Samples) |

## Functions

| Name | Description |
| --- | --- |
| [F\_GetVersionTcNcDrive](ms-xhelp:///?Id=beckhoff-ea2b-424f-b5b3-797f1fc9af2e) | Reads version information from the PLC library. The function has been replaced by the global structure stLibVersion\_Tc2\_NcDrive. |
| F\_ConvWordToSTAX5000C1D | Converts the C1D word (S-0-0011) of the AX5000 to an ST\_AX5000\_C1D structure.  See: TwinCAT 3 PLC Lib documentation: Tc2\_Drive. |

## Function blocks

| Name | Description |
| --- | --- |
| [FB\_SoEReset](ms-xhelp:///?Id=beckhoff-c064-47e9-b664-35dcf2fce908) | Resets the drive (S-0-0099). |
| [FB\_SoEWritePassword](ms-xhelp:///?Id=beckhoff-fef9-4d1a-a08f-d3d5ed564203) | Sets the drive password (S-0-0267). |
|  |  |
| [FB\_SoEReadDiagMessage](ms-xhelp:///?Id=beckhoff-2a2e-4672-9281-b528ff6c007f) | Reads the diagnostic message (S-0-0095). |
| [FB\_SoEReadDiagNumber](ms-xhelp:///?Id=beckhoff-1ac9-40ca-a41c-3b1f50aab62a) | Reads the diagnostic number (S-0-0390). |
| [FB\_SoEReadDiagNumberList](ms-xhelp:///?Id=beckhoff-c63c-41a6-8652-514bc84feb2c) | Reads the diagnostic number list (up to 30 entries) (S-0-0375) |
|  |  |
| [FB\_SoEExecuteCommand](ms-xhelp:///?Id=beckhoff-9b59-4656-a9ea-8dac621132d8) | Executes a command. |
| [FB\_SoEWriteCommandControl](ms-xhelp:///?Id=beckhoff-a892-4f58-a69f-3c18861c4d85) | Sets the Command Control. |
| [FB\_SoEReadCommandState](ms-xhelp:///?Id=beckhoff-e3c4-4ab7-8310-97669843004a) | Checks the command status. |
| [FB\_SoEReadClassXDiag](ms-xhelp:///?Id=beckhoff-1f3a-41fc-8123-92a7eee6ba0e) | Reads Class 1 diagnosis (S-0-0011) ... Class 3 diagnosis (S-0-0013). |
|  |  |
| [FB\_SoERead](ms-xhelp:///?Id=beckhoff-a41d-4079-96c9-96ea2b01797c) | Reads a parameter. |
| [FB\_SoEWrite](ms-xhelp:///?Id=beckhoff-9807-4706-81fe-79d416185609) | Writes a parameter. |
|  |  |
| [FB\_SoEReadAmplifierTemperature](ms-xhelp:///?Id=beckhoff-7cc1-4ef8-8aa7-90bf0e5bdba9) | Reads the drive temperature (S-0-0384). |
| [FB\_SoEReadMotorTemperature](ms-xhelp:///?Id=beckhoff-33d4-4fae-bc10-b17ce9bfe88b) | Reads the motor temperature (S-0-0383). |
| [FB\_SoEReadDcBusCurrent](ms-xhelp:///?Id=beckhoff-c34c-43a7-a802-e432486d04d7) | Reads the DC bus current (S-0-0381). |
| [FB\_SoEReadDcBusVoltage](ms-xhelp:///?Id=beckhoff-cdfa-421e-94ee-76aa139a3c0a) | Reads the DC bus voltage (S-0-0380). |
|  |  |
| [FB\_SoEAX5000ReadActMainVoltage](ms-xhelp:///?Id=beckhoff-d7d6-405b-9e99-c2794ec348c1) | Reads the mains voltage (P-0-0200). |
| [FB\_SoEAX5000SetMotorCtrlWord](ms-xhelp:///?Id=beckhoff-f941-4011-a430-0605c25c655b) | Sets the Motor Control Word (P-0-0096). |
| [FB\_SoEAX5000FirmwareUpdate](ms-xhelp:///?Id=beckhoff-377b-4214-886b-843e28162173) | Executes an automatic firmware update for the AX5000. |
|  |  |
| [FB\_CoERead](ms-xhelp:///?Id=beckhoff-f6d9-40d1-9c38-38915b6aeb8b) | Reads a parameter. |
| [FB\_CoEWrite](ms-xhelp:///?Id=beckhoff-0b0a-4c8f-9ca6-5631df2292b4) | Writes a parameter. |

## Requests

| Component | Version |
| --- | --- |
| TwinCAT on the development computer | 3.1 Build 4016 or higher |
| TwinCAT on the Windows CE-Image | 3.1 Build 4016 or higher |
| TwinCAT on the Windows XP-Image | 3.1 Build 4016 or higher |

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
