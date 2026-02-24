# F_CreateHashTableHnd

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_CreateHashTableHnd

![22568466](/tcplclib_tc2_utilities/1033/Images/gif/35807883__en-US__Web.gif)

The function initializes the hash table handle. The table handle must be initialized once by calling the F\_CreateHashTableHnd function.

## FUNCTION F\_CreateHashTableHnd: BOOL

## VAR\_INPUT

```
VAR_INPUT  
    pEntries   : POINTER TO T_HashTableEntry := 0;  
    cbEntries  : UDINT := 0;  
END_VAR
```

**pEntries**: Address of the first T\_HashTableEntry array element. The address can be determined with the ADR operator (type: [T\_HashTableEntry](ms-xhelp:///?Id=beckhoff-f709-431c-b52e-a525ed95ad7f)).

**cbEntries**: T\_HashTableEntry byte size. The byte size can be determined with the SIZEOF operator.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    hTable : T_HHASHTABLE;  
END_VAR
```

**hTable**: Hash table handle to be initialized (type: [T\_HHASHTABLE](ms-xhelp:///?Id=beckhoff-e87f-4e13-9774-2f414847ed8d)). The handle is required for accessing the hash table from the function block [FB\_HashTableCtrl](ms-xhelp:///?Id=beckhoff-b702-456e-9a3d-bc5349e22c87).

| Return parameter | Description |
| --- | --- |
| TRUE | No error |
| FALSE | Error |

**Example**:

See: [Example: Hash table (FB\_HashTableCtrl).](ms-xhelp:///?Id=beckhoff-a6cc-49d6-81e1-84d07b1d573e)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
