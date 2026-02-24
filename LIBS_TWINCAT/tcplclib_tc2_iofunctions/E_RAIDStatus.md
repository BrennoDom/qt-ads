# E_RAIDStatus

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. E\_RAIDStatus

# E\_RAIDStatus

```
TYPE E_RAIDStatus :  
(  
    eRAID_SET_STATUS_OK         := 0,  
    eRAID_SET_STATUS_DEGRADED   := 1,  
    eRAID_SET_STATUS_REBUILDING := 2,  
    eRAID_SET_STATUS_FAILED     := 3  
);  
END_TYPE
```

| Name | Value | Meaning |
| --- | --- | --- |
| eRAID\_SET\_STATUS\_OK | 0 | Indicates that the RAID set is ready for operation. |
| eRAID\_SET\_STATUS\_DEGRADED | 1 | Indicates that the RAID set is no longer operating in an error-tolerant mode. |
| eRAID\_SET\_STATUS\_REBUILDING | 2 | Indicates that the RAID set is rebuilding. This means that operation is restricted. Once the rebuild has been successfully completed, the status changes to **eRAID\_SET\_STATUS\_OK**. The status is updated accordingly if the rebuild fails. |
| eRAID\_SET\_STATUS\_FAILED | 3 | Indicates that the RAID set has failed. There is no guarantee of the readiness for operation of the RAID set and loss of data has occurred or threatens. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
