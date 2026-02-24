# Example: Linked list (FB_LinkedListCtrl)

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Example: Linked list (FB\_LinkedListCtrl)

Here you can unpack the complete sources: [LinkedListExample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_utilities/Resources/zip/9007200058166539.zip)

The example project has two parts to the program:

* P\_LIST\_OF\_UDINT is a simple example program that simply edits 32-bit values in the linked list.
* P\_LIST\_OF\_STRUCTDATA illustrates how other data types (e.g. structured data types) can be managed in the context of the linked list.

The maximum number of node elements cannot be changed at runtime, and is limited in the example project by MAX\_DATA\_ELEMENTS. If you need more nodes, then you must increase the size of the node array accordingly (i.e. increase the value of the constant).

```
VAR_GLOBAL CONSTANT  
    MAX_DATA_ELEMENTS : UDINT := 100;(* Max. number of elements in the list *)  
    MAX_NAME_LENGTH   : UDINT := 30;(* Max. length of article name *)  
END_VAR
```

## PROGRAM P\_LIST\_OF\_UDINT

The handle of the linked list is initialized in the first PLC cycle. This handle is then passed as the VAR\_IN\_OUT variable to the FB\_LinkedListCtrl function block when accessing the list. The linked list is manipulated through the action calls of the function block. This allows node elements to be added, removed, searched. The desired action is executed in response to a rising edge of the associated boolean variable. When you run the program, all the operations are carried out once.

```
PROGRAM P_LIST_OF_UDINT  
VAR  
    sInfo               : T_MaxString := '';  
    bAddTailValue       : BOOL := TRUE;  
    bAddHeadValue       : BOOL := TRUE;  
    bGetTail            : BOOL := TRUE;  
    bGetHead            : BOOL := TRUE;  
    bFind               : BOOL := TRUE;  
    bRemoveHeadValue    : BOOL := TRUE;  
    bRemoveTailValue    : BOOL := TRUE;  
    bCount              : BOOL := TRUE;  
  
    search              : UDINT := 12345;  
  
    fbList              : FB_LinkedListCtrl;(* basic linked list control function block *)  
    hList               : T_HLINKEDLIST;(* linked list handle *)  
    nodes               : ARRAY[0..MAX_DATA_ELEMENTS] OF T_LinkedListEntry;(* Max. number of linked list nodes. The value of list node = 32 bit integer *)  
    putValue            : PVOID;(* Pointer or integer value (x86=>32bit, x64=>64bit)*)  
    getValue            : PVOID;(* Pointer or integer value (x86=>32bit, x64=>64bit)*)  
    getPosPtr           : POINTER TO T_LinkedListEntry := 0;  
    bInit               : BOOL := TRUE;  
END_VAR
```

