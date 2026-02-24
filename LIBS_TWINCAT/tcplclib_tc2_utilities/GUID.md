# GUID

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# GUID

System ID.

```
TYPE GUID :  
STRUCT  
    Data1 : DWORD;  
    Data2 : WORD;  
    Data3 : WORD;  
    Data4 : ARRAY[0..7] OF BYTE;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
