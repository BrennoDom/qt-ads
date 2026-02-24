# ST_TcHydAxParam (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcHydAxParam (from V3.0)

# ST\_TcHydAxParam (from V3.0)

This structure contains all axis parameters. Under Setup (partly in preparation), suitable procedures for axis commissioning are presented.

|  |  |
| --- | --- |
| 50226059 | The order of the parameters is not guaranteed. |

```
            TYPE ST_TcHydAxParam :  
(* last modification: 08.07.2020 *)  
STRUCT  
    (* ==================================================================  
    this section isn't saved / dieser Bereich wird nicht gesichert  
    ================================================================== *)  
    sParamFileName:            STRING(255) := 'DefAxParmFile.dat';  
    (* ==================================================================  
    from this point all parameters are saved /  
 von hier an werden alle Parameter gesichert  
    ================================================================== *)  
    fAcc:                         LREAL := 2000.0;  
    fAreaRatio:                   LREAL := 1.0;  
    fBrakeDeadTimeM:              LREAL := 0.0;  
    fBrakeDeadTimeP:              LREAL := 0.0;  
    fBrakeDistanceM:              LREAL := 0.1;  
    fBrakeDistanceP:              LREAL := 0.1;  
    fBrakeOffDelay:               LREAL := 0.0;  
    fBrakeOnDelay:                LREAL := 0.0;  
    fBrakeSafetyDelay:            LREAL := 0.0;  
    fCreepDistanceM:              LREAL := 1.0;  
    fCreepDistanceP:              LREAL := 1.0;  
    fCreepSpeedM:                 LREAL := 80.0;  
    fCreepSpeedP:                 LREAL := 80.0;  
    fCustomerData:                ARRAY [1..iTcHydfCustDataMaxIdx] OF LREAL;  
    fCycletime:                   LREAL := 0.010;  
    fCylinder_ArreaA:             LREAL := 1.0;  
    fCylinder_ArreaB:             LREAL := 1.0;  
    fCylinder_Mass:               LREAL := 1.0;  
    fCylinder_Stroke:             LREAL := 1.0;  
    fDec:                         LREAL := 2000.0;  
    fDrive_IncInterpolation:      LREAL := 1.0;  
    fDrive_IncWeighting:          LREAL := 0.001;  
    fEmergencyRamp:               LREAL := 0.1;  
    fEnc_BaseDistance:            LREAL := 0.001;  
    fEnc_DefaultHomePosition:     LREAL := 0.0;  
    fEnc_IncInterpolation:        LREAL := 1.0;  
    fEnc_IncWeighting:            LREAL := 0.001;  
    fEnc_ModuloBase:              LREAL := 0.001;  
    fEnc_PotiRgToRl:              LREAL := 0.0;  
    fEnc_RefIndexVelo:            LREAL := 0.1;  
    fEnc_RefSyncVelo:             LREAL := 0.1;  
    fEnc_ZeroShift:               LREAL := 0.0;  
    fJogVeloFast:                 LREAL := 100.0;  
    fJogVeloSlow:                 LREAL := 25.0;  
    fFeedForward:                 LREAL := 1.0;  
    fAccFeedForward:              LREAL := 0.0;   
    fLagAmp:                      LREAL := 0.05;  
    fLagAmpDp:                    LREAL := 0.0;  
    fLagAmpDx:                    LREAL := 0.0;  
    fLagAmpTi:                    LREAL := 0.0;  
    fLagAmpOutL:                  LREAL := 0.0;  
    fLagAmpWuL:                   LREAL := 0.0;  
    fLagAmpTd:                    LREAL := 0.0;  
    fLagAmpTdd:                   LREAL := 0.0;  
    fLagAmpCfb_kV:                LREAL := 0.0;  
    fLagAmpCfb_tV:                LREAL := 0.0;  
    fLagAmpCfb_kA:                LREAL := 0.0;  
    fLagAmpCfb_tA:                LREAL := 0.0;  
    fLagAmpCfb_kF:                LREAL := 0.0;  
    fLagAmpCfb_tF:                LREAL := 0.0;  
    fMaxAcc:                      LREAL := 500.0;  
    fMaxDec:                      LREAL := 500.0;  
    fMaxDynamicLag:               LREAL := 0.0;  
    fMaxJerk:                     LREAL := 1000.0;  
    fMaxLag:                      LREAL := 0.0;  
    fMaxLagFilter:                LREAL := 0.0;  
    fMaxVelo:                     LREAL := 500.0;  
    fMonPositionRange:            LREAL := 1.0;  
    fMonTargetFilter:             LREAL := 1.0;  
    fMonTargetRange:              LREAL := 1.0;  
    fPEH_Timeout:                 LREAL := 0.0;  
    fRefVelo:                     LREAL := 500.0;  
    fReposDistance:               LREAL := 0.0;  
    fSoftEndMax:                  LREAL := 10000.0;  
    fSoftEndMin:                  LREAL := 0.0;  
    fStartAccDistance:            LREAL := 1.0;  
    fStartRamp:                   LREAL := 1.0;  
    fStopRamp:                    LREAL := 1.0;  
    fTargetClamping:              LREAL := 0.0;  
    fVeloAmp:                     LREAL := 0.0;  
    fVeloAmpDx:                   LREAL := 0.0;  
    fVeloAmpTi:                   LREAL := 0.0;  
    fVeloAmpOutL:                 LREAL := 0.0;  
    fVeloAmpWuL:                  LREAL := 0.0;  
    fValve_BendPointOutput:       LREAL := 0.0;  
    fValve_BendPointVelo:         LREAL := 0.0;  
    fValve_OverlapCompM:          LREAL := 0.0;  
    fValve_OverlapCompP:          LREAL := 0.0;  
    fValve_ResponseTime:          LREAL := 0.0;  
    fZeroCompensation:            LREAL := 0.0;  
  
    nEnc_OverrunMask:             DWORD := 0;  
    nEnc_PositionMask:            DWORD := 0;  
    nEnc_ZeroSwap:                DINT := 0;  
    nDigInReversed:               DINT := 0;   
  
    nCycleDivider:                INT := 1;  
    nDrive_Type:                  E_TcMcDriveType:=iTcMc_Drive_Customized;  
    nEnc_HomingType:              E_TcMcHomingType:=iTcMc_HomingOnBlock;  
    nEnc_Type:                    E_TcMcEncoderType:=iTcMc_EncoderSim;  
  
    nJerkEnabled:                 WORD := 16#0101;  
    nProfileType:                 E_TcMcProfileType:=iTcMc_ProfileCtrlBased;  
    nControllerType:              WORD := 16#0101;  
    nOverlapDefMode:              WORD := 0;  
  
    bAsymetricalTargeting:        BOOL := FALSE;  
    bDrive_AbsoluteOutput:        BOOL := FALSE;  
    bDrive_DefaultPowerOk:        BOOL := FALSE;  
    bDrive_Reversed:              BOOL := FALSE;  
    bEnableAutoBrakeDistance:     BOOL := FALSE;  
    bEnableControlLoopOnFault:    BOOL := FALSE;  
    bEnc_RefIndexPositive:        BOOL := FALSE;  
    bEnc_RefSyncPositive:         BOOL := FALSE;  
  
    bEnc_Reversed:                BOOL := FALSE;  
    bMaxLagEna:                   BOOL := FALSE;  
    bPEH_Enable:                  BOOL := FALSE;  
    bPosCtrlAccEna:               BOOL := FALSE;  
    bSoftEndMaxEna:               BOOL := FALSE;  
    bSoftEndMinEna:               BOOL := FALSE;  
    bTimeBased:                   BOOL := FALSE;  
    bLinTabAvailable:             BOOL := FALSE;  
  
    bEnc_NoUpLoad:                BOOL := FALSE;  
    bDrive_NoUpLoad:              BOOL := FALSE;  
    bDriveIsHybrid:               BOOL := FALSE;   
    bAlignedStart:                BOOL := FALSE;   
    bEncModuloMode:               BOOL := FALSE;   
  
    (*-----------------------------------------------------------------*)  
  
    stHybrid:                     ST_TcHybridAxParam;  
    stPctrl:                      ST_TcPctrlParam;  
END_STRUCT  
END_TYPE
```

