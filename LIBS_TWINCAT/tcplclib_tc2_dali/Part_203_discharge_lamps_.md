# Part 203 (discharge lamps)

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. Part 203 (discharge lamps)

# Part 203 (discharge lamps)

|  |  |
| --- | --- |
| The function blocks and variables for discharge lamps with DALI interface are described below. All below function blocks described below call 'application-related expansion commands'. According to the DALI standard (IEC 62386) these commands are within the range 224 to 255. Because of the existence of a variety of application-related expansion commands, it is necessary to use the [FB\_DALIV2EnableDeviceType()](ms-xhelp:///?Id=beckhoff-e277-46a4-85ba-43a8cbcb1cb1) function block to specify which type of control gears (emergency lighting, discharge lamps, ...) should react to the extension commands. A precise description of the individual DALI commands and the variables for discharge lamps with DALI interface will be found in Part 203 of the IEC 62386 standard. | 39473694 |

## Function blocks

| Name | Description |
| --- | --- |
| [FB\_DALIV2QueryActualHIDFailure](ms-xhelp:///?Id=beckhoff-9056-442d-9e87-f2c80f67ab38) | The [ACTUAL HID FAILURE](ms-xhelp:///?Id=beckhoff-668d-4053-a897-bdc3b3aa4303) variable (current failure status) is read from the control gear. |
| [FB\_DALIV2QueryHIDFeatures](ms-xhelp:///?Id=beckhoff-4a4b-4bb2-a0e7-609e9051e4ed) | The [HID FEATURES](ms-xhelp:///?Id=beckhoff-668d-4053-a897-bdc3b3aa4303) variable (performance characteristics) is read from the control gear. |
| [FB\_DALIV2QueryHIDStatus](ms-xhelp:///?Id=beckhoff-6cd1-4af0-950d-ed1d257d5805) | The [HID STATUS](ms-xhelp:///?Id=beckhoff-668d-4053-a897-bdc3b3aa4303) variable is read from the control gear. |
| [FB\_DALIV2QueryStoredHIDFailure](ms-xhelp:///?Id=beckhoff-b5d3-4d1c-bf56-01802093d966) | The [STORED HID FAILURE](ms-xhelp:///?Id=beckhoff-668d-4053-a897-bdc3b3aa4303) variable (stored failure status) is read from the control gear. |
| [FB\_DALIV2QueryThermalLoad](ms-xhelp:///?Id=beckhoff-861f-4fe9-8225-75721d88cf7a) | The [THERMAL LOAD](ms-xhelp:///?Id=beckhoff-668d-4053-a897-bdc3b3aa4303) variable is read. |
| [FB\_DALIV2QueryThermalOverloadTime](ms-xhelp:///?Id=beckhoff-8c5b-47f6-b446-311b8a2832de) | The 16-bit variable [THERMAL OVERLOAD TIME](ms-xhelp:///?Id=beckhoff-668d-4053-a897-bdc3b3aa4303) is read. |
| [FB\_DALIV2QueryThermalOverloadTimeHB](ms-xhelp:///?Id=beckhoff-5289-48cd-97f6-c0fccb070224) | The high-order byte of the 16-bit variable [THERMAL OVERLOAD TIME](ms-xhelp:///?Id=beckhoff-668d-4053-a897-bdc3b3aa4303) is read. |
| [FB\_DALIV2QueryThermalOverloadTimeLB](ms-xhelp:///?Id=beckhoff-3a7c-4978-83f9-ff0f71cc32c2) | The low-order byte of the 16-bit variable [THERMAL OVERLOAD TIME](ms-xhelp:///?Id=beckhoff-668d-4053-a897-bdc3b3aa4303) is read. |
| [FB\_DALIV2ResetStoredHIDFailure](ms-xhelp:///?Id=beckhoff-41f1-45aa-bc5a-ff449cd26680) | The [STORED HID FAILURE](ms-xhelp:///?Id=beckhoff-668d-4053-a897-bdc3b3aa4303) variable (stored lamp faults) is reset. |

|  |  |
| --- | --- |
| 19718930 | These commands belong to the application-related expansion commands for DALI discharge lamps. They function only if they are preceded by the *Enable Device Type 2* command, which can be sent with the [FB\_DALIV2EnableDeviceType()](ms-xhelp:///?Id=beckhoff-e277-46a4-85ba-43a8cbcb1cb1) function block. The *Enable Device Type 2* command is internally placed automatically before all application-related expansion commands for DALI discharge lamps. |

Further Information

* [Variables](ms-xhelp:///?Id=beckhoff-668d-4053-a897-bdc3b3aa4303)
* [FB\_DALIV2QueryActualHIDFailure](ms-xhelp:///?Id=beckhoff-9056-442d-9e87-f2c80f67ab38)
* [FB\_DALIV2QueryHIDFeatures](ms-xhelp:///?Id=beckhoff-4a4b-4bb2-a0e7-609e9051e4ed)
* [FB\_DALIV2QueryHIDStatus](ms-xhelp:///?Id=beckhoff-6cd1-4af0-950d-ed1d257d5805)
* [FB\_DALIV2QueryStoredHIDFailure](ms-xhelp:///?Id=beckhoff-b5d3-4d1c-bf56-01802093d966)
* [FB\_DALIV2QueryThermalLoad](ms-xhelp:///?Id=beckhoff-861f-4fe9-8225-75721d88cf7a)
* [FB\_DALIV2QueryThermalOverloadTime](ms-xhelp:///?Id=beckhoff-8c5b-47f6-b446-311b8a2832de)
* [FB\_DALIV2QueryThermalOverloadTimeHB](ms-xhelp:///?Id=beckhoff-5289-48cd-97f6-c0fccb070224)
* [FB\_DALIV2QueryThermalOverloadTimeLB](ms-xhelp:///?Id=beckhoff-3a7c-4978-83f9-ff0f71cc32c2)
* [FB\_DALIV2ResetStoredHIDFailure](ms-xhelp:///?Id=beckhoff-41f1-45aa-bc5a-ff449cd26680)

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
