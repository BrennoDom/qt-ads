# T_LinkedListEntry

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# T\_LinkedListEntry

Variables of this type represents a node/element of a linked list.

```
TYPE T_LinkedListEntry :  
STRUCT  
    value : PVOID := 0;  
END_STRUCT  
END_TYPE
```

**value**: Value (may be 32/64-bit unsigned number or pointer).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
