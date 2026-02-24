# E_TcMCParameter (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. E\_TcMCParameter (from V3.0)

# E\_TcMCParameter (from V3.0)

The constants listed here are used for numbering parameters.

```
                        TYPE E_TcMCParameter :  
(  
(*  
==================================================================  
            A T T E N T I O N  
==================================================================  
= These Codes are also used to identify parameters in files.  
= Any change of the meaning of any code here will make any file  
= incompatible without notice and may even cause a crash of  
= the control system!  
==================================================================  
= CONSEQUENCE: Only adding new codes is allowed!  
==================================================================  
= These codes are also used for ADS communication  
==================================================================  
*)  
(*  
==================================================================  
            A C H T U N G  
==================================================================  
= Diese Codes werden auch zur Kennzeichnung von Parametern  
= in den Dateien verwendet. Eine Veraenderung der Codes wuerde  
= die Dateien (nicht erkennbar) inkompatibel machen und koennte  
= zum Systemabsturz fuehren!  
==================================================================  
= ALSO: Es duerfen nur neue Codes dazugefuegt werden!  
==================================================================  
= Diese Codes werden ebenfalls fuer die ADS-Kommunikation benutzt  
==================================================================  
*)  
McPara_CommandedPosition:=1,  
McPara_SWLimitPos,  
McPara_SWLimitNeg,  
McPara_EnableLimitPos,  
McPara_EnableLimitNeg,  
McPara_EnablePosLagMonitoring,  
McPara_MaxPositionLag,  
McPara_MaxVelocitySystem,  
McPara_MaxVelocityAppl,  
McPara_ActualVelocity,  
McPara_CommandedVelocity,  
McPara_MaxAccelerationSystem,  
McPara_MaxAccelerationAppl,  
McPara_MaxDecelerationSystem,  
McPara_MaxDecelerationAppl,  
McPara_MaxJerk,  
(* ============================================================ *)  
McPara_BkPlcMc_ProfilType:=1000,  
McPara_BkPlcMc_EnvCycletime,  
McPara_BkPlcMc_AxName,  
McPara_BkPlcMc_TimeBased,  
McPara_BkPlcMc_JerkEnabled,  
McPara_BkPlcMc_LogLevel,  
McPara_BkPlcMc_CycleDivider,  
McPara_BkPlcMc_ParamFileName,  
  
McPara_BkPlcMc_EncoderType:=1100,  
McPara_BkPlcMc_EncoderHomingType,  
McPara_BkPlcMc_EncoderZeroShift,  
McPara_BkPlcMc_EncoderIncWeighting,  
McPara_BkPlcMc_EncoderIncInterpolation,  
McPara_BkPlcMc_EncoderRefIndexVelo,  
McPara_BkPlcMc_EncoderRefIndexPositive,  
McPara_BkPlcMc_EncoderRefSyncVelo,  
McPara_BkPlcMc_EncoderRefSyncPositive,  
McPara_BkPlcMc_EncoderDefaultHomePosition,  
McPara_BkPlcMc_EncoderReversed,  
McPara_BkPlcMc_EncoderBaseDistance,  
McPara_BkPlcMc_EncoderModuloBase,  
McPara_BkPlcMc_EncoderEnableLatch,  
McPara_BkPlcMc_EncoderLatchedPos,  
McPara_BkPlcMc_EncoderRefShift,  
McPara_BkPlcMc_EncoderRefFlag,  
McPara_BkPlcMc_EncoderPotiRgToRl,  
McPara_BkPlcMc_EncoderOverrunMask,  
McPara_BkPlcMc_EncoderPositionMask,  
McPara_BkPlcMc_EncoderZeroSwap,   
McPara_BkPlcMc_EncoderNoUpload,  
McPara_BkPlcMc_EncoderModuloMode,  
  
McPara_BkPlcMc_ValveOverlapCompP:=1200,  
McPara_BkPlcMc_ValveBendPointVelo,  
McPara_BkPlcMc_ValveBendPointOutput,  
McPara_BkPlcMc_ValveResponseTime,  
McPara_BkPlcMc_ValveOverlapCompM,  
McPara_BkPlcMc_CylinderArreaA:=1280,  
McPara_BkPlcMc_CylinderArreaB,  
  
McPara_BkPlcMc_DriveType:=1300,  
McPara_BkPlcMc_AreaRatio,  
McPara_BkPlcMc_DriveReversed,  
McPara_BkPlcMc_DriveDefaultPowerOk  
McPara_BkPlcMc_DriveAbsoluteOutput,  
McPara_BkPlcMc_DriveIncWeighting,  
McPara_BkPlcMc_DriveIncInterpolation,   
McPara_BkPlcMc_DriveNoUpload,   
  
McPara_BkPlcMc_DriveIsHybrid,   
McPara_BkPlcMc_HybridConcept,   
McPara_BkPlcMc_Pump_Cavities,   
McPara_BkPlcMc_Pump_EncType,   
McPara_BkPlcMc_Pump_N_max,   
McPara_BkPlcMc_Pump_N_min,   
McPara_BkPlcMc_Pump_P_max,   
McPara_BkPlcMc_Pump_P_min,   
McPara_BkPlcMc_Pump_Q_fast_P,   
McPara_BkPlcMc_Pump_Q_slow_P,   
McPara_BkPlcMc_Pump_Q_fast_M,   
McPara_BkPlcMc_Pump_Q_slow_M,   
McPara_BkPlcMc_Pump_Q_leak,   
McPara_BkPlcMc_Pump_Enc_Offset,   
McPara_BkPlcMc_Cylinder_A_addP,   
McPara_BkPlcMc_Cylinder_A_addM,   
McPara_BkPlcMc_PrsScaling_A,  
McPara_BkPlcMc_PrsScaling_B,  
McPara_BkPlcMc_PrsScaling_Sys,  
McPara_BkPlcMc_Motor_RampTime,  
McPara_BkPlcMc_Pump_Regenerative,  
McPara_BkPlcMc_Virtual_A_addP,  
McPara_BkPlcMc_Virtual_A_addM,  
McPara_BkPlcMc_Aside_PrsHiResADC,  
McPara_BkPlcMc_Bside_PrsHiResADC,  
McPara_BkPlcMc_System_PrsHiResADC,   
  
McPara_BkPlcMc_StartRamp:=1400,  
McPara_BkPlcMc_obsolete_1,  
McPara_BkPlcMc_obsolete_2,  
  
McPara_BkPlcMc_StopRamp:=1500,  
McPara_BkPlcMc_EmergencyRamp,  
McPara_BkPlcMc_BrakeOn,  
McPara_BkPlcMc_BrakeOff,  
McPara_BkPlcMc_BrakeSafety,  
  
McPara_BkPlcMc_CreepSpeedP:=1600,  
McPara_BkPlcMc_CreepDistanceP,  
McPara_BkPlcMc_BrakeDistanceP,  
McPara_BkPlcMc_BrakeDeadTimeP,  
McPara_BkPlcMc_CreepSpeedM,  
McPara_BkPlcMc_CreepDistanceM,  
McPara_BkPlcMc_BrakeDistanceM,  
McPara_BkPlcMc_BrakeDeadTimeM,  
McPara_BkPlcMc_AsymetricalTargeting,  
  
McPara_BkPlcMc_LagAmp:=1700,  
McPara_BkPlcMc_LagAmpAdaptLimit,  
McPara_BkPlcMc_LagAmpAdaptFactor,  
McPara_BkPlcMc_ZeroCompensation,  
McPara_BkPlcMc_TargetClamping,  
McPara_BkPlcMc_ReposDistance,  
McPara_BkPlcMc_AutoBrakeDistance,  
McPara_BkPlcMc_EnableControlLoopOnFault,  
McPara_BkPlcMc_LagAmpDx,  
McPara_BkPlcMc_LagAmpTi,  
McPara_BkPlcMc_LagAmpWuLimit,  
McPara_BkPlcMc_LagAmpOutLimit,  
  
McPara_BkPlcMc_VeloAmp,  
McPara_BkPlcMc_VeloAmpDx,  
McPara_BkPlcMc_VeloAmpTi,  
McPara_BkPlcMc_VeloAmpWuLimit,  
McPara_BkPlcMc_VeloAmpOutLimit,  
McPara_BkPlcMc_FeedForward,  
  
McPara_BkPlcMc_LagAmpTd,  
McPara_BkPlcMc_LagAmpTdd,  
McPara_BkPlcMc_LagAmpCfb_tA,  
McPara_BkPlcMc_LagAmpCfb_kA,  
McPara_BkPlcMc_LagAmpCfb_tV,  
McPara_BkPlcMc_LagAmpCfb_kV,   
McPara_BkPlcMc_LagCtrlType,   
McPara_BkPlcMc_LagAmpCfb_tF,   
McPara_BkPlcMc_LagAmpCfb_kF,   
McPara_BkPlcMc_AccFeedForward,  
  
McPara_BkPlcMc_Pctrl_kP:=1780,   
McPara_BkPlcMc_Pctrl_Tn,   
McPara_BkPlcMc_Pctrl_Tv,   
McPara_BkPlcMc_Pctrl_Nf,   
McPara_BkPlcMc_Pctrl_Preset,   
McPara_BkPlcMc_Pctrl_WuLimit,   
McPara_BkPlcMc_Pctrl_AlignAreas,  
  
McPara_BkPlcMc_MonPositionRange:=1800,  
McPara_BkPlcMc_MonTargetRange,  
McPara_BkPlcMc_MonTargetFilter,  
McPara_BkPlcMc_MonPositionLagFilter,  
McPara_BkPlcMc_MonDynamicLagLimit,  
McPara_BkPlcMc_MonPehEnable,  
McPara_BkPlcMc_MonPehTimeout,  
McPara_BkPlcMc_DigInputReversed,  
  
McPara_PFW_EnableLimitPos:=1898,   
McPara_PFW_EnableLimitNeg:=1899,   
  
McPara_BkPlcMc_JogVeloFast:=1900,  
McPara_BkPlcMc_JogVeloSlow,  
  
McPara_BkPlcMc_CustomerData:=2000,  
  
McPara_BkPlcMc_AutoId_EnaEoT:=3000,  
McPara_BkPlcMc_AutoId_EnaOvl,  
McPara_BkPlcMc_AutoId_EnaZadj,  
McPara_BkPlcMc_AutoId_EnaAratio,  
McPara_BkPlcMc_AutoId_EnaLinTab,  
McPara_BkPlcMc_AutoId_EoT_N:=3100,  
McPara_BkPlcMc_AutoId_EoT_P,  
McPara_BkPlcMc_AutoId_EoI_N,  
McPara_BkPlcMc_AutoId_EoI_P,  
McPara_BkPlcMc_AutoId_EoTlim_N,  
McPara_BkPlcMc_AutoId_EoTlim_P,  
McPara_BkPlcMc_AutoId_DecFactor,  
McPara_BkPlcMc_AutoId_EoVlim_N,   
McPara_BkPlcMc_AutoId_EoVlim_P,   
McPara_BkPlcMc_AutoId_LastIdent_N,   
McPara_BkPlcMc_AutoId_LastIdent_P,   
McPara_BkPlcMc_AutoId_TblCount:=3150,  
McPara_BkPlcMc_AutoId_TblLowEnd,  
McPara_BkPlcMc_AutoId_TblHighEnd,  
McPara_BkPlcMc_AutoId_TblRamp,  
McPara_BkPlcMc_AutoId_TblSettling,  
McPara_BkPlcMc_AutoId_TblRecovery,  
McPara_BkPlcMc_AutoId_TblMinCycle,  
McPara_BkPlcMc_AutoId_LinTblAvailable,  
McPara_BkPlcMc_AutoId_TblValveType,  
McPara_BkPlcMc_AutoId_LinTab_1:=3200,  
McPara_BkPlcMc_AutoId_LinTab_2:=3400,  
(* ---------------------------------------------------------- *)  
McRtData_BkPlcMc_ActualPosition:=10000,  
McRtData_BkPlcMc_ActualAcceleration,  
McRtData_BkPlcMc_PosError,  
McRtData_BkPlcMc_DistanceToTarget,  
McRtData_BkPlcMc_ActPressure,  
McRtData_BkPlcMc_ActPressureA,  
McRtData_BkPlcMc_ActPressureB,  
McRtData_BkPlcMc_ActForce,  
McRtData_BkPlcMc_ValvePressure,  
McRtData_BkPlcMc_SupplyPressure,  
McRtData_BkPlcMc_SetPosition,  
McRtData_BkPlcMc_SetVelocity,  
McRtData_BkPlcMc_SetAcceleration,  
McRtData_BkPlcMc_SetPressure,  
McRtData_BkPlcMc_SetOverride,  
McRtData_BkPlcMc_LatchPosition,  
McRtData_BkPlcMc_CtrlOutLag,  
McRtData_BkPlcMc_CtrlOutClamping,  
McRtData_BkPlcMc_CtrlOutOverlapComp,  
McRtData_BkPlcMc_TargetPosition,  
McRtData_BkPlcMc_NSDW:=11000,  
McRtData_BkPlcMc_DCDW,  
McRtData_BkPlcMc_ErrCode,  
McRtData_BkPlcMc_FbState,  
McRtData_BkPlcMc_CurStep,  
McRtData_BkPlcMc_ParamsUnsave,  
McRtData_BkPlcMc_RawPosition,  
McRtData_BkPlcMc_ActPosCams,  
McRtData_BkPlcMc_ReloadParams,  
McRtData_BkPlcMc_EncoderMinPos,  
McRtData_BkPlcMc_EncoderMaxPos,  
McRtData_BkPlcMc_BufferedEntries,  
McRtData_BkPlcMc_Pump_Switched:=12000,   
McRtData_BkPlcMc_Pump_AreaSwitched,   
McRtData_BkPlcMc_Pump_Angle:=12100,   
McRtData_BkPlcMc_Pump_ModuloAngle,   
McRtData_BkPlcMc_Pump_Speed,   
McRtData_BkPlcMc_Pump_Torque,   
McRtData_BkPlcMc_Motor_N_max,   
McRtData_BkPlcMc_Active_Area_P,   
McRtData_BkPlcMc_Active_Area_M,   
McRtData_BkPlcMc_Active_Qmax_P,   
McRtData_BkPlcMc_Active_Qmax_M,   
McRtData_BkPlcMc_Active_Feed_P,   
McRtData_BkPlcMc_Active_Feed_M,   
McRtData_BkPlcMc_Active_N_max,   
McRtData_BkPlcMc_Active_Vmax_P,   
McRtData_BkPlcMc_Active_Vmax_M,   
 (* ---------------------------------------------------------- *)  
(**)  
McPara_BkPlcMc_  
(**)  
McPara_BkPlcMc_FileMarkComplete:=32767  (* Ax.Params.bLinTabAvailable AutoIdent: .. / AutoIdent: .. *)  
);  
END_TYPE
```

