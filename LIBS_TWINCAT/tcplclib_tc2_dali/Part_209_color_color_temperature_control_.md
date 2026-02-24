# Part 209 (color/color temperature control)

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. Part 209 (color/color temperature control)

# Part 209 (color/color temperature control)

|  |  |
| --- | --- |
| The function blocks and variables for lamps for color/color temperature control with DALI interface are described below. All below function blocks described below call 'application-related expansion commands'. According to the DALI standard (IEC 62386) these commands are within the range 224 to 255. Because of the existence of a variety of application-related expansion commands, it is necessary to use the [FB\_DALIV2EnableDeviceType()](ms-xhelp:///?Id=beckhoff-e277-46a4-85ba-43a8cbcb1cb1) function block to specify which type of control gears (emergency lighting, discharge lamps, ...) should react to the extension commands. A precise description of the individual DALI commands and the variables for lamps for color/color temperature control with DALI interface can be found in IEC 62386 part 209. | 6606172 |

## Function blocks

| Name | Description |
| --- | --- |
| [FB\_DALIV2Activate](ms-xhelp:///?Id=beckhoff-7bd8-4669-a55a-8ae3fa04d1da) | Starts a new cross-fade. A running cross-fade will be ended beforehand. |
| [FB\_DALIV2AssignColourToLinkedChannel](ms-xhelp:///?Id=beckhoff-0216-4595-a506-61d607934432) | Linked output channels are assigned to the defined color. |
| [FB\_DALIV2ColourTemperatureTcStepCooler](ms-xhelp:///?Id=beckhoff-2fe2-43bd-81e9-d1173d761c1f) | The value [COLOR TEMPERATURE Tc](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) is decremented by 1 Mirek. |
| [FB\_DALIV2ColourTemperatureTcStepWarmer](ms-xhelp:///?Id=beckhoff-59aa-4d76-8207-ae34da7e06d3) | The value [COLOR TEMPERATURE Tc](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) is incremented by 1 Mirek. |
| [FB\_DALIV2CopyReportToTemporary](ms-xhelp:///?Id=beckhoff-77d5-4e56-89a3-1093fd3dabca) | The color settings report is copied to the temporary color settings. |
| [FB\_DALIV2QueryAssignedColour](ms-xhelp:///?Id=beckhoff-3a56-4296-baff-3d2179e249fe) | Reads the assigned color of the specified output channel. |
| [FB\_DALIV2QueryColourStatus](ms-xhelp:///?Id=beckhoff-ed62-4911-ad94-6cfea37f52ce) | The [COLOR STATUS](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable is read from the control gear. |
| [FB\_DALIV2QueryColourTypeFeatures](ms-xhelp:///?Id=beckhoff-4f79-476f-a608-43ca7221cfc5) | The color representations supported by the control gear are read out. |
| [FB\_DALIV2QueryColourValue](ms-xhelp:///?Id=beckhoff-bf54-40b6-b294-0a21b4b8b625) | The specified color value is read from the control gear. |
| [FB\_DALIV2QueryGearFeaturesStatus](ms-xhelp:///?Id=beckhoff-3ae6-44b0-b294-75a1916df3fa) | The [GEAR FEATURES/STATUS](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable is read from the control gear. |
| [FB\_DALIV2QueryRGBWAFControl](ms-xhelp:///?Id=beckhoff-ba08-4f18-a1c9-7d1513ad636d) | The [RGBWAF CONTROL](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable is read from the control gear. |
| [FB\_DALIV2SetTemporaryColourTemperatureTc](ms-xhelp:///?Id=beckhoff-3b5c-47ee-9eeb-d0a873ec4bcf) | Saves the value in the [TEMPORARY COLOR TEMPERATURE Tc](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable of the control gear. |
| [FB\_DALIV2SetTemporaryPrimaryNDimlevel](ms-xhelp:///?Id=beckhoff-7b9b-4e32-b0ed-810e34d7dfaa) | Saves the value in the [TEMPORARY PRIMARY N DIMLEVEL](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable of the control gear. |
| [FB\_DALIV2SetTemporaryRGBDimlevel](ms-xhelp:///?Id=beckhoff-1636-48d5-85e5-9531f2aed152) | Saves the values in the [TEMPORARY RED DIMLEVEL](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44), [TEMPORARY GREEN DIMLEVEL](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) and [TEMPORARY BLUE DIMLEVEL](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variables of the control gear. |
| [FB\_DALIV2SetTemporaryRGBWAFControl](ms-xhelp:///?Id=beckhoff-9769-4b03-93a8-6591fae29d7d) | Saves the value in the [TEMPORARY RGBWAF CONTROL](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable of the control gear. |
| [FB\_DALIV2SetTemporaryWAFDimlevel](ms-xhelp:///?Id=beckhoff-e34e-475d-8f0b-5ea84582e724) | Saves the values in the [TEMPORARY WHITE DIMLEVEL](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44), [TEMPORARY AMBER DIMLEVEL](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) and [TEMPORARY FREECOLOR DIMLEVEL](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variables of the control gear. |
| [FB\_DALIV2SetTemporaryXCoordinate](ms-xhelp:///?Id=beckhoff-b479-4a27-8661-3a43ae1346ab) | Saves the value in the [TEMPORARY x-COORDINATE](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable of the control gear. |
| [FB\_DALIV2SetTemporaryYCoordinate](ms-xhelp:///?Id=beckhoff-9ea4-4cfc-af61-5ff8851c0019) | Saves the value in the [TEMPORARY y-COORDINATE](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable of the control gear. |
| [FB\_DALIV2StartAutoCalibration](ms-xhelp:///?Id=beckhoff-7f66-4609-a334-3a89db1263e5) | The calibration procedure is started in order to measure the x-coordinate, the y-coordinate and the TY value of all supported primary colors. |
| [FB\_DALIV2StoreColourTemperatureTcLimit](ms-xhelp:///?Id=beckhoff-b262-4d98-9d32-4b2c9ebff06b) | Saves the value in the [COLOR TEMPERATURE Tc COOLEST](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44), [COLOR TEMPERATURE Tc WARMEST](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44), [COLOR TEMPERATURE Tc PHYSICAL COOLEST](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) or [COLOR TEMPERATURE Tc PHYSICAL WARMEST](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable of the control gear. |
| [FB\_DALIV2StoreGearFeaturesStatus](ms-xhelp:///?Id=beckhoff-c7ef-478c-9c31-06f97a31a661) | Saves the value in the [GEAR FEATURES/STATUS](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable of the control gear. |
| [FB\_DALIV2StoreTYPrimaryN](ms-xhelp:///?Id=beckhoff-1389-4e30-94f7-ee8af5bc2b58) | Saves the value in the [TY PRIMARY N](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable of the control gear. |
| [FB\_DALIV2StoreXyCoordinatePrimaryN](ms-xhelp:///?Id=beckhoff-532b-4c0f-ae09-1437f0d13a6c) | Copies the value from the [TEMPORARY x-COORDINATE](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) and [TEMPORARY y-COORDINATE](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variables to the [x-COORDINATE PRIMARY N](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) and [y-COORDINATE PRIMARY N](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variables. |
| [FB\_DALIV2XCoordinateStepDown](ms-xhelp:///?Id=beckhoff-39e2-44bc-a675-6e0d9a8ce3be) | The x-COORDINATE variable is reduced by 256 steps (256 / 65536) without cross-fading. |
| [FB\_DALIV2XCoordinateStepUp](ms-xhelp:///?Id=beckhoff-fa9c-4d0f-a75b-f5ce10e34382) | The x-COORDINATE variable is increased by 256 steps (256 / 65536) without cross-fading. |
| [FB\_DALIV2YCoordinateStepDown](ms-xhelp:///?Id=beckhoff-fc3c-4df2-b6da-3061f3d9c288) | The y-COORDINATE variable is reduced by 256 steps (256 / 65536) without cross-fading. |
| [FB\_DALIV2YCoordinateStepUp](ms-xhelp:///?Id=beckhoff-0ca3-48d8-b3d7-7bb97c9bd7e2) | The y-COORDINATE variable is increased by 256 steps (256 / 65536) without cross-fading. |

|  |  |
| --- | --- |
| 59455556 | These commands belongs to the application-related expansion commands for lamps for the color/color temperature control with DALI interface. They function only if they are preceded by the *Enable Device Type 8* command, which can be sent with the [FB\_DALIV2EnableDeviceType()](ms-xhelp:///?Id=beckhoff-e277-46a4-85ba-43a8cbcb1cb1) function block. The *Enable Device Type 8* command is internally placed automatically before all application-related expansion commands for lamps for the color/color temperature control with DALI interface. |

Further Information

* [Variables](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44)
* [FB\_DALIV2Activate](ms-xhelp:///?Id=beckhoff-7bd8-4669-a55a-8ae3fa04d1da)
* [FB\_DALIV2AssignColourToLinkedChannel](ms-xhelp:///?Id=beckhoff-0216-4595-a506-61d607934432)
* [FB\_DALIV2ColourTemperatureTcStepCooler](ms-xhelp:///?Id=beckhoff-2fe2-43bd-81e9-d1173d761c1f)
* [FB\_DALIV2ColourTemperatureTcStepWarmer](ms-xhelp:///?Id=beckhoff-59aa-4d76-8207-ae34da7e06d3)
* [FB\_DALIV2CopyReportToTemporary](ms-xhelp:///?Id=beckhoff-77d5-4e56-89a3-1093fd3dabca)
* [FB\_DALIV2QueryAssignedColour](ms-xhelp:///?Id=beckhoff-3a56-4296-baff-3d2179e249fe)
* [FB\_DALIV2QueryColourStatus](ms-xhelp:///?Id=beckhoff-ed62-4911-ad94-6cfea37f52ce)
* [FB\_DALIV2QueryColourTypeFeatures](ms-xhelp:///?Id=beckhoff-4f79-476f-a608-43ca7221cfc5)
* [FB\_DALIV2QueryColourValue](ms-xhelp:///?Id=beckhoff-bf54-40b6-b294-0a21b4b8b625)
* [FB\_DALIV2QueryGearFeaturesStatus](ms-xhelp:///?Id=beckhoff-3ae6-44b0-b294-75a1916df3fa)
* [FB\_DALIV2QueryRGBWAFControl](ms-xhelp:///?Id=beckhoff-ba08-4f18-a1c9-7d1513ad636d)
* [FB\_DALIV2SetTemporaryColourTemperatureTc](ms-xhelp:///?Id=beckhoff-3b5c-47ee-9eeb-d0a873ec4bcf)
* [FB\_DALIV2SetTemporaryPrimaryNDimlevel](ms-xhelp:///?Id=beckhoff-7b9b-4e32-b0ed-810e34d7dfaa)
* [FB\_DALIV2SetTemporaryRGBDimlevel](ms-xhelp:///?Id=beckhoff-1636-48d5-85e5-9531f2aed152)
* [FB\_DALIV2SetTemporaryRGBWAFControl](ms-xhelp:///?Id=beckhoff-9769-4b03-93a8-6591fae29d7d)
* [FB\_DALIV2SetTemporaryWAFDimlevel](ms-xhelp:///?Id=beckhoff-e34e-475d-8f0b-5ea84582e724)
* [FB\_DALIV2SetTemporaryXCoordinate](ms-xhelp:///?Id=beckhoff-b479-4a27-8661-3a43ae1346ab)
* [FB\_DALIV2SetTemporaryYCoordinate](ms-xhelp:///?Id=beckhoff-9ea4-4cfc-af61-5ff8851c0019)
* [FB\_DALIV2StartAutoCalibration](ms-xhelp:///?Id=beckhoff-7f66-4609-a334-3a89db1263e5)
* [FB\_DALIV2StoreColourTemperatureTcLimit](ms-xhelp:///?Id=beckhoff-b262-4d98-9d32-4b2c9ebff06b)
* [FB\_DALIV2StoreGearFeaturesStatus](ms-xhelp:///?Id=beckhoff-c7ef-478c-9c31-06f97a31a661)
* [FB\_DALIV2StoreTYPrimaryN](ms-xhelp:///?Id=beckhoff-1389-4e30-94f7-ee8af5bc2b58)
* [FB\_DALIV2StoreXyCoordinatePrimaryN](ms-xhelp:///?Id=beckhoff-532b-4c0f-ae09-1437f0d13a6c)
* [FB\_DALIV2XCoordinateStepDown](ms-xhelp:///?Id=beckhoff-39e2-44bc-a675-6e0d9a8ce3be)
* [FB\_DALIV2XCoordinateStepUp](ms-xhelp:///?Id=beckhoff-fa9c-4d0f-a75b-f5ce10e34382)
* [FB\_DALIV2YCoordinateStepDown](ms-xhelp:///?Id=beckhoff-fc3c-4df2-b6da-3061f3d9c288)
* [FB\_DALIV2YCoordinateStepUp](ms-xhelp:///?Id=beckhoff-0ca3-48d8-b3d7-7bb97c9bd7e2)
* [KELVIN\_TO\_MIREK](ms-xhelp:///?Id=beckhoff-16ce-4a74-bac4-8265e67da8cf)
* [MIREK\_TO\_KELVIN](ms-xhelp:///?Id=beckhoff-1184-4099-b5ff-b4d543412b80)

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
