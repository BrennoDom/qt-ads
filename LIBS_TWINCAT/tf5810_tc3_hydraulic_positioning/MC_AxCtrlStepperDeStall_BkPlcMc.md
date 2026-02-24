# MC_AxCtrlStepperDeStall_BkPlcMc

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Controller](ms-xhelp:///?Id=beckhoff-d178-4221-a79e-98bd3d3716b1)
5. MC\_AxCtrlStepperDeStall\_BkPlcMc

# MC\_AxCtrlStepperDeStall\_BkPlcMc

![6017800](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854746891__Web.gif)

The function block monitors the motion of a stepper motor axis, which is operated with an encoder.

|  |  |
| --- | --- |
| 54160201 | It is essential to use a real encoder (not an encoder emulation based on pulse counting of an output terminal) in order to ensure correct function of this function block. |

|  |  |
| --- | --- |
| 17679762 | The application of such a function block can result in stalling (torque discontinuity). It therefore cannot be assumed that the velocity is constant. |

```
VAR_INPUT  
    EnableAcc:       BOOL:=FALSE;  
    EnableDec:       BOOL:=FALSE;  
    Reset:           BOOL:=FALSE;  
    UseKL2531State:  BOOL:=FALSE;  
    ResetRefOnError: BOOL:=FALSE;  
    FirstAuxParamIdx:INT:=0;  
    VeloLimit:       LREAL:=0.0;  
    LimitFilter:     LREAL:=0.0;  
    UpdateFilter:    LREAL:=0.0;  
END_VAR
```

```
VAR_INOUT  
    Axis:            Axis_Ref_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
    Active:          BOOL;  
    Activated:       BOOL;  
    Error:           BOOL;  
    ErrorID:         UDINT;  
END_VAR
```

**EnableAcc, EnableDec**: These inputs determine whether the monitoring may intervene during the acceleration and braking phases.

**Reset**: This input controls the activity of the controller.

**UseKL2531State**: If TRUE is transferred here, the function block evaluates [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d).bTerminalState.

**ResetRefOnError**: If TRUE is transferred here, the function block clears the reference flag of the axis.

**FirstAuxParamIdx**: Here a range in the [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).fCustomerData can be activated as parameter interface.

**VeloLimit**: The threshold for the velocity deviation, from which the stall situation is detected.

**LimitFilter**: The time over which an excessive velocity deviation must be present continuously for the stall situation to be detected.

**UpdateFilter**: The time constant, with which the velocity control value in the function block is adjusted to the actual velocity.

**Active**: Indicates that a stall situation was detected.

**Activated**: Indicates that a stall situation was detected since the last start of an active axis movement.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block:

During each call the function block checks whether it has to change the state. It goes in the active state if the internal motion phase permits this under the rules of **EnableAcc, EnableDec** and the velocity error continuously exceeds the value of **VeloLimit** for at least **LimitFilter**. **EnableAcc** enables the function block to intervene during phases with constant phases or phases with rising magnitude. **EnableDec** enables the activity of the function block for phases with falling magnitude or constant velocity. **Active** and **Activated** are set during the transition to the active state.

The function block changes to inactive state if the velocity error was reduced to half the value of **VeloLimit**. **Active** is cancelled during the transition to the inactive state.

In active state the control value is adjusted to the actual velocity with the time constant **UpdateFilter**. If the time constant is set to 0.0, the actual velocity is applied directly.

In inactive state **Activated** is cancelled, if the axis leaves the idle state and starts an active motion.

|  |  |
| --- | --- |
| 24900132 | Since the function block evaluates the difference between set and actual velocity, it is important to set the reference velocity correctly when this function block is used. Imprecise setting of this parameter can result in unnecessary intervention by the function block in the motion. |

The following Scope View shows a positioning, during which an obstacle was encountered twice. In each case the axis stopped completely.

![22774600](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600008331__Web.gif)

## Integration of the function block in the application

A function block of this type must be called after the actual value acquisition and control value generation. The function block superimposes its response with that of the control value generator and enters it in the [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d). The [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) function block to be positioned after the controller function block then considers the response automatically.

|  |  |
| --- | --- |
| 3644816 | A value greater than 0 in FirstAuxParamIdx can be used to instruct the function block to use three consecutive values in the fCustomerData of the parameter structure as VeloLimit, LimitFilter and UpdateFilter. If the address of a suitable ARRAY[..] OF STRING() is entered in Axis.pStAxAuxLabels, the parameters are automatically assigned a name. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
