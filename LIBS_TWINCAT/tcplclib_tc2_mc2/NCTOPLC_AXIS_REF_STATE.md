# NCTOPLC_AXIS_REF_STATE

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Axis interface](ms-xhelp:///?Id=beckhoff-6c92-40ec-8c23-14d31eb6d79e)
4. NCTOPLC\_AXIS\_REF\_STATE

# NCTOPLC\_AXIS\_REF\_STATE

The structure NCTOPLC\_AXIS\_REF\_STATE is part of the structure [NCTOPLC\_AXIS\_REF](ms-xhelp:///?Id=beckhoff-00d5-42b3-9ded-9a9f62e7df27).

```
TYPE NCTOPLC_AXIS_REF_STATE :  
    DWORD;  
END_TYPE
```

The individual items of information are provided in the status structure of the AXIS\_REF at the following points:

| Bit | Variable name | Description |
| --- | --- | --- |
| 0 | Status.Operational | Axis is ready for operation |
| 1 | Status.Homed | Axis is referenced ("axis calibrated") |
| 2 | Status.NotMoving | Axis is logically stationary ("Axis not moving") |
| 3 | Status.InPositionArea | Axis is in position window (physical feedback) |
| 4 | Status.InTargetPosition | Axis is at target position (PEH) (physical feedback) |
| 5 | Status.Protected | Axis in protected operation mode (e.g. slave axis) |
| 6 | Status.ErrorPropagationDelayed | Axis signals a preliminary error warning (from TC 2.11) |
| 7 | Status.HasBeenStopped | Axis has been stopped or is presently executing a stop |
| 8 | Status.HasJob | Axis has job, is executing job |
| 9 | Status.PositiveDirection | Axis moving to logically larger values |
| 10 | Status.NegativeDirection | Axis moving to logically smaller values |
| 11 | Status.HomingBusy | Axis is referencing ("axis is being calibrated") |
| 12 | Status.ConstantVelocity | Axis has reached its constant velocity or rotary speed |
| 13 | Status.Compensating | Section compensation passive[0]/active[1] (see MC\_MoveSuperImposed) |
| 14 | Status.ExtSetPointGenEnabled | Enable external setpoint generation |
| 15 |  | Operation mode not yet executed (Busy). Not yet released! |
| 16 | Status.ExternalLatchValid | External latch value or measuring probe has become valid |
| 17 | Status.NewTargetPos | Axis has received a new end position or a new velocity |
| 18 |  | Axis not in target position or cannot/will not reach it (e.g. axis stop). Not yet released! |
| 19 | Status.ContinuousMotion | Axis executing endless positioning task |
| 20 | Status.ControlLoopClosed | Axis ready to operate and axis control loop closed (e.g. position control) |
| 21 | Status.CamTableQueued | New table ready for "Online Change" and waiting for activation |
| 22 | Status.CamDataQueued | Table data (MF) ready for "Online Change" and waiting for activation |
| 23 | CamScalingPending | Table scalings ready for "Online Change" and waiting for activation |
| 24 | Status.CmdBuffered | Follow-up command is available in the command buffer (see BufferMode) (from TwinCAT V2.10 Build 1311) |
| 25 | Status.PTPmode | Axis in PTP operating mode (no slave, no NCI axis, no FIFO axis) (from TC 2.10 Build 1326) |
| 26 | Status.SoftLimitMinExceeded | Software minimum end position is active/occupied (from TC 2.10 Build 1327) |
| 27 | Status.SoftLimitMaxExceeded | Software maximum end position is active/occupied (from TC 2.10 Build 1327) |
| 28 | Status.DriveDeviceError | Drive hardware has an error (no warning); interpretation possible only if drive is in I/O data exchange. e.g. EtherCAT "OP" state (from TC 2.10 Build 1326) |
| 29 | Status.MotionCommandsLocked | Axis is blocked for motion commands (TcMc2) |
| 30 | Status.IoDataInvalid | IO data invalid (e.g. "WcState" or "CdlState" of the fieldbus) |
| 31 | Error | Axis is in an error state |

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
