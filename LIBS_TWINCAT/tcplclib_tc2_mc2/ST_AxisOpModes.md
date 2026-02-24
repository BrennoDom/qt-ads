# ST_AxisOpModes

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Motion](ms-xhelp:///?Id=beckhoff-2107-47ed-8b8e-b9259019655e)
4. ST\_AxisOpModes

# ST\_AxisOpModes

This data type contains information about the parameterization of the operating modes of an axis.

```
TYPE ST_AxisOpModes :  
STRUCT  
    PositionAreaMonitoring   : BOOL; (* bit 0 - OpModeDWord *)  
    TargetPositionMonitoring : BOOL; (* bit 1 - OpModeDWord *)  
    LoopMode                 : BOOL; (* bit 2 - OpModeDWord - loop mode for two speed axes *)  
    MotionMonitoring         : BOOL; (* bit 3 - OpModeDWord *)  
    PEHTimeMonitoring        : BOOL; (* bit 4 - OpModeDWord *)  
    BacklashCompensation     : BOOL; (* bit 5 - OpModeDWord *)  
    Modulo                   : BOOL; (* bit 7 - OpModeDWord - axis is parameterized as modulo axis *)  
    PositionLagMonitoring    : BOOL; (* bit 16 - OpModeDWord *)  
    VelocityLagMonitoring    : BOOL; (* bit 17 - OpModeDWord *)  
    SoftLimitMinMonitoring   : BOOL; (* bit 18 - OpModeDWord *)  
    SoftLimitMaxMonitoring   : BOOL; (* bit 19 - OpModeDWord *)  
    PositionCorrection       : BOOL; (* bit 20 - OpModeDWord *)  
END_STRUCT  
END_TYPE 
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
