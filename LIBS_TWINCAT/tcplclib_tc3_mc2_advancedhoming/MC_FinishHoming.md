# MC_FinishHoming

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_FinishHoming

![53442317](/tcplclib_tc3_mc2_advancedhoming/1033/Images/png/1962418699__Web.png)

To complete a homing sequence (not when using exclusively [passive homing functions](ms-xhelp:///?Id=beckhoff-a495-4d61-9d84-bfc1898bf20d)) it is necessary to call a finalizing FB. The function block MC\_FinishHoming completes a successful homing sequence and ensures that modified parameters are reset to their original values. The axis leaves the homing state.

## 11218807 Inputs

```
VAR_INPUT  
    Execute      : BOOL;  
    Distance     : LREAL;  
    Velocity     : LREAL;  
    Acceleration : LREAL;  
    Deceleration : LREAL;  
    Jerk         : LREAL;  
    BufferMode   : MC_BufferMode;  
    Options      : ST_Home_Options2;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | The command is executed with a rising edge. |
| Distance | LREAL | Distance by which the axis moves away from the current position. |
| Velocity | LREAL | Maximum travel velocity (>0). |
| Acceleration | LREAL | Acceleration (≥0); if the value is 0, the standard acceleration from the axis configuration for the XAE TwinCAT Engineering environment is used. |
| Deceleration | LREAL | Deceleration (≥0). If the value is 0, the standard deceleration from the axis configuration for the XAE TwinCAT Engineering environment is used. |
| Jerk | LREAL | Jerk (≥0). If the value is 0, the default pressure from the axis configuration for the XAE TwinCAT Engineering environment is used. |
| BufferMode | MC\_BufferMode | Currently not implemented |
| Options | ST\_Home\_Options2 | **DisableDriveAccess**: Can be set to TRUE if not all required parameters are available on the hardware drive. |

|  |  |
| --- | --- |
| 33860402 | In this case it is the user's responsibility to ensure that the parameters required for the desired homing sequence are modified and reconstructed. |

## 36308168 Outputs

```
VAR_OUTPUT  
    Done           : BOOL;  
    Busy           : BOOL;   
    CommandAborted : BOOL;  
    Error          : BOOL;  
    ErrorID        : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Done | BOOL | Becomes TRUE, if the command was completed successfully. |
| Busy | BOOL | The Busy output becomes TRUE when the command is started with Execute and remains TRUE as long as the command is processed. If Busy becomes FALSE again, the function block is ready for a new order. At the same time one of the outputs, Done, CommandAborted or Error, is set. |
| CommandAborted | BOOL | Becomes TRUE, if the command could not be fully executed. |
| Error | BOOL | Becomes TRUE, as soon as an error occurs. |
| ErrorID | UDINT | If the error output is set, this parameter supplies the error number. |

## 58338056/55280461 Inputs/Outputs

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
