# FB_DALI103ReadMemoryBank

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Applications](ms-xhelp:///?Id=beckhoff-bd9c-45d9-9ddb-74b3ed68e5b8)
5. [Part 103 (control devices)](ms-xhelp:///?Id=beckhoff-d6bc-4a8f-bfae-12d6929c4de0)
6. [Settings](ms-xhelp:///?Id=beckhoff-0336-4b0a-9350-cde90f44683e)
7. FB\_DALI103ReadMemoryBank

# FB\_DALI103ReadMemoryBank

![39958021](/tcplclib_tc3_dali/1033/Images/gif/9007207201915403__Web.gif)

The specified memory bank of the DALI control device is read (see [Memory banks](ms-xhelp:///?Id=beckhoff-f157-4446-a05b-f675f276156a)). The memory bank is specified by the parameter *nMemoryBank*. The range to be read can be limited with the help of the parameters *nSubRangeStart* and *nSubRangeEnd*.

|  |  |
| --- | --- |
| 24077873 | The function block changes the DTR0 and the DTR1 of all connected DALI control devices. |

|  |  |
| --- | --- |
| 15374270 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bStart            : BOOL;  
nAddress          : BYTE;  
eAddressType      : E_DALIAddressType := E_DALIAddressType.Short;  
eCommandPriority  : E_DALICommandPriority := E_DALICommandPriority.Middle;  
nOptions          : DWORD := 0;  
bCancel           : BOOL;  
nMemoryBank       : BYTE := 0;  
nSubRangeStart    : BYTE(0..254) := 0;  
nSubRangeEnd      : BYTE := 255;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nAddress:** Address of a DALI control gear or a DALI group.

**eAddressType:** Defines whether the input *nAddress* contains a short address (0...63) or a group address (0...15). Input *nAddress* has no meaning if a broadcast or a broadcast to unaddressed devices (BroadcastUnaddr) has been selected (see [E\_DALIAddressType](ms-xhelp:///?Id=beckhoff-8a4e-4869-9ea1-1920c00d61f5)).

**eCommandPriority:** Priority (high, middle or low) with which the DALI commands are processed (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

**nOptions:** Reserved for future extensions.

**bCancel:** A rising edge at this input disables the function block and aborts the reading of the variables.

**nMemoryBank:** Specifies the memory bank for the read access.

**nSubRangeStart:** Offset inside the memory bank from which reading is to take place.

**nSubRangeEnd:** Offset inside the memory bank up to which reading is to take place.

| nSubRangeEnd | Description |
| --- | --- |
| 255 | Offset 0 of the memory bank determines the offset up to which reading is to take place. |
| 254 | Offset 0 is not read at the beginning. Reading always takes place up to Offset 254. |
| <=254 | *nSubRangeEnd* may not be greater than the value in Offset 0. The partial areas of the memory bank are read with this setting. |

## VAR\_OUTPUT

```
bError                        : BOOL;  
ipResultMessage               : I_TcMessage;  
bBusy                         : BOOL;  
nCurrentOffset                : BYTE;  
nLastOffset                   : BYTE;  
aValues                       : ARRAY [0..254] OF BYTE;  
aErrors                       : ARRAY [0..254] OF BOOL;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

**nCurrentOffset:** The offset that is currently being read is output at this output.

**nLastOffset:** Last valid offset of the memory bank that was read.

**aValues:** Array containing the read parameters of the memory bank.

**aErrors:** Array containing errors of the parameters of the memory bank that occurred during reading.

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.10 | Tc3\_DALI from v3.4.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
