# FB_DALI103ChangeAddresses

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
7. FB\_DALI103ChangeAddresses

# FB\_DALI103ChangeAddresses

![40261524](/tcplclib_tc3_dali/1033/Images/gif/9007205111669259__Web.gif)

This function block can be used to change the short addresses of several DALI control devices.

A list of the DALI control devices for which the short address is to be changed is transferred in the array *aChangeAddressList* of type [ST\_DALIChangeAddressList](ms-xhelp:///?Id=beckhoff-f1d0-4d80-8eda-7cf09b60e1c9). The list has 64 entries from 0 to 63. Each entry contains a variable *nOldAddress* and *nNewAddress* with which the address assignment is parameterized. The end of the list is programmed with a 255 entry at *nOldAddress*, so that the whole list does not necessarily have to be filled in. If this entry is missing, however, then all entries are accepted. When the function block is started (positive edge on *bStart*), the list end is first determined on the basis of the described entry and afterwards the valid list range is examined for the following false entries:

* Address entries > 63
* Double address entry on the source page *nOldAddress*
* Double address entry on the target page *nNewAddress* (leads to double assignment of an address and, hence, to errors)

The function block then uses the short addresses to determine the internal long addresses of the DALI devices and enters them in the *nRandomAddress* parameter of the list.

If an error occurs during queries or during reprogramming, this leads to an error entry for the respective device in the list element *nErrors* (see [ST\_DALIChangeAddressList](ms-xhelp:///?Id=beckhoff-f1d0-4d80-8eda-7cf09b60e1c9)).

The individual bits in the list element *nErrors* have the following meaning:

| Bit | Error |
| --- | --- |
| 0 | Error during reading of the long address |
| 1 | - |
| 2 | - |
| 3 | - |
| 4 | - |
| 5 | Error during programming of the new short address |
| 6 | *nOldAddress* and *nNewAddress* have the same values |

|  |  |
| --- | --- |
| 26809401 | The function block cannot be used when using the KL6811. |

## VAR\_INPUT

```
bStart              : BOOL;  
nOptions            : DWORD := 0;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nOptions:** Reserved for future expansions.

## VAR\_OUTPUT

```
bError                  : BOOL;  
ipResultMessage         : I_TcMessage;  
bBusy                   : BOOL;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

## VAR\_IN\_OUT

```
aChangeAddressList    : ARRAY [0..63] OF ST_DALIChangeAddressList;
```

**aChangeAddressList:** List with the short addresses that are to be changed (see [ST\_DALIChangeAddressList](ms-xhelp:///?Id=beckhoff-f1d0-4d80-8eda-7cf09b60e1c9)).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.29 | Tc3\_DALI from v3.1.4.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
