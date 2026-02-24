# Overview

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# Overview

The Tc2\_MC2\_Drive library includes functions and function blocks for   
SoE drives that access the drive by MC2 axis structure (AXIS\_REF).

## Drive libraries

The three drive libraries Tc2\_Drive, Tc2\_NcDrive and Tc2\_MC2\_Drive were developed for different functional purposes, but are almost identical in their functionality. The function blocks of the libraries Tc2\_NcDrive and Tc\_MC2\_Drive form wrapper function blocks around the function blocks of the Tc2\_Drive library.

| Drive library | Use | Access to the drive | Note |
| --- | --- | --- | --- |
| **Tc2\_Drive**  See documentation [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787) | Use the Tc2\_Drive library if you use the drive entirely from the PLC (i.e. without NC). | The drive is accessed via a drive reference. Within the library, the ST\_DriveRef structure is used for this with the NetID as a string. For linking purposes, a structure called ST\_PlcDriveRef is also provided with the NetID as a byte array.  (See Drive reference ST\_DriveRef) | If you want to access parameters in the drive for which no special function block has been implemented, use the function blocks FB\_SoERead\_ByDriveRef and FB\_SoEWrite\_ByDriveRef. These function blocks are implemented in the PLC Lib Tc2\_EtherCAT in the SoE Interface folder. |
| **Tc2\_NcDrive**  See documentation [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354) | Use the Tc2\_NcDrive library if you are using the drive via the NC with the Tc2\_Nc libraries. | The drive is accessed via the NC axis structure (NC\_TO\_PLC). The function blocks of the Tc2\_NcDrive library independently determine the access data to the drive (NetID, address and channel number) via the NC axis ID from the NC axis structure. | If you want to access parameters in the drive for which no special function block has been implemented, use the function blocks FB\_SoERead and FB\_SoEWrite. |
| **Tc2\_MC2\_Drive**  See: [TwinCAT 3 PLC Lib Tc2\_MC2\_Drive](ms-xhelp:///?Id=beckhoff-4b94-4c92-a9c4-2eef4688f69f) documentation | Use the Tc2\_MC2\_Drive library if you are using the drive via the NC with the Tc2\_MC2 library. | The drive is accessed via the MC2 axis reference (AXIS\_REF). The function blocks of the Tc2\_MC2\_Drive library independently determine the access data to the drive (NetID, address and channel number) via the NC axis ID from the MC2 axis reference. | If you want to access parameters in the drive for which no special function block has been implemented, use the function blocks FB\_SoERead and FB\_SoEWrite. |

|  |  |
| --- | --- |
| 10796581 | Note the differences when using the drive libraries with AX5000 and Bosch Rexroth IndraDrive CS (see Samples) |

## Functions

| Name | Description |
| --- | --- |
| [F\_GetVersionTcMc2Drive](ms-xhelp:///?Id=beckhoff-36c6-478c-8f57-f41883a147ad) | Reads version information from the PLC library. The function has been replaced by the global structure stLibVersion\_Tc2\_MC2\_Drive. |
| F\_ConvWordToSTAX5000C1D | Converts the C1D word (S-0-0011) of the AX5000 to an ST\_AX5000\_C1D structure.  See: TwinCAT3 PLC Lib:Tc2\_Drive documentation. |

## Function blocks

| Name | Description |
| --- | --- |
| [FB\_SoEReset](ms-xhelp:///?Id=beckhoff-5d01-40fa-890f-e3eef6e8c99c) | Resets the drive (S-0-0099). |
| [FB\_SoEWritePassword](ms-xhelp:///?Id=beckhoff-f217-49ac-85d5-063a9740f7a2) | Sets the drive password (S-0-0267). |
|  |  |
| [FB\_SoEReadDiagMessage](ms-xhelp:///?Id=beckhoff-46e3-4382-a264-7fd99b700039) | Reads the diagnostic message (S-0-0095). |
| [FB\_SoEReadDiagNumber](ms-xhelp:///?Id=beckhoff-503e-49fd-974b-d8ad0791eb91) | Reads the diagnostic number (S-0-0390). |
| [FB\_SoEReadDiagNumberList](ms-xhelp:///?Id=beckhoff-3abd-4843-940b-23e642ea1279) | Reads the diagnostic number list (up to 30 entries) (S-0-0375). |
| [FB\_SoEReadClassXDiag](ms-xhelp:///?Id=beckhoff-f3bc-4389-8d9d-ddb1dce17a51) | Reads the Class 1 diagnosis (S-0-0011) and the Class 3 diagnosis (S-0-0013). |
|  |  |
| [FB\_SoEExecuteCommand](ms-xhelp:///?Id=beckhoff-0948-4f8a-b323-f1e61fd1566c) | Executes a command. |
| [FB\_SoEWriteCommandControl](ms-xhelp:///?Id=beckhoff-1747-4a51-ae92-fd17efb5089e) | Sets the Command Control. |
| [FB\_SoEReadCommandState](ms-xhelp:///?Id=beckhoff-1787-43ad-9453-d040695e5413) | Checks the command status. |
|  |  |
| [FB\_SoERead](ms-xhelp:///?Id=beckhoff-9f3c-481f-a5d4-cf6d29cb47d0) | Reads a parameter. |
| [FB\_SoEWrite](ms-xhelp:///?Id=beckhoff-a0f5-4177-b2a5-dc9a1beacf16) | Writes a parameter. |
|  |  |
| [FB\_SoEReadAmplifierTemperature](ms-xhelp:///?Id=beckhoff-fdbf-4ffa-8830-959d82b9ffce) | Reads the drive temperature (S-0-0384). |
| [FB\_SoEReadMotorTemperature](ms-xhelp:///?Id=beckhoff-a594-4ec6-b5eb-967aa86c702f) | Reads the motor temperature (S-0-0383). |
| [FB\_SoEReadDcBusCurrent](ms-xhelp:///?Id=beckhoff-aa01-4059-b15f-e186ac1639c8) | Reads the DC bus current (S-0-0381). |
| [FB\_SoEReadDcBusVoltage](ms-xhelp:///?Id=beckhoff-172c-41d3-b81b-607a7afb96cf) | Reads the DC bus voltage (S-0-0380). |
|  |  |
| [FB\_SoEAX5000ReadActMainVoltage](ms-xhelp:///?Id=beckhoff-d887-4ae9-bd7b-55e5e08c05e2) | Reads the mains voltage (P-0-0200). |
| [FB\_SoEAX5000SetMotorCtrlWord](ms-xhelp:///?Id=beckhoff-a7db-488d-9be7-7e68ab6dd817) | Sets the Motor Control Word (P-0-0096). |
| [FB\_SoEAX5000FirmwareUpdate](ms-xhelp:///?Id=beckhoff-0075-4f76-80ed-bcdaa1d42ede) | Executes an automatic firmware update for the AX5000. |
| [FB\_SoEAX5000SetPositionOffset](ms-xhelp:///?Id=beckhoff-b8ce-4251-89b9-56fd89628732) | Saves a position offset. |
| [FB\_SoEAX5000DeletePositionOffset](ms-xhelp:///?Id=beckhoff-f284-43b8-aeac-c68b90738099) | Deletes a position offset. |
|  |  |
| [FB\_CoERead](ms-xhelp:///?Id=beckhoff-968d-4c5d-90fe-b8a45358365b) | Reads a parameter. |
| [FB\_CoEWrite](ms-xhelp:///?Id=beckhoff-f7af-4b95-b7b8-66838e6ac781) | Writes a parameter. |
|  |  |
| [FB\_CoEAX80000SetPositionOffset](ms-xhelp:///?Id=beckhoff-26a1-477d-bc14-f2f01b8c0949) | Saves a position offset. |
| [FB\_CoEAX80000DeletePositionOffset](ms-xhelp:///?Id=beckhoff-2de5-4c72-a11c-ed4e6bc4b668) | Deletes a position offset. |

## Requests

| Component | Version |
| --- | --- |
| TwinCAT on the development computer | 3.1 Build 4016 or higher |
| TwinCAT on the Windows CE-Image | 3.1 Build 4016 or higher |
| TwinCAT on the Windows XP-Image | 3.1 Build 4016 or higher |
