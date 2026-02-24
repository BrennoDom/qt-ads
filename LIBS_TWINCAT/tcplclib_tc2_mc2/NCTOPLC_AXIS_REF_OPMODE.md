# NCTOPLC_AXIS_REF_OPMODE

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Axis interface](ms-xhelp:///?Id=beckhoff-6c92-40ec-8c23-14d31eb6d79e)
4. NCTOPLC\_AXIS\_REF\_OPMODE

# NCTOPLC\_AXIS\_REF\_OPMODE

The structure NCTOPLC\_AXIS\_REF\_OPMODE is part of the structure [NCTOPLC\_AXIS\_REF](ms-xhelp:///?Id=beckhoff-00d5-42b3-9ded-9a9f62e7df27).

```
TYPE NCTOPLC_AXIS_REF_OPMODE :  
    DWORD;  
END_TYPE
```

The individual items of information are provided in the status structure of the AXIS\_REF at the following points:

| Bit | Variable name | Description |
| --- | --- | --- |
| 0 | Status.Opmode.PositionAreaMonitoring | Position range monitoring |
| 1 | Status.Opmode.TargetPositionMonitoring | Target position window monitoring |
| 2 | Status.Opmode.LoopMode | Loop movement |
| 3 | Status.Opmode.MotionMonitoring | Physical movement monitoring |
| 4 | Status.Opmode.PEHTimeMonitoring | PEH time monitoring |
| 5 | Status.Opmode.BacklashCompensation | Backlash compensation |
| 6 | Status.Opmode.DelayedErrorReaction | Delayed error reaction of the NC |
| 7 | Status.Opmode.Modulo | Modulo axis (modulo display) |
| 8 | Status.Opmode.SimulationAxis | Simulation axis |
| 9-11 |  |  |
| 12 | Status.Opmode.StopMonitoring | Standstill monitoring |
| 13-15 |  |  |
| 16 | Status.Opmode.PositionLagMonitoring | Lag monitoring - position |
| 17 | Status.Opmode.VeloLagMonitoring | Lag monitoring - velocity |
| 18 | Status.Opmode.SoftLimitMinMonitoring | End position monitoring min. |
| 19 | Status.Opmode.SoftLimitMaxMonitoring | End position monitoring max. |
| 20 | Status.Opmode.PositionCorrection | Position correction ("Measuring system error compensation") |
| 21 | Status.Opmode.AllowSlaveCommands | Allow motion commands to slave axes |
| 22 | Status.Opmode.AllowExtSetAxisCommands | Allow motion commands to an axis that is fed by an external setpoint generator |
| 23 | Status.NcApplicationRequest | Request bit for the application software (PLC code), e.g. for an "ApplicationHomingRequest" |
| 24-31 | Status.NcCycleCounter | NC cycle counter |

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
