# MC_StepReferencePulse

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_StepReferencePulse

![11161650](/tcplclib_tc3_mc2_advancedhoming/1033/Images/png/1962555275__Web.png)

This function block performs the search for a zero pulse of an encoder.

A zero pulse is not present in all encoders and occurs only once per encoder revolution. The advantage of using a zero pulse for referencing is the high accuracy of this signal compared to that of a standard sensor.

## 33345988 Inputs

```
VAR_INPUT  
    Execute         : BOOL;  
    Direction       : MC_Home_Direction;  
    SwitchMode      : MC_Switch_Mode;  
    ReferenceSignal : MC_Ref_Signal_Ref;  
    Velocity        : LREAL;  
    Acceleration    : LREAL;  
    Deceleration    : LREAL;  
    Jerk            : LREAL;  
    SetPosition     : LREAL;  
    TimeLimit       : TIME;  
    DistanceLimit   : LREAL;  
    TorqueLimit     : LREAL;  
    BufferMode      : MC_BufferMode;  
    Options         : ST_Home_Options4;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | The command is executed with a rising edge at Execute input. |
| Direction | MC\_Home\_Direction | Enumeration that defines the initial direction of movement for the search procedure. |
| SwitchMode | MC\_Switch\_Mode | Enumeration that defines the final condition for the search procedure. |
| ReferenceSignal | MC\_Ref\_Signal\_Ref | This structure defines the source of the reference cam signal. |
| Velocity | LREAL | Maximum travel velocity (>0). |
| Acceleration | LREAL | Acceleration (≥0). If the value is 0, the standard acceleration from the axis configuration in the System Manager is used. |
| Deceleration | LREAL | Deceleration (≥0). If the value is 0, the standard deceleration from the axis configuration in the System Manager is used. |
| Jerk | LREAL | Jerk (≥0). If the value is 0, the standard jerk from the axis configuration in the System Manager is used. |
| SetPosition | LREAL | Position value to which the axis position is to be set. |
| TimeLimit | TIME | Exceeding this time leads to the search procedure being aborted. |
| DistanceLimit | LREAL | Exceeding this distance in relation to the start position leads to the search procedure being aborted. |
| TorqueLimit | LREAL | The motor torque is limited to this value in order to avoid mechanical damage. |
| BufferMode | MC\_BufferMode | Currently not implemented. |
| Options | ST\_Home\_Options4 | **DisableDriveAccess**: Can be set to TRUE if not all required parameters are available on the hardware drive.  Note In this case it is the user's responsibility to ensure that the parameters required for the desired homing sequence are modified and reconstructed.  **EnableLagErrorDetection**: In the step functions the lag error detection is switched off in order to ensure a smooth referencing process. If it would be purposeful to keep the lag error detection active in an application, this can be achieved by setting this flag. |

## 31678442 Outputs

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

## 16670523/15816986 Inputs/Outputs

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
