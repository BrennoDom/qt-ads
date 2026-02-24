# FB_DALI102QueryExtendedVersionNumber

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-f3c7-4b21-a3cb-088caa074ef9)
6. [Application extended commands](ms-xhelp:///?Id=beckhoff-5e73-4667-9be9-c1c1151e063b)
7. FB\_DALI102QueryExtendedVersionNumber

# FB\_DALI102QueryExtendedVersionNumber

![4150710](/tcplclib_tc3_dali/1033/Images/gif/18014404366382731__Web.gif)

The *extendedVersionNumber* variable is read from the DALI control gear. It specifies the version for the implemented, application-related extension commands.

This command belongs to the application-related extension commands.

|  |  |
| --- | --- |
| 37356392 | Since each DALI control gear can support several device types, the DALI command ENABLE DEVICE TYPE must be called before each application-related extension command. Application-related extension commands are defined in the IEC 62386-2xx standard. |

The function block FB\_DALI102QueryExtendedVersionNumber independently executes the DALI command ENABLE DEVICE TYPE internally.

The input variable *nDeviceType* specifies for which device type the variable *extendedVersionNumber* is to be read.

## VAR\_INPUT

```
bStart            : BOOL;  
nAddress          : BYTE;  
eAddressType      : E_DALIAddressType := E_DALIAddressType.Short;  
eCommandPriority  : E_DALICommandPriority := E_DALICommandPriority.MiddleLow;  
eDeviceType       : E_DALIDeviceType;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nAddress:** Address of a DALI device or a DALI group.

**eAddressType:** Defines whether the input *nAddress* contains a short address (0…63) or a group address (0…15). Input *nAddress* has no meaning if a broadcast or a broadcast to unaddressed devices (BroadcastUnaddr) has been selected (see [E\_DALIAddressType](ms-xhelp:///?Id=beckhoff-8a4e-4869-9ea1-1920c00d61f5)).

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 663215 | *eCommandPriority* has no function with the KL6811. The command priorities are supported by the KL6821 from the firmware version BD. |

**eDeviceType:** Identification of the device type (see [E\_DALIDeviceType](ms-xhelp:///?Id=beckhoff-1044-42a7-9d1e-50f3758e68ec)).

## VAR\_OUTPUT

```
bError                  : BOOL;  
ipResultMessage         : I_TcMessage;  
bBusy                   : BOOL;  
nExtendedVersionNumber  : BYTE;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

**nExtendedVersionNumber:** Extended version number of the control gear.

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
