# FB_DALI_Glamox_LMS_PB8_SwitchPanel

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Devices](ms-xhelp:///?Id=beckhoff-6e24-4037-9db1-b195b107840a)
5. [Glamox](ms-xhelp:///?Id=beckhoff-d179-41c3-a3a8-14738126cf10)
6. FB\_DALI\_Glamox\_LMS\_PB8\_SwitchPanel

# FB\_DALI\_Glamox\_LMS\_PB8\_SwitchPanel

![54938922](/tcplclib_tc3_dali/1033/Images/png/9007209646616715__Web.png)

The function block represents the LMS DALI-2 PB8 Switch Panel DALI push-button interface from Glamox.

Up to eight push buttons (instances 0 to 7) can be connected directly via the device.

For information on the exact functions of the individual instances, please refer to the manufacturer's device documentation.

Further information on the supported instance types can be found here:

Part 301 (push buttons) - [Introduction](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf)

The existing parameters can be overwritten by changing the properties listed below.

Readout of the corresponding instance can be triggered immediately via the input variables *bQueryInputValueN*.

The properties *bEnablePushButtonN* make it possible to block individual instances.

All parameters are written to the DALI control device by a positive edge at *bInitialize* and stored there.

|  |  |
| --- | --- |
| 24688256 | Set the times so that as few events as possible are sent. If too many events are sent, this can have a negative effect on the behavior of the application. |

|  |  |
| --- | --- |
| 20867713 | The function block cannot be used when using the KL6811. |

**VAR\_INPUT**

```
bInitialize        : BOOL  := FALSE;  
nShortAddress      : BYTE  := 0;  
nOptions           : DWORD := 0;  
bQueryInputValue1  : BOOL  := FALSE;  
bQueryInputValue2  : BOOL  := FALSE;  
bQueryInputValue3  : BOOL  := FALSE;  
bQueryInputValue4  : BOOL  := FALSE;  
bQueryInputValue5  : BOOL  := FALSE;  
bQueryInputValue6  : BOOL  := FALSE;  
bQueryInputValue7  : BOOL  := FALSE;  
bQueryInputValue8  : BOOL  := FALSE;
```

**bInitialize**: The configuration of the DALI control device is started by a positive edge at this input. During this time no DALI commands are processed.

**nShortAddress**: Short address (0…63) of the DALI control device.

**nOptions**: Reserved for future extensions.

**bQueryInputValueN**: The state of the corresponding push button is queried immediately by a positive edge at this input.

**VAR\_OUTPUT**

```
bError               : BOOL;  
ipResultMessage      : I_TcMessage;  
bInitializing        : BOOL;  
bReadingInputValue1  : BOOL;  
bReadingInputValue2  : BOOL;  
bReadingInputValue3  : BOOL;  
bReadingInputValue4  : BOOL;  
bReadingInputValue5  : BOOL;  
bReadingInputValue6  : BOOL;  
bReadingInputValue7  : BOOL;  
bReadingInputValue8  : BOOL;  
nPushButton1Event    : WORD;  
nPushButton2Event    : WORD;  
nPushButton3Event    : WORD;  
nPushButton4Event    : WORD;  
nPushButton5Event    : WORD;  
nPushButton6Event    : WORD;  
nPushButton7Event    : WORD;  
nPushButton8Event    : WORD;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see error evaluation) that can be used to obtain detailed information about the processing of the function block (see runtime messages). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bInitializing:** The output is set as soon as the initialization of the DALI control device has been started, and remains active until all DALI commands have been executed.

**bReadingInputValueN**: The outputs are set as soon as the manual reading of the corresponding input has been triggered.

**nPushButtonNEvent**: The outputs output the events for the respective push button via one bit each for a cycle.

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
| bEnablePushButtonN | BOOL | Get, Set | TRUE | TRUE at this property enables the instance. FALSE at this property causes sending of events from this instance to be disabled. However, the actual value of the instance can still be queried via the input *bQueryPushButtonN*. |
| nEventFilterPushButtonN | BYTE | Get, Set | 2#1000\_0011 | Setting of the [event filter](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf). |
| eEventPriorityPushButtonN | E\_DALIEventPriority | Get, Set | Middle | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nDoubleTimerPushButtonN | UINT | Get, Set | 0 ms | Time (0, *tDoubleMin*…2000 ms) to distinguish between a single and a double keystroke. |
| nRepeatTimerPushButtonN | UINT | Get, Set | 160 ms | Interval (100…2000 ms) of repetitive events in the case of a long keystroke. |
| nShortTimerPushButtonN | UINT | Get, Set | 500 ms | Time (*tShortMin*...5100 ms) to distinguish between a long and a short keystroke. *tShortMin* is a manufacturer-specific value. |
| nStuckTimerPushButtonN | BYTE | Get, Set | 20 s | Time (5…255 s) after the expiry of which the push button no longer represents a long keystroke. The push button is stuck. |

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.20 | Tc3\_DALI from v3.7.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
