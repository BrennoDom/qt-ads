# FB_BA_DynamicArray

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# FB\_BA\_DynamicArray

![63074124](/tcplclib_tc3_ba_common/1033/Images/gif/9007204969333899__Web.gif)

The function block generates and deletes memory areas dynamically so that entries can be added and removed at runtime.

As soon as the [maximum capacity](ms-xhelp:///?Id=beckhoff-a4ad-4361-bcbd-ed75d22f6d47) of the array is reached, the internal memory area is automatically extended. If the capacity is more than sufficient, the internal memory area is reduced in size.

|  |  |
| --- | --- |
| 30796205 | The internally used memory is allocated from the router memory pool and is generated via \_NEW and released via \_DELETE at runtime. With each adaptation (i.e. extension or reduction in size) of the internal memory, the pointers to the obsolete/adapted memory are also invalid! |

|  |  |
| --- | --- |
| 8730397 | The data type of the entries is not important for the dynamic array! The user must ensure in every case that the data type is always correctly observed by the application when dealing with contained entries. Furthermore, all data added to the array must have a uniformly defined [size](ms-xhelp:///?Id=beckhoff-a4ad-4361-bcbd-ed75d22f6d47)! |

It is recommended to use the dynamic array in particular in cases where the expected memory utilization can be estimated relatively well. Router memory is only available to a limited extent (especially with small controllers) and is to be used as efficiently as possible! If necessary, the amount of router memory available in the target system must additionally be adapted.

## VAR\_OUTPUT

```
bReady    : BOOL;  
discount  : DINT;
```

**bReady:** Status of the allocated memory. (TRUE if at least one entry is contained in the array and memory is thus already generated)

**diCount:** Current number of entries contained.

## VAR

Internal variables that have to be initialized during the declaration.

```
uiEntrySize     : UINT;  
uiMinExpCount:  : UINT;
```

**uiEntrySize:** Expected size of entries. Used to allocate internal memory and to manage memory areas of recorded entries.

**uiMinExpCount:** Expected size of the internal memory (specified in [number of entries]) on reaching the [maximum capacity](ms-xhelp:///?Id=beckhoff-a4ad-4361-bcbd-ed75d22f6d47).

**For further information, see** [examples](ms-xhelp:///?Id=beckhoff-a4ad-4361-bcbd-ed75d22f6d47) **of initialization during variable declaration.**

## Application

Two typical application cases are imaginable:

**Case 1) Array contains data sets**

In this case the array contains data sets (generic types such as BOOL, INT, STRING or structures) by reserving internal memory in accordance with the size of the type used.

**Case 2) Array contains pointers**

In this case the array contains pointers to externally declared data and only memory corresponding to the size of memory addresses is reserved.

|  |  |
| --- | --- |
| 11464716 | Instances of the dynamic array are not called cyclically. It is sufficient to use the management functions and properties described here. |

## Examples

**Example 1:**

Data sets of the data type *ST\_DATA* are stored in an array.

Access to the respective data sets takes place by means of pointers to the internal memory of the array or by means of a copy of a data set.

```
VAR  
    fbArray : FB_DynamicArray := (uiEntrySize:=SIZEOF(ST_Data), uiMinExpCount:=5);  
       stMyDataTmp  : ST_Data;  
       ptrMyDataTmp : POINTER TO ST_Data;  
       diIndexTmp   : DINT;  
END_VAR
```

```
// 1) Save data in array and remove them with the help of index position:  
IF (fbArray.AddEntry(ADR(stMyDataTmp), diResultIndex=>diIndexTmp)) THEN  
       fbArray.RemoveEntry(diIndexTmp);  
END_IF  
  
// 2) List all data sets consecutively:  
FOR diIndexTmp = 0 TO fbArray.LastIndex DO  
    IF (fbArray.GetEntryEx(diIndexTmp, pMemoryPtr=>ptrMyDataTemp)) THEN  
       ptrMyDataTmp^.diValue := (diIndexTmp+1);  
    END_IF  
END_FOR  
  
// 3) Get a copy of the first data set:  
If (fbArray.GetEntry(0, ADR(stMyDataTmp))) THEN  
    // Edit and update data set:  
    stMyDataTmp.diValue := 99;  
  
    fbArray.SetEntry(0, ADR(stMyDataTmp));  
END_IF
```

**Example 2:**

The addresses of externally declared instances of the function block *FB\_Object* are stored in an array.

```
VAR  
    fbArray : FB_DynamicArray := (uiEntrySize:=SIZEOF(POINTER TO FB_Object), uiMinExpCount:=5);  
       fbMyObject1  : FB_Object;  
       fbMyObject2  : FB_Object;  
       fbObjectTmp  : POINTER TO FB_Object;  
  
       diIndexTmp   : DINT;  
END_VAR
```

```
// 1) Add object to array and remove it with the help of index position:  
If (fbArray.AddEntryPtr(ADR(fbMyObject1), diResultIndex=>diIndexTmp)) THEN  
    fbArray.RemoveEntry(diIndexTmp);  
END_IF  
  
// 2) Add object to array and remove subsequently with the use of the pointer:  
fbArray.AddEntryPtr(ADR(fbMyObject1));  
fbArray.RemoveEntryExPtr(ADR(fbMyObject1));  
  
// 3) Determine the index position of an object within an array:  
IF (fbArray.FindEntryPtr(ADR(fbMyObject1), diResultIndex=>diIndexTemp)) THEN  
    // Replace entry on position “fbMyObject1” with “fbMyObject2”:  
    fbArray.SetEntryPtr(diIndexTmp, ADR(fbMyObject2));  
ELSE  
    // Error handling  
    …  
END_IF  
  
// 4) Determine first object:  
IF (fbArray.GetEntry(0,ADR(fbObjTemp))) THEN  
    // …  
END_IF  
  
// 5) Remove content of the array if it has more than 10 entries:  
IF(fbArray.diCount > 10) THEN  
    fb_Array.Reset();  
END_IF
```

## Error messages

The following error messages may be output in the TwinCAT display window at runtime:

[EDB4] Entry-size of array not defined!  
The [expected size](ms-xhelp:///?Id=beckhoff-a4ad-4361-bcbd-ed75d22f6d47) of entries was not initialized during the declaration of the array.

[EDB7] Expansion-count of entries not defined!  
The [expected size](ms-xhelp:///?Id=beckhoff-a4ad-4361-bcbd-ed75d22f6d47) of the internal memory was not initialized during the declaration of the array.

## Methods of FB\_BA\_DynamicArray

| Name | Definition location | Description |
| --- | --- | --- |
| [AddEntry](ms-xhelp:///?Id=beckhoff-be44-480b-bf2a-08381aac1f1e) | Local | Creates a new data set at the end of the array and copies the content of the specified entry to the internal memory |
| [FindEntry](ms-xhelp:///?Id=beckhoff-d4b5-4699-bbea-c1d2e6fbc2e3) | Local | Determines the position of the specified entry in the array by comparing its content with the data sets of the array. |
| [GetEntry](ms-xhelp:///?Id=beckhoff-3790-4b84-abff-32d1e24f9998) | Local | Copies the contents of the data set to a certain position in the specified memory area. |
| [GetEntryEx](ms-xhelp:///?Id=beckhoff-d149-4341-b4cc-c37e7be0b241) | Local | Determines a pointer to the internal memory of the specified data set. |
| [RemoveEntry](ms-xhelp:///?Id=beckhoff-d2cf-446b-93d1-b520a38dd220) | Local | Removes the data set at the specified index position from the array. |
| [RemoveEntryEx](ms-xhelp:///?Id=beckhoff-6600-4781-936b-3b015384e5fc) | Local | Determines the position of the specified entry and deletes it from the array. |
| [Reset](ms-xhelp:///?Id=beckhoff-5fca-481b-a846-b2d98e8a7f8d) | Local | Resets the complete content of the array. |
| [SetEntry](ms-xhelp:///?Id=beckhoff-8489-48a9-85d8-0fa8def3fc96) | Local | Replaces the existing data set with a new one by overwriting the internal memory area of the existing data set with the value of the new entry. |
| [AddEntryPtr](ms-xhelp:///?Id=beckhoff-80f7-4c2b-8dca-f7c3517cb268) | Local | Creates a new entry at the end of the array and copies its memory address (i.e. the address to which the pointer *pEntry* points) to the internal memory. |
| [FindEntryPtr](ms-xhelp:///?Id=beckhoff-d171-4775-8509-66211120c70d) | Local | Determines the position of an entry in the array by comparing its address with the addresses stored in the array. |
| [GetEntryExPtr](ms-xhelp:///?Id=beckhoff-204e-41e5-9afd-04a45e3da920) | Local | Outputs a pointer to the memory address of the requested entry. |
| [RemoveEntryExPtr](ms-xhelp:///?Id=beckhoff-f96f-435a-a952-d65c7c86e505) | Local | Determines the position of the specified entry and deletes it from the array. |
| [SetEntryPtr](ms-xhelp:///?Id=beckhoff-23a0-4fa6-bc26-f4d9d3c338f0) | Local | Replaces an existing entry with a new one. |

## Properties of FB\_BA\_DynamicArray

| Name | Type | Access | Definition location | Initial value | Description |
| --- | --- | --- | --- | --- | --- |
| CurCapacity | DINT | Get | Local | - | Current capacity of the array (number of entries). Corresponds to the maximum number of entries that can be accepted by the internal memory. |
| EntrySize | DINT | Get | Local | [uiEntrySize](ms-xhelp:///?Id=beckhoff-a4ad-4361-bcbd-ed75d22f6d47) | Expected size of entries that are stored in the array |
| LastIndex | DINT | Get | Local | - | Index position of the last entry. This is -1 if no entries exist |
| UsedMemory | DINT | Get | Local | - | Size of the internal memory consumed [bytes]. |

## Requirements

| Development environment | Required library | Necessary function |
| --- | --- | --- |
| TwinCAT3.1 4022.16 | Tc3Building Automation Common from V1.0.4.3 | TF8040 | TwinCAT Building Automation from V1.0.5.0 |

Further Information

* [AddEntry](ms-xhelp:///?Id=beckhoff-be44-480b-bf2a-08381aac1f1e)
* [FindEntry](ms-xhelp:///?Id=beckhoff-d4b5-4699-bbea-c1d2e6fbc2e3)
* [GetEntry](ms-xhelp:///?Id=beckhoff-3790-4b84-abff-32d1e24f9998)
* [GetEntryEx](ms-xhelp:///?Id=beckhoff-d149-4341-b4cc-c37e7be0b241)
* [RemoveEntry](ms-xhelp:///?Id=beckhoff-d2cf-446b-93d1-b520a38dd220)
* [RemoveEntryEx](ms-xhelp:///?Id=beckhoff-6600-4781-936b-3b015384e5fc)
* [Reset](ms-xhelp:///?Id=beckhoff-5fca-481b-a846-b2d98e8a7f8d)
* [SetEntry](ms-xhelp:///?Id=beckhoff-8489-48a9-85d8-0fa8def3fc96)
* [AddEntryPtr](ms-xhelp:///?Id=beckhoff-80f7-4c2b-8dca-f7c3517cb268)
* [FindEntryPtr](ms-xhelp:///?Id=beckhoff-d171-4775-8509-66211120c70d)
* [GetEntryExPtr](ms-xhelp:///?Id=beckhoff-204e-41e5-9afd-04a45e3da920)
* [RemoveEntryExPtr](ms-xhelp:///?Id=beckhoff-f96f-435a-a952-d65c7c86e505)
* [SetEntryPtr](ms-xhelp:///?Id=beckhoff-23a0-4fa6-bc26-f4d9d3c338f0)
