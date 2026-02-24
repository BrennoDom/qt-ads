# Example: Hash table (FB_HashTableCtrl)

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Example: Hash table (FB\_HashTableCtrl)

Here you can unpack the complete sources: [HashTableExample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_utilities/Resources/zip/9007200058162699.zip)

The example project has two parts to the program:

* P\_TABLE\_OF\_UDINT is a simple example program that only processes 32-bit values in the hash table.
* P\_TABLE\_OF\_STRUCTDATA illustrates how other data types (e.g. structured data types) can be processed in the hash table.

The maximum number of table elements cannot be changed at runtime, and is limited in the example project by MAX\_DATA\_ELEMENTS. If more elements are required, the table array can be enlarged accordingly (i.e. increase the value of the constant).

```
VAR_GLOBAL CONSTANT  
    MAX_DATA_ELEMENTS   : UDINT := 100;(* Max. number of elements in the list *)  
    MAX_NAME_LENGTH     : UDINT := 30;(* Max. length of article name *)  
END_VAR
```

## PROGRAM P\_TABLE\_OF\_UDINT

In the first PLC cycle the article number and article name are stored in the table. The article number serves as key and the array index of the article name as value.  
 Via a rising edge at bLookup the article name can be found via the article number.

```
PROGRAM P_TABLE_OF_UDINT  
VAR  
    sInfo    : T_MaxString := '';  
    bAdd     : BOOL := TRUE;  
    bLookup  : BOOL := TRUE;  
    bRemove  : BOOL := TRUE;  
    bEnum    : BOOL := TRUE;  
    bCount   : BOOL := TRUE;  
  
    search   : UDINT := 11111;(* article number *)  
  
    fbTable  : FB_HashTableCtrl;(* basic hash table control function block *)  
    hTable   : T_HHASHTABLE;(* hash table handle *)  
    table    : ARRAY[0..MAX_DATA_ELEMENTS] OF T_HashTableEntry;(* Max. number of hash table entries. The value of hash table entry = 32 bit integer *)  
    names    : ARRAY[0..MAX_DATA_ELEMENTS] OF STRING(MAX_NAME_LENGTH);  
    bInit    : BOOL := TRUE;  
END_VAR
```

```
IF bInit THEN  
    bInit := FALSE;  
    F_CreateHashTableHnd( ADR( table ), SIZEOF( table ), hTable );(* Intialize table handle *)  
END_IF  
  
IF bAdd THEN  
    bAdd := FALSE;  
  
    (* Fill table. Article number is the key. Array index number is the value (article name) *)  
    names[0] := 'Chair';  
    fbTable.A_Add( key := 12345, putValue := 0(* array index*), hTable := hTable );  
    IF NOT fbTable.bOk THEN  
        ;(* Table overflow *)  
    END_IF  
  
    names[1] := 'Table';  
    fbTable.A_Add( key := 67890, putValue := 1, hTable := hTable );  
    IF NOT fbTable.bOk THEN  
        ;(* Table overflow *)  
    END_IF  
  
    names[2] := 'Couch';  
    fbTable.A_Add( key := 11111, putValue := 2, hTable := hTable );  
    IF NOT fbTable.bOk THEN  
        ;(* Table overflow *)  
    END_IF  
  
    names[3] := 'TV set';  
    fbTable.A_Add( key := 22222, putValue := 3, hTable := hTable );  
    IF NOT fbTable.bOk THEN  
        ;(* Table overflow *)  
    END_IF  
END_IF  
  
  
IF bLookup THEN    (* search for the article name by article number *)  
    bLookup := FALSE;  
    sInfo := '';  
    fbTable.A_Lookup( key := search, hTable := hTable );  
    IF fbTable.bOk THEN  
        sInfo := names[fbTable.getValue];  
    ELSE  
        ;(* Entry not found *)  
    END_IF  
END_IF  
  
IF bRemove THEN(* remove one entry from the table *)  
    bRemove := FALSE;  
    sInfo := '';  
    fbTable.A_Remove( key := search, hTable := hTable );  
    IF fbTable.bOk THEN  
        sInfo := names[fbTable.getValue];  
    ELSE  
        ;(* Entry not found *)  
    END_IF  
END_IF  
  
  
IF bEnum THEN(* enumerate table entries *)  
    bEnum := FALSE;  
    sInfo := '';  
  
    fbTable.A_GetFirst( putPosPtr := 0, hTable := hTable );  
    IF fbTable.bOk THEN  
        sInfo := names[fbTable.getValue];  
  
        REPEAT  
            fbTable.A_GetNext( putPosPtr := fbTable.getPosPtr , hTable := hTable );  
            IF fbTable.bOk THEN  
                sInfo := names[fbTable.getValue];  
            END_IF  
        UNTIL NOT fbTable.bOk  
        END_REPEAT  
  
    END_IF  
END_IF  
  
IF bCount THEN(* count entries in the table *)  
    bCount := FALSE;  
    sInfo := UDINT_TO_STRING( hTable.nCount );  
END_IF
```

