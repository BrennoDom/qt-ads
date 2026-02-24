# FB_DALI_Loytec_LDALI_BM2

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Devices](ms-xhelp:///?Id=beckhoff-6e24-4037-9db1-b195b107840a)
5. [Loytec](ms-xhelp:///?Id=beckhoff-5ef8-4ddf-8346-4de944d9097e)
6. FB\_DALI\_Loytec\_LDALI\_BM2

# FB\_DALI\_Loytec\_LDALI\_BM2

![53591696](/tcplclib_tc3_dali/1033/Images/png/27021605634603659__Web.png)

The function block represents the LDALI-BM2 DALI push-button interface from Loytec.

Up to four push buttons (instances 0, 3, 6, and 7) can be connected directly via the device.

The first two inputs are configurable so that NTC/PTC temperature sensors (instances 1 and 4) or potentiometers/slide resistors (instances 2 and 5) can be used instead of push buttons.

These functions can be configured via the properties *eInput1Configuration* and *eInput2Configuration* (see [E\_DALILoytecInputConfiguration](ms-xhelp:///?Id=beckhoff-de99-4797-8057-52cd1d3633bd)).

The resistance value is read directly on setting one of the two inputs as Generic Input (resistance thermometer). This readout takes place when a positive edge is detected at the respective input *bQueryInputValue1* or *bQueryInputValue2*.

The resistance value is read in % when setting one of the two inputs as Absolute Input (potentiometer). The corresponding channel is configured via the property *eResistanceValueAbsoluteInput1* or *eResistanceValueAbsoluteInput2* on the connected resistor (1 kΩ or 10 kΩ) (see Use of properties). The output value lies between 0 (0 %) and 31 (100 %).

The inputs can be queried via a positive edge at *bQueryInputValueN*.

In addition, the time-dependent querying of these values is possible. The properties *nReportTimerAbsoluteInput1* and *nReportTimerAbsoluteInput2* are used for this. The value is read again on expiry of the set time [s]. To prevent events following one another too quickly, a dead time [ms] can be set via the properties *nDeadtimeTimerAbsoluteInput1* and *nDeadtimeTimerAbsoluteInput2*.

The push button inputs 3 and 4 can be disabled via the properties *bEnableInput3* and *bEnableInput4*.

All parameters are written to the DALI control device by a positive edge at *bInitialize* and stored there.

The existing parameters can be overwritten by changing the properties listed below.

|  |  |
| --- | --- |
| 12563221 | Set the times so that as few events as possible are sent. If too many events are sent, this can have a negative effect on the behavior of the application. |

|  |  |
| --- | --- |
| 45960129 | Set the event priorities on the properties *eEventPriorityInput1* and *eEventPriorityInput2* to the value *MiddleLow* if the inputs are not used as push buttons. |

|  |  |
| --- | --- |
| 10987981 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bInitialize                      : BOOL  := FALSE;  
nShortAddress                    : BYTE  := 0;  
nOptions                         : DWORD := 0;  
bQueryInputValue1                : BOOL  := FALSE;  
bQueryInputValue2                : BOOL  := FALSE;  
bQueryInputValue3                : BOOL  := FALSE;  
bQueryInputValue4                : BOOL  := FALSE;
```

**bInitialize:** The configuration of the DALI control device is started by a positive edge at this input. During this time no DALI commands are processed.

**nShortAddress:** Short address (0…63) of the DALI control device.

**nOptions:** Reserved for future extensions.

**bQueryInputValueN:** The state of the corresponding input is queried immediately by a positive edge at this input. Values of resistance sensors (setting of the input as Generic Input) can only be queried manually and not event-driven.

## VAR\_OUTPUT

```
bError                  : BOOL;  
ipResultMessage         : I_TcMessage;  
bInitializing           : BOOL;  
bReadingInputValue1     : BOOL;  
bReadingInputValue2     : BOOL;  
bReadingInputValue3     : BOOL;  
bReadingInputValue4     : BOOL;  
nPushButton1Event       : WORD;  
nGenericInput1          : UINT;  
nAbsoluteInput1         : BYTE;  
nPushButton2Event       : WORD;  
nGenericInput2          : UINT;  
nAbsoluteInput2         : BYTE;  
nPushButton3Event       : WORD;  
nPushButton4Event       : WORD;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

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

**nGenericInputN:** Outputs containing the measured values of the connected resistance sensors (NTC/PTC).

**nAbsoluteInputN:** Outputs containing the measured values of the connected potentiometers or slide resistors. The individual ranges are scaled from 0 to 100 %, with the following output values: 0 = 0 % and 31 = 100 %.

## PROPERTIES

All parameters that are written to the DALI control device via *bInitialize* are available as properties.

The properties of instances of the same type are listed only once in the table and marked with N at the end.

| Name | Type | Access | Initial value | Description |
| --- | --- | --- | --- | --- |
| eInputNConfiguration | [E\_DALILoytecInputConfiguration](ms-xhelp:///?Id=beckhoff-de99-4797-8057-52cd1d3633bd) | Get, Set | PushButton | Configuration of input 1 or 2 as a push button or analog input for the connection of potentiometers or resistance sensors, e.g. NTC/PTC. |
| eResistanceValueAbsoluteInputN | [E\_DALILoytecResistanceConfiguration](ms-xhelp:///?Id=beckhoff-7db4-450b-8e94-4f9c93063ff6) | Get, Set | Resistance10kOhm | Configuration of the resistance value of the potentiometer or slide resistor at input 1 or 2. |
| bEnablePushButtonN | BOOL | Get, Set | TRUE | Push button input 3 or 4, which can be enabled or disabled on the DALI control device. FALSE at this property causes sending of events from this instance to be disabled. However, the actual value of the instance can still be queried via the input *bQueryPushButtonN*. |
| nEventFilterPushButtonN | BYTE | Get, Set | 2#1000\_0011 | Setting of the [event filter](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf). |
| eEventPriorityInputN | E\_DALIEventPriority | Get, Set | Middle | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nDeadtimeTimerAbsoluteInputN | UINT | Get, Set | 100 ms | Dead time (0...12750 ms) to ensure that not too many events are sent in succession. An event is not sent until the dead time timer has expired. The dead time timer is restarted each time an event is sent. |
| nReportTimerAbsoluteInputN | BYTE | Get, Set | 0 s | Time [0…255 s] after which the pending event of the absolute encoder is repeated if no other event has occurred in the meantime. |
| nDoubleTimerPushButtonN | UINT | Get, Set | 0 ms | Time (0, *tDoubleMin*…2000 ms) to distinguish between a single and a double keystroke. |
| nRepeatTimerPushButtonN | UINT | Get, Set | 160 ms | Interval (100…2000 ms) of repetitive events in the case of a long keystroke. |
| nShortTimerPushButtonN | UINT | Get, Set | 500 ms | Time (*tShortMin*...5100 ms) to distinguish between a long and a short keystroke. *tShortMin* is a manufacturer-specific value. |
| nStuckTimerPushButtonN | BYTE | Get, Set | 20 s | Time (5…255 s) after the expiry of which the push button no longer represents a long keystroke. The push button is stuck. |

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
