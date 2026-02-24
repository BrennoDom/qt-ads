# FB_DALI103Addressing

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Applications](ms-xhelp:///?Id=beckhoff-bd9c-45d9-9ddb-74b3ed68e5b8)
5. [Part 103 (control devices)](ms-xhelp:///?Id=beckhoff-d6bc-4a8f-bfae-12d6929c4de0)
6. [Addressing](ms-xhelp:///?Id=beckhoff-2b03-48d8-8dec-0e8d82783e09)
7. FB\_DALI103Addressing

# FB\_DALI103Addressing

![21209668](/tcplclib_tc3_dali/1033/Images/gif/9007205111666315__Web.gif)

This function block addresses the DALI control devices at random. The user has no influence on which control device is assigned which short address. Short addresses are allocated in ascending order.

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. The terminal now addresses all DALI control devices independently. Once all DALI control devices have been addressed, the *bBusy* output goes back to FALSE. The output variable *nAddressedDevices* provides information on how many DALI control devices were assigned a short address. Depending on how many DALI control devices are connected, processing of this function block can take several minutes.

|  |  |
| --- | --- |
| 56669285 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bStart                  : BOOL;  
nStartWithShortAddress  : BYTE := 0;  
nOptions                : DWORD := Tc3_DALI.GVL.cOpticalFeedback;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nStartWithShortAddress:** Short address assigned to the first DALI control device (0…63).

**nOptions:** Options for addressing the DALI control devices (see table below). The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| Tc3\_DALI.GVL.cCompleteNewInstallation | All DALI control devices are readdressed, even those that already have a short address. |
| Tc3\_DALI.GVL.cOpticalFeedback | Newly addressed DALI control devices are allocated the DALI command IDENTIFY DEVICE once the short address has been assigned. |

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

**nAddressedDevices:** When addressing is completed (*bBusy* is FALSE), the number of addressed control devices is displayed at this output.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.29 | Tc3\_DALI from v3.1.4.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
