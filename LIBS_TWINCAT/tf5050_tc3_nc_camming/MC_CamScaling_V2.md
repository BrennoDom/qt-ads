# MC_CamScaling_V2

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Multi cam plates](ms-xhelp:///?Id=beckhoff-dd87-41e9-b4ea-3b6ec8e607a2)
3. MC\_CamScaling\_V2

# MC\_CamScaling\_V2

![29599739](/tf5050_tc3_nc_camming/1033/Images/png/1005062923__en-US__Web.png)

A cam plate coupling can be scaled with the function block *MC\_CamScaling\_V2*. The raw table data of the cam plate are not affected, however the scaling refers to an existing master/slave coupling. The following parameters can be modified: scaling factors for master and slave, and offsets for the cam plate within the coordinate system.

Optionally, the modification will only take effect from a certain master position, enabling precise scaling during the motion. Caution when scaling during motion. The slave position at the time of scaling should only be affected slightly by the change.

The status flag Axis.Status.CamScalingPending (AXIS\_REF) can be used to check whether a scaling procedure is queued.

## Inputs

```
VAR_INPUT  
   InSync             : BOOL;  
   Execute            : BOOL;  
   ActivationMode     : MC_CamActivationMode;  
   ActivationPosition : LREAL;  
   CamTableID         : MC_CAM_ID;  
   Scaling            : ST_CamScalingData;  
   Options            : ST_CamScalingOptions_V2;  
END_VAR
```

|  |  |
| --- | --- |
| **Execute** | The command is executed with a rising edge at input *Execute*. |
| **ActivationMode** | [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) specifies the scaling time and position. |
| **ActivationPosition** | Master position at which a cam plate is scaled, depending on the [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957).  If [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) MC\_CAMACTIVATION\_ATMASTERCAMPOS is used, the position refers to the non-scaled cam plate. If the position in the application refers to the scaled cam plate, it can be divided by the *MasterScaling* before the function block is called. |
| **CamTableID** | [ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4) of the cam plate that is scaled. |
| **Scaling** | Scaling data such as mode, offset and scaling factor |
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
| **Done** | Becomes TRUE if scaling was successful. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs, *Done*, *CommandAborted* or *Error*, is set. |
| **Active** | Active indicates that the command is executed When the scaling was done depending on [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957), *Active* becomes FALSE and *Done* is set. |
| **CommandAborted** | Becomes TRUE, if the command could not be fully executed. |
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
