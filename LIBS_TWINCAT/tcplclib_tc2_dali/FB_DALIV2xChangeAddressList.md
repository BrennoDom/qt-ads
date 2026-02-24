# FB_DALIV2xChangeAddressList

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [High-Level commands](ms-xhelp:///?Id=beckhoff-19b2-4bc9-a63f-87f11156498e)
5. [Part 103 (control units)](ms-xhelp:///?Id=beckhoff-7c75-4e57-be0c-df25a53078a0)
6. [Addressing](ms-xhelp:///?Id=beckhoff-547a-48a7-9385-05f772490234)
7. FB\_DALIV2xChangeAddressList

# FB\_DALIV2xChangeAddressList

![25717600](/tcplclib_tc2_dali/1033/Images/gif/4415299979__Web.gif)

This function block can be used to change the short addresses of several control units.

A list of the control units for which the short address is to be changed is transferred in the array *arrChangeAddressList* of type [ST\_DALIV2ChangeAddressList](ms-xhelp:///?Id=beckhoff-5257-44af-8e09-47b0f6652f0d). The list has 64 entries from 0 to 63. Each entry contains a variable *nOldAddress* and *nNewAddress* with which the address assignment is parameterized. The end of the list is programmed with a 255 entry at *nOldAddress*, so that the whole list does not necessarily have to be filled in. If this entry is missing, however, then all entries are accepted. When the function block is started (positive edge on *bStart*), the list end is first determined on the basis of the above-described entry and afterwards the valid list range is examined for the following false entries:

* Address entries > 63
* Double address entry on the original page nOldAddress (would not make sense)
* Double address entry on the target page nNewAddress (leads to double assignment of an address and, hence, to errors)

The function block then determines the internal long addresses of the DALI devices on the basis of the short addresses and enters them respectively to the parameters *nRandomAddressHigh, nRandomAddressMiddle* and *nRandomAddressLow* in the list. If an error occurs during this query, this leads to a false entry for the respective device in the list element *nErrors* (see [ST\_DALIV2ChangeAddressList](ms-xhelp:///?Id=beckhoff-5257-44af-8e09-47b0f6652f0d)). The further sequence in the function block now depends on the option DALIV2\_OPTION\_SAFE\_ADDRESSING (*nOptions* input). If it is set, then safe new addressing takes place: first of all, all short addresses of the selected DALI devices are deleted. Afterwards, status queries are sent to all desired new addresses in the DALI line.  
Two cases are possible:

* If a device responds to this query, then this desired new address is already otherwise assigned. The previously “deleted” DALI devices are programmed with their old addresses and an error message is output.
* If no devices respond to this status query, then the previously “deleted” DALI devices are programmed with the desired new addresses.

The reprogramming is checked afterwards in both cases. If an error occurs during deletion, during the status query or during the reprogramming, this leads to a false entry for the respective device in the list element nErrors (see [ST\_DALIV2ChangeAddressList](ms-xhelp:///?Id=beckhoff-5257-44af-8e09-47b0f6652f0d)).

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
| 6 | The value of the variable nOldAddress is equal to the value of the variable nNewAddress. The entry in the list is ignored. (Tc2\_DALI from v3.6.10.0) |

## VAR\_INPUT

```
bStart             : BOOL;  
eCommandPriority   : E_DALIV2CommandPriority := eDALIV2CommandPriorityHigh;  
nOptions           : DWORD := 0;  
eDataFrameType     : E_DALIV2DataFrameType := eDALIV2DataFrameType24Bit;
```

**bStart:** The function block is activated by a positive edge at this input.

**eCommandPriority**: Priority (high, medium or low) with which the command is processed by the library.

**nOptions**: Options for writing the variables (see table). The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| DALIV2\_OPTION\_SAFE\_ADDRESSING | Secure addressing: Old short addresses are deleted, the new ones are checked for already existing ones and the reprogramming is verified. |

**eDataFrameType**: Output format of the DALI command (*eDALIV2DataFrameType24Bit* or *eDALIV2DataFrameTypeOsram*).

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
arrChangeAddressList  : ARRAY [0..63] OF ST_DALIV2ChangeAddressList;  
stCommandBuffer       : ST_DALIV2CommandBuffer;
```

**stCommandBuffer**: Reference to the internal structure for communication with the function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

**arrChangeAddressList:** A reference to the list containing the short addresses to be changed.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.4 | Tc2\_DALI from v3.6.2.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
