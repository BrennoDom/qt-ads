# FB_DALI102WriteMemoryLocationNoReply

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-f3c7-4b21-a3cb-088caa074ef9)
6. [Special commands](ms-xhelp:///?Id=beckhoff-26f9-46a1-b2c5-bbd1b8053da6)
7. FB\_DALI102WriteMemoryLocationNoReply

# FB\_DALI102WriteMemoryLocationNoReply

![25151514](/tcplclib_tc3_dali/1033/Images/gif/6523002635__Web.gif)

The value *nValue* is written in the memory bank of the DALI control gear. The corresponding memory bank is specified by the input variable *nMemoryBank*, the address within the memory bank by the input variable *nOffset*.

The DALI commands ENABLE WRITE MEMORY and WRITE MEMORY LOCATION – NO REPLY are called internally.

|  |  |
| --- | --- |
| 25037038 | The function block changes the DTR0 and the DTR1 of all connected DALI control gears. |

|  |  |
| --- | --- |
| 24006753 | The function block sends the DALI command ENABLE WRITE MEMORY twice, as foreseen by the DALI standard for certain DALI commands. |

## VAR\_INPUT

```
bStart            : BOOL;  
nAddress          : BYTE;  
eAddressType      : E_DALIAddressType := E_DALIAddressType.Short;  
eCommandPriority  : E_DALICommandPriority := E_DALICommandPriority.MiddleLow;  
nMemoryBank       : BYTE := 0;  
nOffset           : BYTE := 0;  
nValue            : BYTE;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nAddress:** Address of a DALI device or a DALI group.

**eAddressType:** Defines whether the input *nAddress* contains a short address (0…63) or a group address (0…15). Input *nAddress* has no meaning if a broadcast or a broadcast to unaddressed devices (BroadcastUnaddr) has been selected (see [E\_DALIAddressType](ms-xhelp:///?Id=beckhoff-8a4e-4869-9ea1-1920c00d61f5)).

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 14734188 | *eCommandPriority* has no function with the KL6811. The command priorities are supported by the KL6821 from the firmware version BD. |

**nMemoryBank:** Specifies the memory bank for the write access.

**nOffset:** Address within the memory bank selected with the variable *nMemoryBank*.

**nValue:** Value to be written to the address within the memory bank.

## VAR\_OUTPUT

```
bError                  : BOOL;  
ipResultMessage         : I_TcMessage;  
bBusy                   : BOOL;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.0 | Tc3\_DALI from v3.1.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