**bAlignedStart:** From V3.x.y: If this parameter is TRUE, a jump of the output is avoided when starting from a lag error.

**bAsymetricalTargeting**: From V3.0.8: If this parameter is TRUE, direction-dependent parameters take effect during target approach and overlap compensation.

**bDrive\_AbsoluteOutput**: If this parameter is TRUE, control values outputs are always positive, irrespective of the direction.

**bDrive\_DefaultPowerOk**: If this parameter is set, the PowerOk feedback in the [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) structure of the axis is ignored.

**bDrive\_NoUpload**: If this parameter is set, no parameters are read from the device, even in configurations with fieldbus drives and valves.

**bDrive\_Reversed**: If this parameter is set, the control value output is negated.

**bDriveIsHybrid**: This parameter is used to identify a servo-electric/hydraulic hybrid axis. The extended parameters in stHybrid take effect and appear in the PlcMcManager.

**bEnableAutoBrakeDistance**: If this parameter is TRUE, **fCreepDistanceM** and **fCreepDistanceP** are calculated automatically from **fCreepSpeedM** or **fCreepSpeedP** and fLagAmp.

**bEnableControlLoopOnFault**: If this parameter is TRUE, the standstill position controller of the axis also becomes active in the event of an error. **Requirement**: Its parameter are suitable for this, and the axis is in a suitable state.

