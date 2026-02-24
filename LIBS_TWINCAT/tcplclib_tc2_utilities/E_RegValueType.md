# E_RegValueType

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_RegValueType

Type IDs for registry values.

```
TYPE E_RegValueType :  
(  
    REG_NONE := 0,  
    REG_SZ,  
    REG_EXPAND_SZ,  
    REG_BINARY,  
    REG_DWORD,  
    REG_DWORD_BIG_ENDIAN,  
    REG_LINK,  
    REG_MULTI_SZ,  
    REG_RESOURCE_LIST,  
    REG_FULL_RESOURCE_DESCRIPTOR,  
    REG_RESOURCE_REQUIREMENTS_LIST,  
    REG_QWORD  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| REG\_NONE | No value TYPE |
| REG\_SZ | Unicode null terminated STRING |
| REG\_EXPAND\_SZ | Unicode null terminated STRING (with environment variable references) |
| REG\_BINARY | Free form binary |
| REG\_DWORD | 32 bit number and REG\_DWORD\_LITTLE\_ENDIAN (same as REG\_DWORD) |
| REG\_DWORD\_BIG\_ENDIAN | 32 bit number |
| REG\_LINK | Symbolic Link (unicode) |
| REG\_MULTI\_SZ | Multiple Unicode strings |
| REG\_RESOURCE\_LIST | Resource list in the resource map |
| REG\_FULL\_RESOURCE\_DESCRIPTOR | Resource list in the hardware description |
| REG\_RESOURCE\_REQUIREMENTS\_LIST | - |
| REG\_QWORD | 64 bit number and REG\_QQOERD\_LITTLE\_ENDIAN (same as REG\_QWORD) |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
