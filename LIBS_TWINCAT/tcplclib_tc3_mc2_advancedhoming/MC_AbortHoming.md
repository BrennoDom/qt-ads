# MC_AbortHoming

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_AbortHoming

![36022757](/tcplclib_tc3_mc2_advancedhoming/1033/Images/png/1962424203__Web.png)

To complete a homing sequence (not when using exclusively passive homing functions) it is necessary to call a finalizing FB. The function block MC\_AbortHoming aborts a homing sequence and ensures that modified parameters are reset to their original values. The axis leaves the homing state.

## 55769358 Inputs

```
VAR_INPUT  
    Execute : BOOL;  
    Options : ST_Home_Options2;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | The command is executed with a rising edge. |
| Options | ST\_Home\_Options2 | Can be set to TRUE if not all required parameters are available on the hardware drive. |

|  |  |
| --- | --- |
| 32162181 | In this case it is the user's responsibility to ensure that the parameters required for the desired homing sequence are modified and reconstructed. |

## 21024178 Outputs

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

## 54999878/25236858 Inputs/Outputs

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