**bEnc\_NoUpload**: If this parameter is set, no parameters are read from the device, even in configurations with fieldbus encoders.

**bEnc\_RefIndexPositive**: If this parameter is set, while searching for the reference index (cam) during homing a positive control value is output, otherwise a negative value.

**bEnc\_RefSyncPositive**: If this parameter is set, while searching for the reference pulse (sync pulse, zero pulse) during homing a positive control value is output, otherwise a negative value.

**bEnc\_Reversed**: If this parameter is set, the actual position value is evaluated in negated form.

**bLinTabAvailable**: TRUE here means that each pointer was associated with a linearization table during initialization, which contains a successfully determined characteristic curve.

**bMaxLagEna**: This parameter activates lag monitoring.

**bEncModuloMode:** reserved.

**bPEH\_Enable**: This parameter is used to active PEH monitoring.

**bPosCtrlAccEna**: obsolete, will be removed in the near future.

**bSoftEndMaxEna**: This parameter activates the upper software limit switch.

**bSoftEndMinEna**: This parameter activates the lower software limit switch.

**bTimeBased**: If this parameter is TRUE, the profile calculations are time-controlled. The position controller is always active.

**fAcc**: [mm/s2] The absolute acceleration limitation of the axis.

**fAccFeedForward**: [s] The optional acceleration pre-control of the axis.

**fAreaRatio**: [1] This parameter can be used to compensate the directionality of the velocity.

**fBrakeDistance**: [mm] up to V3.0.7: Braking distance: At this not direction-dependent distance from the target, active profile-controlled control value generation ceases; optionally a standstill position controller or a different mechanism that applies at target is activated.

**fBrakeDistanceM**: [mm] from V3.0.8: Braking distance: If **bAsymetricalTargeting** is TRUE, at this negative distance from the target active profile-controlled control value generation ceases; optionally a standstill position controller or a different mechanism that applies at target is activated.

**fBrakeDistanceP**: [mm] from V3.0.8: Braking distance: At this not direction-dependent or (if **bAsymetricalTargeting** is TRUE) positive distance from the target, active profile-controlled control value generation ceases; optionally a standstill position controller or a different mechanism that applies at target is activated.

**fBrakeDeadTime**: [s] up to V3.0.7: This parameter makes it possible to extend the set braking distance by an amount proportional to the actual velocity.

