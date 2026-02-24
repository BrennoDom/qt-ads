# ST_AxisStatus

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Data types](ms-xhelp:///?Id=beckhoff-6026-4a24-928a-c60b12336bae)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-6b3d-418f-93da-0bb0ed053a4a)
4. ST\_AxisStatus

# ST\_AxisStatus

This data type contains extensive status information about an axis. The data structure must be updated in each PLC cycle by calling MC\_ReadStatus or by calling the action Axis.ReadStatus() or Axis() ([AXIS\_REF](ms-xhelp:///?Id=beckhoff-1610-445d-9b44-15a5aa4e120c)).

```
TYPE ST_AxisStatus :  
STRUCT  
    AxisId               : UDINT;  
    AxisName             : STRING;  
  
    ActPos               : LREAL;  
    ModuloActPos         : LREAL;  
    ActVelo              : LREAL;  
    ActAcceleration      : LREAL;  
  
    SetPos               : LREAL;  
    ModuloSetPos         : LREAL;  
    SetVelo              : LREAL;  
    SetAcceleration      : LREAL;  
  
    PosDiff              : LREAL;  
  
    TargetPosition       : LREAL;  
    TargetVelocity       : LREAL;  
    TargetAcceleration   : LREAL;  
    TargetDeceleration   : LREAL;  
  
    InfoData1            : LREAL;  
    InfoData2            : LREAL;  
    InfoData3            : LREAL;  
  
    DigitalInput1        : BOOL;  
    DigitalInput2        : BOOL;  
  
    CmdNo                : UINT;  
    CmdState             : UINT;  
  
    MotionState          : MC_AxisStates; (* motion state in the PLCopen state diagram *)  
  
    Error                : BOOL;  (* axis error state *)  
    ErrorId              : UDINT; (* axis error code *)  
  
    (* statemachine states: *)  
    ErrorStop            : BOOL;  
    Disabled             : BOOL;  
    Stopping             : BOOL;  
    StandStill           : BOOL;  
    DiscreteMotion       : BOOL;  
    ContinuousMotion     : BOOL;   
    Homing               : BOOL;  
  
    (* additional status *)  
    ConstantVelocity     : BOOL;   
    Accelerating         : BOOL;  
    Decelerating         : BOOL;  
  
    (* Status *)  
    Operational          : BOOL;   
    ControlLoopClosed    : BOOL; (* operational and position control active *)  
    HasJob               : BOOL;   
    HasBeenStopped       : BOOL;   
    InTargetPosition     : BOOL;   
    Protected            : BOOL;   
    Homed                : BOOL;   
    HomingBusy           : BOOL;   
    MotionCommandsLocked : BOOL; (* stop 'n hold *)  
  
    Moving               : BOOL;   
    PositiveDirection    : BOOL;   
    NegativeDirection    : BOOL;   
    NotMoving            : BOOL;   
  
    PTPmode              : BOOL;   
    DriveDeviceError     : BOOL;   
    DrivePositioningError: BOOL;   
    IoDataInvalid        : BOOL;   
END_STRUCT  
END_TYPE
```

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
