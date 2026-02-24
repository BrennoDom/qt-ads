# FB_DALI_Esylux_PDC_360_BMS

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Devices](ms-xhelp:///?Id=beckhoff-6e24-4037-9db1-b195b107840a)
5. [Esylux](ms-xhelp:///?Id=beckhoff-6826-4353-b659-76c042af8154)
6. FB\_DALI\_Esylux\_PDC\_360\_BMS

# FB\_DALI\_Esylux\_PDC\_360\_BMS

![29969153](/tcplclib_tc3_dali/1033/Images/png/9007208249359371__Web.png)

The function block represents the PD-C 360/8 BMS DALI-2 or PD-C 360/24 BMS DALI-2 DALI sensor from Esylux.

This outputs two signals from connected push buttons (instances 0 and 1), an occupancy signal (instance 2) and the measured brightness value (instance 3).

Further information on the supported instance types can be found here:

Part 301 (push buttons) – [Introduction](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf)

Part 303 (occupancy sensors) – [Introduction](ms-xhelp:///?Id=beckhoff-5860-45ad-91f4-6edf1ff97245)

Part 304 (light sensors) – [Introduction](ms-xhelp:///?Id=beckhoff-9545-4680-9025-766fb391cf97)

The existing parameters can be overwritten by changing the properties listed below.

The input variables *bQueryPushButtonN, bQueryOccupancy*, and *bQueryBrightness* can be used to trigger the read-out immediately, even if the corresponding instance is not enabled.

|  |  |
| --- | --- |
| 1286929 | Set the times so that as few events as possible are sent. If too many events are sent, this can have a negative effect on the behavior of the application. |

|  |  |
| --- | --- |
| 11582368 | The function block cannot be used when using the KL6811. |

## ALS correction factor

During programming, it may be necessary to calibrate the brightness measurement.

The values can be changed via the properties.

The function block transmits the individual ALS (ambient light sensor) parameters to the 2 light sensors integrated in the DALI control device.

The ALS correction factor has a value range from 0.1 to 5.0. The input values are increased by a factor of 10 from 1 to 50.

The correction factor of a light sensor is determined at 100 and 500 lux on the floor. A separate luxmeter is necessary for this.

1. Dim the lighting until 100 lux is measured on the floor.
2. Read the output value of the sensor.
3. Determine the correction factor for the sensor and enter it at the inputs *nALS0CorrectionFactor100* and *nALS1CorrectionFactor100* .  
     
   In the following example, a value of 100 lux is measured with the luxmeter. The device function block returns the value 54 at the output *nBrightnessLevel*.  
   This calculates the correction factor as follows:  
   ![37132456](/tcplclib_tc3_dali/1033/Images/png/9007208029365131__Web.png)  
   The value 19 must be entered at the inputs *nALS0CorrectionFactor100* and *nALS1CorrectionFactor100* .
4. Repeat this procedure from step 1 at 500 lux.

## VAR\_INPUT

```
bInitialize                : BOOL  := FALSE;  
nShortAddress              : BYTE  := 0;  
nOptions                   : DWORD := 0;  
bQueryPushButton1          : BOOL  := FALSE;  
bQueryPushButton2          : BOOL  := FALSE;  
bQueryOccupancy            : BOOL  := FALSE;  
bQueryBrightness           : BOOL  := FALSE;  
bCancelHoldTimerOccupancy  : BOOL  := FALSE;
```

**bInitialize:** The configuration of the DALI control device is started by a positive edge at this input. During this time no DALI commands are processed.

**nShortAddress:** Short address (0…63) of the DALI control device.

**nOptions:** Reserved for future extensions.

**bQueryPushButtonN:** The state of the button is queried immediately by a positive edge at this input.

**bQueryOccupancy:** The occupancy is queried immediately by a positive edge at this input.

**bQueryBrightness:** The brightness is queried immediately by a positive edge at this input.

**bCancelHoldTimerOccupancy:** A positive edge at this input prematurely terminates the Hold Timer and resets the output *bOccupied*.

## VAR\_OUTPUT

```
bError                 : BOOL;  
ipResultMessage        : I_TcMessage;  
bInitializing          : BOOL;  
bReadingPushButton1    : BOOL;  
bReadingPushButton2    : BOOL;  
bReadingOccupancy      : BOOL;  
bReadingBrightness     : BOOL;  
nPushButton1Event      : WORD;  
nPushButton2Event      : WORD;  
bOccupied              : BOOL;  
nBrightnessLevel       : UINT;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bInitializing:** The output is set as soon as the initialization of the DALI control device has been started, and remains active until all DALI commands have been executed.

**bReadingPushButton1:** The output is TRUE as long as values of the instance of the light sensor are being read by the DALI control device.

**bReadingPushButton2:** The output is TRUE as long as values of the instance of the light sensor are being read by the DALI control device.

**bReadingOccupancy:** The output is TRUE as long as values of the instance of the light sensor are being read by the DALI control device.

**bReadingBrightness:** The output is TRUE as long as values of the instance of the light sensor are being read by the DALI control device.

**nPushButtonNEvent:** The output outputs the events for the respective push button via one bit each for a cycle.

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

**bOccupied:** If the output is TRUE, then occupancy has been detected in the detection range of the occupancy sensor.

**nBrightnessLevel:** Measured brightness value of the light sensor.

|  |  |
| --- | --- |
| 65756648 | This measured value must be compared with the measured reference values at the place of operation of the DALI control device. A description can be found under [ALS correction factor](ms-xhelp:///?Id=beckhoff-f640-4067-bed9-ed92357d7161). |

## PROPERTIES

All parameters that are written to the DALI control device via *bInitialize* are available as properties.

The properties of instances of the same type are listed only once in the table and marked with N at the end.

| Name | Type | Access | Initial value | Description |
| --- | --- | --- | --- | --- |
| bEnableBrightness | BOOL | Get, Set | TRUE | TRUE at this property enables the instance for brightness measurement. FALSE at this property causes sending of events from this instance to be disabled. However, the actual value of the instance can still be queried via the input *bQueryBrightness*. |
| bEnableOccupancy | BOOL | Get, Set | TRUE | TRUE at this property enables the instance for motion detection. FALSE at this property causes sending of events from this instance to be disabled. However, the actual value of the instance can still be queried via the input *bQueryOccupancy*. |
| bEnablePushButtonN | BOOL | Get, Set | FALSE | Push button input 1 or 2, which can be enabled or disabled on the DALI control device. FALSE at this property causes sending of events from this instance to be disabled. However, the actual value of the instance can still be queried via the input *bQueryPushButtonN*. |
| eEventPriorityBrightness | E\_DALIEventPriority | Get, Set | MiddleLow | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nALS0CorrectionFactor100 | BYTE | Get, Set | 10 | Correction factor (1…50) of light sensor 0 at a measured value of 100 lux on the surface to be measured. |
| nALS0CorrectionFactor500 | BYTE | Get, Set | 10 | Correction factor (1…50) of light sensor 0 at a measured value of 500 lux on the surface to be measured. |
| nALS1CorrectionFactor100 | BYTE | Get, Set | 10 | Correction factor (1…50) of light sensor 1 at a measured value of 100 lux on the surface to be measured. |
| nALS1CorrectionFactor500 | BYTE | Get, Set | 10 | Correction factor (1…50) of light sensor 1 at a measured value of 500 lux on the surface to be measured. |
| nReportTimerBrightness | BYTE | Get, Set | 30 s | Time (0…255 s) after which the pending event of the light sensor is repeated if no other event has occurred in the meantime. |
| nDeadtimeTimerBrightness | UINT | Get, Set | 1500 ms | Dead time (0...12750 ms) to ensure that not too many events are sent in succession. An event is not sent until the dead time timer has expired. The dead time timer is restarted each time an event is sent. |
| nHysteresisBrightness | BYTE | Get, Set | 5 % | Value (0…25 %) for calculating a hysteresis value in order to prevent frequent and disturbing changes when measuring the brightness. |
| nHysteresisMinBrightness | BYTE | Get, Set | 81 | As the percentage hysteresis can also lead to large fluctuations at low brightness, a minimum hysteresis can be specified via this property. The minimum hysteresis is an absolute value with a value range from 0 to 255. |
| eEventPriorityOccupancy | E\_DALIEventPriority | Get, Set | Middle | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nDeadtimeTimerOccupancy | UINT | Get, Set | 100 ms | Dead time (0...12750 ms) to ensure that not too many events are sent in succession. An event is not sent until the dead time timer has expired. The dead time timer is restarted each time an event is sent. |
| nHoldTimerOccupancy | UINT | Get, Set | 900 s | Dwell time (1...2538 s) in which the occupancy continues to be active after no more movement has been detected by the sensor. |
| nReportTimerOccupancy | BYTE | Get, Set | 60 s | Time (0…255 s) after which the pending event of the occupancy sensor is repeated if no other event has occurred in the meantime. |
| nSensitivityOccupancy | BYTE | Get, Set | 95 | Setting of the sensitivity of both occupancy sensor instances from 1 (low sensitivity) to 100 (high sensitivity). The written value of 254 resets the sensitivity to the factory setting. |
| nEventFilterPushButtonN | BYTE | Get, Set | 2#1000\_0011 | Setting of the [event filter](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf). |
| eEventPriorityPushButtonN | E\_DALIEventPriority | Get, Set | Middle | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nDoubleTimerPushButtonN | UINT | Get, Set | 0 ms | Time (0, *tDoubleMin*…2000 ms) to distinguish between a single and a double keystroke. |
| nRepeatTimerPushButtonN | UINT | Get, Set | 160 ms | Interval (100…2000 ms) of repetitive events in the case of a long keystroke. |
| nShortTimerPushButtonN | UINT | Get, Set | 500 ms | Time (*tShortMin*...5100 ms) to distinguish between a long and a short keystroke. *tShortMin* is a manufacturer-specific value. |
| nStuckTimerPushButtonN | BYTE | Get, Set | 20 s | Time (5…255 s) after the expiry of which the push button no longer represents a long keystroke. The push button is stuck. |

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