## PROGRAM P\_TABLE\_OF\_STRUCTDATA

This section of the program illustrates how structured data sets can be manipulated in the table in place of simply 32-bit numbers. The 32-bit element value is only used as reference pointer to the actual element value. The reference pointer is able to point to instances of structured variables or other data types. The functionality is encapsulated in a function block. The function block *FB\_SpecialHashTableCtrl* can be regarded as a specialized version of the *FB\_HashTableCtrl* function block. The *FB\_HashTableCtrl*-block is also used internally by the FB the specialized FB.

The *DATAELEMENT\_TO\_STRING* function is only used to permit visual output of the value of the node.

A structured variable of type *ST\_DataElement* is used as an example. The highlight: You can add further member variables to the data type declaration of ST\_DataElement without having to make any changes to the program or to the FB\_SpecialHashTableCtrl function block.

The type declaration for ST\_DataElement:

```
TYPE ST_DataElement :(* Structured application data entry *)  
STRUCT  
    (* Adapt this structure to match your application needs *)  
    number        : UDINT := 0;  
    name        : STRING(MAX_NAME_LENGTH) := '';  
    price        : REAL := 0.0;  
END_STRUCT  
END_TYPE
```

## How do the 32-bit element values become reference pointers to the instances of the ST\_DataElement array?

The maximum size of the table is limited by the constant MAX\_DATA\_ELEMENTS. It follows that no more than MAX\_DATA\_ELEMENTS reference pointers can be stored in the table. Internally the *FB\_SpecialHashTableCtrl* block has a ST\_DataElement array variable with the same array size as the T\_HashTableEntry array variable. To simplify matters, the array indices are the same for both arrays!

Each T\_HashTableEntry array element can only be used once in the table. The *FB\_HashTableCtrl* function block searches for a free/unused T\_HashTableEntry array element. If successful, the element is added to the table. The action *A\_GetIndexAtPosPtr* can be used to determine the index of the T\_HashTableEntry array. In the next step, the 32-bit node value that has just been added is assigned the address of the same array element in the ST\_DataElement array. In the project example through the second action call: *A\_Add*.

**nodes[index].value := ADR( dataPool[index] )**

The allocation is realized in the *FB\_SpecialHashTableCtrl*->*A\_Add* action, for example:

```
(* Adds entry to the table *)  
MEMSET( ADR( getValue ), 0, SIZEOF( getValue ) );  
getPosPtr := 0;  
  
fbTable.A_Add( hTable := hTable, key := key, putValue := 16#00000000(* we will set this value later *), getPosPtr=>getPosPtr, bOk=>bOk );(* Add new element to the table, getPosPtr points to the new entry *)  
IF fbTable.bOk THEN(* Success *)  
    fbTable.A_GetIndexAtPosPtr( hTable := hTable, putPosPtr := getPosPtr, getValue =>indexOfElem, bOk=>bOk );(* Get array index of getPosPtr entry *)  
    IF fbTable.bOk THEN(* Success *)  
        pRefPtr     := ADR( dataPool[indexOfElem] );(* Get pointer to the data element *)  
  
        pRefPtr^ := putValue;(* copy application value *)  
  
        fbTable.A_Add( hTable := hTable, key := key, putValue := pRefPtr, bOk=>bOk );(* Assign the entry value = pointer to the data element *)  
        IF fbTable.bOk THEN(* Success *)  
            getValue := putValue;  
        END_IF  
    END_IF  
END_IF
```

