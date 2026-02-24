# MC_CamIn_V2

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Multi cam plates](ms-xhelp:///?Id=beckhoff-dd87-41e9-b4ea-3b6ec8e607a2)
3. MC\_CamIn\_V2

# MC\_CamIn\_V2

![178395](/tf5050_tc3_nc_camming/1033/Images/png/1005056267__en-US__Web.png)

*MC\_CamIn\_V2* is a further development of the function block [MC\_CamIn](ms-xhelp:///?Id=beckhoff-9d6c-4e6e-b012-23819a633f2e) and is able to operate with several superimposed cam plates (Multi-Cam). When MC\_CamIn\_V2 is first called it creates a master/slave coupling with the cam plate. Subsequent calls during runtime can be used to superimpose additional cam plates for the same slave axis or remove them again. The switching rules, in particular the time or position, can be specified.

*MC\_CamIn\_V2* can only be used as an alternative to *MC\_CamIn*. The two function blocks cannot be used together for the same slave axis. For addition, replacement and removal of cam plates the function blocks [MC\_CamAdd](ms-xhelp:///?Id=beckhoff-6fca-4811-bc4f-a4fc92d79f0f), [MC\_CamExchange](ms-xhelp:///?Id=beckhoff-9234-4440-a20f-48dd96cece08) and [MC\_CamRemove](ms-xhelp:///?Id=beckhoff-0c2b-4e53-8b0a-6e5fd4702091) are available as alternatives. All operations can also be carried out with *MC\_CamIn\_V2*.

The status flag Axis.Status.CamTableQueued (AXIS\_REF) can be used to check whether a cam plate is queued for addition or switchover.

**Important:**

[ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) (time and/or position from which the operation takes place)

[CamOperationMode](ms-xhelp:///?Id=beckhoff-2312-4d6a-9c65-8194b8b2e23a) (adding, switching or removal of superimposed cam plates)

[ScalingMode](ms-xhelp:///?Id=beckhoff-ec0d-401b-8d43-f6039df26ed1)

## Inputs

```
    VAR_INPUT      
   Execute            : BOOL;  
   ActivationMode     : MC_CamActivationMode := MC_CAMACTIVATION_INSTANTANEOUS;  
   ActivationPosition : LREAL;  
   CamTableID         : MC_CAM_ID;   
   Scaling            : ST_CamScalingData;  
   Options            : ST_CamInOptions_V2;  
END_VAR
```

|  |  |  |
| --- | --- | --- |
| **Execute** | The command is executed with a rising edge at input *Execute*. | |
| **ActivationMode** | The [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) is used to specify the time and/or position at which the cam plate coupling or switchover is to take place.  [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) can also be specified when a slave is coupled for the first time. | |
| **ActivationPosition** | Optional master position at which a cam plate is switched, depending on the [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957).  (not required for first coupling.)  If [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) MC\_CAMACTIVATION\_ATMASTERCAMPOS is used, the position refers to the non-scaled cam plate. If the position in the application refers to the scaled cam plate, it can be divided by the *MasterScaling* before the function block is called. | |
| **CamTableID** | [ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4) of the cam plate used for the coupling | |
| **Scaling** | Optional [scaling parameters](ms-xhelp:///?Id=beckhoff-2296-4707-bc2f-6b46959e6d52) for the cam plate | |
| **Options** | Data structure with further coupling and switching options: | |
| **Interpolation type** | [Interpolation type](ms-xhelp:///?Id=beckhoff-cf32-4289-8aa5-acbf2b9c9914) for position tables. Not required for motion functions. |
| **CamOperationMode** | The [CamOperationMode](ms-xhelp:///?Id=beckhoff-2312-4d6a-9c65-8194b8b2e23a) defines the way the specified cam plate (*CamTableID*) has to act in the coupled system. Cam plates can be added, switched or removed. |
| **ReferenceCamTableID** | Optional [ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4) of a cam plate that is already active in the coupling. This ID is specially required for operations that would otherwise be ambiguous, e.g. replacement of certain cam plates in multi-couplings. In unambiguous operations the value can remain 0. |

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
| **InSync** | Becomes TRUE if the cam plate operation was completed successfully. In operations with activation position InSync only becomes TRUE after the actual activation. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs *InSync*, *CommandAborted* or *Error* is set. |
| **Active** | Active indicates that the command is executed *Active* becomes TRUE if the command was issued successfully but the operation is still queued. If the cam plate is activated depending on the *ActivationMode*, *Active* becomes FALSE and *InSync* is set. |
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
