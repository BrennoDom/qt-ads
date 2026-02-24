# Interior Automation

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Third-party function blocks](ms-xhelp:///?Id=beckhoff-3be5-46f6-9609-796403dd277e)
5. Interior Automation

# Interior Automation

The Interior Automation company has defined its own DALI commands for PIR sensors. These commands extend beyond the possible DALI commands in accordance with the IEC 62386 standard. Please contact Interior Automation for a more detailed description of the commands.

## Function blocks

|  | Description |
| --- | --- |
| [FB\_DALIV2IAPIR](ms-xhelp:///?Id=beckhoff-fdd1-4f66-b1c9-b98be6b1c5c4) | This function block cyclically reads the status of an IA PIR sensor and scales the measured brightness and detected presence based on the received value. |
| **FB\_DALIV2IAPIRPhysicalIndicatorOff** | Deactivates the red LED. |
| **FB\_DALIV2IAPIRPhysicalIndicatorOn** | Activates the red LED. |
| **FB\_DALIV2IAPIRQueryExtendedVersion** | Reads the software version number. |
| **FB\_DALIV2IAPIRQueryFlags** | Reads the properties. |
| **FB\_DALIV2IAPIRQuerySensitivity** | Reads the sensor sensitivity. |
| **FB\_DALIV2IAPIRQueryTimeout** | Reads the time-out. |
| **FB\_DALIV2IAPIRStartIdentification** | Makes the green LED flash for 10 seconds. |
| **FB\_DALIV2IAPIRStoreDTRAsFlags** | Saves the data in the Data Transfer Register (DTR) as properties. |
| **FB\_DALIV2IAPIRStoreDTRAsSensitivity** | Saves the data in the Data Transfer Register (DTR) as sensor sensitivity. |
| **FB\_DALIV2IAPIRStoreDTRAsTimeout** | Saves the data in the Data Transfer Register (DTR) as Time-out. |

|  |  |
| --- | --- |
| 25660991 | These commands belong to the application-related expansion commands for DALI devices. They function only if they are preceded by the *Enable Device Type 128* command, which can be sent with the [FB\_DALIV2EnableDeviceType()](ms-xhelp:///?Id=beckhoff-e277-46a4-85ba-43a8cbcb1cb1) function block. The *Enable Device Type 128* command is internally placed automatically before all application-related expansion commands for DALI devices. |

Further Information

* [FB\_DALIV2IAPIR](ms-xhelp:///?Id=beckhoff-fdd1-4f66-b1c9-b98be6b1c5c4)

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
