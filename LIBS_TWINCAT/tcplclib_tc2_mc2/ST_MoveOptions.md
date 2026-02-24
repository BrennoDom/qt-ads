# ST_MoveOptions

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Motion](ms-xhelp:///?Id=beckhoff-2107-47ed-8b8e-b9259019655e)
4. ST\_MoveOptions

# ST\_MoveOptions

This data type contains optional settings for travel commands such as MC\_MoveAbsolute or MC\_Halt.

```
                    TYPE ST_MoveOptions :  
STRUCT  
// Command activation at defined ActivationPosition   
// Extends the buffer mode when enabled *)  
    EnableBlendingPosition : BOOL;  
    BlendingPosition : LREAL;  
      
// PositionAreaMonitoring, TargetPositionMonitoring   
// and StopMonitoring can be ignored using this flag  
     IgnorePositionMonitoring : BOOL;   
  
// PositionAreaMonitoring, TargetPositionMonitoring   
// can be enabled for MC_Stop and MC_Halt commands   
    EnableStopPositionMonitoring : BOOL;  
END_STRUCT  
END_TYPE 
```

**EnableBlendingPosition**: This flag can be activated in order to define a different blending position for a command. In the normal case, the blending position is the target of the running command. With an active MC\_MoveVelocity, no target is defined at first.

**BlendingPosition**: Blending position used with active EnableBlendingPosition flag.

**IgnorePositionMonitoring**: The target window monitor can be switched off for a single travel command with this flag. The target window monitor waits until the actual value is within a defined target window after reaching the target position. The target window monitor can be activated in the axis parameters.

**EnableStopPositionMonitoring:** MC\_Stop and MC\_Halt commands do not define a target position. However, a target window monitor can still be activated for these commands with this flag. The travel command then waits until the actual position of the axis is also within a defined window at the stopping position. The target window monitor must be activated in the axis parameters for this.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
