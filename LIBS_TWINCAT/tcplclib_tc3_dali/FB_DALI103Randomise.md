# FB_DALI103Randomise

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
7. FB\_DALI103Randomise

# FB\_DALI103Randomise

![34329433](/tcplclib_tc3_dali/1033/Images/gif/9007205112058379__Web.gif)

The function block generates a new random address for all selected DALI control devices and writes it to the *randomAddress* variable. DALI control devices are selected if the DALI command INITIALISE (see [FB\_DALI103Initialise](ms-xhelp:///?Id=beckhoff-ee71-48f0-a3d9-b1176d6782a5)) was executed previously.

This function block is required if addressing of the DALI control devices is to be implemented in the PLC. The function block [FB\_DALI103Addressing](ms-xhelp:///?Id=beckhoff-cfe2-4b73-a793-e7fed7a088c0) can be used to assign the addresses from the PLC.

|  |  |
| --- | --- |
| 40529449 | The function block sends the DALI command RANDOMIZE twice, as required by the DALI standard for certain DALI commands. |

|  |  |
| --- | --- |
| 29220727 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bStart            : BOOL;  
eCommandPriority  : E_DALICommandPriority := E_DALICommandPriority.Middle;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 61659956 | The command priorities are supported by the KL6821 from the firmware version BD. |

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
