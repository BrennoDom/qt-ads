# MC_CamRemove

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Multi cam plates](ms-xhelp:///?Id=beckhoff-dd87-41e9-b4ea-3b6ec8e607a2)
3. MC\_CamRemove

# MC\_CamRemove

![62941183](/tf5050_tc3_nc_camming/1033/Images/png/1005061259__en-US__Web.png)

*MC\_CamRemove* removes a cam from a multi-cam environment. See also [MC\_CamIn\_V2](ms-xhelp:///?Id=beckhoff-b46a-4343-a1d4-b2c35fe9a410).

**Important**:

[ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) (time and/or position from which the operation takes place)

## Inputs

```
VAR_INPUT  
   Execute            : BOOL;  
   ActivationMode     : MC_CamActivationMode := MC_CAMACTIVATION_INSTANTANEOUS;  
   ActivationPosition : LREAL;  
   CamTableID         : MC_CAM_ID;   
   Options            : ST_CamInOptions_V2;  
END_VAR
```

|  |  |
| --- | --- |
| **Execute** | The command is executed with a rising edge at input *Execute*. |
| **ActivationMode** | The [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) is used to specify the time and/or position at which the cam plate coupling or switchover is to take place.  [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) can also be specified when a slave is coupled for the first time. |
| **ActivationPosition** | Optional master position at which a cam plate is switched, depending on the [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957).  (not required for first coupling.)  If [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) *MC\_CAMACTIVATION\_ATMASTERCAMPOS* is used, the position refers to the non-scaled cam plate. If the position in the application refers to the scaled cam plate, it can be divided by the *MasterScaling* before the function block is called. |
| **CamTableID** | [ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4) of the cam plate that is removed from the coupled system. |
| **Options** | not used |

## Outputs

```
VAR_OUTPUT  
    Done           : BOOL;  
    Busy           : BOOL;   
    Active         : BOOL;   
    CommandAborted : BOOL;  
    Error          : BOOL;  
    ErrorID        : UDINT;  
END_VAR
```

|  |  |
| --- | --- |
| **Done** | Becomes TRUE if the cam plate operation was completed successfully. In operations with activation position Done only becomes TRUE after the actual deactivation. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs *InSync*, *CommandAborted* or *Error* is set. |
| **Active** | Active indicates that the command is executed *Active* becomes TRUE if the command was issued successfully but the operation is still queued. If the cam plate is activated depending on the [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957), *Active* becomes FALSE and *InSync* is set. |
| **CommandAborted** | Becomes TRUE, if the command could not be fully executed. The axis may have become decoupled during the coupling process (simultaneous command execution). |
| **Error** | Becomes TRUE, as soon as an error occurs. |
| **ErrorID** | If the error output is set, this parameter supplies the error number |

## Inputs/outputs

```
VAR_IN_OUT  
   Master : AXIS_REF;  
   Slave  : AXIS_REF;  
END_VAR
```

|  |  |
| --- | --- |
| **Master** | Master axis data structure. |
| **Slave** | Axis data structure of the Slave. |

The axis data structure of type AXIS\_REF addresses an axis uniquely within the system. Among other parameters it contains the current axis status, including position, velocity or error status.

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