```
IF bInit THEN  
    bInit     := FALSE;  
    F_CreateLinkedListHnd( ADR( nodes ), SIZEOF( nodes ), hList );  
END_IF  
  
IF bAddTailValue THEN(* add some nodes to the list *)  
    bAddTailValue := FALSE;  
  
    putValue := 22222;  
    fbList.A_AddTailValue( hList := hList, putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    putValue := 11111;  
    fbList.A_AddTailValue( hList := hList, putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    putValue := 12345;  
    fbList.A_AddTailValue( hList := hList, putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    putValue := 67890;  
    fbList.A_AddTailValue( hList := hList, putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
END_IF  
  
IF bAddHeadValue THEN  
    bAddHeadValue := FALSE;  
  
    putValue := 33333;  
    fbList.A_AddHeadValue( hList := hList, putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    putValue := 44444;  
    fbList.A_AddHeadValue( hList := hList, putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
END_IF  
  
  
IF bGetTail THEN(* enumerate all nodes in list (start at tail node) *)  
    bGetTail := FALSE;  
    sInfo := '';  
  
    fbList.A_GetTail( hList := hList, getValue=>getValue, getPosPtr=>getPosPtr );  
    IF fbList.bOk THEN  
        sInfo := PVOID_TO_STRING( getValue );  
  
        REPEAT  
            fbList.A_GetPrev( hList := hList, putPosPtr := getPosPtr, getValue=>getValue, getPosPtr=>getPosPtr );  
            IF fbList.bOk THEN  
                sInfo := PVOID_TO_STRING( getValue );  
            ELSE  
                EXIT;  
            END_IF  
        UNTIL NOT fbList.bOk  
        END_REPEAT  
    END_IF  
END_IF  
  
IF bGetHead THEN(* enumerate all nodes in list (start at head node) *)  
    bGetHead := FALSE;  
    sInfo := '';  
  
    fbList.A_GetHead( hList := hList, getValue=>getValue, getPosPtr=>getPosPtr );  
    IF fbList.bOk THEN  
        sInfo := PVOID_TO_STRING( getValue );  
  
        REPEAT  
            fbList.A_GetNext( hList := hList, putPosPtr := getPosPtr, getValue=>getValue, getPosPtr=>getPosPtr );  
            IF fbList.bOk THEN  
                sInfo := PVOID_TO_STRING( getValue );  
            ELSE  
                EXIT;  
            END_IF  
        UNTIL NOT fbList.bOk  
        END_REPEAT  
    END_IF  
END_IF  
  
  
IF bFind  THEN(* search for node in the list by node value*)  
    bFind     := FALSE;  
    getPosPtr := 0;(* start from first node element *)  
    sInfo := '';  
  
    REPEAT  
        fbList.A_FindNext( hList := hList, putPosPtr := getPosPtr, putValue := search, getValue=>getValue, getPosPtr=>getPosPtr );  
        IF fbList.bOk THEN  
            sInfo := PVOID_TO_STRING( getValue );  
        ELSE  
            EXIT;  
        END_IF  
    UNTIL NOT fbList.bOk  
    END_REPEAT  
  
END_IF  
  
  
IF bRemoveTailValue THEN(* remove tail node from node list *)  
    bRemoveTailValue := FALSE;  
    sInfo := '';  
    fbList.A_RemoveTailValue( hList := hList, getValue=>getValue, getPosPtr=>getPosPtr );  
    IF fbList.bOk THEN  
        sInfo := PVOID_TO_STRING( getValue );  
    END_IF  
END_IF  
  
  
IF bRemoveHeadValue THEN(* remove head node from node list *)  
    bRemoveHeadValue := FALSE;  
    sInfo := '';  
    fbList.A_RemoveHeadValue( hList := hList, getValue=>getValue, getPosPtr=>getPosPtr );  
    IF fbList.bOk THEN  
        sInfo := PVOID_TO_STRING( getValue );  
    END_IF  
END_IF  
  
IF bCount THEN(* count nodes in list *)  
    bCount := FALSE;  
    sInfo := UDINT_TO_STRING( hList.nCount );  
END_IF
```

## PROGRAM P\_LIST\_OF\_STRUCTDATA

This section of the program illustrates how structured data sets can be manipulated in the list in place of simply 32-bit numbers. In this case, the 32-bit node value is only used as a reference pointer to the actual value of the node. The reference pointer is able to point to instances of structured variables or other data types. The functionality is encapsulated in a function block. The function block *FB\_SpecialLinkedListCtrl* can be regarded as a specialized version of the FB\_*LinkedListCtrl* function block. The *FB\_LinkedListCtrl* block is also used internally by the specialized FB.

The *DATAELEMENT\_TO\_STRING* function is only used to permit visual output of the value of the node.

A structured variable of type *ST\_DataElement* is used as an example. The highlight: You can add further member variables to the data type declaration of ST\_DataElement without having to make any changes to the program or to the FB\_SpecialLinkedListCtrl function block.

The type declaration for ST\_DataElement:

```
(* Structured application data entry *)  
TYPE ST_DataElement :  
STRUCT  
    (* Adapt this structure to match your application needs *)  
    number   : UDINT := 0;  
    name     : STRING(MAX_NAME_LENGTH) := '';  
    price    : REAL := 0.0;  
END_STRUCT  
END_TYPE
```

A simple search function is implemented. You can search for nodes having a particular *name*, *number* or *price*.

## How do the 32-bit node values become reference pointers to the instances of the ST\_DataElement array?

