# ST_TcHydAxRtData (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcHydAxRtData (from V3.0)

# ST\_TcHydAxRtData (from V3.0)

The variables in this structure indicate the runtime state of the axis.

|  |  |
| --- | --- |
| 49381354 | The order of the data is not guaranteed. |

```
    TYPE ST_TcHydAxRtData :  
(* last modification: 02.07.2018 *)  
STRUCT  
 (*-------------------------------*)  
 fActForce:           LREAL := 0.0;  
 fActiveOverlap:      LREAL := 0.0;  
 fActPos:             LREAL := 0.0;  
 fActPosDelta:        LREAL := 0.0;  
 fActPosOffset:       LREAL := 0.0;  
 fActPressure:        LREAL := 0.0;  
 fActPressureA:       LREAL := 0.0;  
 fActPressureB:       LREAL := 0.0;  
 fActVelo:            LREAL := 0.0;  
 fBrakeOffTimer:      LREAL := 0.0;  
 fBrakeOnTimer:       LREAL := 0.0;  
 fBrakeSafetyTimer:   LREAL := 0.0;  
 fClampingOutput:     LREAL := 0.0;  
 fDestAcc:            LREAL := 0.0;  
 fDestCreepDistanceM: LREAL := 0.0;  
 fDestCreepDistanceP: LREAL := 0.0;  
 fDestCreepSpeedM:    LREAL := 0.0;  
 fDestCreepSpeedP:    LREAL := 0.0;  
 fDestDec:            LREAL := 0.0;  
 fDestJerk:           LREAL := 0.0;  
 fDestPos:            LREAL := 0.0;  
 fDestRampEnd:        LREAL := 0.0;  
 fDestSpeed:          LREAL := 0.0;  
 fDistanceToTarget:   LREAL := 0.0;  
 fEnc_RefShift:       LREAL := 0.0;  
 fEnc_ZeroSwap:       LREAL := 0.0;  
 fGearActive:         LREAL := 0.0;  
 fGearSetting:        LREAL := 0.0;  
 fLagCtrlOutput:      LREAL := 0.0;  
 fLatchedPos:         LREAL := 0.0;  
 fOilRequirred_A:     LREAL := 0.0;  
 fOilRequirred_B:     LREAL := 0.0;  
 fOilUsed_A:          LREAL := 0.0;  
 fOilUsed_B:          LREAL := 0.0;  
 fOutput:             LREAL := 0.0;  
 fOverride:           LREAL := 1.0;  
 fParamAccTime:       LREAL := 0.0;  
 fPosError:           LREAL := 0.0;  
 fSetAcc:             LREAL := 0.0;  
 fSetPos:             LREAL := 0.0;  
 fSetPressure:        LREAL := 0.0;  
 fSetSpeed:           LREAL := 0.0;  
 fSetSpeedOld:        LREAL := 0.0;  
 fSetVelo:            LREAL := 0.0;  
 fStartPos:           LREAL := 0.0;  
 fStartRamp:          LREAL := 0.0;  
 fStartRampAnchor:    LREAL := 0.0;  
 fSupplyPressure:     LREAL := 0.0;  
 fTargetPos:          LREAL := 0.0;  
 fTimerPEH:           LREAL := 0.0;  
 fTimerTPM:           LREAL := 0.0;  
 fValvePressure:      LREAL := 0.0;  
 fVeloError:          LREAL := 0.0;   
 fBlockDetectDelay:    LREAL := 2.0;  
 (*------------------------------------------------------*)  
 nAxisState:          DWORD := 0;  
 nCalibrationState:   DWORD := 0;  
 nDeCtrlDWord:        DWORD := 0;  
 nErrorCode:          DWORD := 0;  
 nStateDWord:         DWORD := 0;  
 udiAmpErrorCode:     UDINT;  
 (*------------------------------------------------------*)  
 iCurrentStep: E_TcMcCurrentStep;  
 wEncErrMask:         WORD:=0;  
 wEncErrMaskInv:      WORD:=0;  
 nDrvWcCount:         INT:=0;  
 (**)  
 nEncWcCount:         INT:=0;  
 nDrvDeviceState:     UINT:=0;  
 nEncDeviceState:     INT:=0;  
 (*------------------------------------------------------*)  
 bActPosCams:         BYTE := 0;  
 bBrakeOff:           BOOL := FALSE;  
 bBrakeOffInverted:   BOOL := FALSE;  
 bControllable:       BOOL := FALSE;  
 bCountedCycles:      BYTE := 1;  
 bCycleCounter:       BYTE := 0;  
 bDriveResponse:      BOOL := FALSE;  
 bEncDoLatch:         BOOL := FALSE;  
 (**)  
 bEncoderResponse:    BOOL := FALSE;  
 bEncLatchValid:      BOOL := FALSE;  
 bLocked_Estop:       BOOL := FALSE;  
 bParamsUnsave:       BOOL := FALSE;  
 bReloadParams:       BOOL := FALSE;  
 bTargeting:          BOOL := FALSE;  
 bUnalignedOverlap:   BOOL := FALSE;  
 bActPosOffsetEnable: BOOL := FALSE; (* starting with 09.03.2015 *)  
 (**)  
 bDriveStartup:       BOOL := FALSE;  
 bEncAlignRefShift:   BOOL := FALSE;  
 bDrvWcsError:        BOOL := FALSE;  
 bEncWcsError:        BOOL := FALSE;  
 bFirstWcs:           BOOL := FALSE;  
 bChangeCount:        BYTE := 0;  
 bStartAutoIdent:     BOOL := FALSE;  
 bParamFileComplete:  BOOL := FALSE;   
 (*------------------------------------------------------*)  
 pMasterRtData:       POINTER TO BYTE;  
 pMasterParam:        POINTER TO BYTE;  
 (*------------------------------------------------------*)  
 udiSercDeviceID:     UDINT := 0;  
 uiSercBoxAddr:       UINT := 0;  
 uiSercPort:          UINT := 0;  
 (*------------------------------------------------------*)  
 stPosCtrlr: stbkplcinternal_cplxctrl;  
 stVeloCtrlr: stbkplcinternal_cplxctrl;  
 (*------------------------------------------------------*)  
 sTopBlockName:       STRING(87) := '';  
  
 stHybrid:           ST_TcHybridAxRtData;  
 (*------------------------------------------------------*)  
END_STRUCT  
END_TYPE
```

