# FB_BA_StaticArray

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# FB\_BA\_StaticArray

![36666067](/tcplclib_tc3_ba_common/1033/Images/gif/9007204969327499__Web.gif)

The function block is an extension of the function block [FB\_DynamicArray](ms-xhelp:///?Id=beckhoff-a4ad-4361-bcbd-ed75d22f6d47).

The background to this extension is to avoid the use of router memory and to use static memory instead. This must be declared in the application, where its size can be adapted as desired.

|  |  |
| --- | --- |
| 61559149 | The static memory must be provided by the application, but it must never be changed outside of the array! The management should take place in all cases via the array itself. |

It is recommended to always use the static array in cases where the expected memory utilization can be precisely estimated.

For reasons of efficiency the memory size should be dimensioned such that as little memory as possible and as much memory as necessary is reserved. Global constants and parameter lists are suitable for declaring the limits of the memory area.

## Application

In principle the application cases are identical to those with the [dynamic array](ms-xhelp:///?Id=beckhoff-a4ad-4361-bcbd-ed75d22f6d47). Only the declaration differs in part, as the external memory area and its size are to be transferred there.

**Further information**

See [examples](ms-xhelp:///?Id=beckhoff-a187-4282-8c15-9ccb66df4f6d) of initialization during variable declaration.

## Examples

Example declaration of the array, its static memory and corresponding constants.

```
VAR_GLOBAL CONSTANT  
    uiObjectCount  : UINT := 100;  
    uiArrayMemSize : UINT := TO_UINT(uiObjectCount * SIZEOF(FB_OBJECT));  
END_VAR
```

```
VAR  
    bArrayMemory   : ARRAY[0.. uiArrayMemSize] OF BYTE;  
    fbArray        : FB_StaticArray := (uiEntrySize:=SIZEOF(FB_Object), pExtMemory:=ADR(bArrayMemory), uiExtMemorySize:=uiArrayMemSize);)  
END_VAR
```

**Further information**

Since the static array is to be used in exactly the same way as the [dynamic array](ms-xhelp:///?Id=beckhoff-a4ad-4361-bcbd-ed75d22f6d47), appropriate [application examples](ms-xhelp:///?Id=beckhoff-a4ad-4361-bcbd-ed75d22f6d47) are documented there.

## Methods of FB\_BA\_StaticArray

| Name | Definition location | Description |
| --- | --- | --- |
| [AddEntry](ms-xhelp:///?Id=beckhoff-be44-480b-bf2a-08381aac1f1e) | Local | Creates a new data set at the end of the array and copies the content of the specified entry to the internal memory |
| [Reset](ms-xhelp:///?Id=beckhoff-5fca-481b-a846-b2d98e8a7f8d) | Local | Resets the complete content of the array. |

## Requirements

| Development environment | Required library | Necessary function |
| --- | --- | --- |
| TwinCAT3.1 4022.16 | Tc3Building Automation Common from V1.0.4.3 | TF8040 | TwinCAT Building Automation from V1.0.5.0 |