**fBrakeDeadTimeM**: [s] from V3.0.8: This parameter makes it possible to extend the set braking distance for the negative direction by an amount proportional to the actual velocity.

**fBrakeDeadTimeP**: [s] from V3.0.8: This parameter makes it possible to extend the set braking distance for the positive direction by an amount proportional to the actual velocity.

**fBrakeOffDelay**: [s] If this parameter is set to a value greater than 0, the control value generator observes a delay time between the rising edge at [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f).bBrakeOff and the start of the acceleration phase.

**fBrakeOnDelay**: [s] If this parameter is set to a value greater than 0, the control value generator observes a delay time between the end of the active profile generation and the negative edge at [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f).bBrakeOff.

**fBrakeSafetyDelay**: [s] If this parameter is set to a value greater than 0, the control value generator at the falling edge at [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f).bBrakeOff observes a delay time between the end of an active profile generation and the rising edge of the next travel command.

**fCreepSpeed**: [mm/s] up to V3.0.7: This velocity is used, in non-direction-dependent mode, for the last phase of the profile-controlled control value generation.

**fCreepSpeedM**: [mm/s] from V3.0.8: If **bAsymetricalTargeting** is TRUE and the direction of movement is negative, this velocity is used for the last phase of the profile-controlled control value generation.

**fCreepSpeedP**: [mm/s] from V3.0.8: This velocity is used, in non-direction-dependent mode, or (if **bAsymetricalTargeting** is TRUE) if the direction of movement is positive, for the last phase of the profile-controlled control value generation.

**fCreepDistance**: [mm] up to V3.0.7: From this non-direction-dependent distance from the target, **fCreepSpeed** is used as control value for the last phase of the profile-controlled control value generation.

**fCreepDistanceM**: [mm] from V3.0.8: If **bAsymetricalTargeting** is TRUE, from this negative distance from the target **from fCreepSpeedM** is used as control value for the last phase of the profile-controlled control value generation.

**fCreepDistanceP**: [mm] from V3.0.8: From this non-direction-dependent or (if **bAsymetricalTargeting** is TRUE) positive distance from the target, **fCreepSpeedP** is used as control value for the last phase of the profile-controlled control value generation.

**fCustomerData**: 20 LREAL parameters are available for use by the application, as required. They are loaded and stored together with the other axis parameters. Library function blocks do not use these parameters independently, by the application can instruct to use them based on the type of call.

**fCycletime**: [s] The cycle time of the PLC task, from which the library function blocks are called. This value is determined automatically by an [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46)() function block and may be used but **not be changed** by the application.

**fCylinder\_ArreaA**: [mm2] The active area of the cylinder, which is under pressure during a motion in positive direction.

**fCylinder\_ArreaB**: [mm2] The active area of the cylinder, which is under pressure during a motion in negative direction.

**fCylinder\_Mass**: reserved.

**fCylinder\_Stroke**: reserved.

**fDec**: [mm/s2] The absolute deceleration limitation of the axis.

**fDrive\_IncInterpolation**: This parameter is used in some output devices for internal conversion of the velocity control value.

**fDrive\_IncWeighting**: This parameter is used in some output devices for internal conversion of the velocity control value.

**fEmergencyRamp**: [s] This parameter specifies the time required for deceleration from **fRefVelo** to standstill. It is used by different control value generators in response to unscheduled emergency stop requests (lack of controller enable, fault condition, function block call).

**fEnc\_BaseDistance**: [mm] This parameter is used for the evaluation of encoders with distance-coded zero marks.

**fEnc\_DefaultHomePosition**: [mm] This parameter can be used to store a position, which can be transferred as reference position to an [MC\_Home\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1b39-4911-8ef7-a4d128653cfd)() function block. If homing is triggered by the PlcMcManager, the value stored here is used in this way. If this is also intended to be the case if homing is triggered by the PLC application, this parameter should be transferred when the used function block is called.

**fEnc\_IncInterpolation**: [mm/n] This parameter specifies the resolution with which the actual position of the axis is determined.

