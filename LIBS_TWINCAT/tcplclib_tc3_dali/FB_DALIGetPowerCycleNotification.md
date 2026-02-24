# FB_DALIGetPowerCycleNotification

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Events](ms-xhelp:///?Id=beckhoff-bdcd-4fd3-8748-5fa268c4f125)
5. FB\_DALIGetPowerCycleNotification

# FB\_DALIGetPowerCycleNotification

![44289360](/tcplclib_tc3_dali/1033/Images/gif/9007205111672203__Web.gif)

Filters all received *Power Cycle Notification Events*.

Each *Power Cycle Notification Event* sent by a DALI control device contains two fields that provide information about the event source. These two fields are the short address and the smallest group address to which the DALI control device belongs.

An instance of FB\_DALIGetPowerCycleNotification must be created for each KL6821 through which *Power Cycle Notification Events* are to be received and processed. If a *Power Cycle Notification* *Event* is detected, the output *bNewData* is set to TRUE for one PLC cycle. The two outputs *nShortAddress* and *nLowestDeviceGroup* provide information about the exact source of the event.

|  |  |
| --- | --- |
| 63059925 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bEnable            : BOOL;
```

**bEnable:** If this input is TRUE, all received *Power Cycle Notification Events* of the DALI control devices are output.

## VAR\_OUTPUT

```
bError                  : BOOL;  
ipResultMessage         : I_TcMessage;  
bNewData                : BOOL;  
nShortAddress           : BYTE;  
nLowestDeviceGroup      : BYTE;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bNewData:** As soon as a *Power Cycle Notification Event* matches the desired filter criteria, this output is set to TRUE for one PLC cycle.

**nShortAddress:** This output contains the short address (0…63) of the DALI control device that sent the *Power Cycle Notification Event*. If the DALI control device does not have a short address, 255 (MASK) is output.

**nLowestDeviceGroup:** This output contains the lowest group address (0…31) of the DALI control device that sent the *Power Cycle Notification Even*t. If the DALI control device is not assigned to a group, 255 (MASK) is output.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.29 | Tc3\_DALI from v3.1.4.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