**McPara\_ActualVelocity:** The actual axis velocity.

**McPara\_BkPlcMc\_Aside\_PrsHiResADC:** The pressure sensor on the area acting in positive direction is read in with a 24-bit terminal.

**McPara\_BkPlcMc\_AreaRatio:** The direction-dependent velocity ratio.

**McPara\_BkPlcMc\_AsymmetricalTargeting:** Enable for the asymmetric targeting.

**McPara\_BkPlcMc\_AutoID\_EnaAratio:** Automatic identification: Determining direction-related velocity ratio.

**McPara\_BkPlcMc\_AutoID\_DecFactor:** Automatic identification: Factor for weighting the deceleration.

**McPara\_BkPlcMc\_AutoID\_EnaEoI\_N:** Automatic identification: Determined negative hard stop of the cylinder in increments.

**McPara\_BkPlcMc\_AutoID\_EnaEoI\_P:** Automatic identification: Determined positive hard stop of the cylinder in increments.

**McPara\_BkPlcMc\_AutoID\_EnaEoT:** Automatic identification: Determining the hard stops of the cylinders.

**McPara\_BkPlcMc\_AutoID\_EnaLinTab:** Automatic identification: Determining the characteristic curve.

**McPara\_BkPlcMc\_AutoID\_EnaOvl:** Automatic identification: Determining the valve overlap.

