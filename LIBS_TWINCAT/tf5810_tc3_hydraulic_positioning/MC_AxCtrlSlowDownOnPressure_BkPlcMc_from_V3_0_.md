# MC_AxCtrlSlowDownOnPressure_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Controller](ms-xhelp:///?Id=beckhoff-d178-4221-a79e-98bd3d3716b1)
5. MC\_AxCtrlSlowDownOnPressure\_BkPlcMc (from V3.0)

# MC\_AxCtrlSlowDownOnPressure\_BkPlcMc (from V3.0)

![3908185](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854744459__Web.gif)

The function block decelerates an axis such that a certain default value is not exceeded in the actual value selected through **ReadingMode**. The rules of substitutional pressure control apply.

In most cases the actual pressure can be logged with function blocks of type [MC\_AxRtReadPressureSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6b58-42dd-9f28-b93f3336f1ca) or [MC\_AxRtReadPressureDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-56dc-4d1a-b49b-0b7b2af8cf24).

```
VAR_INPUT  
    EnableP:          BOOL:=FALSE;  
    EnableM:          BOOL:=FALSE;  
    Reset:            BOOL:=TRUE;  
    FirstAuxParamIdx: INT:=0.0;  
    kP:               LREAL:=0.0;  
    Tn:               LREAL:=0.0;  
    PreSet:           LREAL:=0.0;  
    ReadingMode:      E_TcMcPressureReadingMode:=iTcHydPressureReadingDefault;  
END_VAR
```

[E\_TcMcPressureReadingMode](ms-xhelp:///?Id=beckhoff-0fab-4419-8171-b0d510ff6e3f)

```
VAR_INOUT  
    Axis:             Axis_Ref_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
    Response:         LREAL;  
    Active:           BOOL;  
    Error:            BOOL;  
    ErrorID:          UDINT;  
END_VAR
```

**EnableP**: TRUE at this input enables the controller to influence the output value during a motion in positive direction.

**EnableM**: TRUE at this input enables the controller to influence the output value during a motion in negative direction.

**Reset**: TRUE at this input resets the controller. The memory of the I component is cleared.

**FirstAuxParamIdx**: Here a range in the [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).fCustomerData can be activated as parameter interface.

**kP**: The gain factor of the P component.

**Tn**: The integral action time of the I component.

**PreSet**: Here you can specify a default value for calculating an initial value for the I component of the controller. The I component is preloaded with this value on activation.

**Response**: The output value of a pressure regulator.

**ReadingMode**: The actual value to be controlled can be specified here. [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).[ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).**fActPressure** is selected as default value.

**Active**: TRUE at this output indicates that the function block generates a response in order to take over the pressure control.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block:

TRUE at **Reset** puts the function block in an idle state, irrespective of the other control signals. **Active** is then FALSE and **Response** := 0.0, since both the P component and the I component are deleted.

The input **ReadingMode** determines which variable is assigned the parameter to be controlled in the stAxRtData structure.

* iTcHydPressureReadingDefault, iTcHydPressureReadingActPressure: fActPressure is controlled.
* iTcHydPressureReadingActForce: fActForce is controlled.
* Any other value deactivates the controller.

|  |  |
| --- | --- |
| 35173667 | The set value has to be specified in fSetPressure in the stAxRtData structure of the axis. |

During active operation the behavior of the function block is determined by the inputs **EnableP** and **EnableM**. They determine whether the function block should intervene in positive or negative direction during a motion. Note that the function block is tasked to counteract an active travelling motion. **EnableP** should therefore be set if travelling motion in positive direction should not exceed a specified pressure. In opposite direction of travel **EnableM** enables a pressure-limiting controller response in positive direction.

First, the function block determines whether it has to assume or quit the active state. To this end the signals **EnableP**, **EnableM**, the sign of [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).fSetSpeed and the difference between **SetPressure** and the selected actual value are evaluated.

During transition to the active state the I component is initialized with **PreSet**. It is loaded with a starting value, which in combination with [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).fSetSpeed results in the value of **PreSet**. If the output value matching **fSetPressure** is known, it can be utilized for reaching the compensated state more quickly. In practice, the choice of this parameter should be made dependent on the behavior of the controlled system. This is mainly influenced by the flexibility of the pressed in object, but also by the selected velocity. If the increase is rather slow compared with the **Tn** used, the current control value from [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).fSetSpeed should be used as preset value. If the actual pressure responds with a rapid increase, it is advisable to use a value, which takes into account the set pressure and the pressure amplification of the valve.

A P component is then calculated with **kP,** an I component with **Tn**. The sum of these controller components is output as **Response,** and the state of the controller is indicated as TRUE at **Active**.

The transition to the inactive state results in deletion of the controller components and is indicated with FALSE at **Active**.

## Integration of the function block in the application

A function block of this type must be called after the actual value and actual pressure acquisition, and after the control value generation. If function blocks are called for velocity or position control, these must also be positioned before the pressure regulator function block, or the responses of the controllers should be coordinated with due diligence.

Although the pressure regulator calculates a response, it is not entered in the [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d) structure. This is done by the application, depending on **Active** and taking into account signals of other controllers. Usually, **Response** is assigned to the variable [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).fLagCtrlOutput. The [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) function block to be positioned after the controller function block then considers the response automatically.

|  |  |
| --- | --- |
| 48127554 | A value greater than 0 in FirstAuxParamIdx can be used to instruct the function block to use three consecutive values in the fCustomerData of the parameter structure as Tn, kP and PreSet. If the address of a suitable ARRAY[..] OF STRING() is entered in Axis.pStAxAuxLabels, the parameters are automatically assigned a name. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
