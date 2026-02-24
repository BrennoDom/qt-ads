# Knowledge Base

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. Knowledge Base

# Knowledge Base

## Knowledge Base of the TcPlcHydraulics PLC library (from V3.0)

Here you will find a number of answers to recurring questions.

## Topics

| Name | Description |
| --- | --- |
| [Global Constants](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) | Pre-defined error codes, masks for bit queries, ADS codes etc. |
| Setup | Commissioning information |
| [SampleList](ms-xhelp:///?Id=beckhoff-6af5-4f42-8491-7a510b7dd9b7) | Program examples |
| [Ideas Bank](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | Tips and tricks |
| [HMI tool](ms-xhelp:///?Id=beckhoff-608b-4730-aaaf-88380a952170) | The PlcMcManager |

## Problems during library updates

Compilation problems may occur when the library is updated. The reason may be a change of name of one or several function blocks or data types. Such changes are not always avoidable and generally implemented for one of the following reasons:

* Adaptation to the rules of the PLC Open Motion Control definitions.
* Further development of the PLC Open Motion Control definitions.
* Further development the technology provided.
* Adaptation to the technology used, particularly support of further I/O devices.
* Avoidance of name collisions and other compatibility problems with other libraries.

From V3.0 build 22, the library uses TcEtherCAT.LIB for communication via the EtherCAT fieldbus. In older TwinCAT environments this library is not yet available. If the TcPlcHydraulics library is to be used in such an environment, the TcEtherCatDummy.LIB provided should be copied into the project directory and renamed to TcEtherCAT.LIB. This library should then be added to the project **BEFORE** TcPlcHydraulics.LIB.

|  |  |
| --- | --- |
| 37029065 | This procedure must not be used in TwinCAT environments that support EtherCAT. The file provided must **NOT** be used to replace an existing operational TcEtherCAT.LIB. |

There are no functions that require EtherCAT technologies.

|  |  |
| --- | --- |
| 64826129 | The library version used in a project should be copied into the project directory and backed up together with the project. This avoids inadvertent version changes, which could otherwise occur if TwinCAT is updated in the meantime. To update the library, copy the new version directly into the project directory. |

|  |  |
| --- | --- |
| 46564252 | We strongly recommend carrying out a trial compilation of the whole project after a library update. In addition, the mapping should be updated with the System Manager. If the table shown below indicates a change in size in one of the structures, it is essential to check the address assignment. |

|  |  |
| --- | --- |
| 16425092 | If the library is updated to a version that differs not only in the third (build) number, but also in the major and minor version number, it can be assumed that the mappings created by the System Manager are no longer correct. In this case it is imperative to refresh the links. |

| Old name | New name | Reason of for the change |
| --- | --- | --- |
| ST\_TcMcAxInterface | Axis\_Ref\_BkPlcMc | Adaptation to PLC Open Motion Control definitions. |
| ST\_TcPlcMcCamId | MC\_CAM\_ID\_BkPlcMc | Adaptation to PLC Open Motion Control definitions. |
| ST\_TcPlcMcCamRef | MC\_CAM\_REF\_BkPlcMc | Adaptation to PLC Open Motion Control definitions. |
| E\_TcMCDirection | MC\_Direction\_BkPlcMc | Adaptation to PLC Open Motion Control definitions. |
| E\_TcMCStartMode | MC\_StartMode\_BkPlcMc | Adaptation to PLC Open Motion Control definitions. |
| ST\_TcPlcMcEncoderIn | --- | Omitted; task is handled by ST\_TcPlcDeviceInput |
| ST\_TcPlcMcEncoderOut | --- | Omitted; task is handled by ST\_TcPlcDeviceOutput |
| ST\_TcPlcMcDriveIn | --- | Omitted; task is handled by ST\_TcPlcDeviceInput |
| ST\_TcPlcMcDriveOut | --- | Omitted; task is handled by ST\_TcPlcDeviceOutput |
| ST\_TcPlcMcAx2000In | --- | Omitted; task is handled by ST\_TcPlcDeviceInput |
| ST\_TcPlcMcAx2000Out | --- | Omitted; task is handled by ST\_TcPlcDeviceOutput |
| MC\_AxUtiCancelMonitoring\_BkPlcMc | --- | Omitted; redundant due to PLC Open definitions |

## Size of the I/O structures in bytes

| Name | V 2.1.X | from V3.0.0 | from V3.1.0 (proposed) |
| --- | --- | --- | --- |
| ST\_TcPlcMcEncoderIn | 16 | - | - |
| ST\_TcPlcMcEncoderOut | 1 | - | - |
| ST\_TcPlcMcDriveIn | 23 | - | - |
| ST\_TcPlcMcDriveOut | 40 | - | - |
| ST\_TcPlcMcAx2000In | 37 | - | - |
| ST\_TcPlcMcAx2000Out | 26 | - | - |
| [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) | - | 143 | ? |
| [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) | - | 103 | ? |

Further Information

* [FAQs (from V3.0)](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd)
* [Global constants (from V3.0)](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c)
* [Valve](ms-xhelp:///?Id=beckhoff-49b6-4edb-a72d-4a3bbdaa8b74)
* [Electric/hydraulic hybrid axes](ms-xhelp:///?Id=beckhoff-ea06-49ec-8c31-a8096ff18462)
* [Configuration of an axis](ms-xhelp:///?Id=beckhoff-3441-4f47-83c3-f9da89e9665b)
* [The PlcMcManager](ms-xhelp:///?Id=beckhoff-608b-4730-aaaf-88380a952170)
* [Sample programs (from V3.0)](ms-xhelp:///?Id=beckhoff-6af5-4f42-8491-7a510b7dd9b7)
* [Commissioning](ms-xhelp:///?Id=beckhoff-89eb-40cd-9eeb-3b237fbc590a)

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
