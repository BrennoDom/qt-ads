# FB_DALI_Tridonic_XC_G3_CWM30

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Devices](ms-xhelp:///?Id=beckhoff-6e24-4037-9db1-b195b107840a)
5. [Tridonic](ms-xhelp:///?Id=beckhoff-d733-41fc-861d-fb9fd0e0bfd5)
6. FB\_DALI\_Tridonic\_XC\_G3\_CWM30

# FB\_DALI\_Tridonic\_XC\_G3\_CWM30

![23890167](/tcplclib_tc3_dali/1033/Images/gif/9007208249394955__Web.gif)

The function block represents the DALI XC G3 CWM 30 DA2 DALI push-button interface from Tridonic.

Up to four push buttons (instances 0 to 3) can be connected directly via the device.

For information on the exact functions of the individual instances, please refer to the manufacturer's device documentation.

Further information on the supported instance types can be found here:

Part 301 (push buttons) - [Introduction](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf)

The existing parameters can be overwritten by changing the properties listed below.

The input variables *bQueryInputValueN* trigger the manual reading of the corresponding instance.

The properties *bEnablePushButtonN* make it possible to block individual instances.

All parameters are written to the DALI control device by a positive edge at *bInitialize* and stored there.

|  |  |
| --- | --- |
| 13684913 | Set the times so that as few events as possible are sent. If too many events are sent, this can have a negative effect on the behavior of the application. |

|  |  |
| --- | --- |
| 56055356 | The function block cannot be used when using the KL6811. |

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

**bQueryInputValueN:** The state of the corresponding push button is queried immediately by a positive edge at this input.

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
nPushButton2Event       : WORD;  
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

## PROPERTIES

All parameters that are written to the DALI control device via *bInitialize* are available as properties.

The properties of instances of the same type are listed only once in the table and marked with N at the end.

| Name | Type | Access | Initial value | Description |
| --- | --- | --- | --- | --- |
| bEnablePushButtonN | BOOL | Get, Set | TRUE | Push button input 1...4, which can be either enabled or disabled on the DALI control device. FALSE at this property causes sending of events from this instance to be disabled. However, the actual value of the instance can still be queried via the input *bQueryPushButtonN*. |
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
