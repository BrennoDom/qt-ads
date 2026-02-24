# NCTOPLC_AXIS_REF

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Axis interface](ms-xhelp:///?Id=beckhoff-6c92-40ec-8c23-14d31eb6d79e)
4. NCTOPLC\_AXIS\_REF

# NCTOPLC\_AXIS\_REF

The data structure NCTOPLC\_AXIS\_REF is part of the [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) data structure and is automatically updated by the NC, so that updated information is available during each PLC cycle. NCTOPLC\_AXIS\_REF is also referred to as axis interface between NC and PLC.

```
TYPE NCTOPLC_AXIS_REF  
STRUCT  
    StateDWord                    : NCTOPLC_AXIS_REF_STATE; (* Status double word *)  
    ErrorCode                     : DWORD; (* Axis error code *)  
    AxisState                     : DWORD; (* Axis moving status *)  
    AxisModeConfirmation          : DWORD; (* Axis mode confirmation (feedback from NC) *)  
    HomingState                   : DWORD; (* State of axis calibration (homing) *)  
    CoupleState                   : DWORD; (* Axis coupling state *)  
    SvbEntries                    : DWORD; (* SVB entries/orders (SVB = Set preparation task) *)  
    SafEntries                    : DWORD; (* SAF entries/orders (SAF = Set execution task) *)  
    AxisId                        : DWORD; (* Axis ID *)  
    OpModeDWord                   : NCTPPLC_AXIS_REF_OPMODE; (* Current operation mode *)  
    ActPos                        : LREAL; (* Actual position (absolut value from NC) *)  
    ModuloActPos                  : LREAL; (* Actual modulo position *)  
    ActiveControlLoopIndex        : WORD; (* Active control loop index *)  
    ControlLoopIndex              : WORD; (* Axis control loop index (0, 1, 2, when multiple control loops are used) *)  
    ModuloActTurns                : DINT; (* Actual modulo turns *)  
    ActVelo                       : LREAL; (* Actual velocity *)  
    PosDiff                       : LREAL; (* Position difference (lag distance) *)  
    SetPos                        : LREAL; (* Setpoint position *)  
    SetVelo                       : LREAL; (* Setpoint velocity *)  
    SetAcc                        : LREAL; (* Setpoint acceleration *)  
    TargetPos                     : LREAL; (* Estimated target position *)  
    ModuloSetPos                  : LREAL; (* Setpoint modulo position *)  
    ModuloSetTurns                : DINT; (* Setpoint modulo turns *)  
    CmdNo                         : WORD; (* Continuous actual command number *)  
    CmdState                      : WORD; (* Command state *)  
    SetJerk                       : LREAL;  
    SetTorque                     : LREAL;  
    ActTorque                     : LREAL;  
    StateDWord2                   : NCTOPLC_AXIS_REF_STATE2;  
    StateDWord3                   : DWORD;  
    TouchProbeState               : DWORD;  
    TouchProbeCounter             : DWORD;  
    CamCouplingState              : ARRAY [0..7] OF NCTOPLC_AXIS_REF_CAMCOUPLINGSTATE;  
    CamCouplingTableID            : ARRAY [0..7] OF UINT;  
    ActTorqueDerivative           : LREAL;  
    SetTorqueDerivative           : LREAL;  
    {attribute 'hide'}  
    _reserved1                    : ARRAY [1..16] OF USINT;  
    ActPosWithoutPosCorrection    : LREAL;  
    ActAcc                        : LREAL;  
    DcTimeStamp                   : UDINT;  
    {attribute 'hide'}  
    _reserved2                    : ARRAY [1..12] OF USINT;  
END_TYPE
```

| Variable name | Data type | Definition range | Description |
| --- | --- | --- | --- |
| StateDWord | [NCTOPLC\_AXIS\_REF\_STATE](ms-xhelp:///?Id=beckhoff-f85c-4b89-b684-6d91327d85ee) | - | State double word. |
| ErrorCode | DWORD | ≥0 | Axis error code |
| AxisState | DWORD | [ENUM](ms-xhelp:///?Id=beckhoff-00d5-42b3-9ded-9a9f62e7df27) | Present state of the axis movement |
| AxisModeConfirmation | DWORD | ENUM | Axis operating mode (feedback from the NC) |
| HomingState | DWORD | [ENUM](ms-xhelp:///?Id=beckhoff-00d5-42b3-9ded-9a9f62e7df27) | Reference status of the axis ("calibration status") |
| CoupleState | DWORD | [ENUM](ms-xhelp:///?Id=beckhoff-00d5-42b3-9ded-9a9f62e7df27) | Axis coupling state |
| SvbEntries | DWORD | ≥0 | SVB entries/tasks |
| SafEntries | DWORD | ≥0 | SAF entries/tasks (NC interpreter, FIFO group) |
| AxisId | DWORD | >0 | Axis ID |
| OpModeDWord. | [NCTOPLC\_AXIS\_REF\_OPMODE](ms-xhelp:///?Id=beckhoff-d000-4c03-ac10-44589daa5245) | - | Axis operation mode double word |
| ActPos | LREAL | ±∞ | Actual position (calculated absolute value) |
| ModuloActPos | LREAL | ≥0 | Modulo actual position (calculated value in, for example, degrees) |
| ActiveControlLoopIndex | WORD | ≥0 | Active axis control loop index |
| ControlLoopIndex | WORD | ≥0 | Axis control loop index (0, 1, 2, etc. if more than one axis control loop is used) |
| ModuloActTurns | DINT | ±∞ | Modulo actual rotations |
| ActVelo | LREAL | ±∞ | Actual velocity (optional) |
| PosDiff | LREAL | ±∞ | Lag error (position) |
| SetPos | LREAL | ±∞ | Set position (calculated absolute value) |
| SetVelo | LREAL | ±∞ | Set velocity |
| SetAcc | LREAL | ±∞ | Set acceleration |
| TargetPos | LREAL | ±∞ | Estimated target position of the axis |
| ModuloSetPos | LREAL | ≥0 | Modulo set position (calculated value in, for example, degrees) |
| ModuloSetTurns | DINT | ≥0 | Modulo set rotations |
| CmdNo | WORD | ≥0 | Command number of the active axis job (see BufferMode) |
| CmdState | WORD | ≥0 | Command status information (see BufferMode) |
| SetJerk | LREAL |  | Set jerk |
| SetTorque | LREAL |  | Set torque |
| ActTorque | LREAL |  | Actual torque |
| StateDWord2 | [NCTOPLC\_AXIS\_REF\_STATE2](ms-xhelp:///?Id=beckhoff-cd8b-4016-88e6-2fb03b75e036) |  | State double word 2 |
| StateDWord3 | DWORD |  | State double word 3 |
| TouchProbeState | DWORD |  | TouchProbe status |
| TouchProbeCounter | DWORD |  | TouchProbe counter |
| CamCouplingState | ARRAY [0..7] OF [NCTOPLC\_AXIS\_REF\_CAMCOUPLINGSTATE](ms-xhelp:///?Id=beckhoff-d639-41b4-86cf-6b02fb28d121) |  | Cam coupling information for multitables (from TwinCAT 3.1.4020.0) |
| CamCouplingTableId | ARRAY [0..7] OF UINT |  | Cam coupling ID for multitables (from TwinCAT 3.1.4020.0) |
| ActTorqueDerivative | LREAL |  | First derivative of the actual torque |
| SetTorqueDerivative | LREAL |  | First derivative of the set torque |
| ActPosWithoutPosCorrection | LREAL |  | Actual position without position correction |
| ActAcc | LREAL |  | Actual acceleration |
| DcTimeStamp | UDINT |  | Current NC time stamp |

| Define | Master: Motion state / drive phase of the continuous master axis (servo) (AxisState) |
| --- | --- |
| 0 | Setpoint generator not active (INACTIVE) |
| 1 | Setpoint generator active (RUNNING) |
| 2 | Velocity override is zero (OVERRIDE\_ZERO) |
| 3 | Constant velocity (PHASE\_VELOCONST) |
| 4 | Acceleration phase (PHASE\_ACCPOS) |
| 5 | Deceleration phase (PHASE\_ACCNEG) |

| Define | Master: Motion state / drive phase of the discrete master axis (fast/creep) (AxisState) |
| --- | --- |
| 0 | Setpoint generator not active |
| 1 | Moving phase (rapid or slow traverse) |
| 2 | Switchover delay from rapid to slow traverse |
| 3 | Creep motion (within the creep region) |
| 4 | Braking time (starting from the braking distance in front of the target) |

| Define | Slave: Motion state / drive phase of the continuous slave axis (servo) (AxisState)! |
| --- | --- |
| 0 | Slave generator not active (INACTIVE) |
| 11 | Slave is in a movement pre-phase (PRE-PHASE) |
| 12 | Slave is synchronizing (SYNCHRONIZING) |
| 13 | Slave is synchronized and moves synchronously (SYNCHRON) |

| Define | Referencing state of the axis (HomingState) |
| --- | --- |
| 0 | Referencing process completed (READY) |
| 1 | Endless start in the direction of the referencing cam (note: if the cam is occupied at the start, then the process commences directly with referencing status 3) |
| 2 | Wait for rising edge of the referencing cam and initiate axis stop |
| 3 | Wait until the axis is stopped (check whether cam is still occupied) and then endless start of the referencing cam in the direction of the sync pulse |
| 4 | Wait for falling edge of the referencing cam |
| 5 | Activate latch, wait until latch has become valid and then initiate axis stop |
| 6 | If axis has stopped, then set actual position (actual position = reference position + braking distance) |

See also function block description and remarks for [MC\_Home](ms-xhelp:///?Id=beckhoff-6ee1-4cfb-b8c8-8c450b3b93d9)

| Define | Coupling state of the axis (CoupleState) |
| --- | --- |
| 0 | Single axis that is neither a master nor a slave (SINGLE) |
| 1 | Master axis with any number of slaves (MASTER) |
| 2 | Slave axis that is the master of another slave (MASTERSLAVE) |
| 3 | Just a slave axis (SLAVE) |

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
