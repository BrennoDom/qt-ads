# FB_HashTableCtrl

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_HashTableCtrl

![43945239](/tcplclib_tc2_utilities/1033/Images/png/9007199290267275__Web.png)

The hash table can be used as an efficient tool for finding individual data element among a larger number of data elements. The data objects must have a unique key. The key enables the data objects to be identified unambiguously and found quickly in the table.

The function block FB\_HashTableCtrl can be used to realize a simple hash table in the PLC project, using the hashing with chaining (separate chaining) procedure. The hashing with chaining (separate chaining) procedure is used.

The maximum number of data elements cannot be changed at runtime and must be specified in advance. Adding/removing/finding of data elements is controlled through action calls. The function block features the following tasks:

* **A\_Add** (adds a new data element to the table (key/value). If an element with the same key already exists, it is overwritten! )
* **A\_GetFirst** (reads the first table data element. If successful, *getValue* supplies the associated value.)
* **A\_GetNext** (reads the next table data element. The address *putPosPtr* must point to the previous data element!)
* **A\_Lookup** (looks for a data element matching the key. If successful, *getValue* supplies the associated value.)
* **A\_Remove** (removes a data element matching the key.)
* **A\_RemoveAll** (removes all data elements)
* **A\_RemoveFirst** (removes the first data element)
* **A\_reset** (deletes all data elements and resets the table.)
* **A\_GetIndexAtPosPtr** (supplies the array index of the data element at the address: *putPosPtr*. When successful, *getValue* returns the null-based array index. The value of *putValue* is not used. Please note that the value *getValue* returns a data element index, not the data element value! )

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    hTable  : T_HHASHTABLE;  
END_VAR
```

**hTable**: Hash table handle (type: [T\_HHASHTABLE](ms-xhelp:///?Id=beckhoff-e87f-4e13-9774-2f414847ed8d)). The handle must be initialized once with the function [F\_CreateHashTableHnd](ms-xhelp:///?Id=beckhoff-d385-465c-a304-0e60b9d1d697) before it can be used. A corresponding instance of the handle variable must be created and initialized for each table.

## VAR\_INPUT

```
VAR_INPUT  
    key       : DWORD := 0;  
    putValue  : PVOID := 0;  
    putPosPtr : POINTER TO T_HashTableEntry := 0;  
END_VAR
```

**key:** Key (unsigned 32 bit number or pointer). This key enables a data object to be identified and found quickly in the table.

**putValue**: Value/data element (input parameter, 32/64 bit, unsigned number or pointer).

**putPosPtr**: Address for data element (input parameter, type: [T\_HashTableEntry](ms-xhelp:///?Id=beckhoff-f709-431c-b52e-a525ed95ad7f))

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bOk        : BOOL := FALSE;  
    getValue   : PVOID := 0;  
    getPosPtr  : POINTER TO T_HashTableEntry := 0;  
END_VAR
```

**bOk**: Returns TRUE if a new data element was added to/removed from or found in the table. Returns FALSE, if the searched data element was not found, the table is empty or an overflow occurred (table has no free data elements).

**getValue**: The value matching the key/data element (output parameter, 32/64 bit, unsigned number or pointer).

**getPosPtr**: The address for the data element (output parameter, type: [T\_HashTableEntry](ms-xhelp:///?Id=beckhoff-f709-431c-b52e-a525ed95ad7f)).

**Example:**

See: [Example: Hash table (FB\_HashTableCtrl).](ms-xhelp:///?Id=beckhoff-a6cc-49d6-81e1-84d07b1d573e)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
