# E_PositionType

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [External set value generator](ms-xhelp:///?Id=beckhoff-de8f-406a-99d6-4a433628a6b1)
4. E\_PositionType

# E\_PositionType

```
TYPE E_PositionType :  
(  
    POSITIONTYPE_ABSOLUTE := 1, (*Absolute position*)  
    POSITIONTYPE_RELATIVE,     (*Relative position*)  
    POSITIONTYPE_MODULO := 5 (*Modulo position*)  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
