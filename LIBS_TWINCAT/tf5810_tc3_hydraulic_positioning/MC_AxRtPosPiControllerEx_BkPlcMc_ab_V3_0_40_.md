# MC_AxRtPosPiControllerEx_BkPlcMc (ab V3.0.40)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Controller](ms-xhelp:///?Id=beckhoff-d178-4221-a79e-98bd3d3716b1)
5. MC\_AxRtPosPiControllerEx\_BkPlcMc (ab V3.0.40)

# MC\_AxRtPosPiControllerEx\_BkPlcMc (ab V3.0.40)

![32803348](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9051354379__Web.gif)

The function block can be used as an alternative to the default position controller. It is called after the MC\_AxRuntime\_BkPlcMc() function block (setpoint generator and default position controller). This arrangement overwrites the responses of the default position controller.

```
VAR_INPUT  
    Reset:          BOOL:=FALSE;  
    I_Enable:       BOOL:=FALSE;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
    SetPos:         LREAL;  
    SetVelo:        LREAL;  
    Response:       LREAL;  
    InWindup:       BOOL;  
END_VAR
```

**Reset**: This input deletes all internal and external controller responses.

**I\_Enable:** This input controls the activity of the I component.

**SetPos**: [mm] The set position that becomes effective at the internal controller.

**SetVelo**: [mm/s] The set velocity that becomes effective at the internal controller.

**Response**: [mm/s] The controller response.

**InWindup**: Here, the limitation of the I component that has become active is signaled.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Purpose of the function block

The default position controller integrated in the [MC\_AxRuntime\_BkPlcMc()](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862) function block cannot meet the control requirements of some applications, due to its simple structure. The MC\_AxRtPosPiControllerEx\_BkPlcMc() function block is available for such applications. It supports the following control components:

* Position P controller
* Position I controller with threshold and Windup limit
* Position D controller (realized as velocity P controller) with attenuation time
* Condition feedback for the actual velocity
* Condition feedback for the actual acceleration
* Compensation of the static effect of the condition feedback for the actual velocity

Velocity pre-control is activated after the controller. The same applies to any activated linearizations.

|  |  |
| --- | --- |
| 26794676 | The controller is enabled with V3.0.40. The extended parameters are supported by the PlcMcManager released with this version. |

## Structure of the controller

![39825499](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/4227438731__Web.gif)

The component marked with an asterisk **\*** prepares the set value for the I component of the controller when the setpoint generator is path-controlled. This is necessary because the set position provided by the setpoint generator jumps to the target position when the braking distance is reached. With time-controlled setpoint generator, the component is transparent.

|  |  |
| --- | --- |
| 22885177 | Not shown here: TRUE on Reset, or a missing controller enable of the axis deletes both the I component and the controller output. |

The I component has a threshold value Dx, which prevents a response to small deviations. For technical reasons, this parameter is limited to at least 2/3 incremental weighting of the encoder. If the I component is to be inactive, set Ti to zero.

The implementation of the D component takes advantage of the fact that the differentiated set position is provided by the setpoint generator. An actual velocity is determined by differentiating the actual position. Under this condition, the differentiation time constant Td acts as a proportionality factor. If the D component is to be inactive, set the time constant Td to zero.

Three branches are implemented in the condition feedback:

* Velocity activation: The actual velocity is filtered and activated with a weighting factor. As it is subtracted, it has an attenuating effect. If the connection is to be inactive, set KCfb\_V to zero.
* Acceleration activation: The actual velocity is differentiated, filtered and activated with a weighting factor. As it is subtracted, it has an attenuating effect. If the connection is to be inactive, set KCfb\_A to zero.
* A velocity activation generates a statically effective reduction of the velocity pre-control. In the case of path-controlled positioning, this generates a noticeable velocity deviation. With time-controlled positioning, this effect is compensated, as far as possible, by the continuously active position control. This undesirable side-effect of velocity feedback is eliminated by automatic adjustment of the pre-control. Deactivating the velocity activation also deactivates this compensation.

Velocity pre-control is activated after the controller. The weighting is fixed at 1.0 when the setpoint generator is path-controlled and cannot be reduced.

If linearization is activated, it takes place after the controller and is not shown here.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
