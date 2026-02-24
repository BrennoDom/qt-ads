# FB_DALI208QueryGearType

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 208 (device for switching functions)](ms-xhelp:///?Id=beckhoff-311e-40a1-9c96-ad05c0524017)
6. [Query commands](ms-xhelp:///?Id=beckhoff-bc83-4d8c-8e6b-515a62e87241)
7. FB\_DALI208QueryGearType

# FB\_DALI208QueryGearType

![6101690](/tcplclib_tc3_dali/1033/Images/gif/10380399627__Web.gif)

The function block reads the variable [gearType](ms-xhelp:///?Id=beckhoff-c35d-4ca0-9bd6-597c2a99a83f) from the DALI control gear.

|  |  |
| --- | --- |
| 54915211 | Prior to the DALI command QUERY GEAR TYPES, the function block sends the DALI command ENABLE DEVICE TYPE 7, as is necessary for application extended commands (see also [FB\_DALI102EnableDeviceType](ms-xhelp:///?Id=beckhoff-6f87-4d1b-b5a6-4f03ac5df1fb)). |

## VAR\_INPUT

```
bStart            : BOOL;  
nAddress          : BYTE;  
eAddressType      : E_DALIAddressType := E_DALIAddressType.Short;  
eCommandPriority  : E_DALICommandPriority := E_DALICommandPriority.MiddleLow;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nAddress:** Address of a DALI control gear or a DALI group.

**eAddressType:** Defines whether the input *nAddress* contains a short address (0…63) or a group address (0…15). Input *nAddress* has no meaning if a broadcast or a broadcast to unaddressed devices (BroadcastUnaddr) has been selected (see [E\_DALIAddressType](ms-xhelp:///?Id=beckhoff-8a4e-4869-9ea1-1920c00d61f5)).

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 24474856 | *eCommandPriority* has no function with the KL6811. The command priorities are supported by the KL6821 from the firmware version BD. |

## VAR\_OUTPUT

```
bError                : BOOL;  
ipResultMessage       : I_TcMessage;  
bBusy                 : BOOL;  
nGearType             : BYTE;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

**nGearType:** Contains information on the properties of the DALI control gear (see [gearType](ms-xhelp:///?Id=beckhoff-c35d-4ca0-9bd6-597c2a99a83f)).

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.20 | Tc3\_DALI from v3.7.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
