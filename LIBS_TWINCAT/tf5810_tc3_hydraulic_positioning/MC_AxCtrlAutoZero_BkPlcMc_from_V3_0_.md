# MC_AxCtrlAutoZero_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Controller](ms-xhelp:///?Id=beckhoff-d178-4221-a79e-98bd3d3716b1)
5. MC\_AxCtrlAutoZero\_BkPlcMc (from V3.0)

# MC\_AxCtrlAutoZero\_BkPlcMc (from V3.0)

![48030711](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007203480581387__Web.gif)

The function block executes an automatic zero balance. This function block may only be used for zero overlap valves.

```
VAR_INPUT  
    Enable:         BOOL:=FALSE;  
    EnableOnMoving: BOOL:=FALSE;  
    OffsetLimit:    LREAL:=0.0;  
    Tn:             LREAL:=0.0;  
    Threshold:      LREAL:=0.1;  
    Filter:         LREAL:=0.1;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
    Error:          BOOL;  
    ErrorID:        UDINT;  
    Active:         BOOL;  
    Limiting:       BOOL;  
    Done:           BOOL;  
END_VAR
```

**Enable**: This input controls the activity of the compensation.

**EnableOnMoving**: This input controls the activity of the compensation.

**Tn**: [s] The integral action time of the compensation. This is the time for a change by 10 V. Values greater than 100 s are recommended.

**Threshold**: [V] Parameter for the **Done** signal.

**Filter**: [s] Parameter for the **Done** signal.

**OffsetLimit**: [V] The value in fZeroCompensation is limited to this value.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Active:** Indicates that the function block actively adjusts the value of fZeroCompensation in [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).

**Limiting**: Indicates that the value of fZeroCompensation in [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2) has reached the limit specified by OffsetLimit.

**Done**: Indicates leveling out of the offset compensation.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Purpose of the function block

If a hydraulic cylinder is drifting when the position controller is switched off (kP=0.0), or if there is a permanent lag error relative to the target when the position controller is active, this can be corrected by using a zero overlap valve with offset compensation.

A hydraulic cylinder stops when it is in equilibrium of forces. In the simplest case (cylinder with identical surfaces, no external forces by gravity or a process) this equilibrium is fulfilled, if the same pressure acts on both surfaces. For a differential cylinder, the pressures must be proportional to the inverse of the surfaces. Any external forces must be included. In order to achieve the required pressure conditions, a proportion of the system pressure is required as pressure difference. In the case of a zero overlap valve, this is defined by the pressure gain characteristic.

Another possible reason for an offset is a difference between the hydraulic zero point of the valve and the logical zero point of the output hardware. These are unavoidable manufacturing tolerances.

Therefore, a small valve excitation with up to ±0.5 V is required. Refer to the data sheets provided by the valve and hardware manufacturers for further information.

## Behavior of the function block: Enable logic

As long as **Enable** for the function block or the axis controller is FALSE, the function block does not become **Active**. The comparison value for monitoring the compensation is initialized and the time measurement for the **Done** message is reset.

If the enable conditions are met and the axis is not in idle state (i.e. it is in motion), the time measurement for the **Done** message is also reset.

If the enable conditions are met and the axis is in idle state, the function block 'Compensation&Timing' is processed.

Irrespective of these preconditions, the function block' Feedback' is processed.

Enable logic:

![29623216](/tf5810_tc3_hydraulic_positioning/1033/Images/png/3719092747__Web.png)

## Behavior of the function block: Compensation&Timing

A correction value is formed from the lag error and the response of the controller. The bandwidth of the possible axis controller parameterization is taken into account. A delta value (maximum change in **zero compensation** per cycle) is formed from this correction value and **Tn**. **Tn** defines a ramp time for an increase by 10 V. The delta value is limited such that this ramp slope is not exceeded. In this way an excessively fast change, during which the correction would become unstable, can be avoided. Values greater than 100 seconds are recommended.

A tolerance threshold is used for compensation. In this case **LagAmpDx** (threshold value of the I component in the position controller) is used.  
If the correction value is greater than or equal to the tolerance threshold and the actual velocity is greater than or equal to zero (i.e. the remaining correction value is not already reduced), the **Active** function block is used and the compensation is reduced in each cycle by the delta value described.  
If the correction value is less than or equal to the tolerance threshold and the actual velocity is less than or equal to zero (i.e. the remaining correction value is not already reduced), the **Active** function block is used and the compensation is reduced in each cycle by the delta value described.  
If the magnitude of the correction value is smaller than the tolerance threshold, **Active** becomes FALSE.

If the compensation differs by more than the **Threshold** from the OldValue comparison value, the time measurement is reset and the current compensation is updated as a new comparison value. Otherwise, the time measurement is increased with the cycle time. In this way, the time required to accumulate a change in compensation by at least the **Threshold** is logged.

Compensation&Timing:

![65282360](/tf5810_tc3_hydraulic_positioning/1033/Images/png/3719094667__Web.png)

## Behavior of the function block: Feedback

The compensation is limited to ±**OffsetLimit** and signaled to **Limiting**.

**Done** is reported when the function block is active and the time measurement reaches the time set in **Filter**. Example: If **Threshold** is set to 0.05 and **Filter** to 2.0, **Done** is reported if the compensation has been readjusted by less than 0.05 V within the last 2 seconds.

Feedback

![50670335](/tf5810_tc3_hydraulic_positioning/1033/Images/png/3719096587__Web.png)

|  |  |
| --- | --- |
| 53379839 | The limitation to the range specified by OffsetLimit applies even if the function block is not active. The Limiting output is updated. |

The value **OffsetLimit** and [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).**fZeroCompensation** are regarded as offset voltage. The value 10.0 therefore corresponds to full scale control. In general, a value between 0.1 and 1.0 makes sense for **OffsetLimit,** depending on the application.

## Integration of the function block in the application

In the call sequence for the function blocks of an axis, an MC\_AxCtrlAutoZero\_BkPlcMc function block should appear immediately before the [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd). If an [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344) function block is called instead of the individual function blocks, MC\_AxCtrlAutoZero\_BkPlcMc should be called before this function block.

Note

Dangerous axis movement

If situations occur during axis operation, in which the axis has a controller enable pending but does not display its normal motion behavior, the MC\_AxCtrlAutoZero\_BkPlcMc function block must be disabled. Possible causes for such a situation including function block startup with or without transition to pressure control or reduction of or switch-off of the supply. If this is not taken into account, the value of fZeroCompensation in [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2) may run in any direction until the specified limit is reached. As soon as the axis is responsive again at a later stage, a dangerous motion may be unavoidable. In this case the positioning behavior will be severely affected. If the function block is called without **EnableOnMoving,** it may no longer be able to automatically correct the shifted offset. In this case the axis will stop outside the target window and never report the motion as complete, or only after a long time.

In combination with an [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344) function block, all responses of the MC\_AxCtrlAutoZero\_BkPlcMc function block are delayed by one PLC cycle. Usually this is no problem. If this offset does cause problems, the individual function blocks for encoder etc. should be used, and the MC\_AxCtrlAutoZero\_BkPlcMc function block should be called immediately before the [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) function block.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
