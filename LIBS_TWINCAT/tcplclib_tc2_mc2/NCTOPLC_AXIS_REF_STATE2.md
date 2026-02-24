# NCTOPLC_AXIS_REF_STATE2

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Axis interface](ms-xhelp:///?Id=beckhoff-6c92-40ec-8c23-14d31eb6d79e)
4. NCTOPLC\_AXIS\_REF\_STATE2

# NCTOPLC\_AXIS\_REF\_STATE2

The structure NCTOPLC\_AXIS\_REF\_STATE2 is part of the structure [NCTOPLC\_AXIS\_REF](ms-xhelp:///?Id=beckhoff-00d5-42b3-9ded-9a9f62e7df27).

```
TYPE NCTOPLC_AXIS_REF_STATE2 :  
UNION  
    Value     : DWORD;  
    Flags     : NCTOPLC_AXIS_REF_STATE2_FLAGS;  
END_TYPE
```

See also: [NCTOPLC\_AXIS\_REF\_STATE2\_FLAGS](ms-xhelp:///?Id=beckhoff-2d8f-499f-b23c-8150f42edb62)

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
