# MC_StepAbsoluteSwitchDetection

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_StepAbsoluteSwitchDetection

![15848707](/tcplclib_tc3_mc2_advancedhoming/1033/Images/png/1962543627__Web.png)

This function block searches for an absolutely positioned, external physical switch.

In general, an absolute switch has two "off" areas and one "on" area.

![8420641](/tcplclib_tc3_mc2_advancedhoming/1033/Images/png/9173353867__Web.png)

If the absolute switch cannot be overcrossed, then it has only one "off" area and one "on" area.

![8676909](/tcplclib_tc3_mc2_advancedhoming/1033/Images/png/9173359499__Web.png)

The "..Detection" version of this function block does not manipulate the current position of the axis at the end of the sequence, but instead returns the detected position to the user as "RecordedPosition".

## 10983320 Inputs

```
VAR_INPUT  
    Execute             : BOOL;  
    Direction           : MC_Home_Direction;  
    SwitchMode          : MC_Switch_Mode;  
    ReferenceSignal     : MC_Ref_Signal_Ref;  
    Velocity            : LREAL;  
    Acceleration        : LREAL;  
    Deceleration        : LREAL;  
    Jerk                : LREAL;  
    TimeLimit           : TIME;  
    DistanceLimit       : LREAL;  
    TorqueLimit         : LREAL;  
    PositiveLimitSwitch : BOOL;  
    NegativeLimitSwitch : BOOL;  
    BufferMode          : MC_BufferMode;  
    Options             : ST_Home_Options4;  
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
| TimeLimit | TIME | Exceeding this time leads to the search procedure being aborted. |
| DistanceLimit | LREAL | Exceeding this distance in relation to the start position leads to the search procedure being aborted. |
| TorqueLimit | LREAL | The motor torque is limited to this value in order to avoid mechanical damage. |
| PositiveLimitSwitch | BOOL | Signal of the hardware limit switch in the logically positive direction of movement (PositiveLimitSwitch = FALSE within the permissible travel range). |
| NegativeLimitSwitch | BOOL | Signal of the hardware limit switch in the logically negative direction of movement (NegativeLimitSwitch = FALSE within the permissible travel range). |
| BufferMode | MC\_BufferMode | Currently not implemented |
| Options | ST\_Home\_Options4 | **DisableDriveAccess**: Can be set to TRUE if not all required parameters are available on the hardware drive.  Note In this case it is the user's responsibility to ensure that the parameters required for the desired homing sequence are modified and reconstructed.  **EnableLagErrorDetection**: In the step functions the lag error detection is switched off in order to ensure a smooth referencing process. If it would be purposeful to keep the lag error detection active in an application, this can be achieved by setting this flag. |

## 31741019 Outputs

```
VAR_OUTPUT  
    Done             : BOOL;  
    Busy             : BOOL;  
    Active           : BOOL;  
    CommandAborted   : BOOL;  
    Error            : BOOL;  
    ErrorID          : UDINT;  
    RecordedPosition : LREAL;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Done | BOOL | Becomes TRUE, if the command was completed successfully. |
| Busy | BOOL | The Busy output becomes TRUE when the command is started with Execute and remains TRUE as long as the command is processed. When Busy becomes FALSE again, the function block is ready for a new order. At the same time one of the outputs, Done, CommandAborted or Error, is set. |
| Active | BOOL | Indicates that the command is executed. |
| CommandAborted | BOOL | Becomes TRUE, if the command could not be fully executed. |
| Error | BOOL | Becomes TRUE, as soon as an error occurs. |
| ErrorID | UDINT | If the error output is set, this parameter supplies the error number. |
| RecordedPosition | LREAL | Axis position at which the event was recorded. |

## 17233719/20885750 Inputs/Outputs

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