**bActPosCams**: The current position cam of the axis. This value is only used, if iTcMc\_EncoderDigCam is set as encoder type.

**bActPosOffsetEnable**: A TRUE in this variable activates actual value influencing. See also under **fActPosOffset**.

**bBrakeOff**: The control signal for an external brake. An output variable of the profile generators.

**bBrakeOffInverted**: The inverted **bBrakeOff** signal.

**bChangeCount**: This value is incremented with each parameter change.

**bEncAlignRefShift**: Reserved.

**bEncDoLatch**: This signal is used for communication by the [MC\_Home\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1b39-4911-8ef7-a4d128653cfd) and [MC\_AxRtEncoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) function blocks of the axis during homing.

**bEncLatchValid**: This signal is used for communication by the [MC\_Home\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1b39-4911-8ef7-a4d128653cfd) and [MC\_AxRtEncoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) function blocks of the axis during homing.

**bLocked\_Estop**: A TRUE in this variable prevents the control value generators from exiting the state iTcHydStateEmergencyBreak / McState\_Errorstop, despite the fact that the drive outputs are reduced to 0. Used by [MC\_EmergencyStop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b20e-4907-bca3-7e0069a79051) and [MC\_ImediateStop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-a719-4119-90f6-ffe5dfef2115).

**bParamFileComplete:** This flag is set if a corresponding identifier was found at the end of the file when the parameters were loaded and the CRC check was successful.

