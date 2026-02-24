# FB_DALI301PushButton

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Devices](ms-xhelp:///?Id=beckhoff-6e24-4037-9db1-b195b107840a)
5. FB\_DALI301PushButton

# FB\_DALI301PushButton

![38756276](/tcplclib_tc3_dali/1033/Images/gif/27021605507076491__Web.gif)

The function block is used for the configuration and operation of an instance of a DALI control device that supports Part 301 (push buttons).

Further information on the supported instance types can be found here:

Part 301 (push buttons) - [Introduction](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf)

If necessary, the output value can also be queried immediately using the variable *bQueryInputValue*.

|  |  |
| --- | --- |
| 13262169 | Set the times so that as few events as possible are sent. If too many events are sent, this can have a negative effect on the behavior of the application. |

|  |  |
| --- | --- |
| 52250665 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bInitialize                 : BOOL  := FALSE;  
nShortAddress               : BYTE  := 0;  
nInstanceNumber             : BYTE  := 0;  
bQueryInputValue            : BOOL  := FALSE;  
bGetInputNotifications      : BOOL  := TRUE;  
nOptions                    : DWORD := 0;
```

**bInitialize:** The configuration of the DALI control device is started by a positive edge at this input. During this time no DALI commands are processed.

**nShortAddress:** Short address (0…63) of the DALI control device.

**nInstanceNumber:** Number of the instance (0…31) of the DALI control device to be addressed.

**bQueryInputValue:** The state of the input is queried immediately by a positive edge at this input. A query is also possible if the instance is locked via the property *bEnableInstance* .

**bGetInputNotifications:** A TRUE at this input causes the received *Input Notification Events* to be output at the output.

**nOptions:** Reserved for future extensions.

## VAR\_OUTPUT

```
bError                  : BOOL;  
ipResultMessage         : I_TcMessage;  
bInitializing           : BOOL;  
bReadingInputValue      : BOOL;  
nPushButtonEvent        : WORD;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bInitializing:** The output is set as soon as the initialization of the DALI control device has been started, and remains active until all DALI commands have been executed.

**bReadingInputValue:** The output is set as soon as the manual reading of the measured value has been started and remains active until all DALI commands have been processed.

**nPushButtonEvent:** The output outputs the events via one bit each for a cycle.

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

| Name | Type | Access | Initial value | Description |
| --- | --- | --- | --- | --- |
| bEnableInstance | BOOL | Get, Set | TRUE | The instance can be enabled or disabled on the DALI control device. If this property is FALSE, sending events from this instance is disabled. However, the actual value of the instance can still be queried via the input *bQueryInputValue*. |
| nEventFilter | BYTE | Get, Set | 2#1000\_0011 | Setting of the [event filter](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf). |
| eEventPriority | E\_DALIEventPriority | Get, Set | Middle | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nRepeatTimer | UINT | Get, Set | 160 ms | Time (100...2000 ms) after which the pending event of the push button is repeated in case of a long keystroke. |
| nShortTimer | UINT | Get, Set | 500 ms | Time (*tShortMin*...5100 ms) to distinguish between a long and a short keystroke |
| nDoubleTimer | UINT | Get, Set | 0 ms | Time (0, *tDoubleMin*…2000 ms) to distinguish between a single and a double keystroke. |
| nStuckTimer | BYTE | Get, Set | 20 s | Time (5…255 s) after the expiry of which the push button no longer represents a long keystroke. The push button is stuck. |

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