**fEnc\_IncWeighting**: [1] This parameter specifies the resolution with which the actual position of the axis is determined.

**fEnc\_PotiRgToRl**: [1] It is used by some function blocks for linearization of simple potentiometer displacement transducer, which are subject to load from the input resistance of the interface electronics.

**fEnc\_RefIndexVelo**: [1] This parameter specifies the control value as a proportion of **fRefVelo**, which is output during a search for the reference index (cam) during homing.

**fEnc\_RefSyncVelo**: 81] This parameter specifies the control value as a proportion of **fRefVelo**, which is output during a search for the reference pulse (sync pulse, zero pulse) during homing.

**fEnc\_ZeroShift**: [mm] This parameter shifts the zero point of the actual value determination of the axis.

**fJogVeloFast**: [mm/s] Set velocity for fast manual travel.

**fJogVeloSlow**: [mm/s] Set velocity for slow manual travel.

**fLagAmp**: [mm/s per mm → 1/s] The Kp amplification of the standstill position controller.

**fLagAmpCfb\_kA**: [1] Optional: Weighting factor of the actual acceleration activation in the condition feedback of the position controller.   
This parameter is only used by MC\_AxRtPosPiControllerEx\_BkPlcMc().

**fLagAmpCfb\_kF**: [1] Optional: Weighting factor of the actual force activation in the condition feedback of the position controller.   
This parameter is only used by MC\_AxRtPosPiControllerEx\_BkPlcMc().

**fLagAmpCfb\_kV**: : [1] Optional: Weighting factor of the actual velocity activation in the condition feedback of the position controller.   
This parameter is only used by MC\_AxRtPosPiControllerEx\_BkPlcMc().

**fLagAmpCfb\_tA**: [1] Optional: Filter time of the actual acceleration activation in the condition feedback of the position controller.   
This parameter is only used by MC\_AxRtPosPiControllerEx\_BkPlcMc().

**fLagAmpCfb\_tF**: [1] Optional: Filter time of the actual force activation in the condition feedback of the position controller. **Note**: This parameter is only used by MC\_AxRtPosPiControllerEx\_BkPlcMc().

**fLagAmpCfb\_tV**: : [1] Optional: Filter time of the actual velocity activation in the condition feedback of the position controller. **Note**: This parameter is only used by MC\_AxRtPosPiControllerEx\_BkPlcMc().

**fLagAmpDp**: [mm] In preparation: The response window of the extended standstill position controller.

**fLagAmpDx**: [mm] In preparation: The response window of the standstill position controller.

**fLagAmpTd**: [1] Optional: Rate time of the differential component of the position controller.   
This parameter is only used by MC\_AxRtPosPiControllerEx\_BkPlcMc().

**fLagAmpTdd**: [s] Optional: Damping time of the differential component of the position controller.   
This parameter is only used by MC\_AxRtPosPiControllerEx\_BkPlcMc().

**fLagAmpTi**: In preparation: The integration time of the standstill position controller.

**fLagAmpOutL**: In preparation: The output limitation of the standstill position controller.

**fLagAmpWuL**: In preparation: The limitation of the I component of the standstill position controller.

**fMaxAcc**: [mm/s2] The axis acceleration limitation applicable to the function blocks. This value is limited to **fAcc**.

**fMaxDec**: [mm/s2] The axis deceleration limitation applicable to the function blocks. This value is limited to **fDec**.

**fMaxDynamicLag**: [s] This parameter specifies one of the limit values for the lag monitoring.

**fMaxJerk**: [mm/s3] The axis jerk limitation applicable to the function blocks. This value is used if **iTcMc\_ProfileJerkBased** is set as profile type.

**fMaxLag**: [mm] This parameter specifies one of the limit values for the lag monitoring.

**fMaxLagFilter**: [s] This parameter specifies one of the limit values for the lag monitoring.

fMaxVelo: [mm/s] The maximum velocity that can be used by function blocks. If a function block tries to use a higher value, the value is generally limited accordingly without an error message.   
This parameter is limited to fRefVelo.

