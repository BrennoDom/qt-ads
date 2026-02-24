# MC_AxCtrlSlowDownOnPressureEx_BkPlcMc

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Controller](ms-xhelp:///?Id=beckhoff-d178-4221-a79e-98bd3d3716b1)
5. MC\_AxCtrlSlowDownOnPressureEx\_BkPlcMc

# MC\_AxCtrlSlowDownOnPressureEx\_BkPlcMc

![30494806](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9119544075__Web.gif)

The function block brakes an axis in such a way that the actual value in **Actual** does not exceed the setpoint specified in **Setpoint**.

In most cases, the actual pressure or actual force can be measured with function blocks of the type [MC\_AxRtReadPressureSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6b58-42dd-9f28-b93f3336f1ca) or [MC\_AxRtReadPressureDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-56dc-4d1a-b49b-0b7b2af8cf24) or [MC\_AxRtReadForceSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9b6c-4ec2-b19e-edaa3299193e) or [MC\_AxRtReadForceDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1946-4575-bcf0-63dbcf7a8ec1).

```
VAR_INPUT  
    Enable:           BOOL:=FALSE;  
    EnableRelief:     BOOL:=FALSE;   
    Setpoint:         LREAL;  
    Actual:           LREAL;  
    FeedVelocity:     LREAL:=0.0;  
    pParam:           POINTER TO ST_TcPctrlParam:=0;  
END_VAR
```

```
VAR_INOUT  
    Axis:             Axis_Ref_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
    Busy:             BOOL;  
    Active:           BOOL;  
    Error:            BOOL;  
    ErrorID:          UDINT;  
END_VAR
```

**Enable**: A TRUE at this input enables the controller.

**EnableRelief**: A TRUE at this input allows the controller to actively back off if necessary.

**Setpoint**: The setpoint for the actual value to be limited.

**Actual**: The current value of the variable to be limited.

**FeedVelocity**: If the object against which the pressure or force is applied is moving, its velocity can be pre-controlled here.

**pParam**: The address of a structure of the type [ST\_TcPctrlParam](ms-xhelp:///?Id=beckhoff-4ea0-4c57-bfee-17c3e3d7e778) can be transferred here. If this input is unused or if 0 is applied to it, the control parameters from the parameters of the axis are used.

**Busy**: A TRUE at this output indicates that the function block is enabled. This does not necessarily mean that it is actively intervening in the behavior of the axis.

**Active**: A TRUE at this output indicates that the function block is enabled and is actively intervening in the behavior of the axis.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block is placed in an idling state by a FALSE at **Enable** or if the axis is not enabled by the controller. **Busy**, **Active** and **Error** are then FALSE.

If **Enable** is TRUE, a series of prerequisites is checked.

* **Setpoint** must be recognizably different from 0.0.
* The axis must be distance-controlled.
* The axis must not be operated with an external setpoint generator.
* The product of **Setpoint** and kP of the controller must not fall below the creep velocity of the axis. In this case, the axis would no longer be able to move sensibly.

If one of these prerequisites is not satisfied, then **Busy** and **Active** are FALSE and **Error** is TRUE. Otherwise **Busy** is TRUE.

The sign of **Setpoint** determines the working direction of the function block. If it is positive, it intervenes when **Actual** approaches the setpoint from below in an ascending direction. **Active** is only TRUE if the function block intervenes.

The function block determines the difference between the setpoint and the actual value, taking into account the working direction, and calculates the still permissible velocity with the kP from the parameter structure used. If the target velocity exceeds this value, **Active** goes TRUE and the velocity is limited.

When the actual value reaches the setpoint, the still permissible velocity = 0.0 and the axis should come to a standstill now at the latest. If the actual value continues to increase, an opposite movement is only triggered with **EnableRelief**.

In some applications, a force or pressure must be exerted against a moving object. In this case, the control accuracy can be improved by providing the controller with a suitable pre-control at **FeedVelocity**.

## Integration of the function block in the application

A function block of this type must be called after the actual value and actual pressure acquisition, and after the control value generation. If function blocks are called for velocity or position control, they must also be placed in front of the pressure controller function block. The [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) function block to be positioned after the controller function block then considers the response automatically.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
