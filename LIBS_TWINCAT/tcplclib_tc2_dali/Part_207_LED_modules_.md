# Part 207 (LED modules)

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. Part 207 (LED modules)

# Part 207 (LED modules)

## Function blocks

The function blocks and variables for LED modules with DALI interface are described below. All below function blocks described below call 'application-related expansion commands'. According to the DALI standard (IEC 62386) these commands are within the range 224 to 255. Because of the existence of a variety of application-related expansion commands, it is necessary to use the [FB\_DALIV2EnableDeviceType()](ms-xhelp:///?Id=beckhoff-e277-46a4-85ba-43a8cbcb1cb1) function block to specify which type of control gears (emergency lighting, discharge lamps, ...) should react to the extension commands. A detailed description of the individual DALI commands and the variables for LED modules with DALI interface can be found in standard IEC 62386 Part 207.

| Name | Description |
| --- | --- |
| [FB\_DALIV2DisableCurrentProtector](ms-xhelp:///?Id=beckhoff-528f-4a47-8721-81e266a877c9) | The command disables the current protection device of the control gear. |
| [FB\_DALIV2EnableCurrentProtector](ms-xhelp:///?Id=beckhoff-ab4c-4bdf-b2d0-d23edfd63432) | The command enables the current protection device of the control gear. |
| [FB\_DALIV2QueryCurrentProtectorActive](ms-xhelp:///?Id=beckhoff-fc3d-47ad-bbfb-d650559305bc) | The system checks whether the current protection device is active. |
| [FB\_DALIV2QueryCurrentProtectorEnabled](ms-xhelp:///?Id=beckhoff-2c43-42f3-8d01-e893ee3c8414) | The system queries whether the current protection device is enabled. |
| [FB\_DALIV2QueryDimmingCurve](ms-xhelp:///?Id=beckhoff-62b1-437c-98f0-181dff8c5e7b) | The dimming curve of the control gear is read out. |
| [FB\_DALIV2QueryFastFadeTime](ms-xhelp:///?Id=beckhoff-f61d-4590-a1d7-fb9c020a42ac) | Queries the value of FAST FADE TIME. |
| [FB\_DALIV2QueryGearType](ms-xhelp:///?Id=beckhoff-bad8-41f2-b970-d147dfd0745b) | Queries the value of GEAR TYPE. |
| [FB\_DALIV2QueryLedFailureStatus](ms-xhelp:///?Id=beckhoff-51ca-4e3c-ab7b-6db9330feeff) | Queries the value of FAILURE STATUS. |
| [FB\_DALIV2QueryLedFeatures](ms-xhelp:///?Id=beckhoff-66bf-42b3-bd15-732d77160324) | Queries the value of FEATURES. |
| [FB\_DALIV2QueryLoadDecrease](ms-xhelp:///?Id=beckhoff-2724-490a-a5bc-c4a903fd0bc8) | The system queries whether a significant decrease in load (compared to the reference power of the system) has been detected. |
| [FB\_DALIV2QueryLoadIncrease](ms-xhelp:///?Id=beckhoff-c60d-419e-ba11-341feef98a4b) | The system queries whether a significant increase in load (compared to the reference power of the system) has been detected. |
| [FB\_DALIV2QueryMinFastFadeTime](ms-xhelp:///?Id=beckhoff-c08f-4f33-b335-d452a7dce04f) | Queries the value of MIN FAST FADE TIME. |
| [FB\_DALIV2QueryOpenCircuit](ms-xhelp:///?Id=beckhoff-aecc-4e7a-92e6-76f5e7b99b61) | The system queries whether an idle mode has been detected. |
| [FB\_DALIV2QueryOperatingMode](ms-xhelp:///?Id=beckhoff-9b82-4d1a-9016-ba18e1f435c6) | Queries the value of OPERATING MODE. |
| [FB\_DALIV2QueryPossibleOperatingModes](ms-xhelp:///?Id=beckhoff-f0bb-4f5f-9b2c-38a720856ddc) | Queries the value of POSSIBLE OPERATING MODE. |
| [FB\_DALIV2QueryReferenceMeasurementFailed](ms-xhelp:///?Id=beckhoff-c1df-481b-8320-01ffe6275142) | The system queries whether a started reference measurement has failed. |
| [FB\_DALIV2QueryReferenceRunning](ms-xhelp:///?Id=beckhoff-fbd8-4d8b-922e-6e95f288a6c7) | The system queries whether a reference measurement of the system performance is active. |
| [FB\_DALIV2QueryShortCircuit](ms-xhelp:///?Id=beckhoff-d518-4834-a287-5a29029e590f) | The system queries whether a short circuit has been detected. |
| [FB\_DALIV2QueryThermalOverload](ms-xhelp:///?Id=beckhoff-6e12-451a-b997-a5871e5a6fab) | The system queries whether there is a thermal overload with reduction of the luminous flux. |
| [FB\_DALIV2QueryThermalShutDown](ms-xhelp:///?Id=beckhoff-8d0d-4455-aa71-582aa3392b1e) | The system queries whether a thermal shutdown occurred. |
| [FB\_DALIV2ReferenceSystemPower](ms-xhelp:///?Id=beckhoff-bb62-4fdf-b4c7-68f46eeb4eda) | The control gear measures and stores the performance level of the system, in order to detect load increase and decrease. |
| [FB\_DALIV2SelectDimmingCurve](ms-xhelp:///?Id=beckhoff-515e-41b5-b31f-6e84e6d99e1b) | The dimming curve of the control gear is selected. |
| [FB\_DALIV2SetFastFadeTime](ms-xhelp:///?Id=beckhoff-2828-45fe-86aa-ff8eeeb49b29) | Sets the FAST FADE TIME in the control gear. |

|  |  |
| --- | --- |
| 33212803 | These commands belong to the application-specific expansion commands for LED modules with DALI interface. They function only if they are preceded by the *Enable Device Type 6* command, which can be sent with the [FB\_DALIV2EnableDeviceType()](ms-xhelp:///?Id=beckhoff-e277-46a4-85ba-43a8cbcb1cb1) function block. The command *Enable Device Type 6* is already automatically internally prefixed to all application-related expansion commands for LED modules with DALI interface. |

Further Information

* [FB\_DALIV2DisableCurrentProtector](ms-xhelp:///?Id=beckhoff-528f-4a47-8721-81e266a877c9)
* [FB\_DALIV2EnableCurrentProtector](ms-xhelp:///?Id=beckhoff-ab4c-4bdf-b2d0-d23edfd63432)
* [FB\_DALIV2QueryCurrentProtectorActive](ms-xhelp:///?Id=beckhoff-fc3d-47ad-bbfb-d650559305bc)
* [FB\_DALIV2QueryCurrentProtectorEnabled](ms-xhelp:///?Id=beckhoff-2c43-42f3-8d01-e893ee3c8414)
* [FB\_DALIV2QueryDimmingCurve](ms-xhelp:///?Id=beckhoff-62b1-437c-98f0-181dff8c5e7b)
* [FB\_DALIV2QueryFastFadeTime](ms-xhelp:///?Id=beckhoff-f61d-4590-a1d7-fb9c020a42ac)
* [FB\_DALIV2QueryGearType](ms-xhelp:///?Id=beckhoff-bad8-41f2-b970-d147dfd0745b)
* [FB\_DALIV2QueryLedFailureStatus](ms-xhelp:///?Id=beckhoff-51ca-4e3c-ab7b-6db9330feeff)
* [FB\_DALIV2QueryLedFeatures](ms-xhelp:///?Id=beckhoff-66bf-42b3-bd15-732d77160324)
* [FB\_DALIV2QueryLoadDecrease](ms-xhelp:///?Id=beckhoff-2724-490a-a5bc-c4a903fd0bc8)
* [FB\_DALIV2QueryLoadIncrease](ms-xhelp:///?Id=beckhoff-c60d-419e-ba11-341feef98a4b)
* [FB\_DALIV2QueryMinFastFadeTime](ms-xhelp:///?Id=beckhoff-c08f-4f33-b335-d452a7dce04f)
* [FB\_DALIV2QueryOpenCircuit](ms-xhelp:///?Id=beckhoff-aecc-4e7a-92e6-76f5e7b99b61)
* [FB\_DALIV2QueryOperatingMode](ms-xhelp:///?Id=beckhoff-9b82-4d1a-9016-ba18e1f435c6)
* [FB\_DALIV2QueryPossibleOperatingModes](ms-xhelp:///?Id=beckhoff-f0bb-4f5f-9b2c-38a720856ddc)
* [FB\_DALIV2QueryReferenceMeasurementFailed](ms-xhelp:///?Id=beckhoff-c1df-481b-8320-01ffe6275142)
* [FB\_DALIV2QueryReferenceRunning](ms-xhelp:///?Id=beckhoff-fbd8-4d8b-922e-6e95f288a6c7)
* [FB\_DALIV2QueryShortCircuit](ms-xhelp:///?Id=beckhoff-d518-4834-a287-5a29029e590f)
* [FB\_DALIV2QueryThermalOverload](ms-xhelp:///?Id=beckhoff-6e12-451a-b997-a5871e5a6fab)
* [FB\_DALIV2QueryThermalShutDown](ms-xhelp:///?Id=beckhoff-8d0d-4455-aa71-582aa3392b1e)
* [FB\_DALIV2ReferenceSystemPower](ms-xhelp:///?Id=beckhoff-bb62-4fdf-b4c7-68f46eeb4eda)
* [FB\_DALIV2SelectDimmingCurve](ms-xhelp:///?Id=beckhoff-515e-41b5-b31f-6e84e6d99e1b)
* [FB\_DALIV2SetFastFadeTime](ms-xhelp:///?Id=beckhoff-2828-45fe-86aa-ff8eeeb49b29)

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
