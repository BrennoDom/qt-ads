# MC_SetCamOnlineChangeMode

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Motion functions](ms-xhelp:///?Id=beckhoff-78ed-4874-867e-fcf1d97d2c04)
3. MC\_SetCamOnlineChangeMode

# MC\_SetCamOnlineChangeMode

![51789668](/tf5050_tc3_nc_camming/1033/Images/png/1005346059__en-US__Web.png)

The function block *MC\_SetCamOnlineChangeMode* specifies the mode for write access to cam plate data.

Cam plate can be modified at run time via the PLC (see [MC\_WriteMotionFunction](ms-xhelp:///?Id=beckhoff-f4cf-455a-9065-f89bcc2425b4), [MC\_WriteMotionFunctionPoint](ms-xhelp:///?Id=beckhoff-7a01-4003-99d3-69e74c0ccf29)). The function block *MC\_SetCamOnlineChangeMode* is used to specify when and how these changes take effect. The set mode affects all subsequent write operations. It is therefore not necessary to call the block before each write access.

This function specifies the activation mode for modifications but does not affect a change or changeover of cam plates.

## Inputs

```
VAR_INPUT  
   Execute            : BOOL;  
   ActivationMode     : MC_CamActivationMode;  
   ActivationPosition : LREAL;  
   MasterScalingMode  : MC_CamScalingMode;  
   SlaveScalingMode   : MC_CamScalingMode;  
   CamTableID         : MC_CAM_ID;  
END_VAR
```

|  |  |
| --- | --- |
| **Execute** | The command is executed with rising edge. |
| **ActivationMode** | Defines when and how scaling takes place. ([MC\_CamActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957)) |
| **ActivationPosition** | Optional master position at which scaling is carried out (depending on [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957)).  If [ActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) MC\_CAMACTIVATION\_ATMASTERCAMPOS is used, the position refers to the non-scaled cam plate. If the position in the application refers to the scaled cam plate, it can be divided by the *MasterScaling* before the function block is called. |
| **MasterScalingMode** | Type of master scaling. ([MC\_CamScalingMode](ms-xhelp:///?Id=beckhoff-ec0d-401b-8d43-f6039df26ed1)) |
| **SlaveScalingMode** | Type of slave scaling. ([MC\_CamScalingMode](ms-xhelp:///?Id=beckhoff-ec0d-401b-8d43-f6039df26ed1)) |
| **CamTableID** | [Table ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4). |

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
| **Done** | Becomes TRUE when the function has been successfully executed. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs, *Done* or *Error*, is set. |
| **Error** | Becomes TRUE, as soon as an error occurs. |
| **ErrorID** | If the error output is set, this parameter supplies the error number |

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
