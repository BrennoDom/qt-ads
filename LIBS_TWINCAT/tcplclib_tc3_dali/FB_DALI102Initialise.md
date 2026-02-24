# FB_DALI102Initialise

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
7. FB\_DALI102Initialise

# FB\_DALI102Initialise

![22047016](/tcplclib_tc3_dali/1033/Images/gif/9007205101947147__Web.gif)

The function block prepares the addressing of the DALI control gears.

This function block is required if addressing of the DALI control gears is to be implemented in the PLC. The function block [FB\_DALI102Addressing](ms-xhelp:///?Id=beckhoff-7cb8-4d09-a360-0c6f73431eea) can be used to assign the addresses from the PLC.

*nParameter* is used to define which DALI control gears are taken into account for addressing:

| Value (binary) | Description |
| --- | --- |
| 0000 0000 | All DALI control gears respond. |
| 0AAA AAA1 | DALI control gears with the address 00AA AAAA respond. |
| 1111 1111 | DALI control gears without a short address respond. |

|  |  |
| --- | --- |
| 64205424 | The function block sends the DALI command INITIALIZE twice, as required by the DALI standard for certain DALI commands. |

## VAR\_INPUT

```
bStart            : BOOL;  
eCommandPriority  : E_DALICommandPriority := E_DALICommandPriority.Middle;  
nParameter        : BYTE := 2#1111_1111;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 40977906 | *eCommandPriority* has no function with the KL6811. The command priorities are supported by the KL6821 from the firmware version BD. |

**nParameter:** Specifies which control gears should react to this command (see table above).

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