**bParamsUnsave**: The function blocks [MC\_WriteParameter\_BkPlcMc](ms-xhelp:///?Id=beckhoff-37ac-4014-b387-f8451c1ea86a) and [MC\_WriteBoolParameter\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0385-4ba1-91ad-2fe61a251600) set this flag if they change a parameter value. An [MC\_AxParamSave\_BkPlcMc](ms-xhelp:///?Id=beckhoff-aaf6-41ce-bb18-a1a64bda1099) function block clears the flag when the parameters are successfully saved. In online mode of the [PlcMcManager](ms-xhelp:///?Id=beckhoff-608b-4730-aaaf-88380a952170), this flag is used for the status display.

**bStartAutoIdent:**

**bUnalignedOverlap:** The characteristic of the overlap compensation is defined here.

**fActForce**: [N, kN] Actual force of the cylinder. This value is usually determined by an acquisition function block for acquisition of [actual force or pressure values](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188).

**fActiveOverlap**: [1] The current output of the overlap compensation. An output variable of the profile generators.

**fActPos**: [mm] The current actual position of the axis. This value is usually determined by an encoder function block.

**fActPosOffset**: [mm] The offset used to influence the actual value. If **bActPosOffsetEnable** is TRUE, this offset is added to **fActPos**. If **fActPosOffset** changes, **fActVelo** is unaffected.

If **bActPosOffsetEnable** is TRUE, **fActPosOffset** takes effect immediately and without ramp.

|  |  |
| --- | --- |
| 41779002 | If actual value influencing is active during homing, bActPosOffset is taken into account when the actual position is set. |

Sample: If the reference position is 100.0 mm and the offset is 1.0 mm, the actual position at the point of the zero pulse is set to 101.0 mm. If influencing is subsequently deactivated or set to 0.0, the actual position at the point of the zero pulse shows the value 100.0, just like it would have done during homing without influencing.

|  |  |
| --- | --- |
| 40466701 | This function is only implemented for the following encoder types: iTcMc\_EncoderCoE\_DS406, iTcMc\_EncoderEL3255, iTcMc\_EncoderSim, iTcMc\_EncoderEL5101, iTcMc\_EncoderKL5101, iTcMc\_EncoderKL5111, iTcMc\_EncoderEL5001, iTcMc\_EncoderKL5001, iTcMc\_EncoderKL3002, iTcMc\_EncoderEL3102, iTcMc\_EncoderKL3042, iTcMc\_EncoderKL3062, iTcMc\_EncoderEL3142, iTcMc\_EncoderEM8908\_A, iTcMc\_EncoderEL3162, iTcMc\_EncoderKL3162. |

|  |  |
| --- | --- |
| 28655997 | If one of the types listed is set for an for an I/O device that is compatible with one of these types, the function described is also realized. |

**fActPosDelta:** [mm] The change of the actual position relative to the previous cycle.

**fActPressure**: [bar] Actual pressure in the cylinder. This value is usually determined by an acquisition function block for acquisition of [actual force or pressure values](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188).

**fActPressureA**: [bar] Actual pressure on the A-side of the cylinder. This value is usually determined by an acquisition function block for acquisition of [actual force or pressure values](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188).

**fActPressureB**: [bar] Actual pressure on the B-side of the cylinder. This value is usually determined by an acquisition function block for acquisition of [actual force or pressure values](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188).

**fActVelo**: [mm/s] The current actual velocity of the axis. This value is usually determined by an encoder function block.

**fBlockDetectDelay**: [s] The delay time for the detection of the function block during homing on block. This value is initialized with 2.0 seconds to reflect the default behavior of previous versions. If a different time is required, it must be updated before homing commences. If a value of less than the cycle time is detected when homing commences, the default value of 2.0 seconds is entered automatically. This value is not saved as a parameter. This variable has been available under TC2 in V3.0.41 from 12 October 2017.

**fClampingOutput**: [V] An output variable of the profile generators.

**fDestAcc**: [mm/s2] The acceleration specified by the current or last executed motion command.

**fDestCreepDistance**: [mm] Up to V3.0.7: The creep distance.

**fDestCreepSpeed**: [mm/s] Up to V3.0.7: The creep speed.

**fDestCreepDistanceP**: [mm] From V3.0.8: The creep distance in positive direction.

**fDestCreepSpeedP**: [mm/s] From V3.0.8: The creep speed in positive direction.

**fDestCreepDistanceM**: [mm] From V3.0.8: The creep distance in negative direction.

**fDestCreepSpeedM**: From V3.0.8: The creep speed in negative direction.

**fDestDec**: [mm/s2] The deceleration specified by the current or last executed motion command.

**fDestJerk**: [mm/s3] The jerk specified by the current or last executed motion command.

**fDestPos**: [mm] The currently active target position.

**fDestSpeed**: [mm/s] The velocity specified by the current or last executed motion command.

**fDistanceToTarget**: [mm] The current remaining distance of the axis. This value is usually determined by a generator function block.

**fEnc\_RefShift**: [mm] The offset between the converted (perhaps internal extended) counter value of an incremental encoder input terminal and the actual position of the axis. This offset is determined through homing, e.g. with an [MC\_Home\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1b39-4911-8ef7-a4d128653cfd) function block, or manipulated with an [MC\_SetPosition\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f65a-4c39-bec9-11940d456eda) function block.

**fLatchedPos**: [mm] The position (taking into account current offsets) at which homing took place or where the components of the actual value acquisition (encoder, I/O electronics) were switched on.

**fLagCtrlOutput**: [1] The normalized output of the position controller. An output variable of the profile generators.

**fOilRequirred\_A**: [l/min] The oil consumption on the A-side, calculated taking into account the set velocity.

**fOilRequirred\_B**: [l/min] The oil consumption on the B-side, calculated taking into account the set velocity.

**fOilUsed\_A**: [l/min] The oil consumption on the A-side, calculated taking into account the actual velocity.

**fOilUsed\_B**: [l/min] The oil consumption on the B-side, calculated taking into account the actual velocity.

**fOutput**: [1] The control value to be output. This variable is used for communication between the [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) and [MC\_AxRtDrive\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) function blocks.

**fOverride**: [1] The current axis velocity override.

**fPosError**: [mm] The current position error of the axis.

**fSetPos**: [mm] The current position command value of the axis.

**fSetSpeed**: [mm/s] The normalized set velocity of the axis. An output variable of the profile generators.

**fSetAcc**: [mm/s2] The current acceleration control value. An output variable of the profile generators.

**fSetPressure**: [bar] The setpoint for an optional pressure or force control must be stored here.

**fStartPos**: [mm] The start position of the current or last processed motion command.

**fSupplyPressure**: [bar] Supply pressure. This value is usually determined by an acquisition function block for acquisition of [actual force or pressure values](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188).

**fTargetPos**: [mm] The target position specified by the current or last processed motion command.

**fValvePressure**: [bar] Pressure drop at the valve. This value is usually determined by an acquisition function block for acquisition of [actual force or pressure values](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188).

**iCurrentStep**: The internal state of the control value generators. Values from [E\_TcMcCurrentStep](ms-xhelp:///?Id=beckhoff-16b4-460f-9810-4e6a9be14841).

**nAxisState**: The motion state of the axis.

**nCalibrationState**: The current homing state.

**nDeCtrlDWord**: The [control signals](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) of the axis.

**nErrorCode**: The current [error code](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) of the axis.

**nStateDWord**: The [status signals](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) of the axis.

**sTopBlockName**: Most of the library function blocks called directly by application enter a debug ID here.

**wEncErrMask:**

**wEncErrMaskInv:**

**stHybrid:** Extended status data for servo-electric/hydraulic hybrid axes.

All other elements of this structure are reserved for internal use. They are not guaranteed and must not be used or modified by the application.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