```
PROGRAM P_TABLE_OF_STRUCTDATA  
VAR  
    sInfo      : T_MaxString := '';  
    bAdd       : BOOL := TRUE;  
    bLookup    : BOOL := TRUE;  
    bRemove    : BOOL := TRUE;  
    bEnum      : BOOL := TRUE;  
    bCount     : BOOL := TRUE;  
  
    search     : UDINT := 11111;(* article number *)  
  
    fbTable    : FB_SpecialHashTableCtrl;(* Specialized hash table control function block *)  
    putValue   : ST_DataElement;  
    getValue   : ST_DataElement;  
    getPosPtr  : POINTER TO T_HashTableEntry := 0;  
    bInit      : BOOL := TRUE;  
END_VAR
```

```
IF bInit THEN  
    bInit     := FALSE;  
    fbTable.A_Reset();(* reset / initialize table *)  
END_IF  
  
  
IF bAdd THEN  
    bAdd := FALSE;  
  
    (* Fill table. Article number is the key and data structure is the value *)  
    putValue.number := 12345;  
    putValue.name := 'Chair';  
    putValue.price := 44.98;  
    fbTable.A_Add( key := 12345, putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF NOT fbTable.bOk THEN  
        ;(* Table overflow *)  
    END_IF  
  
    putValue.number := 67890;  
    putValue.name := 'Table';  
    putValue.price := 99.98;  
    fbTable.A_Add( key := 67890, putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF NOT fbTable.bOk THEN  
        ;(* Table overflow *)  
    END_IF  
  
    putValue.number := 11111;  
    putValue.name := 'Couch';  
    putValue.price :=  99.98;  
    fbTable.A_Add( key := 11111, putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF NOT fbTable.bOk THEN  
        ;(* Table overflow *)  
    END_IF  
  
    putValue.number := 22222;  
    putValue.name := 'TV set';  
    putValue.price :=  99.98;  
    fbTable.A_Add( key := 22222, putValue := putValue, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF NOT fbTable.bOk THEN  
        ;(* Table overflow *)  
    END_IF  
  
END_IF  
  
IF bLookup THEN(* search for the article name by article number *)  
    bLookup := FALSE;  
    sInfo := '';  
    fbTable.A_Lookup( key := search, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF fbTable.bOk THEN  
        sInfo := DATAELEMENT_TO_STRING( getValue );  
    ELSE  
        ;(* Entry not found *)  
    END_IF  
END_IF  
  
IF bRemove THEN(* remove one entry from the table *)  
    bRemove := FALSE;  
    sInfo := '';  
    fbTable.A_Remove( key := search, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF fbTable.bOk THEN  
        sInfo := DATAELEMENT_TO_STRING( getValue );  
    ELSE  
        ;(* Entry not found *)  
    END_IF  
END_IF  
  
IF bEnum THEN(* enumerate table entries *)  
    bEnum := FALSE;  
    sInfo := '';  
  
    fbTable.A_GetFirst( putPosPtr := 0, getPosPtr=>getPosPtr, getValue=>getValue );  
    IF fbTable.bOk THEN  
        sInfo := DATAELEMENT_TO_STRING( getValue );  
  
        REPEAT  
            fbTable.A_GetNext( putPosPtr := fbTable.getPosPtr , getPosPtr=>getPosPtr, getValue=>getValue );  
            IF fbTable.bOk THEN  
                sInfo := DATAELEMENT_TO_STRING( getValue );  
            END_IF  
        UNTIL NOT fbTable.bOk  
        END_REPEAT  
  
    END_IF  
END_IF  
  
IF bCount THEN(* count entries in the table *)  
    bCount := FALSE;  
    fbTable.A_Count();  
    IF fbTable.bOk THEN  
        sInfo := UDINT_TO_STRING( fbTable.nCount );  
    END_IF  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