**McPara\_BkPlcMc\_AutoID\_EnaZadj:** Automatic identification: Determining the offsets.

**McPara\_BkPlcMc\_AutoID\_EoTlim\_N:** Automatic identification: Determined negative hard stop of the cylinder.

**McPara\_BkPlcMc\_AutoID\_EoTlim\_P:** Automatic identification: Determined positive hard stop of the cylinder.

**McPara\_BkPlcMc\_AutoID\_EoT\_N:** Automatic identification: Hard stop of the cylinder in negative direction.

**McPara\_BkPlcMc\_AutoID\_EoT\_P:** Automatic identification: Hard stop of the cylinder in positive direction.

**McPara\_BkPlcMc\_AutoID\_EoVlim\_N:** Automatic identification: Velocity limitation of the characteristic curves determination in negative direction.

**McPara\_BkPlcMc\_AutoID\_EoVlim\_P:** Automatic identification: Velocity limitation of the characteristic curves determination in positive direction.

**McPara\_BkPlcMc\_AutoID\_LastIdent\_N:** Automatic identification: The output value of the last successful measurement in negative direction.

**McPara\_BkPlcMc\_AutoID\_LastIdent\_P:** Automatic identification: The output value of the last successful measurement in positive direction.

**McPara\_BkPlcMc\_AutoID\_LinTab\_1:** Automatic identification: Points of the characteristic curve, relative velocity.

