# MC_AxCtrlPressure_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Controller](ms-xhelp:///?Id=beckhoff-d178-4221-a79e-98bd3d3716b1)
5. MC\_AxCtrlPressure\_BkPlcMc (from V3.0)

# MC\_AxCtrlPressure\_BkPlcMc (from V3.0)

![10656503](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854737163__Web.gif)

The function block controls the pressure applied to an axis such that a specified default value is established and maintained in the actual value selected by **ReadingMode**.

In most cases the actual pressure can be logged with function blocks of type [MC\_AxRtReadPressureSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6b58-42dd-9f28-b93f3336f1ca) or [MC\_AxRtReadPressureDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-56dc-4d1a-b49b-0b7b2af8cf24).

```
VAR_INPUT  
    Enable:     BOOL:=FALSE;  
    Reset:      BOOL:=TRUE;  
    FirstAuxParamIdx: INT:=0;  
    kP:         LREAL:=0.0;  
    Tn:         LREAL:=0.0;  
    ReadingMode:E_TcMcPressureReadingMode:=iTcHydPressureReadingDefault;  
    PreSet:     LREAL:=0.0;  
    WindupLimit:LREAL:=0.0;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
    Error:      BOOL;  
    ErrorID:    UDINT;  
    InWindup:   UDINT;  
END_VAR
```

**Enable**: TRUE at this input activates the controller.

**Reset**: TRUE at this input resets the controller. The memory of the I component is cleared.

**FirstAuxParamIdx**: Here a range in the [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).fCustomerData can be activated as parameter interface.

**InWindup**: This output becomes TRUE if the I component is limited by **WindupLimit**.

**kP**: The gain factor of the P component.

**Tn**: The integral action time of the I component.

**ReadingMode**: The actual value to be controlled can be specified here. [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).[ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).**fActPressure** is selected as default value.

**PreSet**: Here you can specify a default value for calculating an initial value for the I component of the controller. The I component is preloaded with this value on activation.

**WindupLimit**: Here you can specify a limit value for the I component. Such a limitation prevents extreme behavior of the I component in situations where the path does not respond to controller outputs.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block:

The function block investigates the axis interface that has been passed to it every time it is called. TRUE at **Reset** puts the function block in an idle state, irrespective of the other control signals. Both the P component and the I component are then deleted. **Enable** can be used to specified whether the function block assumes the active state.

The input **ReadingMode** determines which variable is assigned the parameter to be controlled in the stAxRtData structure.

* iTcHydPressureReadingDefault, iTcHydPressureReadingActPressure: fActPressure is controlled.
* iTcHydPressureReadingActForce: fActForce is controlled.
* Any other value deactivates the controller.

|  |  |
| --- | --- |
| 28799665 | The set value has to be specified in fSetPressure in the stAxRtData structure of the axis. |

First, the function block determines whether it has to assume or quit the active state. To this end the **Enable** signal is evaluated. A rising edge causes the I component to be initialized with **PreSet**. If the output value matching [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).in fSetPressure is known, it can be utilized for reaching the compensated state more quickly. A P component is then calculated with **kP,** an I component with **Tn**. The sum of these controller components is output as control value in [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).fSetSpeed. Since this controller assumes the function of a control value generator, it cancels [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).fLagCtrlOutput. The [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) function block to be positioned after the controller function block then considers the response automatically.

The transition to the inactive state results in deletion of the controller components.

## Integration of the function block in the application

A function block of this type must be called after the actual value and actual pressure acquisition. It handles the full control of the axis and replaces any function block for control value generation that may be present.

A [program example](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) #15 is available.

|  |  |
| --- | --- |
| 57870399 | If a function block for control value generation and an MC\_AxCtrlPressure\_BkPlcMc function block are present, these function blocks should either be called alternatively, or the MC\_AxCtrlPressure\_BkPlcMc function block must follow after the control value function block, so that it overwrites the outputs of this function block. Not all generator types allow both options. |

|  |  |
| --- | --- |
| 51071544 | A value greater than 0 in FirstAuxParamIdx can be used to instruct the function block to use three consecutive values in the fCustomerData of the parameter structure as Tn, kP and PreSet. If the address of a suitable ARRAY[..] OF STRING() is entered in Axis.pStAxAuxLabels, the parameters are automatically assigned a name. |

## Commissioning

The four parameters **kP**, **Tn**, **PreSet** and **WindupLimit** enable the controller to be adapted to a range of different tasks.

Note

Control oscillations

During commissioning the axis may be subjected to the full system pressure, or damped or undamped vibrations in a wide frequency range may occur. Appropriate measures must be taken, if there is a risk for the axis or its surroundings. In any case, measures should be taken to enable fast deactivation of the controls.

Initially 0.0 should be entered for **Tn** and **Preset** and 1.0 for **WindupLimit**. The controller now operates as a pure P controller. Once a function block has started up and the controller is activated (Enable:=TRUE, Reset:=FALSE, **SetPressure**:=set value), the maximum applicable value for **kP** can be determined. Increase the value step-by-step, until an oscillation tendency becomes apparent. Use repeated deactivation and activation to check whether the controller is actually stable. In practice the value will be between around 0.1 and 0.5.

The next parameter to be set is **Tn**. Initially, a relatively large value should be specified, e.g. 0.5. The actual pressure should now be regulated to the set value with large inertia, but fairly precisely. Now determine the maximum possible setting through step-by-step reduction. Again, use repeated deactivation and activation to check whether the controller is actually stable. If there is a tendency to damped oscillation during activation, **Tn** is already set too low.

The setting of **WindupLimit** does not directly influence the behavior of the controller. Rather, this parameter is used to influence the transition behavior. If the controller is able to build up the pressure immediately because the axis does not have to travel, the value of **WindupLimit** should be chosen such that the I component is not greater than three to four times the value that is required according to valve characteristics. In this way the pressure regulation can be achieved significantly more quickly. If the axis still has some way to travel, a low value for this parameter will determine the motion of the axis until the working position is reached. If the parameter is chosen too low, the axis will move very slowly or even stop. On the other hand, a value that is too large will cause the axis to reach the working position with a rather high velocity, resulting in steep pressure increase. The resulting peak pressure can be significant.

Note

If possible, activation of a pressure controller should be avoided, unless the axis is very close to its working position.

The value for **PreSet** can be used for two procedures. If the pressure regulator should continue the control value of another function block continuously, its control value can be specified for the calculation of **PreSet**. In this way it is possible to reduce or avoid step changes in the control value during activation of the controller.

If the control value to be generated by the controller is known, a value that is close to this value can be specified as **PreSet**. In this way it is possible to reduce the time, which the I component requires to establish the control value. Since the P component is also active, a value should be set that is higher than the exact value.

|  |  |
| --- | --- |
| 56990719 | The ultimate aim when setting these parameters is to find a set of values that is appropriated for the task by making small changes and assessing the controller characteristics. |

![43154428](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1599998603__Web.gif)

Example for the behavior of the controller, if the axis first has to travel some distance before it can build up the required pressure.

![52845536](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600001035__Web.gif)

Example for the controller behavior, if the axis is able to build up the required pressure immediately.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
