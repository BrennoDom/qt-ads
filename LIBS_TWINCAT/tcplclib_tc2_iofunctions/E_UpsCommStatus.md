# E_UpsCommStatus

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. E\_UpsCommStatus

# E\_UpsCommStatus

Status of communication with the UPS hardware.

```
TYPE E_UpsCommStatus :  
(  
    UpsCommUnknownStatus,  
    UpsCommOk,  
    UpsCommFailed  
);  
END_TYPE
```

| Name | Value | Meaning |
| --- | --- | --- |
| UpsCommUnknownStatus | 0 | The communication status is unknown. |
| UpsCommOk | 1 | Communication has been established with the UPS. |
| UpsCommFailed | 2 | Communication with the UPS was interrupted. |

## Requirements

| Development environment | Target platform | UPS hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | * Beckhoff BAPI v1; * Beckhoff P24Vxxxx; * Beckhoff CP903x card (PCI/ISA); * Beckhoff CX2100-09x4 models (e.g. CX2100-0904 or CX2100-0914 + "Smart Battery" CX2900-0192); * The APC devices that come supplied with Beckhoff Industrial PC support the Smart protocol and can be configured with the Windows UPS service. | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
