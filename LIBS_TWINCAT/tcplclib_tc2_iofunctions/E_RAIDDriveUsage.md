# E_RAIDDriveUsage

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. E\_RAIDDriveUsage

# E\_RAIDDriveUsage

```
TYPE E_RAIDDriveUsage :  
(  
    eRAID_DRIVE_CONFIG_NOT_USED   := 0,  
    eRAID_DRIVE_CONFIG_MEMBER     := 1,  
    eRAID_DRIVE_CONFIG_SPARE      := 2  
);  
END_TYPE
```

| Name | Value | Meaning |
| --- | --- | --- |
| eRAID\_DRIVE\_CONFIG\_NOT\_USED | 0 | Indicates that the physical drive is not part of a RAID set. |
| eRAID\_DRIVE\_CONFIG\_MEMBER | 1 | Indicates that the physical drive is part of a RAID set. |
| eRAID\_DRIVE\_CONFIG\_SPARE | 2 | Indicates that the physical drive is part of this RAID set as a “hot swap spare”. |

“hot swap spare” -> if a drive within the RAID group fails, it is replaced by the reserve drive (hot spare) while operation continues (hot swap). Redundancy is thus restored as quickly as possible.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
