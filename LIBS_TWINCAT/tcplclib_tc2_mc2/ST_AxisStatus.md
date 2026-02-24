# ST_AxisStatus

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-a949-4038-af4c-900da2b41d28)
4. ST\_AxisStatus

# ST\_AxisStatus

This data type contains extensive status information about an axis. The data structure must be updated during each PLC cycle by calling [MC\_ReadStatus](ms-xhelp:///?Id=beckhoff-49de-42bc-8e83-8798b6d84282) or by calling the action Axis.ReadStatus ([AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01)).

```
TYPE ST_AxisStatus :  
STRUCT  
    UpdateTaskIndex      : BYTE;  (* Task-Index of the task that updated this data set *)  
    UpdateCycleTime      : LREAL; (* task cycle time of the task which calls the status function *)  
    CycleCounter         : UDINT; (* PLC cycle counter when this data set updated *)  
    NcCycleCounter       : UDINT; (* NC cycle counter incremented after NC task updated NcToPlc data structures *)  
  
    MotionState          : MC_AxisStates; (* motion state in the PLCopen state diagram *)  
  
    Error                : BOOL;  (* axis error state *)  
    ErrorId              : UDINT; (* axis error code *)  
  
    (* PLCopen motion control statemachine states: *)  
    ErrorStop            : BOOL;  
    Disabled             : BOOL;  
    Stopping             : BOOL;  
    StandStill           : BOOL;  
    DiscreteMotion       : BOOL;  
    ContinuousMotion     : BOOL;   
    SynchronizedMotion   : BOOL;  
    Homing               : BOOL;  
  
    (* additional status - (PLCopen definition)*)  
    ConstantVelocity     : BOOL;   
    Accelerating         : BOOL;  
    Decelerating         : BOOL;  
  
    (* Axis.NcToPlc.StateDWord *)  
    Operational          : BOOL;   
    ControlLoopClosed    : BOOL; (* operational and position control active *)  
    HasJob               : BOOL;   
    HasBeenStopped       : BOOL;   
    NewTargetPosition    : BOOL; (* new target position commanded during move *)  
    InPositionArea       : BOOL;   
    InTargetPosition     : BOOL;   
    Protected            : BOOL;   
    Homed                : BOOL;   
    HomingBusy           : BOOL;   
    MotionCommandsLocked : BOOL; (* stop 'n hold *)  
    SoftLimitMinExceeded : BOOL; (* reverse soft travel limit exceeded *)  
    SoftLimitMaxExceeded : BOOL; (* forward soft travel limit exceeded *)  
  
    Moving               : BOOL;   
    PositiveDirection    : BOOL;   
    NegativeDirection    : BOOL;   
    NotMoving            : BOOL;   
    Compensating         : BOOL; (* superposition - overlayed motion *)  
  
    ExtSetPointGenEnabled: BOOL;   
    ExternalLatchValid   : BOOL;   
    CamDataQueued        : BOOL;   
    CamTableQueued       : BOOL;   
    CamScalingPending    : BOOL;   
    CmdBuffered          : BOOL;   
    PTPmode              : BOOL;   
    DriveDeviceError     : BOOL;   
    IoDataInvalid        : BOOL;   
  
    (* Axis.NcToPlc.CoupleState *)  
    Coupled              : BOOL;  
  
    (* axis operation mode feedback from NcToPlc *)  
    OpMode               : ST_AxisOpModes;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
