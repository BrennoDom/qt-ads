# E_RAIDDriveStatus

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. E\_RAIDDriveStatus

# E\_RAIDDriveStatus

```
TYPE E_RAIDDriveStatus :  
(  
    eRAID_DRIVE_STATUS_OK         := 0,  
    eRAID_DRIVE_STATUS_REBUILDING := 1,  
    eRAID_DRIVE_STATUS_FAILED     := 2,  
    eRAID_DRIVE_STATUS_DEGRADED   := 3  
);  
END_TYPE
```

| Name | Value | Meaning |
| --- | --- | --- |
| eRAID\_DRIVE\_STATUS\_OK | 0 | Indicates that the physical drive is ready for operation. |
| eRAID\_DRIVE\_STATUS\_DEGRADED | 1 | Indicates that the physical drive has sent a SMART message to the controller. |
| eRAID\_DRIVE\_STATUS\_REBUILDING | 2 | Indicates that the physical drive is the target drive of a RAID set rebuild. If the rebuild has been successfully completed, the status changes to **eRAID\_DRIVE\_STATUS\_OK**. The status is updated accordingly if the rebuild fails. |
| eRAID\_DRIVE\_STATUS\_FAILED | 3 | Indicates that the physical drive has signaled unrecoverable errors to the controller or that the drive has started a vendor-specific action in order to remove the drive from the RAID set. There is no guarantee of the readiness for operation of the drive and loss of data has occurred or threatens. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
