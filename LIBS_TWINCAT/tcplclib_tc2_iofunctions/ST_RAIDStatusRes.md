# ST_RAIDStatusRes

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_RAIDStatusRes

# ST\_RAIDStatusRes

```
TYPE ST_RAIDStatusRes :  
STRUCT  
    nRAIDSetIndex     : UDINT;  
    eRAIDType         : E_RAIDType;  
    eRAIDStatus       : E_RAIDStatus;  
    nRAIDDriveCount   : UINT;  
    nReserved         : UINT;  
    stRAIDDriveStatus : ARRAY [1..g_nMAX_NUMBER_OF_RAID_DRIVES] OF ST_RAIDDriveStatus;  
END_STRUCT  
END_TYPE
```

**nRAIDSetIndex**: RAID set ID, as for the input.

**eRAIDType:** Contains the basic RAID type of the RAID set (type: [E\_RAIDType](ms-xhelp:///?Id=beckhoff-7b1a-4d9e-9317-152a5bf34ed2)). **eRAID\_TYPE\_NONE,** indicates that the RAID set consists of a single drive, i.e. no set exists with the specified number.

**eRAIDStatus:** Contains the status of the RAID set (type: [E\_RAIDStatus](ms-xhelp:///?Id=beckhoff-c682-4f26-bc2b-1cd3f00ff780)).

**nRAIDDriveCount:** Contains the number of drives in the RAID set

**nReserved:** Reserved.

**stRAIDDriveStatus:** Contains the status of the physical drive and the information regarding whether the physical drive is part of the RAID set (type: [ST\_RAIDDriveStatus](ms-xhelp:///?Id=beckhoff-814e-4b67-8b99-ed594caef807)).

**g\_nMAX\_NUMBER\_OF\_RAID\_DRIVES** is the number of RAID drives whose status can be read and is defined as a global constant = 10.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
