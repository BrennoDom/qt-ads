# T_HHASHTABLE

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# T\_HHASHTABLE

A hash table handle. The hash table handle is used by the function block: [FB\_HashTableCtrl](ms-xhelp:///?Id=beckhoff-b702-456e-9a3d-bc5349e22c87).

```
TYPE T_HHASHTABLE :  
STRUCT  
    nCount : UDINT := 0;  
    nFree  : UDINT := 0;  
END_STRUCT  
END_TYPE
```

**nCount**: Number of elements occupied.

**nFree**: Number of free elements.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