**fMonPositionRange**: [mm] This parameter is used for target window monitoring.

**fMonTargetFilter**: [s] This parameter is used for target window monitoring.

**fMonTargetRange**: [mm] This parameter is used for target window monitoring.

**fPEH\_Timeout**: [s] This parameter specifies the limit value for PEH monitoring.

**fRefVelo**: [mm/s] This parameter specifies the maximum absolute axis velocity.

**fReposDistance**: [mm] If this parameter is greater than 0 and the axis has moved beyond the target by more than this distance, target positioning is automatically applied again.

**fSoftEndMax**: [mm] The upper (positive) software limit switch.

**fSoftEndMin**: [mm] The lower (negative) software limit switch.

**fStartAccDistance**: obsolete, will be removed in the near future.

**fStartRamp**: [s] This parameter specifies the time required in profile type **iTcMc\_ProfileTimeRamp** to accelerate to **fRefVelo**.

**fStopRamp**: [s] This parameter specifies the time required for deceleration from **fRefVelo** to standstill. It is used in profile type **iTcMc\_ProfileTimeRamp** for the target approach, and also by control value generators in response to unscheduled stop requests (lack of feed enable, fault condition, function block call).

**fTargetClamping**: [v] If this parameter is set to a value greater than zero, this control value is output with the correct sign when a target is reached. A position control is suppressed.

**fValve\_BendPointOutput**: [1] In valves with a bend in the characteristic curve, this parameter can be used for simple linearization.

**fValve\_BendPointVelo**: [1] In valves with a bend in the characteristic curve, this parameter can be used for simple linearization.

**fValve\_OverlapComp**: [1] up to V3.0.7: Compensation of a non-direction-dependent valve overlap.

**fValve\_OverlapCompM**: [1] from V3.0.8: Compensation (if **bAsymetricalTargeting** = TRUE) for of a valve overlap used for the negative direction.

**fValve\_OverlapCompP**: [1] from V3.0.8: Compensation of a non-direction-dependent valve overlap or (if **bAsymetricalTargeting** = TRUE) a valve overlap used for the positive direction.

**fValve\_ResponseTime**: [s] This parameter can be used for dead time compensation of the actuator.

**fVeloAmp**: The Kp gain of the lower-level velocity controller.

**fVeloAmpDx**: The response window of the lower-level velocity controller.

**fVeloAmpTi**: The integration time of the lower-level velocity controller.

**fVeloAmpOutL**: The output limitation of the lower-level velocity controller.

**fVeloAmpWuL**: Limitation of the I component of the lower-level velocity controller.

**fZeroCompensation**: [V] This parameter can be used to compensate an analog offset of the velocity output.

**nControllerType**: This parameter is set automatically by the called position controller. It is not saved.

**nCycleDivider**: reserved.

**nDrive\_Type**: Specifies the [drive type](ms-xhelp:///?Id=beckhoff-540a-458a-ab44-3657804f519c).

**nEnc\_HomingType**: Used to specify the referencing method, which an [MC\_Home\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1b39-4911-8ef7-a4d128653cfd)() function block uses if [MC\_DefaultHomingMode\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9007-49dc-a035-f71f1e0e29da) is transferred as **HomingMode**.

**nEnc\_Type**: Specifies the [encoder type](ms-xhelp:///?Id=beckhoff-1819-4c81-9982-5253100bd275).

**nEnc\_ZeroSwap**: reserved.

**nJerkEnabled**: This bit mask determines at which transitions in the profile jerk limitation is to be applied. This value is used if **iTcMc\_ProfileJerkBased** is set as profile type.

**nOverlapDefMode:** reserved.

**nProfileType**: Specifies the [control value generator](ms-xhelp:///?Id=beckhoff-8110-4345-a5e7-67028351ee24).

**sParamFileName**: This file name is used for storing the axis parameter as a DAT file.

**stHybrid**: This structure pools parameters for hybrid electro/hydraulic axes.

**stPctrl**: This structure contains parameters that can be used for a force or pressure regulator.

See Setup for more information about axis commissioning.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
