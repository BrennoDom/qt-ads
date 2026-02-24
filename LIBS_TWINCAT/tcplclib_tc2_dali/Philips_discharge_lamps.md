# Philips discharge lamps

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Third-party function blocks](ms-xhelp:///?Id=beckhoff-3be5-46f6-9609-796403dd277e)
5. Philips discharge lamps

# Philips discharge lamps

## Function blocks

The Philips company has defined its own DALI commands for special discharge lamps. These commands extend beyond the possible DALI commands in accordance with the standard IEC 62386 Part 203. However, these commands are only usable for certain Philips control gears. Please contact Philips for a more detailed description of the commands.

| Name | Description |
| --- | --- |
| **FB\_DALIV2PhilipsChangePAEC** | Activates or deactivates the "Application Extended Command Set". |
| **FB\_DALIV2PhilipsQueryCtrlGearOperationTime** | Reads the execution time of the control gear. |
| **FB\_DALIV2PhilipsQueryCtrlGearOvertempLevel** | Reads the overtemperature threshold value of the control gear. |
| **FB\_DALIV2PhilipsQueryCtrlGearOvertempTime** | Reads the overtemperature time of the control gear. |
| **FB\_DALIV2PhilipsQueryCtrlGearTemperature** | Reads the temperature of the control gear. |
| **FB\_DALIV2PhilipsQueryFailureStatus** | Reads the error state. |
| **FB\_DALIV2PhilipsQueryHIDLampLevel** | Reads the lamp status. |
| **FB\_DALIV2PhilipsQueryHIDMaxFadeDownRate** | Reads the maximum fade down rate. |
| **FB\_DALIV2PhilipsQueryHIDMaxFadeUpRate** | Reads the maximum fade up rate. |
| **FB\_DALIV2PhilipsQueryLampType** | Reads the lamp type. |
| **FB\_DALIV2PhilipsQueryLampVoltage** | Reads the lamp voltage. |
| **FB\_DALIV2PhilipsQueryMainsVoltage** | Reads the mains voltage. |
| **FB\_DALIV2PhilipsQueryTimeout** | Reads the time-out. |
| **FB\_DALIV2PhilipsQueryUICByte** | Reads a byte of the UIC. |
| **FB\_DALIV2PhilipsSetDTRAsSegmentAddress** | Saves the data contained in the Data Transfer Register (DTR) to the Segment Address Register. |
| **FB\_DALIV2PhilipsSetTestMode** | Sets the control gear to test mode. |
| **FB\_DALIV2PhilipsStoreDTRAsLampType** | Saves the data in the Data Transfer Register (DTR) as lamp type. |
| **FB\_DALIV2PhilipsStoreDTRAsOvertempLevel** | Saves the data in the Data Transfer Register (DTR) as overtemperature threshold value. |
| **FB\_DALIV2PhilipsStoreDTRAsSegmentAddress** | Saves the data in the Data Transfer Register (DTR) as Segment Address Register. |
| **FB\_DALIV2PhilipsStoreDTRAsTimeout** | Saves the data in the Data Transfer Register (DTR) as Time-out. |

|  |  |
| --- | --- |
| 38379555 | These commands belong to the application-related expansion commands for DALI discharge lamps. They function only if they are preceded by the *Enable Device Type 2* command, which can be sent with the [FB\_DALIV2EnableDeviceType()](ms-xhelp:///?Id=beckhoff-e277-46a4-85ba-43a8cbcb1cb1) function block. The command *Enable Device Type 2* is automatically internally prefixed to all application-related expansion commands for DALI discharge lamps. |

Further Information

* [Variables](ms-xhelp:///?Id=beckhoff-dffb-4f49-b247-ec4d682c5725)

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
