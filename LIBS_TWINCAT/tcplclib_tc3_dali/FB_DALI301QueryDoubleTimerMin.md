# FB_DALI301QueryDoubleTimerMin

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 301 (push button)](ms-xhelp:///?Id=beckhoff-bb23-414b-871c-eaea68d61810)
6. FB\_DALI301QueryDoubleTimerMin

# FB\_DALI301QueryDoubleTimerMin

![53704644](/tcplclib_tc3_dali/1033/Images/gif/9007205111997835__Web.gif)

The function block reads the variable [tDoubleMin](ms-xhelp:///?Id=beckhoff-9595-416c-b047-7ae6bd54300b).

The value is read in steps of 20 ms.

|  |  |
| --- | --- |
| 13579756 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bStart                : BOOL;  
nAddress              : BYTE;   
eAddressType          : E_DALIAddressType := E_DALIAddressType.Short;  
nInstanceAddress      : BYTE := 0;  
eInstanceAddressType  : E_DALIInstanceAddressType := E_DALIInstanceAddressType.InstanceNumber;  
eCommandPriority      : E_DALICommandPriority := E_DALICommandPriority.MiddleLow;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nAddress:** Address of a DALI device or a DALI group.

**eAddressType:** Defines whether the input *nAddress* contains a short address (0…63) or a group address (0…31). Input *nAddress* has no meaning if a broadcast or a broadcast to unaddressed devices (BroadcastUnaddr) has been selected (see [E\_DALIAddressType](ms-xhelp:///?Id=beckhoff-8a4e-4869-9ea1-1920c00d61f5)).

**nInstanceAddress:** Instance number within a DALI control device. A DALI control device can support multiple instance numbers.

**eInstanceAddressType:** Defines the access type to the required instance within the DALI control device (see [E\_DALIInstanceAddressType](ms-xhelp:///?Id=beckhoff-ee74-466a-a10c-c2bfc99940ad)).

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 55108945 | The command priorities are supported by the KL6821 from the firmware version BD. |

## VAR\_OUTPUT

```
bError                  : BOOL;  
ipResultMessage         : I_TcMessage;  
bBusy                   : BOOL;  
nDoubleMin              : BYTE;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

**nDoubleMin:** Value of the variable *tDoubleMin* [20 ms].

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.29 | Tc3\_DALI from v3.1.4.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
