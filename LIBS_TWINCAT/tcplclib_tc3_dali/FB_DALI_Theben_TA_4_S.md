# FB_DALI_Theben_TA_4_S

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Devices](ms-xhelp:///?Id=beckhoff-6e24-4037-9db1-b195b107840a)
5. [Theben](ms-xhelp:///?Id=beckhoff-bf82-4b3f-bbbd-70c4e1f85c36)
6. FB\_DALI\_Theben\_TA\_4\_S

# FB\_DALI\_Theben\_TA\_4\_S

![32825243](/tcplclib_tc3_dali/1033/Images/gif/9007209615831051__Web.gif)

The function block represents the TA 4 S DALI-2 DALI push-button interface from Theben.

Up to 4 push buttons (instances 2 to 5) and 2 slider/temperature sensors (instances 0 and 1) can be connected via the device.

The push button inputs are configured as make contact (NO) in the delivery state. You can change the contact type to break contact (NC) via the properties (see [Properties](ms-xhelp:///?Id=beckhoff-5bee-463c-8ad5-071760615ae6)).

You can set the parameters of the two absolute inputs via the properties (see [Properties](ms-xhelp:///?Id=beckhoff-5bee-463c-8ad5-071760615ae6)). When delivered, 100 kOhm variable resistors can be connected directly.

For further information on configuration, please refer to the manufacturer's device documentation.

Further information on the supported instance types can be found here:

Part 301 (push buttons) – [Introduction](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf)

Part 302 (absolute encoder) - [Introduction](ms-xhelp:///?Id=beckhoff-071c-4f95-9a92-c586d5868580)

All inputs can be queried immediately via a positive edge at *bQueryInputValueN* and *bQueryAbsoluteInputN*.

The existing parameters can be overwritten by changing the properties listed below. The parameters are written to the device after a positive edge at *bInitialize*.

|  |  |
| --- | --- |
| 26991739 | Set the times so that as few events as possible are sent. If too many events are sent, this can have a negative effect on the behavior of the application. |

|  |  |
| --- | --- |
| 41599065 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bInitialize            : BOOL  := FALSE;  
nShortAddress          : BYTE  := 0;  
nOptions               : DWORD := 0;  
bQueryInputValue1      : BOOL  := FALSE;  
bQueryInputValue2      : BOOL  := FALSE;  
bQueryInputValue3      : BOOL  := FALSE;  
bQueryInputValue4      : BOOL  := FALSE;  
bQueryAbsoluteInput1   : BOOL  := FALSE;  
bQueryAbsoluteInput2   : BOOL  := FALSE;
```

**bInitialize:** The configuration of the DALI control device is started by a positive edge at this input. During this time no DALI commands are processed.

**nShortAddress:** Short address (0…63) of the DALI control device.

**nOptions:** Reserved for future extensions.

**bQueryInputValueN:** Direct query of the values at the button inputs 1 to 4.

**bQueryAbsoluteInputN:** Immediate query of the values at the absolute value inputs 1 to 2.

## VAR\_OUTPUT

```
bError                        : BOOL;  
ipResultMessage               : I_TcMessage;  
bInitializing                 : BOOL;  
bReadingInputValue1           : BOOL;  
bReadingInputValue2           : BOOL;  
bReadingInputValue3           : BOOL;  
bReadingInputValue4           : BOOL;  
bReadingAbsoluteInputValue1   : BOOL;  
bReadingAbsoluteInputValue2   : BOOL;  
nPushButton1Event             : WORD;  
nPushButton2Event             : WORD;  
nPushButton3Event             : WORD;  
nPushButton4Event             : WORD;  
nAbsoluteInput1               : BYTE;  
nAbsoluteInput2               : BYTE;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable ipResultMessage. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bInitializing:** The output is set as soon as the initialization of the DALI control device has been started, and remains active until all DALI commands have been executed.

**bReadingValueN:** The outputs are set as soon as the manual reading of the corresponding input has been triggered.

**nPushButtonNEvent:** The outputs output the events for the respective push button via one bit each for a cycle.

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

**nAbsoluteInputN:** Outputs containing the measured values, [°C] or [Ω], of the connected variable resistors. Please refer to the manufacturer documentation of the TA 4 S DALI-2 for the appropriate scaling of the output value.

## Properties

All parameters that are written to the DALI control device via *bInitialize* are available as properties.

The properties of instances of the same type are listed only once in the table and marked with N at the end.

| Name | Type | Access | Initial value | Description |
| --- | --- | --- | --- | --- |
| bEnablePushButtonN | BOOL | Get, Set | TRUE | Push button input 1 to 4, which can be enabled or disabled on the DALI control device. FALSE at this property causes sending of events from this instance to be disabled. However, the actual value of the instance can still be queried via the input *bQueryPushButtonN*. |
| nEventFilterPushButtonN | BYTE | Get, Set | 2#1000\_0011 | Setting of the [event filter](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf). |
| eEventPriorityInputN | E\_DALIEventPriority | Get, Set | Middle | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nDeadtimeTimerAbsoluteInputN | UINT | Get, Set | 100 ms | Dead time (0...12750 ms) to ensure that not too many events are sent in succession. An event is not sent until the dead time timer has expired. The dead time timer is restarted each time an event is sent. |
| nReportTimerAbsoluteInputN | BYTE | Get, Set | 0 s | Time [s] after which the pending event of the absolute encode is repeated if no other event has occurred in the meantime. |
| nDoubleTimerPushButtonN | UINT | Get, Set | 0 ms | Time (0, *tDoubleMin*…2000 ms) to distinguish between a single and a double keystroke. |
| nRepeatTimerPushButtonN | UINT | Get, Set | 160 ms | Interval (100…2000 ms) of repetitive events in the case of a long keystroke. |
| nShortTimerPushButtonN | UINT | Get, Set | 500 ms | Time (*tShortMin*...5100 ms) to distinguish between a long and a short keystroke. *tShortMin* is a manufacturer-specific value. |
| nStuckTimerPushButtonN | BYTE | Get, Set | 20 s | Time (5…255 s) after the expiry of which the push button no longer represents a long keystroke. The push button is stuck. |
| nContactTypePushButtonN | BYTE | Get, Set | 16#00 | Contact type of the push button:  16#00: Make contact NO (delivery state)  16#FF: Break contact NC |
| bEnableAbsoluteInputN | BOOL | Get, Set | FALSE | Absolute value input 1 or 2, which can be enabled or disabled on the DALI control device. FALSE at this property causes sending of events from this instance to be disabled. However, the actual value of the instance can still be queried via the input *bQueryAbsoluteInputN*. |
| eEventPriorityAbsoluteInputN | E\_DALIEventPriority | Get, Set | Middle | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nDeadtimeTimerAbsoluteInputN | UINT | Get, Set | 100 ms | Dead time (0...12750 ms) to ensure that not too many events are sent in succession. An event is not sent until the dead time timer has expired. The dead time timer is restarted each time an event is sent. |
| nReportTimerAbsoluteInputN | BYTE | Get, Set | 0 s | Time [s] after which the pending event of the absolute encode is repeated if no other event has occurred in the meantime. |
| nSensorTypeAbsoluteInputN | BYTE | Get, Set | 16#03 | Sensor type: 16#00: Theben sensors (9070321, 9070459, 9070489, 9070496).   16#01: Theben sensor (9070191). 16#02: any 100 kΩ NTC with known B or Beta [K] (see also value range parameter Beta Low / Beta High below). 16#03: 100 kΩ variable resistor (delivery state). |
| nBetaHighAbsoluteInputN | BYTE | Get, Set | 16#11 | If sensor type 16#02 has been selected, the associated B or Beta [K] should be set here. The B or Beta is a four-digit number in [K], which can be found in the data sheet of the NTC sensor. For storage in the memory bank, the four-digit number must first be converted to hex format and then stored in the Beta Low and Beta High bytes. Example: B or Beta = 4580, this corresponds to 16#11E4 • Beta Low = 16#E4, delivery state • Beta High = 16#11, delivery state • The setting range is 0x00...0xFF. |
| nBetaLowAbsoluteInputN | BYTE | Get, Set | 16#E4 | See *nBetaHighAbsoluteInputN* |
| nFilterAbsoluteInputN | BYTE | Get, Set | 16#00 | A filter can be set for noise suppression. The setting range is 16#00...16#0B.  16#00: each measured value is transmitted unchanged (delivery status) 16#01: average of 2 measured values (21). 16#02: average of 4 measured values (22). 16#00: average of 8 measured values (23). ... 16#00: average of 512 measured values (29). 16#00: average of 1024 measured values (210). 16#00: average of 2048 measured values (211).  **Attention**: The filter delays the measurement! |
| nHysteresisAbsoluteInputN | BYTE | Get, Set | 16#00 | Hysteresis value to avoid frequent events. The setting range is 16#00...16#FF. This corresponds to a value range of 0.1 °C...25.5 °C for sensor types 16#00...16#02 or a value range of 100 Ω...25.5 kΩ for sensor type 16#03. The step size of the hysteresis corresponds to 0.1 °C or 100 Ω. |
| nOffsetAbsoluteInputN | BYTE | Get, Set | 16#80 | The setting range of the offset is 16#01...16#FF. This corresponds to a value range of -12.7 °C...+12.7 °C for sensor types 16#00...16#02 or a value range of -12.7 kΩ...+12.7 kΩ for sensor type 16#03. The step size of the offset corresponds to 0.1 °C or 100 Ω.  The 16#80 in the delivery state corresponds to 0 °C or 0 Ω. |
| nRangeAbsoluteInputN | BYTE | Get, Set | 16#00 | Setting of the Range parameter:  16#00: Temperature sensors with a positive temperature range (delivery state).  16#01: Temperature sensors with a negative temperature range. |

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.20 | Tc3\_DALI from v3.7.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
