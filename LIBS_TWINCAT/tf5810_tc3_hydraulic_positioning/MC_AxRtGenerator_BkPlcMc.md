# MC_AxRtGenerator_BkPlcMc

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Generators](ms-xhelp:///?Id=beckhoff-66c6-4303-a7eb-fcc945e5c3af)
5. MC\_AxRtGenerator\_BkPlcMc

# MC\_AxRtGenerator\_BkPlcMc

![13722030](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9041952011__Web.gif)

This function block performs the task of a setpoint generator. To this end a profile-specific function block is called, depending on the value set as nProfileType in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).

```
VAR_OUTPUT  
    Error:      BOOL;  
    ErrorID:    UDINT;  
    LagError:   BOOL;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**LagError**: If the lag error violates the set limits, this is indicated here. This signal is also available if position lag monitoring is not activated.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block investigates the axis interface that has been passed to it every time it is called. A number of problems can be detected and reported during this process:

* If one of the pointers has not been initialized the function block reacts with **Error** and with **ErrorID**:=dwTcHydErrCdPtrPlcMc or dwTcHydErrCdPtrMcPlc.

If it is possible to carry out these checks without encountering any problems, the setpoint generation is executed by calling an appropriate function block corresponding to the nProfileType in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).

The **LagError** output indicates whether the current lag error of the axis exceeds the set limits. The axis is only set to an error state if bMaxLagEna is set in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).

The following generators are presently available:

| nProfileType | Description |
| --- | --- |
| [iTcMc\_ProfileCtrlBased](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862) | **Standard profile**: Single-stage time-referenced acceleration, displacement-referenced (square root) braking ramp, target approach at creep velocity, selectable behavior when stationary.  An axis in motion can be restarted at any time (new target, new velocity etc.), except in error state or in a state with dependent control value generation.  **Info:** Overshooting the new target can happen even if the axis is in front of the target position at the time of the start.  **Info:** The function block can be parameterized such that it starts automatically and assumes an active motion state under certain conditions, which are defined through its parameters.  **Info:** This generator type can optionally operate in purely time-controlled mode with continuously closed position controller. |
| iTcMc\_ProfileJerkBased | **Standard profile**: Single- or two-stage time-controlled acceleration through optional jerk limitation, displacement-controlled (square root generator) braking ramp, target approach with jerk limitation, selectable behavior in idle state.  An axis in motion can be restarted at any time (new target, new velocity etc.), except in error state or in a state with dependent control value generation.  **Info:** Overshooting the new target can happen even if the axis is in front of the target position at the time of the start.  **Info:** The function block can be parameterized such that it starts automatically and assumes an active motion state under certain conditions, which are defined through its parameters.  **Info:** This generator type can optionally operate in purely time-controlled mode with continuously closed position controller.  **Info:** Some functions are not supported by this generator type, or not fully. |
| iTcMc\_ProfileTimePosCtrl | **Info:** Only present for compatibility reasons; will shortly no longer be supported.  **Special profile**: Two stage acceleration (initially time-referenced, then displacement-referenced following square root curve), displacement-referenced (square root) braking ramp, target approach at creep velocity, selectable behavior when stationary.  It is not possible to execute a start for an axis that is already travelling (new target, new velocity etc.). |
| iTcMc\_ProfileCosine | **Info:** Only present for compatibility reasons; will shortly no longer be supported.  **Special profile**: Two stage acceleration (initially time-referenced, then displacement-referenced following cosine curve), displacement-referenced (cosine) braking ramp, target approach at creep velocity, selectable behavior when stationary.  It is not possible to execute a start for an axis that is already travelling (new target, new velocity etc.). |
| [iTcMc\_ProfileTimeRamp](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862) | **Special profile**: Single-stage time-controlled acceleration, time-controlled braking ramp, target approach with creep speed, conditionally selectable behavior in idle state. The generator uses position cams instead of an encoder.  An axis in motion can be restarted (new target, new velocity etc.), except in error state.  **Info:** This generator type is intended for axes, which only have digital cams instead of an encoder. |

If only the usual function blocks (encoder, generator, finish, drive) for the axis are to be called, a function block of type [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344) should be used for simplicity.

## iTcMc\_ProfileCtrlBased

A profile is generated with a time-controlled acceleration phase, a displacement-controlled braking phase based on the square root generator principle, and a target approach with creep speed.

![56389407](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600044811__Web.gif)

The arrows on the profile of the control value suggest how the shape of the curve can be affected through the parameters of the move order or of the axis. To begin with, a time-controlled ramp function "1" is used to accelerate to the required travel velocity "2". This control value is maintained until a point is reached that was recalculated at the start. After this point, a displacement-referenced ramp "3" is followed to brake down from the main travel velocity to the creep velocity "5"; this control value is reached at a specified distance, "4", from the target. This control value is retained until the target has been approached to within a specified remaining distance "6". The axis is then switched to its idle behavior.

## Parameters active in the travel profile

**Start ramp "1":** The smallest of the following values is the effective one: **fMaxAcc** and **fAcc** in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2)**, Acceleration** of the function block used to start the axis (for example: [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db)).

**Travel phase "2":** The smallest of the following values is the effective one: **fRefVelo** and **fMaxVelo** in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2), **Velocity** of the function block used to start the axis (for example: [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db)).

**Braking ramp "3":** The smallest of the following values is the effective one: **fMaxDec** and **fDec** in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2)**, Deceleration** of the function block used to start the axis (for example: [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db)).

**Creep phase "4", "5":** The values of **fCreepSpeed** and **fCreepDistance** in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2) have an effect.

**Transfer to target "6":** The **fBrakeDistance** and/or **fBrakeDeadTime** in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2) have an effect.

## Automatic starting of the axis

If the difference between the actual position and the current target position exceeds the value in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).fReposDistance, an automatic start is triggered.

## **iTcMc\_ProfileJerkBased**

A profile is generated with a time-controlled acceleration phase (with optional jerk limitation), a displacement-controlled braking ramp based on the square root generator principle, and a target approach with jerk limitation.

![37742617](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600047243__Web.gif)

The arrows on the profile of the control value suggest how the shape of the curve can be affected through the parameters of the move order or of the axis. To begin with, a time-controlled ramp function "1" is used to accelerate to the required travel velocity "2". The optional jerk limitation "6" can take effect. The travel speed is maintained until a point is reached that was recalculated at the start. At this point a displacement-controlled braking ramp "3" is applied, until the distance to the target has reduced to the residual distance. The deceleration "4" is reduced with limited jerk "5" towards the target. The axis is then switched to its idle behavior.

## Parameters active in the travel profile

**Start ramp "1":** The smallest of the following values is the effective one: **fMaxAcc** and **fAcc** in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2)**, Acceleration** of the function block used to start the axis (for example: [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db)).

**Travel phase "2":** The smallest of the following values is the effective one: **fRefVelo** and **fMaxVelo** in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2), **Velocity** of the function block used to start the axis (for example: [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db)).

**Braking ramp "3", "4":** The smallest of the following values is the effective one: **fMaxDec** and **fDec** in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2)**, Deceleration** of the function block used to start the axis (for example: [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db)).

**Transfer to target "5":** **fMaxJerk** in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2) and **fJerk** of the function block used on axis start take effect (example: [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db)) and **fBrakeDistance** and/or **fBrakeDeadTime** in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).

## iTcMc\_ProfileTimePosCtrl

|  |  |
| --- | --- |
| 4139237 | Only present for compatibility reasons; will shortly no longer be supported. It should not be used for new projects and should be replaced when existing projects are revised, if possible. |

## iTcMc\_ProfileCosine

|  |  |
| --- | --- |
| 37253141 | Only present for compatibility reasons; will shortly no longer be supported. It should not be used for new projects and should be replaced when existing projects are revised, if possible. |

## iTcMc\_ProfileTimeRamp

A profile is generated with a time-controlled acceleration phase, a time-controlled braking phase and a target approach with creep speed.

![66842817](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600049675__Web.gif)

The arrows on the profile of the control value suggest how the shape of the curve can be affected through the parameters of the move order or of the axis. To begin with, a time-controlled ramp function "1" is used to accelerate to the required travel velocity "2". This control value is maintained until the direction-specific target window cam is detected. From here, a time-controlled ramp "3" is applied to decelerate from the set motion value to the set creep value "5". This control value is maintained until the direction-specific target cam is detected. The axis is then switched to its idle behavior.

## Parameters active in the travel profile

**Start ramp "1":** **fStartRamp** has an effect in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).

**Travel phase "2":** The smallest of the following values is the effective one: **fRefVelo** and **fMaxVelo** in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2), **Velocity** of the function block used to start the axis (for example: [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db)).

**Braking ramp "3":** **fStopRamp** has an effect in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).

**Creep phase "4":** **fCreepSpeed** has an effect in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).

## Behavior of the function block on restart during a motion

If a further start command is issued during an active movement, a distinction has to be made between two cases.

![64714441](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600052107__Web.gif)

This profile is created on restart in the same direction with a different velocity (higher in this case).

![45559064](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600054539__Web.gif)

This profile is created on restart in the opposite direction, in this case with the same velocity.

This profile type can only be used in a meaningful manner in combination with the encoder type [iTcMc\_EncoderDigCam](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191). See also Special case: digital position cams.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
