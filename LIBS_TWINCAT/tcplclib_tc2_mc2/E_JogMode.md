# E_JogMode

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Motion](ms-xhelp:///?Id=beckhoff-2107-47ed-8b8e-b9259019655e)
4. E\_JogMode

# E\_JogMode

This data type is used in conjunction with the function block [MC\_Jog](ms-xhelp:///?Id=beckhoff-d9b3-4f59-8228-37a7917c3bcf).

```
TYPE E_JogMode :  
(  
    MC_JOGMODE_STANDARD_SLOW, (* motion with standard jog parameters for slow motion *)  
    MC_JOGMODE_STANDARD_FAST, (* motion with standard jog parameters for fast motion *)  
    MC_JOGMODE_CONTINOUS, (* axis moves as long as the jog button is pressed using parameterized dynamics *)  
    MC_JOGMODE_INCHING, (* axis moves for a certain relative distance *)  
    MC_JOGMODE_INCHING_MODULO (* axis moves for a certain relative distance - stop position is rounded to the distance value *)  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
