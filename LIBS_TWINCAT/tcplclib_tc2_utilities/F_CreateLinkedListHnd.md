# F_CreateLinkedListHnd

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_CreateLinkedListHnd

![1789605](/tcplclib_tc2_utilities/1033/Images/gif/35811083__en-US__Web.gif)

The function initializes the Linked List Handle. The List Handle must be initialized once by calling the F\_CreateLinkedListHnd function.

## FUNCTION F\_CreateLinkedListHnd: BOOL

## VAR\_INPUT

```
VAR_INPUT  
    pEntries  : POINTER TO T_LinkedListEntry := 0;  
    cbEntries : UDINT := 0;  
END_VAR
```

**pEntries**: The address of the first *T\_LinkedListEntry* array element. The address can be determined with the ADR operator (type: [T\_LinkedListEntry](ms-xhelp:///?Id=beckhoff-edd3-49b4-8da6-ead12db500ff)).

**cbEntries**: The size of the *T\_LinkedListEntry* array in bytes. The byte size can be determined with the SIZEOF operator.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    hList  : T_HLINKEDLIST;  
END_VAR
```

**hList**: Hash table handle to be initialized (type: [T\_HLINKEDLIST](ms-xhelp:///?Id=beckhoff-218a-42dd-bd87-50bf63327f35)). The handle is required for accessing the list from the function block [FB\_LinkedListCtrl](ms-xhelp:///?Id=beckhoff-ef44-4813-9f63-c2cc598139aa).

| Return parameter | Description |
| --- | --- |
| TRUE | No error |
| FALSE | Error |

**Example**:

See: [Example: Linked list (FB\_LinkedListCtrl).](ms-xhelp:///?Id=beckhoff-936a-409a-a255-4bf44bd5912c)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
