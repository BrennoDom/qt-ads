# FB_DALI304LightSensor

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Devices](ms-xhelp:///?Id=beckhoff-6e24-4037-9db1-b195b107840a)
5. FB\_DALI304LightSensor

# FB\_DALI304LightSensor

![37110132](/tcplclib_tc3_dali/1033/Images/png/27021605511075979__Web.png)

The function block is used for the configuration and operation of an instance of a DALI control device that supports Part 304 (light sensor).

Further information on the supported instance types can be found here:

Part 304 (light sensor) - [Introduction](ms-xhelp:///?Id=beckhoff-9545-4680-9025-766fb391cf97)

The properties can be used to configure whether the instance is enabled and how it behaves with regard to time (timer). In addition, values can also be queried immediately if necessary via the input variable *bQueryInputValue*.

The output variable *nBrightnessLevel* is written depending on the specified resolution *nResolution* (application and manufacturer-specific).

|  |  |
| --- | --- |
| 65555736 | Set the times so that as few events as possible are sent. If too many events are sent, this can have a negative effect on the behavior of the application. |

|  |  |
| --- | --- |
| 53130720 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bInitialize                 : BOOL  := FALSE;  
nShortAddress               : BYTE  := 0;  
nInstanceNumber             : BYTE  := 0;  
nResolution                 : BYTE  := 10;  
bQueryInputValue            : BOOL  := FALSE;  
bGetInputNotifications      : BOOL  := TRUE;  
nOptions                    : DWORD := 0;
```

**bInitialize:** The configuration of the DALI control device is started by a positive edge at this input. During this time no DALI commands are processed.

**nShortAddress:** Short address (0…63) of the DALI control device.

**nInstanceNumber:** Number of the instance (0…31) of the DALI control device to be addressed.

**nResolution**: Manufacturer-specific resolution (1...64) of the input value. The value specifies the number of bits with which the input value is scaled.

**bQueryInputValue:** Immediate query of the measured value. A query is also possible if the instance is locked via the property *bEnableInstance* .

**bGetInputNotifications:** A TRUE at this input causes the received *Input Notification Events* to be output at the output.

**nOptions:** Reserved for future extensions.

## VAR\_OUTPUT

```
bError                        : BOOL;  
ipResultMessage               : I_TcMessage;  
bInitializing                 : BOOL;  
bReadingInputValue            : BOOL;  
nBrightnessLevel              : ULINT;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bInitializing:** The output is set as soon as the initialization of the DALI control device has been started, and remains active until all DALI commands have been executed.

**bReadingInputValue:** The output is set as soon as the manual reading of the measured value has been started and remains active until all DALI commands have been processed.

**nBrightnessLevel:** Measured brightness value of the light sensor.

|  |  |
| --- | --- |
| 8414436 | This measured value must be compared with the measured reference values at the place of operation of the DALI control device. |

## PROPERTIES

All parameters that are written to the DALI control device via *bInitialize* are available as properties.

| Name | Type | Access | Initial value | Description |
| --- | --- | --- | --- | --- |
| bEnableInstance | BOOL | Get, Set | TRUE | The instance can be enabled or disabled on the DALI control device. If this property is FALSE, sending events from this instance is disabled. However, the actual value of the instance can still be queried via the input *bQueryInputValue*. |
| eEventPriority | E\_DALIEventPriority | Get, Set | MiddleLow | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |
| nDeadtimeTimer | UINT | Get, Set | 1500 ms | Dead time (0...12750 ms) to ensure that not too many events are sent in succession. An event is not sent until the dead time timer has expired. The dead time timer is restarted each time an event is sent. |
| nHysteresis | BYTE | Get, Set | 5 % | Value (0…25 %) for calculating a hysteresis value in order to prevent frequent and disturbing changes when measuring the illuminance. |
| nHysteresisMin | BYTE | Get, Set | 10 | Since the percentage hysteresis can also lead to strong fluctuations when the illuminance is low, a minimum hysteresis can be specified via this property. The minimum hysteresis is an absolute value with a value range from 0 to 255. The value depends on the resolution. |
| nReportTimer | BYTE | Get, Set | 30 s | Time (0…255 s) after which the pending event of the light sensor is repeated if no other event has occurred in the meantime. |

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
