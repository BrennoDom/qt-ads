# FB_DALIV2ChangeAddressList

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [High-Level commands](ms-xhelp:///?Id=beckhoff-19b2-4bc9-a63f-87f11156498e)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-9f59-405b-9b5e-1a946f4c914f)
6. [Addressing](ms-xhelp:///?Id=beckhoff-4c3b-4992-8862-5b6f028dc3ef)
7. FB\_DALIV2ChangeAddressList

# FB\_DALIV2ChangeAddressList

![35513827](/tcplclib_tc2_dali/1033/Images/gif/9007199398089483__en-US__Web.gif)

The short addresses of several control gears can be changed using this function block. As opposed to the [FB\_DALIV2SwapShortAddressList](ms-xhelp:///?Id=beckhoff-2df0-445f-9f7c-78cd65d9aa35) function block, it is not necessary for a free, unused short address to be present in the DALI line.

A list of the control gears whose short addresses are to be changed is transferred in the *arrChangeAddressList* arrayof type[ST\_DALIV2ChangeAddressList](ms-xhelp:///?Id=beckhoff-5257-44af-8e09-47b0f6652f0d). The list has 64 entries from 0 to 63. Each entry contains a variable *nOldAddress* and *nNewAddress* with which the address assignment is parameterized. The end of the list is programmed with a 255 entry at *nOldAddress*, so that the whole list does not necessarily have to be filled in. If this entry is missing, however, then all entries are accepted. When the function block is started (positive edge on *bStart*), the list end is first determined on the basis of the above-described entry and afterwards the valid list range is examined for the following false entries:

* Address entries > 63
* Double address entry on the original page *nOldAddress* (would not make sense)
* Double address entry on the target page *nNewAddress* (leads to double assignment of an address and, hence, to errors)

The function block then determines the internal long addresses of the DALI devices on the basis of the short addresses and enters them respectively to the parameters *nRandomAddressHigh*, *nRandomAddressMiddle* and *nRandomAddressLow* in the list. If an error occurs during this query, this leads to a false entry for the respective device in the list element *nErrors* (see [ST\_DALIV2ChangeAddressList](ms-xhelp:///?Id=beckhoff-5257-44af-8e09-47b0f6652f0d)). The further sequence in the function block now depends on the option DALIV2\_OPTION\_SAFE\_ADDRESSING (*nOptions* input). If it is set, then safe new addressing takes place: first of all, all short addresses of the selected DALI devices are deleted. Then, all required new address status requests are sent to the DALI line. Two cases are now possible:

* If a device responds to this query, then this desired new address is already otherwise assigned. The previously “deleted” DALI devices are programmed with their old addresses and an error message is output.
* If no devices respond to this status query, then the previously “deleted” DALI devices are programmed with the desired new addresses.

The reprogramming is checked afterwards in both cases. If an error occurs during deletion, during the status query or during the reprogramming, this leads to a false entry for the respective device in the list element *nErrors* (see [ST\_DALIV2ChangeAddressList](ms-xhelp:///?Id=beckhoff-5257-44af-8e09-47b0f6652f0d)).  
If the option DALIV2\_OPTION\_SAFE\_ADDRESSING (*nOptions* input) is **not** set, then the deletion of the short addresses and the status query for the presence of desired new addresses are omitted and the new addresses are programmed directly. This is possible because programming takes place via the long address determined beforehand. Reprogramming is not verified in this case.

The individual bits in the list element *nErrors* have the following meaning:

| Bit | Error |
| --- | --- |
| 0 | Error whilst reading the high byte of the long address (*nRandomAddressHigh*). |
| 1 | Error whilst reading the middle byte of the long address (*nRandomAddressMiddle*). |
| 2 | Error whilst reading the low byte of the long address (*nRandomAddressLow*). |
| 3 | Error whilst deleting a short address. |
| 4 | Error whilst verifying a short address. |
| 5 | Error whilst programming a short address. |

## VAR\_INPUT

```
bStart           : BOOL;  
bCancel          : BOOL;  
eCommandPriority : E_DALIV2CommandPriority := eDALIV2CommandPriorityHigh;  
nOptions         : DWORD := 0;
```

**bStart:** The function block is activated by a positive edge at this input.

**eCommandPriority:** Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

**nOptions:** Options for writing the variables (see table). The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| DALIV2\_OPTION\_SAFE\_ADDRESSING | Safe addressing: Old short addresses are deleted, the new ones are checked to see if they already exist and reprogramming is verified. |

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
nErrorId : UDINT;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

## VAR\_IN\_OUT

```
arrChangeAddressList : ARRAY [0.. 63] OF ST_DALIV2ChangeAddressList;  
stCommandBuffer      : ST_DALIV2CommandBuffer;
```

**arrChangeAddressList:** A reference to the list containing the short addresses to be changed (see [ST\_DALIV2ChangeAddressList](ms-xhelp:///?Id=beckhoff-5257-44af-8e09-47b0f6652f0d)).

**stCommandBuffer:** Reference to the internal structure for communication with the function block [FB\_KL6811Communication()](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) (KL6811) or [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
