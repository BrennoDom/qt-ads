# NCTOPLC_AXIS_REF

```
TYPE NCTOPLC_AXIS_REF
STRUCT
    StateDWord                    : NCTOPLC_AXIS_REF_STATE; (* Status double word *)
    ErrorCode                     : DWORD; (* Axis error code *)
    AxisState                     : DWORD; (* Axis moving status *)
    AxisModeConfirmation          : DWORD; (* Axis mode confirmation (feedback from NC) *)
    HomingState                   : DWORD; (* State of axis calibration (homing) *)
    CoupleState                   : DWORD; (* Axis coupling state *)
    SvbEntries                    : DWORD; (* SVB entries/orders (SVB = Set preparation task) *)
    SafEntries                    : DWORD; (* SAF entries/orders (SAF = Set execution task) *)
    AxisId                        : DWORD; (* Axis ID *)
    OpModeDWord                   : NCTPPLC_AXIS_REF_OPMODE; (* Current operation mode *)
    ActPos                        : LREAL; (* Actual position (absolut value from NC) *)
    ModuloActPos                  : LREAL; (* Actual modulo position *)
    ActiveControlLoopIndex        : WORD; (* Active control loop index *)
    ControlLoopIndex              : WORD; (* Axis control loop index (0, 1, 2, when multiple control loops are used) *)
    ModuloActTurns                : DINT; (* Actual modulo turns *)
    ActVelo                       : LREAL; (* Actual velocity *)
    PosDiff                       : LREAL; (* Position difference (lag distance) *)
    SetPos                        : LREAL; (* Setpoint position *)
    SetVelo                       : LREAL; (* Setpoint velocity *)
    SetAcc                        : LREAL; (* Setpoint acceleration *)
    TargetPos                     : LREAL; (* Estimated target position *)
    ModuloSetPos                  : LREAL; (* Setpoint modulo position *)
    ModuloSetTurns                : DINT; (* Setpoint modulo turns *)
    CmdNo                         : WORD; (* Continuous actual command number *)
    CmdState                      : WORD; (* Command state *)
    SetJerk                       : LREAL;
    SetTorque                     : LREAL;
    ActTorque                     : LREAL;
    StateDWord2                   : NCTOPLC_AXIS_REF_STATE2;
    StateDWord3                   : DWORD;
    TouchProbeState               : DWORD;
    TouchProbeCounter             : DWORD;
    CamCouplingState              : ARRAY [0..7] OF NCTOPLC_AXIS_REF_CAMCOUPLINGSTATE;
    CamCouplingTableID            : ARRAY [0..7] OF UINT;
    ActTorqueDerivative           : LREAL;
    SetTorqueDerivative           : LREAL;
    AbsPhasingPos                 : LREAL;
    TorqueOffset                  : LREAL;
    ActPosWithoutPosCorrection    : LREAL;
    ActAcc                        : LREAL;
    DcTimeStamp                   : UDINT;
    {attribute 'hide'}
    _reserved2                    : ARRAY [1..4] OF USINT;
    UserData                      : LREAL;
END_STRUCT
END_TYPE
```
