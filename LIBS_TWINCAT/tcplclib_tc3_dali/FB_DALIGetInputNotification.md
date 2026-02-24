# FB_DALIGetInputNotification

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Events](ms-xhelp:///?Id=beckhoff-bdcd-4fd3-8748-5fa268c4f125)
5. FB\_DALIGetInputNotification

# FB\_DALIGetInputNotification

![43629015](/tcplclib_tc3_dali/1033/Images/gif/9007205111700747__Web.gif)

The function block filters all received *Input Notification Events* according to certain filter criteria.

Each *Input Notification* contains the address of the sender and the event information (Event Info).

The address of the sender consists of two fields. The meaning of these fields is defined in the DALI control device by the event scheme (see [E\_DALIEventScheme](ms-xhelp:///?Id=beckhoff-335b-4381-bd96-70abcedc4e61)). The value of the event scheme can be read with the function block [FB\_DALI103QueryEventScheme](ms-xhelp:///?Id=beckhoff-e89b-4e93-a719-aef51359535a) and written with the function block [FB\_DALI103SetEventScheme](ms-xhelp:///?Id=beckhoff-9d45-48fb-b8ed-6e7f1640c9f9). The two fields are a combination of the short address, instance number, instance type, instance group or device group.

The respective event can be determined through the event information.

The possible values of the events for the respective instance types can be found here:

Part 301 (push buttons) – [introduction](ms-xhelp:///?Id=beckhoff-9269-4225-99b2-0eb0584f7ebf)

Part 302 (input devices, absolute encoder) - [Introduction](ms-xhelp:///?Id=beckhoff-071c-4f95-9a92-c586d5868580)

Part 303 (occupancy sensors) - [introduction](ms-xhelp:///?Id=beckhoff-5860-45ad-91f4-6edf1ff97245)

Part 304 (light sensors) - [introduction](ms-xhelp:///?Id=beckhoff-9545-4680-9025-766fb391cf97)

The source of the *Input Notification* is defined by the inputs *eEventScheme*, *nAddressInfo1* and *nAddressInfo2*. As soon as an *Input Notification* is received from this source, the output *bNewData* is set and the event information is output on the output *nEventInfo*.

For each *Input Notification Event*, which is to be received and processed further, an instance of FB\_DALIGetInputNotification must be created and configured with the correct filter criteria.

Moreover, this information can also be obtained at runtime with the help of the [TwinCAT Communication Monitor](ms-xhelp:///?Id=beckhoff-31d0-41d2-b459-c713712c917d) extension.

|  |  |
| --- | --- |
| 57116823 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bEnable         : BOOL;  
eEventScheme    : E_DALIEventScheme := E_DALIEventScheme.DeviceInstance;  
nAddressInfo1   : BYTE;  
nAddressInfo2   : BYTE;
```

**bEnable:** If this input is TRUE, all received *Input Notification Events* of the DALI control devices are output according to the specified filter criteria. The filter criteria are defined by the inputs *eEventScheme*, *nAddressInfo1* and *nAddressInfo2*.

**eEventScheme:** This input specifies the event scheme that the expected event must have. The event scheme also determines the meaning of the two inputs *nAddressInfo1* and *nAddressInfo2* (see [E\_DALIEventScheme](ms-xhelp:///?Id=beckhoff-335b-4381-bd96-70abcedc4e61)).

**nAddressInfo1, nAddressInfo2:** (see table below)

| eEventScheme | nAddressInfo1 | nAddressInfo2 |
| --- | --- | --- |
| E\_DALIEventScheme.Instance | Instance type (0...31) | Instance number (0..31) |
| E\_DALIEventScheme.Device | Short address (0…63) | Instance type (0…31) |
| E\_DALIEventScheme.DeviceInstance | Short address (0…63) | Instance number (0…31) |
| E\_DALIEventScheme.DeviceGroup | Device group (0…31) | Instance type (0…31) |
| E\_DALIEventScheme.InstanceGroup | Instance group (0…31) | Instance type (0…31) |

## VAR\_OUTPUT

```
bError                  : BOOL;  
ipResultMessage         : I_TcMessage;  
bNewData                : BOOL;  
nEventInfo              : WORD;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bNewData:** As soon as an *Input Notification Event* meets the desired filter criteria, this output is set to TRUE for one PLC cycle.

**nEventInfo:** If the output *bNewData* is TRUE, further information about the event can be found at this output. The exact meaning depends on the device type and is described in the respective Part 3xx of IEC 62386.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.29 | Tc3\_DALI from v3.1.4.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
