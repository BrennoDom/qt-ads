# MC_CamOut

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Cam plates](ms-xhelp:///?Id=beckhoff-a988-474a-ac58-949c3c4ab0ef)
3. MC\_CamOut

# MC\_CamOut

![43886731](/tf5050_tc3_nc_camming/1033/Images/png/1004948491__en-US__Web.png)

The function block *MC\_CamOut* deactivates a master-slave coupling.

Note: If a slave axis is uncoupled during the movement, it is not automatically stopped, but reaches a continuous velocity with which it will continue to travel endlessly. The axis can be stopped with a Stop command.

Note

Calling during the movement

After uncoupling, the slave axis switches to acceleration-free state and continues to move with the resulting constant speed. There is no positioning based on the master travel path calculated with the coupling factor. Instead, the behavior matches the behavior after a MC\_MoveVelocity command.

## Inputs

```
VAR_INPUT  
   Execute : BOOL;  
   Options : ST_GearOutOptions;  
END_VAR
```

|  |  |
| --- | --- |
| **Execute** | The command is executed with a rising edge at input *Execute*. |
| **Options** | Currently not implemented |

## Outputs

```
VAR_OUTPUT  
   Done    : BOOL;  
   Busy    : BOOL;  
   Error   : BOOL;  
   ErrorID : UDINT;  
END_VAR
```

|  |  |
| --- | --- |
| **Done** | Becomes TRUE, if the axis was successfully uncoupled. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs, *Done* or *Error*, is set. |
| **Error** | Becomes TRUE, as soon as an error occurs. |
| **ErrorID** | If the error output is set, this parameter supplies the error number |

## Inputs/outputs

```
VAR_IN_OUT  
   Slave : AXIS_REF;  
END_VAR
```

|  |  |
| --- | --- |
| **Slave** | Axis data structure of the Slave. |

The axis data structure of type AXIS\_REF addresses an axis uniquely within the system. Among other parameters it contains the current axis status, including position, velocity or error status.

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
