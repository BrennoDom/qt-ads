# E_RAIDType

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. E\_RAIDType

# E\_RAIDType

```
TYPE E_RAIDType :  
(  
    eRAID_TYPE_NONE  := 0,  
    eRAID_TYPE_0     := 1,  
    eRAID_TYPE_1     := 2,  
    eRAID_TYPE_10    := 3,  
    eRAID_TYPE_5     := 4,  
    eRAID_TYPE_15    := 5,  
    eRAID_TYPE_OTHER := 255  
);  
END_TYPE
```

| Name | Value | Meaning |
| --- | --- | --- |
| eRAID\_TYPE\_NONE | 0 | Indicates that the RAID set consists of a single drive. No set exists with the specified number. |
| eRAID\_TYPE\_0 | 1 | Indicates that the RAID set is a striped set without error tolerance. |
| eRAID\_TYPE\_1 | 2 | Indicates that the RAID set is a mirrored set. |
| eRAID\_TYPE\_10 | 3 | Indicates that the RAID set is a striped and mirrored set. |
| eRAID\_TYPE\_5 | 4 | Indicates that the RAID set is a parity set. |
| eRAID\_TYPE\_15 | 5 | Indicates that the RAID set is advanced parity set. |
| eRAID\_TYPE\_OTHER | 255 | Indicates that the configuration of the RAID set does not correspond to the standard types. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
