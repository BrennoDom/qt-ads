# FB_DALI209QueryColourValue

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 209 (color/color temperature control)](ms-xhelp:///?Id=beckhoff-d816-4de1-bd09-5e02b92cfc27)
6. [Query commands](ms-xhelp:///?Id=beckhoff-7f84-4906-8744-e291b2a80913)
7. FB\_DALI209QueryColourValue

# FB\_DALI209QueryColourValue

![66948675](/tcplclib_tc3_dali/1033/Images/gif/9007205692924043__Web.gif)

The specified variable (color value) is read from the DALI control gear. The value to be read is defined by *eColourValue*.

Certain variables can be read directly by DALI commands (e.g. [FB\_209QueryColourStatus](ms-xhelp:///?Id=beckhoff-bf40-4ec1-9ae2-4b4f83c3bbdc)). Further details on the variables can be found in section [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7).

The response must be 255 (MASK) if the control gear does not know the coordinates or if the primary color is not present.

|  |  |
| --- | --- |
| 65667169 | Prior to the DALI command QUERY COLOUR VALUE, the function block sends the DALI command ENABLE DEVICE TYPE 8, as is necessary for application-related extension commands (see also [FB\_DALI102EnableDeviceType](ms-xhelp:///?Id=beckhoff-6f87-4d1b-b5a6-4f03ac5df1fb)). |

|  |  |
| --- | --- |
| 54133615 | The function block changes the DTR0 of all connected DALI control gears. |

## VAR\_INPUT

```
bStart               : BOOL;  
nAddress             : BYTE;  
eAddressType         : E_DALIAddressType := E_DALIAddressType.Short;  
eCommandPriority     : E_DALICommandPriority := E_DALICommandPriority.MiddleLow;  
eColourValue         : E_DALIColourValue;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nAddress:** Address of a DALI device or a DALI group.

**eAddressType:** Defines whether the input *nAddress* contains a short address (0…63) or a group address (0…15). Input *nAddress* has no meaning if a broadcast or a broadcast to unaddressed devices (BroadcastUnaddr) has been selected (see [E\_DALIAddressType](ms-xhelp:///?Id=beckhoff-8a4e-4869-9ea1-1920c00d61f5)).

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 17440495 | *eCommandPriority* has no function with the KL6811. The command priorities are supported by the KL6821 from the firmware version BD. |

**eColourValue:** Parameter to be read from the DALI control gear (see [E\_DALIColourValue](ms-xhelp:///?Id=beckhoff-4211-4277-aac9-68f1bcf4fdd5)).

## VAR\_OUTPUT

```
bError                    : BOOL;  
ipResultMessage           : I_TcMessage;  
bBusy                     : BOOL;  
nColourValue              : UINT;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

**nColourValue:** Contains the value of the read parameter.

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.10 | Tc3\_DALI from v3.4.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
