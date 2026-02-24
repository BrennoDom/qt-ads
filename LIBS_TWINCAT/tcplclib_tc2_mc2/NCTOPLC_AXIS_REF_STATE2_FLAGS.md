# NCTOPLC_AXIS_REF_STATE2_FLAGS

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Axis interface](ms-xhelp:///?Id=beckhoff-6c92-40ec-8c23-14d31eb6d79e)
4. NCTOPLC\_AXIS\_REF\_STATE2\_FLAGS

# NCTOPLC\_AXIS\_REF\_STATE2\_FLAGS

The structure NCTOPLC\_AXIS\_REF\_STATE2\_FLAGS is part of the structure [NCTOPLC\_AXIS\_REF\_STATE2](ms-xhelp:///?Id=beckhoff-cd8b-4016-88e6-2fb03b75e036).

```
TYPE NCTOPLC_AXIS_REF_STATE2_FLAGS :  
STRUCT  
    AvoidingCollision       : BIT;  
    {attribute 'hide'}  
    _reserved1              : BIT;  
    {attribute 'hide'}  
    _reserved2              : BIT;  
    {attribute 'hide'}  
    _reserved3              : BIT;  
    {attribute 'hide'}  
    _reserved4              : BIT;  
    {attribute 'hide'}  
    _reserved5              : BIT;  
    {attribute 'hide'}  
    _reserved6              : BIT;  
    {attribute 'hide'}  
    _reserved7              : BIT;  
    {attribute 'hide'}  
    _reserved8              : ARRAY [1..3] OF USINT;  
END_STRUCT;  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
