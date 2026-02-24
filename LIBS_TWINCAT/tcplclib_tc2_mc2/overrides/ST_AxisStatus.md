# ST_AxisStatus

```
TYPE ST_AxisStatus :
STRUCT
    UpdateTaskIndex       : BYTE;
    UpdateCycleTime       : LREAL;
    CycleCounter          : UDINT;
    NcCycleCounter        : UDINT;

    MotionState           : MC_AxisStates;

    Error                 : BOOL;
    ErrorId               : UDINT;

    ErrorStop             : BOOL;
    Disabled              : BOOL;
    Stopping              : BOOL;
    StandStill            : BOOL;
    DiscreteMotion        : BOOL;
    ContinuousMotion      : BOOL;
    SynchronizedMotion    : BOOL;
    Homing                : BOOL;

    ConstantVelocity      : BOOL;
    Accelerating          : BOOL;
    Decelerating          : BOOL;

    Operational           : BOOL;
    ControlLoopClosed     : BOOL;
    HasJob                : BOOL;
    HasBeenStopped        : BOOL;
    NewTargetPosition     : BOOL;
    InPositionArea        : BOOL;
    InTargetPosition      : BOOL;
    ProtectedMode         : BOOL;
    Homed                 : BOOL;
    HomingBusy            : BOOL;
    MotionCommandsLocked  : BOOL;
    SoftLimitMinExceeded  : BOOL;
    SoftLimitMaxExceeded  : BOOL;

    Moving                : BOOL;
    PositiveDirection     : BOOL;
    NegativeDirection     : BOOL;
    NotMoving             : BOOL;
    Compensating          : BOOL;

    ExtSetPointGenEnabled    : BOOL;
    PhasingActive            : BOOL;
    ExternalLatchValid       : BOOL;
    CamDataQueued            : BOOL;
    CamTableQueued           : BOOL;
    CamScalingPending        : BOOL;
    CmdBuffered              : BOOL;
    PTPmode                  : BOOL;
    DriveDeviceError         : BOOL;
    IoDataInvalid            : BOOL;
    ErrorPropagationDelayed  : BOOL;
    DriveLimitActive         : BOOL;
    TargetTorqueReached      : BOOL;

    Coupled               : BOOL;

    OpMode                : ST_AxisOpModes;
    NcApplicationRequest  : BOOL;
END_STRUCT
END_TYPE
```