# FB_DALI103ControlDevice

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Devices](ms-xhelp:///?Id=beckhoff-6e24-4037-9db1-b195b107840a)
5. FB\_DALI103ControlDevice

# FB\_DALI103ControlDevice

![43998472](/tcplclib_tc3_dali/1033/Images/gif/27021605507073547__Web.gif)

The function block is used for the configuration and operation of a DALI control unit that supports Part 103 (control units).

The application controller can be activated, the operation mode specified and the event *Power Cycle Notification* enabled.

|  |  |
| --- | --- |
| 60441935 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bInitialize                    : BOOL  := FALSE;  
nShortAddress                  : BYTE  := 0;  
bGetPowerCycleNotifications    : BOOL  := TRUE;  
nOptions                       : DWORD := 0;
```

**bInitialize:** The configuration of the DALI control device is started by a positive edge at this input. During this time no DALI commands are processed.

**nShortAddress:** Short address (0…63) of the DALI control device.

**bGetPowerCycleNotifications:** A TRUE at this input causes the received *Power Cycle Notification* to be output at the output.

**nOptions:** Reserved for future extensions.

## VAR\_OUTPUT

```
bError                               : BOOL;  
ipResultMessage                      : I_TcMessage;  
bInitializing                        : BOOL;  
bPowerCycleNotification              : BOOL;  
nPowerCycleNotificationShortAddress  : BYTE;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bInitializing:** The output is set as soon as the initialization of the DALI device has been started, and remains active until all DALI commands have been executed.

**bPowerCycleNotification:** As soon as a *Power Cycle Notification* Event matches the desired filter criteria, this output is set to TRUE for one PLC cycle.

**nPowerCycleNotificationShortAddress:** This output contains the short address (0…63) of the DALI control device that sent the *Power Cycle Notification Event*.

## PROPERTIES

All parameters that are written to the DALI control device via *bInitialize* are available as properties.

| Name | Type | Access | Initial value | Description |
| --- | --- | --- | --- | --- |
| bEnableApplicationController | BOOL | Get, Set | FALSE | If this property is TRUE, the application controller (see [Device variables](ms-xhelp:///?Id=beckhoff-37b2-43d4-abe8-716d667040d6)) is activated. |
| bEnablePowerCycleNotification | BOOL | Get, Set | FALSE | TRUE at this property enables the *Power Cycle Notification* event. |
| nOperatingMode | BYTE | Get, Set | 0 | Specification of the operation mode (0…255) of the DALI control device (see [Device variables](ms-xhelp:///?Id=beckhoff-37b2-43d4-abe8-716d667040d6)). |

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
