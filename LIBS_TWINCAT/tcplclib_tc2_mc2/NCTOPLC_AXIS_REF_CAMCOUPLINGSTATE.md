# NCTOPLC_AXIS_REF_CAMCOUPLINGSTATE

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Axis interface](ms-xhelp:///?Id=beckhoff-6c92-40ec-8c23-14d31eb6d79e)
4. NCTOPLC\_AXIS\_REF\_CAMCOUPLINGSTATE

# NCTOPLC\_AXIS\_REF\_CAMCOUPLINGSTATE

```
TYPE NCTOPLC_AXIS_REF_CAMCOUPLINGSTATE :  
STRUCT  
    CamActivationPending    : BIT;  
    CamDeactivationPending  : BIT;  
    CamActive               : BIT;  
    {attribute 'hide'}  
    _reserved1              : BIT;  
    {attribute 'hide'}  
    _reserved2              : BIT;  
    {attribute 'hide'}  
    _reserved3              : BIT;  
    CamDataQueued           : BIT;  
    CamScalingPending       : BIT;  
END_STRUCT  
END_TYPE
```

| Bit | Variable name | Description |
| --- | --- | --- |
| 0 | CamActivationPending | Table waiting for activation |
| 1 | CamDeactivationPending | Table waiting for deactivation |
| 2 | CamActive | Table is active |
| 3-5 |  | RESERVE |
| 6 | CamDataQueued | Table data (MF) ready for "Online Change" and waiting for activation |
| 7 | CamScalingPending | Table scalings ready for "Online Change" and waiting for activation |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4020 | PC or CX (x86) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