**McPara\_BkPlcMc\_AutoID\_LinTab\_2:** Automatic identification: Points of the characteristic curve, relative output.

**McPara\_BkPlcMc\_AutoID\_LinTblAvailable:** This signal is set to TRUE at the end of a successful characteristic curve measurement.

**McPara\_BkPlcMc\_AutoID\_MinCycle:** Automatic identification: Minimum measuring distance.

**McPara\_BkPlcMc\_AutoID\_TblCount:** Automatic identification: The number of required table points. Since the zero point is counted but is only present once, this parameter must always be an odd number. Values between 3 and 99 are accepted. A value of less than 11 is not recommended.

**McPara\_BkPlcMc\_AutoID\_TblHighEnd:** Automatic identification: Upper end of the designated measuring section.

**McPara\_BkPlcMc\_AutoID\_TblLowEnd:** Automatic identification: Lower end of the designated measuring section.

**McPara\_BkPlcMc\_AutoID\_TblRamp:** Automatic identification: Ramp for establishing the measuring output. The specified time refers a change from zero to full scale. Smaller output changes are applied in a proportion of the time.

**McPara\_BkPlcMc\_AutoID\_TblRecovery:** Automatic characteristic curve identification: Delay time in the event of a change of direction.

**McPara\_BkPlcMc\_AutoID\_TblSettling:** Automatic identification: Delay time between establishment of the measuring output and the start of the measurement.

**McPara\_BkPlcMc\_AutoID\_TblValveType:** Automatic identification: The expected characteristic curve type.

**McPara\_BkPlcMc\_BrakeDeadTimeM:** The brake dead time in negative direction.

**McPara\_BkPlcMc\_BrakeDeadTimeP:** The brake dead time in positive direction.

**McPara\_BkPlcMc\_Auto\_BrakeDistance:** The enable for automatic calculation of the braking distance.

**McPara\_BkPlcMc\_BrakeDistanceM:** For asymmetric target approach: The braking distance time in negative direction.

