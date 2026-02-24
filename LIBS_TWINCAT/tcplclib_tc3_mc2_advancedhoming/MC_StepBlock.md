# MC_StepBlock

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_StepBlock

![53754023](/tcplclib_tc3_mc2_advancedhoming/1033/Images/png/1962545291__Web.png)

This function block performs the search for a physical object that mechanically blocks the movement.

To avoid mechanical damage, the movement is usually performed with reduced torque ("TorqueLimit"). Since the actual value is subject to fluctuations, a tolerance must also be specified ("TorqueTolerance").

The condition for successful completion of the sequence consists of two parts.

Firstly, the torque within the specified "TorqueTolerance" must correspond to the "TorqueLimit" and secondly, the actual velocity for the time "DetectionVelocityTime" must be below the "DetectionVelocityLimit".

## 14024165 Inputs

```
VAR_INPUT  
    Execute                : BOOL;  
    Direction              : MC_Home_Direction;  
    Velocity               : LREAL;  
    Acceleration           : LREAL;  
    Deceleration           : LREAL;  
    Jerk                   : LREAL;  
    SetPosition            : LREAL;  
    DetectionVelocityLimit : LREAL;  
    DetectionVelocityTime  : TIME;  
    TimeLimit              : TIME;  
    DistanceLimit          : LREAL;  
    TorqueLimit            : LREAL;  
    TorqueTolerance        : LREAL;  
    BufferMode             : MC_BufferMode;  
    Options                : ST_Home_Options3;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | The command is executed with a rising edge at Execute input. |
| Direction | MC\_Home\_Direction | Enumeration that defines the initial direction of movement for the search procedure. |
| Velocity | LREAL | Maximum travel velocity (>0). |
| Acceleration | LREAL | Acceleration (≥0). If the value is 0, the standard acceleration from the axis configuration in the System Manager is used. |
| Deceleration | LREAL | Deceleration (≥0). If the value is 0, the standard deceleration from the axis configuration in the System Manager is used. |
| Jerk | LREAL | Jerk (≥0). If the value is 0, the standard jerk from the axis configuration in the System Manager is used. |
| SetPosition | LREAL | Position value to which the axis position is to be set. |
| DetectionVelocityLimit | LREAL | Velocity that must be fallen below for the time DetectionVelocityTime in order to detect driving against the fixed stop. |
| DetectionVelocityTime | TIME | Time for detecting the velocity undershoot when driving against the fixed stop. |
| TimeLimit | TIME | Exceeding this time leads to the search procedure being aborted. |
| DistanceLimit | LREAL | Exceeding this distance in relation to the start position leads to the search procedure being aborted. |
| TorqueLimit | LREAL | The motor torque is limited to this value, in relation to the weight counterbalance that is possibly parameterized in the drive, in order to avoid mechanical damage. |
| TorqueTolerance | LREAL | Tolerance related to the TorqueLimit within which driving against the fixed stop is detected. |
| BufferMode | MC\_BufferMode | Currently not implemented. |
| Options | ST\_Home\_Options3 | **DisableDriveAccess**: Can be set to TRUE if not all required parameters are available on the hardware drive.  Note In this case it is the user's responsibility to ensure that the parameters required for the desired homing sequence are modified and reconstructed.  **InstantLagReduction:** When referencing to a mechanical fixed stop, the sudden stop produces a position lag in the NC axis, which is dissipated with the parameterized dynamic values in the further course. This can lead to an assumed delay when observing the sequence, but it is purposeful in particular with "soft" fixed stops. The position lag is dissipated abruptly by setting this flag. |

## 59108624 Outputs

```
VAR_OUTPUT  
    Done           : BOOL;  
    Busy           : BOOL;  
    Active         : BOOL;  
    CommandAborted : BOOL;  
    Error          : BOOL;  
    ErrorID        : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Done | BOOL | Becomes TRUE, if the command was completed successfully. |
| Busy | BOOL | The Busy output becomes TRUE when the command is started with Execute and remains TRUE as long as the command is processed. If Busy becomes FALSE again, the function block is ready for a new order. At the same time one of the outputs, Done, CommandAborted or Error, is set. |
| Active | BOOL | Indicates that the command is executed. |
| CommandAborted | BOOL | Becomes TRUE, if the command could not be fully executed. |
| Error | BOOL | Becomes TRUE, as soon as an error occurs. |
| ErrorID | UDINT | If the error output is set, this parameter supplies the error number. |

## 62215569/23069209 Inputs/Outputs

```
VAR_IN_OUT  
    Axis      : AXIS_REF;  
    Parameter : MC_HomingParameter;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Axis | AXIS\_REF | Axis data structure of the type AXIS\_REF, which uniquely addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. |
| Parameter | MC\_HomingParameter | Data structure of the type [MC\_HomingParameter](ms-xhelp:///?Id=beckhoff-1843-4b08-be18-15a550a77714), which must be transferred from function block to function block over the entire homing sequence. |
