# ST_RAIDDriveStatus

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_RAIDDriveStatus

# ST\_RAIDDriveStatus

```
TYPE ST_RAIDDriveStatus :  
STRUCT  
    eRAIDDriveStatus  : E_RAIDDriveStatus;  
    eRAIDDriveUsage   : E_RAIDDriveUsage;  
    nSATAPort         : UINT;  
    sRAIDDriveSerial  : STRING [39];  
END_STRUCT  
END_TYPE
```

**eRAIDDriveStatus**: Contains the status of the physical drive (type: [E\_RAIDDriveStatus](ms-xhelp:///?Id=beckhoff-a263-4b22-b2f9-7b73197ea7dc)).

**eRAIDDriveUsage**: States whether the physical drive is part of the RAID set (type: [E\_RAIDDriveUsage](ms-xhelp:///?Id=beckhoff-05e9-4019-b894-aa9eb8a56f34)).

**nSATAPort**: Contains the SAS address of the physical drive. This box should contain a 0 if the drive has no SAS address, as is the case, for example, with a directly attached SATA drive.

**sRAIDDriveSerial**: Serial number of the RAID drive (40 letters).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
