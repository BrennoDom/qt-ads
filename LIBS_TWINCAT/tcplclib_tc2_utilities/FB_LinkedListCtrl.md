# FB_LinkedListCtrl

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_LinkedListCtrl

![65498832](/tcplclib_tc2_utilities/1033/Images/png/9007199290270475__Web.png)

The function block FB\_LinkedListCtrl can be used to implement a linked list in the PLC project. A double-linked list is created. A linked list allows values (known as nodes) to be stored. It is possible to iterate the list from the back to the front or the other way. Nodes can quickly be added or deleted.

It is not possible to change the maximum number of nodes at runtime; it must be specified before compiling. An array of type *T\_LinkedListEntry* is used as a "node pool". Adding/removing/finding of nodes is controlled through action calls. The function block features the following tasks:

* **A\_AddHeadValue** (adds a new node with the value *putValue* to the top of the list. The same value can be added more than once. If successful, *getPosPtr* returns the address while *getValue* returns the value of the new node.)
* **A\_AddTailValue** (adds a new node with the value *putValue* to the end of the list. The same value can be added more than once. If successful, *getPosPtr* returns the address while *getValue* returns the value of the new node.)
* **A\_FindNext** (searches for the next node (relative to *putPosPtr*) whose value is the same as *putValue*. If successful, *getPosPtr* returns the address while *getValue* returns the value of the node. )
* **A\_FindPrev** (searches for the previous node (relative to *putPosPtr*) whose value is the same as *putValue*. If successful, *getPosPtr* returns the address while *getValue* returns the value of the node.)
* **A\_GetNext** (navigates to the next node (relative to *putPosPtr*). The address *putPosPtr* must point the previous node! The value of *putValue* is not used.)
* **A\_GetPrev** (navigates to the previous node (relative to *putPosPtr*) in the opposite direction to *A\_GetNext*. The address *putPosPtr* must point the previous node! The value of *putValue* is not used.)
* **A\_GetHead** (reads the starting node. If successful, *getPosPtr* returns the address of the node while *getValue* returns the associated value. The values of *putValue* and *putPosPtr* are not used.)
* **A\_GetTail** (reads the final node. If successful, *getPosPtr* returns the address of the node while *getValue* returns the associated value. The values of *putValue* and *putPosPtr* are not used.)
* **A\_RemoveHeadValue** (removes a node from the top of the list. If successful, *getPosPtr* returns the address while *getValue* returns the value of the node. The values of *putValue* and *putPosPtr* are not used.)
* **A\_RemoveTailValue** (removes a node from the end of the list. If successful, *getPosPtr* returns the address while *getValue* returns the value of the node. The values of *putValue* and *putPosPtr* are not used.)
* **A\_RemoveValueAtPosPtr** (searches for and removes a node with address *putPosPtr*. If successful, *getPosPtr* returns the address while *getValue* returns the value of the node. The value of *putValue* is not used.)
* **A\_GetIndexAtPosPtr** (returns the array index (from the "node pool") of the node at address *putPosPtr*. When successful, *getValue* returns the null-based array index. The value of *putValue* is not used. Please note that the value of getValue is a node index, not the value of the node! )
* **A\_SetValueAtPosPtr** (updates/sets the value of the node with *putValue* at the address *putPosPtr*. If successful, *getPosPtr* returns the address while *getValue* returns the value of the node.)
* **A\_Reset** (deletes all list elements and resets the list.)

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    hList  : T_HLINKEDLIST;  
END_VAR
```

**hList**: Linked List Handle (type: [T\_HLINKEDLIST](ms-xhelp:///?Id=beckhoff-218a-42dd-bd87-50bf63327f35)). The handle must be initialized once with the function [F\_CreateLinkedListHnd](ms-xhelp:///?Id=beckhoff-fd6d-424b-8831-b982879d9f9a) before being used. An associated instance of the handle variable must be created and initialized for each linked list

## VAR\_INPUT

```
VAR_INPUT  
    putValue   : PVOID := 0;  
    putPosPtr  : POINTER TO T_LinkedListEntry := 0;  
END_VAR
```

**putValue**: Value/data element (input parameter, 32/64 bit, unsigned number or pointer).

**putPosPtr**: Address of the node element (input parameter, type: [T\_LinkedListEntry](ms-xhelp:///?Id=beckhoff-edd3-49b4-8da6-ead12db500ff)).

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bOk       : BOOL := FALSE;  
    getValue  : PVOID := 0;  
    getPosPtr : POINTER TO T_LinkedListEntry := 0;  
END_VAR
```

**bOk**: Result of the last action called. Returns TRUE if a new node element could be added, removed, or found in the list. FALSE is returned if the node element that was searched for could not be found, the list is empty, or has overflowed (no more free node elements).

**getValue**: Value/data element (output parameter, 32/64 bit, unsigned number or pointer).

**getPosPtr**: Address of the node element (output parameter, type: [T\_LinkedListEntry](ms-xhelp:///?Id=beckhoff-edd3-49b4-8da6-ead12db500ff)).

**Example:**

See: [Example: Linked list (FB\_LinkedListCtrl).](ms-xhelp:///?Id=beckhoff-936a-409a-a255-4bf44bd5912c)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
