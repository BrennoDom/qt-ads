# POUs

## Library
tcplclib_tc2_smi

## Category
Motion Control

# POUs

## Basic commands

| Name | Description |
| --- | --- |
| [FB\_KL6831KL6841Communication](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7) | Reads the SMI commands sequentially from the internal buffer of the PLC library and forwards them to the KL6831/KL6841. |
| [FB\_KL6831KL6841Config](ms-xhelp:///?Id=beckhoff-8ed8-42c9-881b-cfbc88b5802b) | This function block can be used to configure the KL6831/KL6841. |
| [FB\_SMISendSMICommand](ms-xhelp:///?Id=beckhoff-353d-4086-a590-2575ba7b1664) | This function block is for the general sending of an SMI command. |

## Basic commands

| Name | Description |
| --- | --- |
| [FB\_SMIDiagAll](ms-xhelp:///?Id=beckhoff-fd3d-4443-89a5-089a4ecf399a) | Diagnostic telegram is sent. |
| [FB\_SMIDown](ms-xhelp:///?Id=beckhoff-0bab-4cf3-8851-81871aef4fe4) | Motor operation to the lower final position. |
| [FB\_SMIDownStep](ms-xhelp:///?Id=beckhoff-b97d-4db1-8b13-91ffcd906159) | Motor runs downwards by a specified angle. |
| [FB\_SMIPos1](ms-xhelp:///?Id=beckhoff-1783-40af-9366-13f010c82258) | Drives to the fixed position *Pos1* configured on the motor side. |
| [FB\_SMIPos1Read](ms-xhelp:///?Id=beckhoff-177a-4c70-9de2-35e9ca93915c) | Reads the fixed position *Pos1* configured on the motor side. |
| [FB\_SMIPos1Write](ms-xhelp:///?Id=beckhoff-e629-4b9e-8d96-64ab0fdada58) | Writes the fixed position *Pos1* which is configured on the motor side. |
| [FB\_SMIPos2](ms-xhelp:///?Id=beckhoff-a270-49ed-93bd-1576292407d3) | Drives to the fixed position *Pos2* configured on the motor side. |
| [FB\_SMIPos2Read](ms-xhelp:///?Id=beckhoff-d594-403b-8961-5f3f8b8eeae9) | Reads the fixed position *Pos2* configured on the motor side. |
| [FB\_SMIPos2Write](ms-xhelp:///?Id=beckhoff-4d48-4aa1-a643-8e53b769d44b) | Writes the fixed position *Pos2* which is configured on the motor side. |
| [FB\_SMIPosRead](ms-xhelp:///?Id=beckhoff-995e-47f0-90b3-5e1b2db7cbfe) | Reads the current position. |
| [FB\_SMIPosWrite](ms-xhelp:///?Id=beckhoff-a84e-4c71-87df-216863de5da1) | Drives to a position. |
| [FB\_SMIStop](ms-xhelp:///?Id=beckhoff-397a-4301-add4-8a56ec78ab81) | Stops the motor operation. |
| [FB\_SMISyn](ms-xhelp:///?Id=beckhoff-b087-440b-a27d-4e056c7c98ec) | Queries the manufacturer code and drive type. |
| [FB\_SMIUp](ms-xhelp:///?Id=beckhoff-c7b2-45f6-9f77-b3fa0bd7c02d) | Motor operation to the upper final position. |
| [FB\_SMIUpStep](ms-xhelp:///?Id=beckhoff-03f3-4be9-a4a7-4e76c395b615) | Motor operation upwards by a specified angle. |

## Addressing commands

| Name | Description |
| --- | --- |
| [FB\_SMIAddressing](ms-xhelp:///?Id=beckhoff-9403-414a-8dad-6e9bbab3f426) | Addresses SMI devices. |
| [FB\_SMIDiscoverySlaveId](ms-xhelp:///?Id=beckhoff-f9ce-4c1c-99d0-5a987a012161) | Searches for SMI devices by manufacturer code. |
| [FB\_SMISlaveAddrRead](ms-xhelp:///?Id=beckhoff-13c6-4e9e-b5fd-e231d2ec63f8) | Reads the address (0-15) of a drive. |
| [FB\_SMISlaveAddrWrite](ms-xhelp:///?Id=beckhoff-f6d1-41fd-9afc-8406a5fce807) | Writes an address (0-15) to one or more drives. |
| [FB\_SMISlaveIdCompare](ms-xhelp:///?Id=beckhoff-a413-4d40-89b6-25ea972d335a) | Compares a specified slave ID (32-bit key ID) with the slave ID (32-bit key ID) of one or more drives, which is defined on the motor side. |
| [FB\_SMISlaveIdRead](ms-xhelp:///?Id=beckhoff-257c-4aaf-82ef-2b87d72da5ff) | Reads the slave ID (32-bit Key ID). |

## System commands

| Name | Description |
| --- | --- |
| [FB\_SMIParValueReadByte](ms-xhelp:///?Id=beckhoff-8b1b-46b2-a996-70b3ca356dcd) | Reads a byte parameter (1 byte) stored on the motor side. |
| [FB\_SMIParValueReadWord](ms-xhelp:///?Id=beckhoff-2082-4674-aec7-62bf33702184) | Reads a Word parameter (2 bytes) stored on the motor side. |
| [FB\_SMIParValueReadDWord](ms-xhelp:///?Id=beckhoff-77bc-4946-b6e8-83de376b8541) | Reads a DWord parameter (4 bytes) stored on the motor side. |

Further Information

* [Base](ms-xhelp:///?Id=beckhoff-d874-4e92-8448-b73ed76102e9)
* [Basic commands](ms-xhelp:///?Id=beckhoff-ed84-4ca1-8f09-d05844d2e6ed)
* [Addressing commands](ms-xhelp:///?Id=beckhoff-7542-44b7-ab69-ac6e34720675)
* [System commands](ms-xhelp:///?Id=beckhoff-a9b8-401d-acdc-77023b170ba9)
* [Error codes](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7)
