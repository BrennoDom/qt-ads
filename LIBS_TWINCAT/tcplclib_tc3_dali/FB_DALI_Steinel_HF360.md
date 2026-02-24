# FB_DALI_Steinel_HF360

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Devices](ms-xhelp:///?Id=beckhoff-6e24-4037-9db1-b195b107840a)
5. [Steinel](ms-xhelp:///?Id=beckhoff-4433-4e47-b6bb-9f4b9d82c036)
6. FB\_DALI\_Steinel\_HF360

# FB\_DALI\_Steinel\_HF360

![5300362](/tcplclib_tc3_dali/1033/Images/gif/18014406249298059__Web.gif)

The function block represents the HF 360 DALI sensor from Steinel.

This outputs the measured brightness value (instance 0) and an occupancy signal (instance 1).

Further information on the supported instance types can be found here:

Part 303 (occupancy sensors) – [Introduction](ms-xhelp:///?Id=beckhoff-5860-45ad-91f4-6edf1ff97245)

Part 304 (light sensors) - [Introduction](ms-xhelp:///?Id=beckhoff-9545-4680-9025-766fb391cf97)

The existing parameters can be overwritten by changing the properties listed below.

Readout can be triggered manually via the input variables *bQueryOccupancy* and *bQueryBrightness*.

|  |  |
| --- | --- |
| 47703261 | Set the times so that as few events as possible are sent. If too many events are sent, this can have a negative effect on the behavior of the application. |

|  |  |
| --- | --- |
| 26676172 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bInitialize                 : BOOL  := FALSE;  
nShortAddress               : BYTE  := 0;  
nOptions                    : DWORD := 0;  
bQueryOccupancy             : BOOL  := FALSE;  
bQueryBrightness            : BOOL  := FALSE;  
bCancelHoldTimerOccupancy   : BOOL  := FALSE;
```

**bInitialize:** The configuration of the DALI control device is started by a positive edge at this input. During this time no DALI commands are processed.

**nShortAddress:** Short address (0…63) of the DALI control device.

**nOptions:** Reserved for future extensions.

**bQueryOccupancy:** The occupancy is queried immediately by a positive edge at this input.

**bQueryBrightness:** The brightness is queried immediately by a positive edge at this input.

**bCancelHoldTimerOccupancy:** A positive edge at this input prematurely terminates the Hold Timer and resets the output *bOccupied*.

## VAR\_OUTPUT

```
bError                        : BOOL;  
ipResultMessage               : I_TcMessage;  
bInitializing                 : BOOL;  
bReadingOccupancy             : BOOL;  
bReadingBrightness            : BOOL;  
bOccupied                     : BOOL;  
nBrightnessLevel              : UINT;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bInitializing:** The output is set as soon as the initialization of the DALI control device has been started, and remains active until all DALI commands have been executed.

**bReadingOccupancy:** The output is TRUE as long as values of the instance of the motion sensor are being read by the DALI control device.

**bReadingBrightness:** The output is TRUE as long as values of the instance of the light sensor are being read by the DALI control device.

**bOccupied:** If the output is TRUE, then occupancy has been detected in the detection range of the occupancy sensor.

**nBrightnessLevel:** Measured brightness value of the light sensor.

|  |  |
| --- | --- |
| 38758958 | This measured value must be compared with the measured reference values at the place of operation of the DALI control device. |

## PROPERTIES

All parameters that are written to the DALI control device via *bInitialize* are available as properties.

| Name | Type | Access | Initial value | Description |
| --- | --- | --- | --- | --- |
| bEnableBrightness | BOOL | Get, Set | TRUE | TRUE at this property enables the instance for brightness measurement. FALSE at this property causes sending of events from this instance to be disabled. However, the actual value of the instance can still be queried via the input *bQueryBrightness*. |
| bEnableOccupancy | BOOL | Get, Set | TRUE | TRUE at this property enables the instance for motion detection. FALSE at this property causes sending of events from this instance to be disabled. However, the actual value of the instance can still be queried via the input *bQueryOccupancy*. |
| eEventPriorityBrightness | E\_DALIEventPriority | Get, Set | MiddleLow | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nReportTimerBrightness | BYTE | Get, Set | 30 s | Time (0…255 s) after which the pending event of the light sensor is repeated if no other event has occurred in the meantime. |
| nDeadtimeTimerBrightness | UINT | Get, Set | 1500 ms | Dead time (0...12750 ms) to ensure that not too many events are sent in succession. An event is not sent until the dead time timer has expired. The dead time timer is restarted each time an event is sent. |
| nHysteresisBrightness | BYTE | Get, Set | 20 % | Value (0…25 %) for calculating a hysteresis value in order to prevent frequent and disturbing changes when measuring the brightness. |
| nHysteresisMinBrightness | BYTE | Get, Set | 10 | As the percentage hysteresis can also lead to large fluctuations at low brightness, a minimum hysteresis can be specified via this property. The minimum hysteresis is an absolute value with a value range from 0 to 255. |
| eEventPriorityOccupancy | E\_DALIEventPriority | Get, Set | Middle | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nDeadtimeTimerOccupancy | UINT | Get, Set | 100 ms | Dead time (0...12750 ms) to ensure that not too many events are sent in succession. An event is not sent until the dead time timer has expired. The dead time timer is restarted each time an event is sent. |
| nHoldTimerOccupancy | UINT | Get, Set | 900 s | Dwell time (1...2538 s) in which the occupancy continues to be active after no more movement has been detected by the sensor. |
| nReportTimerOccupancy | BYTE | Get, Set | 60 s | Time (0…255 s) after which the pending event of the occupancy sensor is repeated if no other event has occurred in the meantime. |
| nSensitivityOccupancy | BYTE | Get, Set | 100 % | Setting of the sensitivity of the occupancy sensor from 0 % (low sensitivity) to 100 % (high sensitivity). |
| nDetectionRangeOccupancy | BYTE | Get, Set | 100 % | Setting of the detection range of the occupancy sensor from 0 % (small detection range) to 100 % (large detection range). |

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
