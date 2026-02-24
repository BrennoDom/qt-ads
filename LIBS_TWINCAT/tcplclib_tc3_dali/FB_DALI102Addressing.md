# FB_DALI102Addressing

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Applications](ms-xhelp:///?Id=beckhoff-bd9c-45d9-9ddb-74b3ed68e5b8)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-4b6c-4c81-97bd-55dd3a8527c6)
6. [Addressing](ms-xhelp:///?Id=beckhoff-71c5-47f5-976f-d2aad14ed7a9)
7. FB\_DALI102Addressing

# FB\_DALI102Addressing

![38627455](/tcplclib_tc3_dali/1033/Images/gif/9007205111660427__Web.gif)

This function block addresses the DALI control gears at random. The user has no influence on which DALI control gear is assigned which short address. Short addresses are allocated in ascending order.

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. Depending on the selected options (parameter *nOptions*) the group membership and scenes are subsequently deleted. The terminal now addresses all DALI control gears independently. Once all DALI control gears have been addressed, the *bBusy* output goes back to FALSE. The *nAddressedDevices* output variable supplies information about how many DALI control gears have received a short address. Processing this function block can take several minutes, depending on how many DALI control gears are attached.

## VAR\_INPUT

```
bStart                  : BOOL;  
nStartWithShortAddress  : BYTE := 0;  
nOptions                : DWORD := Tc3_DALI.GVL.cOpticalFeedback;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nStartWithShortAddress:** Short address, assigned to the first DALI control gear (0...63).

**nOptions:** Options for addressing the DALI control gears (see table below). The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| Tc3\_DALI.GVL.cCompleteNewInstallation | All control gears are re-addressed, including control gears that already have a short address. |
| Tc3\_DALI.GVL.cDeleteAllGroupAssignments | Before addressing commences, any group assignments are deleted for all control gears, including those that are not actually addressed. |
| Tc3\_DALI.GVL.cDeleteAllSceneAssignments | Before addressing commences, any scene assignments are deleted for all control gears, including those that are not actually addressed. |
| Tc3\_DALI.GVL.cOpticalFeedback | Prior to addressing, all control gears are set to *minLevel*. Newly addressed control gears are assigned *maxLevel* brightness after assignment of the short address. |

## VAR\_OUTPUT

```
bError             : BOOL;  
ipResultMessage    : I_TcMessage;  
bBusy              : BOOL;  
nAddressedDevices  : BYTE;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

**nAddressedDevices:** If addressing has been completed (*bBusy* is FALSE), then the number of addressed control gears is shown at this output.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.29 | Tc3\_DALI from v3.1.4.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