**McPara\_BkPlcMc\_BrakeDistanceP:** The braking distance time in positive direction. For symmetric target approach: The braking distance time in negative direction.

**McPara\_BkPlcMc\_BrakeOff:** A delay between the active axis motion and the signal for activating a brake.

**McPara\_BkPlcMc\_BrakeOn:** A delay between the signal for releasing a brake and the active axis motion.

**McPara\_BkPlcMc\_BrakeSafety:** A delay between the active axis motion in one direction and active motion in the opposite direction.

**McPara\_BkPlcMc\_Bside\_PrsHiResADC:** The pressure sensor on the area acting in negative direction is read in with a 24-bit terminal.

**McPara\_BkPlcMc\_CreepDistanceM:** For asymmetric target approach: The creep distance in negative direction.

**McPara\_BkPlcMc\_CreepDistanceP:** The creep distance in positive direction. For symmetric target approach: The creep distance in negative direction.

**McPara\_BkPlcMc\_CreepSpeedM:** For asymmetric target approach: The creep speed in negative direction.

**McPara\_BkPlcMc\_CreepSpeedP:** The creep speed in positive direction. For symmetric target approach: The creep speed in negative direction.

**McPara\_BkPlcMc\_CustomerData:** A field with parameters that can be used freely by an application. These parameters are stored and loaded with the axis parameters.

**McPara\_BkPlcMc\_CycleDevider:** reserved, not implemented.

**McPara\_BkPlcMc\_CylinderArreaA:** The cylinder area of the cylinder side pushing in positive direction.

**McPara\_BkPlcMc\_CylinderArreaB:** The cylinder area of the cylinder side pushing in negative direction.

**McPara\_BkPlcMc\_DigInputsReversed:** Enable for inversion of the input signals of an axis with digital position sensors.

**McPara\_BkPlcMc\_DriveAbsoluteOutput:** Enable for absolute value formation during output adjustment.

**McPara\_BkPlcMc\_DriveDefaultPowerOk:** Drive power is assumed to be available adopted; no hardware signal required.

**McPara\_BkPlcMc\_DriveIncInterpolation:** Interpolation of the output adjustment.

**McPara\_BkPlcMc\_DriveIncWeighting:** Weighting of the output adjustment.

**McPara\_BkPlcMc\_DriveNoUpload:** A TRUE here prevents the automatic determination of axis parameters by reading data from a drive.

**McPara\_BkPlcMc\_DriveReversed:** Enable for inverted output adjustment.

**McPara\_BkPlcMc\_DriveType:** Type of drive adjustment.

**McPara\_BkPlcMc\_EmergencyRamp:** In the event of an emergency stop: The time for braking from maximum velocity to standstill.

**McPara\_BkPlcMc\_EnableControlLoopOnFaults:** Enable for position control in the event of axis errors.

**McPara\_BkPlcMc\_EncNoUpload:** A TRUE here prevents the automatic determination of axis parameters by reading data from an encoder.

**McPara\_BkPlcMc\_EncoderBaseDistance:** Reserved for distance-coded encoders.

**McPara\_BkPlcMc\_EncoderDefaultHomePosition:** Axes with incremental distance measuring system: A default value for homing.

**McPara\_BkPlcMc\_EncoderEnableLatch:** Enable for the latch function of an encoder hardware.

**McPara\_BkPlcMc\_EncoderHomingType:** Axes with incremental distance measuring system: The default homing method.

**McPara\_BkPlcMc\_EncoderIncInterpolation:** The increment interpolation of the encoder evaluation.

**McPara\_BkPlcMc\_EncoderIncWeighting:** The increment weighting of the encoder evaluation.

**McPara\_BkPlcMc\_EncoderModuloBase:** reserved, not implemented.

**McPara\_BkPlcMc\_EncoderLatchedPosition:** The latched position during homing.

**McPara\_BkPlcMc\_EncoderOverrunMask:** A mask for detecting an encoder overflow.

**McPara\_BkPlcMc\_EncoderPositionMask:** A mask for isolating the valid bits within the mapped variables.

**McPara\_BkPlcMc\_EncoderPotiRgToRl:** For potentiometer encoders: The ratio of total potentiometer resistance to load resistance (input resistance of the terminal).

**McPara\_BkPlcMc\_EncoderRefFlag:** The homing status of the axis.

**McPara\_BkPlcMc\_EncoderRefIndexPositive:** Axes with incremental distance measuring system: During homing the system looks for the index (cam) in positive direction.

**McPara\_BkPlcMc\_EncoderRefIndexVelo:** Axes with incremental distance measuring system: During homing the system looks for the index (cam) with this velocity.

**McPara\_BkPlcMc\_EncoderRefShift:** Axes with incremental distance measuring system: Zero shift of the encoder evaluation.

**McPara\_BkPlcMc\_EncoderRefSyncPositive:** Axes with incremental distance measuring system: During homing the system looks for the homing signal in positive direction.