The maximum size of the list is limited by the constant MAX\_DATA\_ELEMENTS. It follows that no more than MAX\_DATA\_ELEMENTS reference pointers can be stored in the list. The *FB\_SpecialLinkedListCtrl* function block has an internal ST\_DataElement array variable with the same size as the T\_LinkedListEntry array variable. To simplify matters, the array indices are the same for both arrays!

Each T\_LinkedListEntry array element can only be inserted into the list once. The *FB\_LinkedListCtrl* function block therefore searches for a free/unused T\_LinkedListEntry array element, and inserts it into the list if successful. The index of the T\_LinkedListEntry being used can be determined through the action *A\_GetIndexAtPosPtr*. In the next step, the 32-bit node value that has just been added is assigned the address of the same array element in the ST\_DataElement array. In the project example through the action call: *A\_SetValueAtPosPtr*.

**nodes[index].value := ADR( dataPool[index] )**

The assignment is, for instance, carried out in the *FB\_SpecialLinkedListCtrl*->*A\_AddHeadValue* action:

```
(* Adds head to the node list *)  
MEMSET( ADR( getValue ), 0, SIZEOF( getValue ) );  
getPosPtr := 0;  
  
fbList.A_AddHeadValue( hList := hList, putValue := 16#00000000(* we will set this value later *), getPosPtr=>getPosPtr, bOk=>bOk );(* Add new element to the list, getPosPtr points to the new list node *)  
IF fbList.bOk THEN(* Success *)  
    fbList.A_GetIndexAtPosPtr( hList := hList, putPosPtr := getPosPtr, getValue =>indexOfElem, bOk=>bOk );(* Get array index of getPosPtr *)  
    IF fbList.bOk THEN(* Success *)  
        pRefPtr     := ADR( dataPool[indexOfElem] );(* Get pointer to the data element *)  
        pRefPtr^     := putValue;(* set element value *)  
  
        fbList.A_SetValueAtPosPtr( hList := hList, putPosPtr := getPosPtr, putValue := pRefPtr, bOk=>bOk );(* Assign the node value = pointer to the data element *)  
        IF fbList.bOk THEN(* Success *)  
            getValue := putValue;  
        END_IF  
    END_IF  
END_IF
```

```
PROGRAM P_LIST_OF_STRUCTDATA  
VAR  
    sInfo             : T_MaxString := '';  
    bAddTailValue     : BOOL := TRUE;  
    bAddHeadValue     : BOOL := TRUE;  
    bGetTail          : BOOL := TRUE;  
    bGetHead          : BOOL := TRUE;  
    bFind             : BOOL := TRUE;  
    bRemoveHeadValue  : BOOL := TRUE;  
    bRemoveTailValue  : BOOL := TRUE;  
    bCount            : BOOL := TRUE;  
  
    search            : ST_DataElement := ( name := 'Couch', price := 99.98, number := 12345 );(* search value ( by name, by price or by number ) *)  
    eSearch           : E_SEARCH_CRITERIA := eSEARCH_BY_NAME;(* / eSEARCH_BY_PRICE / eSEARCH_BY_NUMBER *)  
  
    fbList            : FB_SpecialLinkedListCtrl;(* Specialized linked list control function block *)  
    putValue          : ST_DataElement;  
    getValue          : ST_DataElement;  
    getPosPtr         : POINTER TO T_LinkedListEntry := 0;  
    bInit             : BOOL := TRUE;  
END_VAR
```

