# FB_DALI102VerifyShortAddress

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
7. FB\_DALI102VerifyShortAddress

# FB\_DALI102VerifyShortAddress

![59962836](/tcplclib_tc3_dali/1033/Images/gif/9007205101910795__Web.gif)

For all selected DALI control gears, the function block checks whether the variable [shortAddress](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) matches the value *nShortAddress*.

DALI control gears are selected if the [randomAddress](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) of the DALI control gear is the same as the [searchAddress](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) and the DALI command INITIALIZE (see [FB\_DALI102Initialize](ms-xhelp:///?Id=beckhoff-1eaa-4d36-bbed-c2807b136b6c)) was executed previously.

This function block is required if addressing of the DALI control gears is to be implemented in the PLC. The function block [FB\_DALI102Addressing](ms-xhelp:///?Id=beckhoff-7cb8-4d09-a360-0c6f73431eea) can be used to assign the addresses from the PLC.

## VAR\_INPUT

```
bStart            : BOOL;  
eCommandPriority  : E_DALICommandPriority := E_DALICommandPriority.Middle;  
nShortAddress     : BYTE;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 2794612 | *eCommandPriority* has no function with the KL6811. The command priorities are supported by the KL6821 from the firmware version BD. |

**nShortAddress:** Short address with which the own short address is compared.

## VAR\_OUTPUT

```
bError             : BOOL;  
ipResultMessage    : I_TcMessage;  
bBusy              : BOOL;  
bAnswer            : BOOL;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

**bAnswer:** Is TRUE if *nShortAddress* is equal to its own short address.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.29 | Tc3\_DALI from v3.1.4.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
