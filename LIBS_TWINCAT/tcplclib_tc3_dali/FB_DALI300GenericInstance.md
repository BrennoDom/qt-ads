# FB_DALI300GenericInstance

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Devices](ms-xhelp:///?Id=beckhoff-6e24-4037-9db1-b195b107840a)
5. FB\_DALI300GenericInstance

# FB\_DALI300GenericInstance

![7106508](/tcplclib_tc3_dali/1033/Images/png/27021605901790475__Web.png)

The function block is used for the direct reading of generic values of an instance of a DALI control device that supports Part 103 (instance type 0).

The input variable *bEnableInstance* can be used to configure whether the instance is enabled.

If necessary, the output value can also be queried immediately using the variable *bQueryInputValue*.

|  |  |
| --- | --- |
| 63958576 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bInitialize                 : BOOL  := FALSE;  
nShortAddress               : BYTE  := 0;  
nInstanceNumber             : BYTE  := 0;  
nResolution                 : BYTE  := 10;  
bQueryInputValue            : BOOL  := FALSE;  
nOptions                    : DWORD := 0;
```

**bInitialize:** The configuration of the DALI control device is started by a positive edge at this input. During this time no DALI commands are processed.

**nShortAddress:** Short address (0…63) of the DALI control device.

**nInstanceNumber:** Number of the instance (0…31) of the DALI control device to be addressed.

**nResolution**: Manufacturer-specific resolution (1...64) of the input value. The value specifies the number of bits with which the input value is scaled.

**bQueryInputValue:** Immediate query of the measured value. A query is also possible if the instance is locked via the property *bEnableInstance*.

**nOptions:** Reserved for future extensions.

## VAR\_OUTPUT

```
bError                  : BOOL;  
ipResultMessage         : I_TcMessage;  
bInitializing           : BOOL;  
bReadingInputValue      : BOOL;  
nValue                  : ULINT;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bInitializing:** The output is set as soon as the initialization of the DALI control device has been started, and remains active until all DALI commands have been executed.

**bReadingInputValue:** The output is set as soon as the manual reading of the measured value has been started and remains active until all DALI commands have been processed.

**nValue:** Outputs the measured value.

## PROPERTIES

All parameters that are written to the DALI control device via *bInitialize* are available as properties.

| Name | Type | Access | Initial value | Description |
| --- | --- | --- | --- | --- |
| bEnableInstance | BOOL | Get, Set | TRUE | The instance can be enabled or disabled on the DALI control device. If this property is FALSE, sending events from this instance is disabled. However, the actual value of the instance can still be queried via the input *bQueryInputValue*. |
| nEventFilter | DWORD | Get, Set | 16#00\_00\_00\_00 | Setting of the event filter. |
| eEventPriority | E\_DALIEventPriority | Get, Set | MiddleLow | Setting of the [event priority](ms-xhelp:///?Id=beckhoff-708d-47aa-9cfa-2706c5d5c470). |

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
