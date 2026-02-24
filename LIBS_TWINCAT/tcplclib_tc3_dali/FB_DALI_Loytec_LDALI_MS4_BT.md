# FB_DALI_Loytec_LDALI_MS4_BT

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Devices](ms-xhelp:///?Id=beckhoff-6e24-4037-9db1-b195b107840a)
5. [Loytec](ms-xhelp:///?Id=beckhoff-5ef8-4ddf-8346-4de944d9097e)
6. FB\_DALI\_Loytec\_LDALI\_MS4\_BT

# FB\_DALI\_Loytec\_LDALI\_MS4\_BT

![20831783](/tcplclib_tc3_dali/1033/Images/png/9007209010869003__Web.png)

The function block represents the LDALI-MS4-BT DALI sensor from Loytec.

This outputs a brightness value (instance 0), an occupancy signal (instance 1), a temperature value (instance 2), a relative humidity value (instance 3), three hardware push button messages (instances 4 to 6) and 18 infrared remote control push button messages (instances 7 to 24).

The infrared push button instances can be used via a remote control from the manufacturer.

For information on the exact functions of the individual instances, please refer to the manufacturer's device documentation.

Further information on the supported instance types can be found here:

Part 301 (push buttons) – [Introduction](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf)

Part 303 (occupancy sensors) - [Introduction](ms-xhelp:///?Id=beckhoff-5860-45ad-91f4-6edf1ff97245)

Part 304 (light sensors) - [Introduction](ms-xhelp:///?Id=beckhoff-9545-4680-9025-766fb391cf97)

The temperature measurement and humidity measurement are executed as Generic Inputs. These values can only be queried via a positive edge at the inputs *bQueryTemperature* and *bQueryHumidity*.

For the other instances, the readout can also be triggered manually via the inputs *bQueryBrightness* and *bQueryOccupancy*.

The existing parameters can be overwritten by changing the properties listed below. The parameters are written to the device after a positive edge at *bInitialize*.

|  |  |
| --- | --- |
| 53268321 | Set the times so that as few events as possible are sent. If too many events are sent, this can have a negative effect on the behavior of the application. |

|  |  |
| --- | --- |
| 9652842 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bInitialize                : BOOL  := FALSE;  
nShortAddress              : BYTE  := 0;  
nOptions                   : DWORD := 0;  
bQueryOccupancy            : BOOL  := FALSE;  
bQueryBrightness           : BOOL  := FALSE;  
bQueryTemperature          : BOOL  := FALSE;  
bQueryHumidity             : BOOL  := FALSE;  
bCancelHoldTimerOccupancy  : BOOL  := FALSE;
```

**bInitialize:** The configuration of the DALI control device is started by a positive edge at this input. During this time no DALI commands are processed.

**nShortAddress:** Short address (0…63) of the DALI control device.

**nOptions:** Reserved for future extensions.

**bQueryOccupancy:** The occupancy is queried immediately by a positive edge at this input.

**bQueryBrightness:** The brightness is queried immediately by a positive edge at this input.

**bQueryTemperature:** The temperature is queried immediately by a positive edge at this input. The DALI device does not support transmission of the temperature per event.

**bQueryHumidity:** The relative humidity is queried immediately by a positive edge at this input. The DALI device does not support transmission of relative humidity per event.

**bCancelHoldTimerOccupancy:** A positive edge at this input prematurely terminates the Hold Timer and resets the output *bOccupied*.

## VAR\_OUTPUT

```
bError               : BOOL;  
ipResultMessage      : I_TcMessage;  
bInitializing        : BOOL;  
bReadingOccupancy    : BOOL;  
bReadingBrightness   : BOOL;  
bReadingTemperature  : BOOL;  
bReadingHumidity     : BOOL;  
bOccupied            : BOOL;  
nBrightnessLevel     : UINT;  
fTemperature         : LREAL;  
nHumidity            : BYTE;  
nPushButtonHWNEvent  : WORD;  
nPushButtonIRNEvent  : WORD;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bInitializing:** The output is set as soon as the initialization of the DALI control device has been started, and remains active until all DALI commands have been executed.

**bReadingOccupancy:** The output is TRUE as long as values of the instance of the motion sensor are being read by the DALI control device.

**bReadingBrightness:** The output is TRUE as long as values of the instance of the light sensor are being read by the DALI control device.

**bReadingTemperature:** The output is TRUE as long as values of the instance of the temperature sensor are being read by the DALI control device.

**bReadingHumidity:** The output is TRUE as long as values of the humidity sensor instance are read by the DALI controller.

**bOccupied:** If the output is TRUE, then occupancy has been detected in the detection range of the occupancy sensor.

**nBrightnessLevel:** Measured brightness value of the light sensor.

|  |  |
| --- | --- |
| 19766715 | This measured value must be compared with the measured reference values at the place of operation of the DALI control device. |

**fTemperature:** Measured temperature value (-5.0...60.0 °C) of the temperature sensor.

**nHumidity:** Measured value of the relative humidity (0...100 %).

**nPushButtonHWNEvent:** The outputs (1…3) output the events for the respective push button via one bit each for a cycle.

**nPushButtonIRNEvent:** The outputs (1...18) output the events for the corresponding infrared button via one bit for one cycle.

| Bit | Description |
| --- | --- |
| 0 | Push button released. |
| 1 | Push button pressed. |
| 2 | Short keystroke. |
| 3 | Double keystroke. |
| 4 | Start long keystroke. |
| 5 | Repeat long keystroke. |
| 6 | Stop long keystroke. |
| 7 | Push button free again; was previously blocked. |
| 8 | Push button blocked. |

The function block [FB\_DALI\_ToPushButtonState](ms-xhelp:///?Id=beckhoff-c0d2-477c-96f3-465feb2dd845) can be used to convert the state of a push button into a BOOL variable.

## PROPERTIES

All parameters that are written to the DALI control device via *bInitialize* are available as properties.

The properties of instances of the same type are listed only once in the table and marked with N at the end.

| Name | Type | Access | Initial value | Description |
| --- | --- | --- | --- | --- |
| bEnableBrightness | BOOL | Get, Set | TRUE | TRUE at this property enables the instance for brightness measurement. FALSE at this property causes sending of events from this instance to be disabled. However, the actual value of the instance can still be queried via the input *bQueryBrightness*. |
| bEnableOccupancy | BOOL | Get, Set | TRUE | TRUE at this property enables the instance for motion detection. FALSE at this property causes sending of events from this instance to be disabled. However, the actual value of the instance can still be queried via the input *bQueryOccupancy*. |
| bEnableTemperature | BOOL | Get, Set | FALSE | TRUE at this property enables the instance for temperature measurement. FALSE at this property causes the instance not to be configured during initialization. The actual value of the instance can only be queried via the input *bQueryTemperature*. |
| bEnableHumidity | BOOL | Get, Set | FALSE | A TRUE on this property enables the instance to measure relative humidity. FALSE at this property causes the instance not to be configured during initialization. The actual value of the instance can only be queried via the input *bQueryHumidity*. |
| bEnablePushButtonHWN | BOOL | Get, Set | FALSE | Push button input 1 to 3, which can be enabled or disabled on the DALI control device. FALSE at this property causes sending of events from this instance to be disabled. |
| bEnablePushButtonIRN | BOOL | Get, Set | FALSE | Infrared button inputs 1 to 18, which can be enabled or disabled on the DALI control device. FALSE at this property causes sending of events from this instance to be disabled. |
| eEventPriorityBrightness | E\_DALIEventPriority | Get, Set | MiddleLow | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nReportTimerBrightness | BYTE | Get, Set | 30 s | Time (0…255 s) after which the pending event of the light sensor is repeated if no other event has occurred in the meantime. |
| nDeadtimeTimerBrightness | UINT | Get, Set | 1500 ms | Dead time (0...12750 ms) to ensure that not too many events are sent in succession. An event is not sent until the dead time timer has expired. The dead time timer is restarted each time an event is sent. |
| nHysteresisBrightness | BYTE | Get, Set | 5 % | Value (0…25 %) for calculating a hysteresis value in order to prevent frequent and disturbing changes when measuring the brightness. |
| nHysteresisMinBrightness | BYTE | Get, Set | 255 | As the percentage hysteresis can also lead to large fluctuations at low brightness, a minimum hysteresis can be specified via this property. The minimum hysteresis is an absolute value with a value range from 0 to 255. |
| eEventPriorityOccupancy | E\_DALIEventPriority | Get, Set | Middle | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nDeadtimeTimerOccupancy | UINT | Get, Set | 100 ms | Dead time (0...12750 ms) to ensure that not too many events are sent in succession. An event is not sent until the dead time timer has expired. The dead time timer is restarted each time an event is sent. |
| nHoldTimerOccupancy | UINT | Get, Set | 900 s | Dwell time (1...2538 s) in which the occupancy continues to be active after no more movement has been detected by the sensor. |
| nReportTimerOccupancy | BYTE | Get, Set | 60 s | Time (0…255 s) after which the pending event of the occupancy sensor is repeated if no other event has occurred in the meantime. |
| eEventPriorityPushButtonHWN | E\_DALIEventPriority | Get, Set | Middle | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nEventFilterPushButtonHWN | BYTE | Get, Set | 2#1000\_0011 | Setting of the [event filter](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf). |
| nDoubleTimerPushButtonHWN | UINT | Get, Set | 0 s | Time (0, *tDoubleMin*…2000 ms) to distinguish between a single and a double keystroke. |
| nRepeatTimerPushButtonHWN | UINT | Get, Set | 160 ms | Interval (100…2000 ms) of repetitive events in the case of a long keystroke. |
| nShortTimerPushButtonHWN | UINT | Get, Set | 500 ms | Time (*tShortMin*...5100 ms) to distinguish between a long and a short keystroke. *tShortMin* is a manufacturer-specific value. |
| nStuckTimerPushButtonHWN | BYTE | Get, Set | 20 s | Time (5…255 s) after the expiry of which the push button no longer represents a long keystroke. The push button is stuck. |
| eEventPriorityPushButtonIRN | E\_DALIEventPriority | Get, Set | Middle | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nEventFilterPushButtonIRN | BYTE | Get, Set | 2#1000\_0011 | Setting of the [event filter](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf). |
| nDoubleTimerPushButtonIRN | UINT | Get, Set | 0 s | Time (0, *tDoubleMin*…2000 ms) to distinguish between a single and a double keystroke. |
| nRepeatTimerPushButtonIRN | UINT | Get, Set | 160 ms | Interval (100…2000 ms) of repetitive events in the case of a long keystroke. |
| nShortTimerPushButtonIRN | UINT | Get, Set | 500 ms | Time (*tShortMin*...5100 ms) to distinguish between a long and a short keystroke. *tShortMin* is a manufacturer-specific value. |
| nStuckTimerPushButtonIRN | BYTE | Get, Set | 20 s | Time (5…255 s) after the expiry of which the push button no longer represents a long keystroke. The push button is stuck. |

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.13 | Tc3\_DALI from v3.6.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
