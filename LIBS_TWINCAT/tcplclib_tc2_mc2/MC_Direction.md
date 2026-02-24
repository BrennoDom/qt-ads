# MC_Direction

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Motion](ms-xhelp:///?Id=beckhoff-2107-47ed-8b8e-b9259019655e)
4. MC\_Direction

# MC\_Direction

This enumeration type contains the possible directions of movement for the function blocks [MC\_MoveVelocity](ms-xhelp:///?Id=beckhoff-864d-4654-8253-2e77f5465a26) and [MC\_MoveModulo](ms-xhelp:///?Id=beckhoff-dbe7-4239-bf28-d7dbf3a3eb65).

```
TYPE MC_Direction :  
(  
    MC_Positive_Direction := 1,  
    MC_Shortest_Way ,  
    MC_Negative_Direction,  
    MC_Current_Direction  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
