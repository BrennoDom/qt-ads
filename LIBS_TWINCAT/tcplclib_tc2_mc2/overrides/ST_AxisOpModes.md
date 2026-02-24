````markdown
# ST_AxisOpModes

```
TYPE ST_AxisOpModes :
STRUCT
    PositionAreaMonitoring   : BOOL; (* bit 0 - OpModeDWord *)
    TargetPositionMonitoring : BOOL; (* bit 1 - OpModeDWord *)
    LoopMode                 : BOOL; (* bit 2 - OpModeDWord - loop mode for two speed axes *)
    MotionMonitoring         : BOOL; (* bit 3 - OpModeDWord *)
    PEHTimeMonitoring        : BOOL; (* bit 4 - OpModeDWord *)
    BacklashCompensation     : BOOL; (* bit 5 - OpModeDWord *)
    DelayedErrorReaction     : BOOL; (* bit 6 - OpModeDWord *)
    Modulo                   : BOOL; (* bit 7 - OpModeDWord - axis is parameterized as modulo axis *)
    SimulationAxis           : BOOL; (* bit 8 - OpModeDWord *)
    StopMonitoring           : BOOL; (* bit 12*)
    PositionLagMonitoring    : BOOL; (* bit 16 - OpModeDWord *)
    VelocityLagMonitoring    : BOOL; (* bit 17 - OpModeDWord *)
    SoftLimitMinMonitoring   : BOOL; (* bit 18 - OpModeDWord *)
    SoftLimitMaxMonitoring   : BOOL; (* bit 19 - OpModeDWord *)
    PositionCorrection       : BOOL; (* bit 20 - OpModeDWord *)
    AllowSlaveCommands       : BOOL; (* bit 21 - OpModeDWord *)
    AllowExtSetAxisCommands  : BOOL; (* bit 22 - OpModeDWord *)
END_STRUCT
END_TYPE 
```
````
