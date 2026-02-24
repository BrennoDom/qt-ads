# MC_CamIn

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Cam plates](ms-xhelp:///?Id=beckhoff-a988-474a-ac58-949c3c4ab0ef)
3. MC\_CamIn

# MC\_CamIn

![59436263](/tf5050_tc3_nc_camming/1033/Images/png/1005003915__en-US__Web.png)

The function block *MC\_CamInt* activates master-slave coupling with a certain cam plate. In addition it is possible to switch to a new cam plate in coupled state. The switching rules, in particular the time or position, can be specified.

The status flag Axis.Status.CamTableQueued (AXIS\_REF) can be used to check whether a cam plate is queued for switchover.

**Important**:

[Further information on coupling with cam plates](ms-xhelp:///?Id=beckhoff-4679-491a-911a-d11a016e477d)

[ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) (coupling or switching of cam plates)

[StartMode](ms-xhelp:///?Id=beckhoff-bb4a-4816-84ef-5a1abd389b8e)

[ScalingMode](ms-xhelp:///?Id=beckhoff-ec0d-401b-8d43-f6039df26ed1)

## **Inputs**

```
VAR_INPUT  
   Execute       : BOOL;  
   MasterOffset  : LREAL;  
   SlaveOffset   : LREAL;  
   MasterScaling : LREAL := 1.0;  
   SlaveScaling  : LREAL := 1.0;  
   StartMode     : MC_StartMode;  
   CamTableID    : MC_CAM_ID;   
   BufferMode    : MC_BufferMode;   
   Options       : ST_CamInOptions;  
END_VAR
```

|  |  |  |
| --- | --- | --- |
| **Execute** | The command is executed with a rising edge at input *Execute*. | |
| **MasterOffset** | Offset to the master position of the cam plate | |
| **SlaveOffset** | Offset to the slave position of the cam plate | |
| **MasterScaling** | Scaling of the master position of the cam plate | |
| **SlaveScaling** | Scaling of the slave position of the cam plate | |
| **StartMode** | [StartMode](ms-xhelp:///?Id=beckhoff-bb4a-4816-84ef-5a1abd389b8e) determines whether the cam plate position is interpreted absolute or relative to the coupling position. *StartMode* can be relative or absolute for master (X coordinate) and slave (Y coordinate). | |
| **CamTableID** | [ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4) of the cam plate used for the coupling | |
| **BufferMode** | Currently not implemented | |
| **Options** | [Data structure](ms-xhelp:///?Id=beckhoff-bdbf-4473-ad4e-c070929e8b61) with further coupling and switching options: | |
| **ActivationMode** | The [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) is used to specify the time and/or position at which the cam plate coupling or switchover is to take place.  *ActivationMode* can also be specified when a slave is coupled for the first time. |
| **ActivationPosition** | Optional master position at which a cam plate is switched, depending on the *ActivationMode*.  (not required for first coupling.)  If *ActivationMode* MC\_CAMACTIVATION\_ATMASTERCAMPOS is used, the position refers to the non-scaled cam plate. If the position in the application refers to the scaled cam plate, it can be divided by the *MasterScaling* before the function block is called. |
| **MasterScalingMode** | optional [Scaling mode](ms-xhelp:///?Id=beckhoff-ec0d-401b-8d43-f6039df26ed1) for the master position of the cam plate |
| **SlaveScalingMode** | optional [Scaling mode](ms-xhelp:///?Id=beckhoff-ec0d-401b-8d43-f6039df26ed1) for the slave position of the cam plate |
| **Interpolation type** | [Interpolation type](ms-xhelp:///?Id=beckhoff-cf32-4289-8aa5-acbf2b9c9914) for position tables. Not required for motion functions. |

## Outputs

```
VAR_OUTPUT  
   InSync         : BOOL;  
   Busy           : BOOL;   
   Active         : BOOL;   
   CommandAborted : BOOL;  
   Error          : BOOL;  
   ErrorID        : UDINT;  
END_VAR
```

|  |  |
| --- | --- |
| **InSync** | Becomes TRUE, if the coupling was successful and the cam plate is active. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs *InSync*, *CommandAborted* or *Error* is set. |
| **Active** | Active indicates that the command is executed For cam plate switching *Active* becomes TRUE, if the coupling command was executed successfully but the cam plate is still queued. If the cam plate is activated depending on the *ActivationMode*, *Active* becomes FALSE and *InSync* is set. |
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