**McPara\_BkPlcMc\_EncoderRefSyncVelo:** Axes with incremental distance measuring system: During homing the system looks for the homing signal with this velocity.

**McPara\_BkPlcMc\_EncoderReversed:** Enable for inverted encoder evaluation.

**McPara\_BkPlcMc\_EncoderType:** Type of encoder evaluation.

**McPara\_BkPlcMc\_EncoderZeroShift:** Axes with absolute distance measuring system: Zero shift of the encoder evaluation.

**McPara\_BkPlcMc\_EncoderZeroSwap:** Block-by-block shifting of the counting range of the encoder evaluation.

**McPara\_BkPlcMc\_EnvCycleTime:** The cycle time of the task in which the core blocks (encoder, setpoint generator, etc.) of the axis are called.

**McPara\_BkPlcMc\_FeedForward:** Pre-control weighting of the axis.

**McPara\_BkPlcMc\_JerkEnabled:** The control word for jerk limitation.

**McPara\_BkPlcMc\_JogVeloFast:** A default value for a fast jog velocity.

**McPara\_BkPlcMc\_JogVeloSlow:** A default value for a slow jog velocity.

**McPara\_BkPlcMc\_LagAmp:** Gain factor for the proportional component in the position controller.

**McPara\_BkPlcMc\_LagAmpAdaptFactor:** reserved.

**McPara\_BkPlcMc\_LagAmpAdaptLimit:** reserved.

