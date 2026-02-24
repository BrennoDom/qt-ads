# T_HashTableEntry

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# T\_HashTableEntry

A hash table entry/element.

```
TYPE T_HashTableEntry :  
STRUCT  
    key   : DWORD := 0;(* Entry key *)  
    value : PVOID := 0;(* Entry value *)  
END_STRUCT  
END_TYPE
```

**key**: Key (32-bit unsigned number or 32-bit pointer).

**value**: Value (may be 32/64-bit unsigned number or pointer).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
