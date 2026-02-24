# FB_DALI103SetSearchAddress

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 103 (control devices)](ms-xhelp:///?Id=beckhoff-9bac-4896-8ced-1a399a3b5aad)
6. [Special commands](ms-xhelp:///?Id=beckhoff-f69d-4212-a050-09b3ac3131f4)
7. FB\_DALI103SetSearchAddress

# FB\_DALI103SetSearchAddress

![43084165](/tcplclib_tc3_dali/1033/Images/gif/9007205112033803__Web.gif)

The function block stores the value *nSearchAddress* in the [searchAddress](ms-xhelp:///?Id=beckhoff-37b2-43d4-abe8-716d667040d6) variable for all selected DALI control devices.

DALI control devices are selected if the DALI command INITIALISE (see [FB\_DALI103Initialise](ms-xhelp:///?Id=beckhoff-ee71-48f0-a3d9-b1176d6782a5)) was executed previously.

The DALI commands SEARCHADDRH, SEARCHADDRM and SEARCHADDRL are called internally.

This function block is required if addressing of the DALI control devices is to be implemented in the PLC. The function block [FB\_DALI103Addressing](ms-xhelp:///?Id=beckhoff-cfe2-4b73-a793-e7fed7a088c0) can be used to assign the addresses from the PLC.

|  |  |
| --- | --- |
| 52213166 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bStart            : BOOL;  
eCommandPriority  : E_DALICommandPriority := E_DALICommandPriority.Middle;  
nSearchAddress    : UDINT;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 156454 | The command priorities are supported by the KL6821 from the firmware version BD. |

**nSearchAddress:** The value to be written to the *searchAddress* variable (0x00 00 00…0xFF FF FF).

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

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.29 | Tc3\_DALI from v3.1.4.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