**McPara\_BkPlcMc\_LagAmpCfb\_tA**: A parameter of the advanced position controller in the [MC\_AxRtPosPiControllerEx\_BkPlcMc](ms-xhelp:///?Id=beckhoff-feba-4c4e-afbf-2a4ddc9e9d94) function block: The filter time of the actual acceleration feedback.

**McPara\_BkPlcMc\_LagAmpCfb\_kA**: A parameter of the advanced position controller in the [MC\_AxRtPosPiControllerEx\_BkPlcMc](ms-xhelp:///?Id=beckhoff-feba-4c4e-afbf-2a4ddc9e9d94) function block: The gain of the actual acceleration feedback.

**McPara\_BkPlcMc\_LagAmpCfb\_tV**: A parameter of the advanced position controller in the [MC\_AxRtPosPiControllerEx\_BkPlcMc](ms-xhelp:///?Id=beckhoff-feba-4c4e-afbf-2a4ddc9e9d94) function block: The filter time of the actual velocity feedback.

**McPara\_BkPlcMc\_LagAmpCfb\_kV**: A parameter of the advanced position controller in the [MC\_AxRtPosPiControllerEx\_BkPlcMc](ms-xhelp:///?Id=beckhoff-feba-4c4e-afbf-2a4ddc9e9d94) function block: The gain of the actual velocity feedback.

**McPara\_BkPlcMc\_LagAmpDx:** Threshold value for the integrating component of the position controller.

**McPara\_BkPlcMc\_LagAmpTd**: A parameter of the advanced position controller in the [MC\_AxRtPosPiControllerEx\_BkPlcMc](ms-xhelp:///?Id=beckhoff-feba-4c4e-afbf-2a4ddc9e9d94) function block: The gain of the D component.

**McPara\_BkPlcMc\_LagAmpTdd**: A parameter of the advanced position controller in the [MC\_AxRtPosPiControllerEx\_BkPlcMc](ms-xhelp:///?Id=beckhoff-feba-4c4e-afbf-2a4ddc9e9d94) function block: The attenuation of the D component.

**McPara\_BkPlcMc\_LagAmpTi:** Time constant for the integrating component of the position controller.

**McPara\_BkPlcMc\_LagAmpOutLimit:** Output limitation for the position controller.

**McPara\_BkPlcMc\_LagAmpWuLimit:** Limitation (wind-up limit) for the integrating component of the position controller.

**McPara\_BkPlcMc\_LogLevel:** Threshold value for message logging.

**McPara\_BkPlcMc\_MonDynamicLagLimit:** Tolerance for dynamic position lag monitoring.

**McPara\_BkPlcMc\_MonPehEnable:** Enable for monitoring of the ready message at the target.

**McPara\_BkPlcMc\_MonPehTimeout:** Filter time for monitoring of the ready message at the target.

**McPara\_BkPlcMc\_MonPositionLagFilter:** Filter time for position lag monitoring.

**McPara\_BkPlcMc\_MonPositionRange:** Tolerance for the position window.

**McPara\_BkPlcMc\_MonTargetFilter:** Filter time for the target window.

**McPara\_BkPlcMc\_MonTargetRange:** Tolerance for the target window.

**McPara\_BkPlcMc\_obsolete\_XYZ:** Placeholder for parameters that are no longer supported. These parameter codes must not be reused for new parameters. To ensure this, such numerical values are assigned names of this form.

**McPara\_BkPlcMc\_ParamFileName:** Name of the parameter file.

**McPara\_BkPlcMc\_Pctrl\_AlignAreas:** Adaptation of the output of a force or pressure regulator to the direction-dependent active areas.

**McPara\_BkPlcMc\_Pctrl\_kP:** Proportional gain of a force or pressure regulator.

**McPara\_BkPlcMc\_Pctrl\_Nf:** Depth of a mean value filter in the D component of a force or pressure regulator.

**McPara\_BkPlcMc\_Pctrl\_Preset:** Initial value of the I component of a force or pressure regulator.

**McPara\_BkPlcMc\_Pctrl\_Tn:** Time constant in the I component of a force or pressure regulator.

**McPara\_BkPlcMc\_Pctrl\_Tv:** Time constant in the D component of a force or pressure regulator.

**McPara\_BkPlcMc\_Pctrl\_WuLimit:** Limitation of the I component of a force or pressure regulator.

**McPara\_BkPlcMc\_ProfilType:** Type of setpoint generator.

**McPara\_BkPlcMc\_ReposDistance:** Threshold value for automatic repositioning.

**McPara\_BkPlcMc\_StartRamp:** Only for certain setpoint generators: Acceleration ramp.

**McPara\_BkPlcMc\_StopRamp:** Only for certain setpoint generators: Braking ramp.

**McPara\_BkPlcMc\_System\_PrsHiResADC:** The pressure sensor at the pressurized hydraulic reservoir is read with a 24-bit terminal.

**McPara\_BkPlcMc\_TargetClamping:** Default output value for the clamping function.

**McPara\_BkPlcMc\_TimeBased:** Switching of setpoint generator: Time-based or displacement-based.

**McPara\_BkPlcMc\_ValveBendPointOutput:** Valve output for compensation of the characteristic curve bend.

**McPara\_BkPlcMc\_ValveBendPointVelo:** Velocity for compensation of the characteristic curve bend.

**McPara\_BkPlcMc\_ValveOverlapCompM:** Compensation of the valve overlap for the negative direction.

**McPara\_BkPlcMc\_ValveOverlapCompP:** Compensation of the valve overlap for the positive direction.

**McPara\_BkPlcMc\_ValveResponseTime:** Compensation of the valve response time.

**McPara\_BkPlcMc\_VeloAmp:** Gain factor for the proportional component in the velocity controller.

**McPara\_BkPlcMc\_VeloAmpDx:** Threshold value for the integrating component of the velocity controller.

**McPara\_BkPlcMc\_VeloAmpTi:** Time constant for the integrating component of the velocity controller.

**McPara\_BkPlcMc\_VeloAmpOutLimit:** Output limitation for the velocity controller.

**McPara\_BkPlcMc\_VelopWuLimit:** Limitation (wind-up limit) for the integrating component of the velocity controller.

**McPara\_BkPlcMc\_Virtual\_A\_addP:** The active area that can be activated in positive direction must be taken into account for the oil demand, but it does not contribute to the force build-up.

**McPara\_BkPlcMc\_Virtual\_A\_addM:** The active area that can be activated in negative direction must be taken into account for the oil demand, but it does not contribute to the force build-up.

**McPara\_BkPlcMc\_ZeroCompensation:** Offset compensation of the output.

**McPara\_CommandedPosition:** The last commanded target position of the axis.

**McPara\_CommandedVelocity:** The last commanded velocity of the axis.

**McPara\_EnableLimitNeg:** Enable for the software limit switch in negative direction.

**McPara\_EnableLimitPos:** Enable for the software limit switch in positive direction.

**McPara\_MaxAccelerationAppl:** The maximum acceleration that can be commanded by the application.

**McPara\_MaxAccelerationSystem:** The upper limit set by the system for the maximum acceleration that can be commanded by the application.

**McPara\_MaxDecelerationAppl:** The maximum deceleration that can be commanded by the application.

**McPara\_MaxDecelerationSystem:** The upper limit set by the system for the maximum deceleration that can be commanded by the application.

**McPara\_MaxJerk:** The upper limit set by the system for the maximum jerk that can be commanded by the application.

**McPara\_MaxPositionLag:** Threshold value for position lag monitoring.

**McPara\_MaxVelocityAppl:** The maximum velocity that can be commanded by the application.

**McPara\_MaxVelocitySystem:** The upper limit set by the system for the maximum velocity that can be commanded by the application.

**McPara\_PFW\_Xyz:** These parameters are reserved for a sector-specific solution.

**McPara\_SWLimitNeg:** Software limit switch in negative direction.

**McPara\_SWLimitPos:** Software limit switch in positive direction.

**McRtData\_BkPlcMc\_ActForce:** The actual force.

**McRtData\_BkPlcMc\_AxName:** The text-based name of the axis.

**McRtData\_BkPlcMc\_ActPosCams:** For axes with digital position sensors: The sensor signals.

**McRtData\_BkPlcMc\_ActPressure:** The actual differential pressure at the valve.

**McRtData\_BkPlcMc\_ActPressureA:** The actual pressure in the A-chamber of the cylinder.

**McRtData\_BkPlcMc\_ActPressureB:** The actual pressure in the B-chamber of the cylinder.

**McRtData\_BkPlcMc\_ActualAcceleration:** The actual acceleration.

**McRtData\_BkPlcMc\_ActualPosition:** The actual position.

**McRtData\_BkPlcMc\_BufferedEntries:** For axes with a command buffer: The number of buffered commands.

**McRtData\_BkPlcMc\_CtrlOutOverlapComp:** The current output component of the overlap compensation.

**McRtData\_BkPlcMc\_CtrlOutClamping:** The current value of the terminal output.

**McRtData\_BkPlcMc\_CtrlOutLag:** The current output of the position controller.

**McRtData\_BkPlcMc\_CurStep:** The current (internal) axis step. See also E\_TcMcCurrentStep.

**McRtData\_BkPlcMc\_DCDW:** The control word of the axis with the enables (and other parameters).   
There is no relationship with the control word of an external device.

**McRtData\_BkPlcMc\_DistanceToTarget:** The remaining distance to the target.

**McRtData\_BkPlcMc\_EncoderMaxPos:** reserved.

**McRtData\_BkPlcMc\_EncoderMinPos:** reserved.

**McRtData\_BkPlcMc\_ErrCode:** The current error code of the axis.

**McRtData\_BkPlcMc\_FbState:** The current axis step (defined by PLCopen). See also E\_TcMCFbState.

**McRtData\_BkPlcMc\_FileMarkComplete:** In a parameter file: The logical end identifier.

**McRtData\_BkPlcMc\_LatchPosition:** The (offset) reference position. This is the position at which the actual position was finally set during homing.

**McRtData\_BkPlcMc\_NSDW:** The axis status word with the operating states.   
There is no relationship with the status word of an external device.

**McRtData\_BkPlcMc\_ParamsUnsave**: A TRUE here indicates that a parameter was changed significantly, but the parameter file was not yet written again. This signal cannot be issued by the library, if the parameter was changed directly (without the write function blocks).

**McRtData\_BkPlcMc\_PosError:** The lag error.

**McRtData\_BkPlcMc\_SetAcceleration:** The current set acceleration value.

**McRtData\_BkPlcMc\_SetOverride:** The current override value.

**McRtData\_BkPlcMc\_SetPosition:** The current set position value.

**McRtData\_BkPlcMc\_SetPressure:** The setpoint for pressure or force regulators.

**McRtData\_BkPlcMc\_SetVelocity:** The current set velocity value.

**McRtData\_BkPlcMc\_SupplyPressure:** The actual supply pressure value.

**McRtData\_BkPlcMc\_RawPosition:** The actual position, which was not manipulated through a zero shift.

**McRtData\_BkPlcMc\_ReloadParams:** For parameter changes through the runtime: A request to the PlcMcManager to re-read the parameters.

**McRtData\_BkPlcMc\_TargetPos:** The last commanded target position of the axis.   
This position is not changed by a Stop command.

**McRtData\_BkPlcMc\_ValvePressure:** The pressure drop at the valve.

**McRtData\_BkPlcMc\_Active\_Area\_M:** With hybrid axes: The active area currently acting in the negative direction.

**McRtData\_BkPlcMc\_Active\_Area\_P:** With hybrid axes: The active area currently acting in the positive direction.

**McRtData\_BkPlcMc\_Active\_Feed\_M:** With hybrid axes: The feed constant currently acting in the negative direction.

**McRtData\_BkPlcMc\_Active\_Feed\_P:** With hybrid axes: The feed constant currently acting in the positive direction.

**McRtData\_BkPlcMc\_Active\_N\_max:** With hybrid axes: The current speed limitation for the pump.

**McRtData\_BkPlcMc\_Active\_Qmax\_M:** With hybrid axes: The current delivery rate of the pump acting in the negative direction.

**McRtData\_BkPlcMc\_Active\_Qmax\_P:** With hybrid axes: The current delivery rate of the pump acting in the positive direction.

**McRtData\_BkPlcMc\_Active\_Vmax\_M:** With hybrid axes: The current maximum velocity in the negative direction.

**McRtData\_BkPlcMc\_Active\_Vmax\_P:** With hybrid axes: The current maximum velocity in the positive direction.

**McRtData\_BkPlcMc\_Motor\_N\_max:** With hybrid axes: The speed limitation for the pump drive.

**McRtData\_BkPlcMc\_Pump\_Angle:** With hybrid axes: The actual pump angle.

**McRtData\_BkPlcMc\_Pump\_AreaSwitched:** With hybrid axes: The status of the area switching.

**McRtData\_BkPlcMc\_Pump\_ModuloAngle:** With hybrid axes: The actual pump angle within the current revolution.

**McRtData\_BkPlcMc\_Pump\_Speed:** With hybrid axes: The actual pump speed.

**McRtData\_BkPlcMc\_Pump\_Switched:** With hybrid axes: The status of the pump switching.

**McRtData\_BkPlcMc\_Pump\_Torque:** With hybrid axes: The actual torque of the pump drive.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