```
IF bInit THEN  
    bInit     := FALSE;  
    fbList.A_Reset();(* reset / initialize list *)  
END_IF  
  
  
IF bAddTailValue THEN(* add some nodes to the list *)  
    bAddTailValue := FALSE;  
  
    putValue.number := 22222;  
    putValue.name := 'TV set';  
    putValue.price :=  99.98;  
    fbList.A_AddTailValue( putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF NOT fbList.bOk THEN  
        ;(* List overflow *)  
    END_IF  
  
  
    putValue.number := 11111;  
    putValue.name := 'Couch';  
    putValue.price :=  99.98;  
    fbList.A_AddTailValue( putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF NOT fbList.bOk THEN  
        ;(* List overflow *)  
    END_IF  
  
    putValue.number := 12345;  
    putValue.name := 'Chair';  
    putValue.price := 44.98;  
    fbList.A_AddTailValue( putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF NOT fbList.bOk THEN  
        ;(* List overflow *)  
    END_IF  
  
    putValue.number := 67890;  
    putValue.name := 'Table';  
    putValue.price := 99.98;  
    fbList.A_AddTailValue( putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF NOT fbList.bOk THEN  
        ;(* List overflow *)  
    END_IF  
END_IF  
  
IF bAddHeadValue THEN  
    bAddHeadValue := FALSE;  
  
    putValue.number := 33333;  
    putValue.name := 'Couch';  
    putValue.price := 199.98;  
    fbList.A_AddHeadValue( putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF NOT fbList.bOk THEN  
        ;(* List overflow *)  
    END_IF  
  
    putValue.number := 44444;  
    putValue.name := 'Couch';  
    putValue.price := 299.98;  
    fbList.A_AddHeadValue( putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF NOT fbList.bOk THEN  
        ;(* List overflow *)  
    END_IF  
END_IF  
  
  
  
IF bGetTail THEN(* enumerate all nodes in list (start at tail node) *)  
    bGetTail := FALSE;  
    sInfo := '';  
  
    fbList.A_GetTail( getValue=>getValue, getPosPtr=>getPosPtr );  
    IF fbList.bOk THEN  
        sInfo := DATAELEMENT_TO_STRING( getValue );  
  
        REPEAT  
            fbList.A_GetPrev( putPosPtr := getPosPtr, getValue=>getValue, getPosPtr=>getPosPtr );  
            IF fbList.bOk THEN  
                sInfo := DATAELEMENT_TO_STRING( getValue );  
            ELSE  
                EXIT;  
            END_IF  
        UNTIL NOT fbList.bOk  
        END_REPEAT  
    END_IF  
END_IF  
  
IF bGetHead THEN(* enumerate all nodes in list (start at head node) *)  
    bGetHead := FALSE;  
    sInfo := '';  
  
    fbList.A_GetHead( getValue=>getValue, getPosPtr=>getPosPtr );  
    IF fbList.bOk THEN  
        sInfo := DATAELEMENT_TO_STRING( getValue );  
  
        REPEAT  
            fbList.A_GetNext( putPosPtr := getPosPtr, getValue=>getValue, getPosPtr=>getPosPtr );  
            IF fbList.bOk THEN  
                sInfo := DATAELEMENT_TO_STRING( getValue );  
            ELSE  
                EXIT;  
            END_IF  
        UNTIL NOT fbList.bOk  
        END_REPEAT  
    END_IF  
END_IF  
  
  
IF bFind  THEN(* search for node in the list by node value (name, price, number... )*)  
    bFind     := FALSE;  
    getPosPtr := 0;(* start from first node element *)  
    sInfo := '';  
  
    REPEAT  
        fbList.A_Find( eSearch := eSearch, putPosPtr := getPosPtr, putValue := search, getValue=>getValue, getPosPtr=>getPosPtr );  
        IF fbList.bOk THEN  
            sInfo := DATAELEMENT_TO_STRING( getValue );  
        ELSE  
            EXIT;  
        END_IF  
    UNTIL NOT fbList.bOk  
    END_REPEAT  
  
END_IF  
  
  
IF bRemoveTailValue THEN(* remove tail node from node list *)  
    bRemoveTailValue := FALSE;  
    sInfo := '';  
    fbList.A_RemoveTailValue( getValue=>getValue, getPosPtr=>getPosPtr );  
    IF fbList.bOk THEN  
        sInfo := DATAELEMENT_TO_STRING( getValue );  
    END_IF  
END_IF  
  
  
IF bRemoveHeadValue THEN(* remove head node from node list *)  
    bRemoveHeadValue := FALSE;  
    sInfo := '';  
    fbList.A_RemoveHeadValue( getValue=>getValue, getPosPtr=>getPosPtr );  
    IF fbList.bOk THEN  
        sInfo := DATAELEMENT_TO_STRING( getValue );  
    END_IF  
END_IF  
  
IF bCount THEN(* count nodes in list *)  
    bCount := FALSE;  
    sInfo := '';  
    fbList.A_Count( );  
    IF fbList.bOk THEN  
        sInfo := UDINT_TO_STRING( fbList.nCount );  
    END_IF  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
