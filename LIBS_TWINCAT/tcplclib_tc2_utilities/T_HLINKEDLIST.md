# T_HLINKEDLIST

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# T\_HLINKEDLIST

A Linked List Handle. The Linked List Handle is used by the function block [FB\_LinkedListCtrl](ms-xhelp:///?Id=beckhoff-ef44-4813-9f63-c2cc598139aa).

```
TYPE T_HLINKEDLIST :  
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
