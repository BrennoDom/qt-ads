# E_TcMcCurrentStep (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. E\_TcMcCurrentStep (from V3.0)

# E\_TcMcCurrentStep (from V3.0)

The constants in this list are used for identifying the internal states of the control value generators.

|  |  |
| --- | --- |
| 43395070 | Not all of these states are used by all control value generators. |

```
TYPE E_TcMcCurrentStep :(  
iTcHydStateIdle,  
iTcHydStateTcAccP,  
iTcHydStateTcAccM,  
iTcHydStatePcAccP,  
iTcHydStatePcAccM,  
iTcHydStateConstVeloP,  
iTcHydStateConstVeloM,  
iTcHydStatePcDecP,  
iTcHydStatePcDecM,  
iTcHydStateCreepVeloP,  
iTcHydStateCreepVeloM,  
iTcHydStateTcDecP,  
iTcHydStateTcDecM,  
iTcHydStateFeedStopPos,  
iTcHydStateFeedStopNeg,  
iTcHydStateDoBrake,  
iTcHydStateCoupling := 1000,  
iTcHydStateCoupled,  
iTcHydStateExtCoupled,  
iTcHydStateExtGenerated := 2000,  
iTcHydStateEmergencyBreak := 9000,  
iTcHydStateFault := 9999  
);  
END_TYPE
```

**iTcHydStateIdle:** The axis is not actively moving. Its behavior is controlled by ST\_TcHydAxParam.fLagAmp, ST\_TcHydAxParam.fTargetClamping and ST\_TcHydAxParam.fReposDistance.

**iTcHydStateTcAccP:** The axis establishes a positive control value according to ST\_TcHydAxRtData.fDestAcc. This value is set by one of the start function blocks according to the data of the travel command. This state is assumed when the control value reaches the specified motion control value. If the system detects that the braking process for the target approach has to be initiated, the state is changed to **iTcHydStatePcDecP**. In the absence of feed enable, the state is changed to **iTcHydStateFeedStopPos**.

**iTcHydStateTcAccM:** The axis establishes a negative control value according to ST\_TcHydAxRtData.fDestAcc. This value is set by one of the start function blocks according to the data of the travel command. This state is assumed when the control value reaches the specified motion control value. If the system detects that the braking process for the target approach has to be initiated, the state is changed to **iTcHydStatePcDecM**. In the absence of feed enable, the state is changed to **iTcHydStateFeedStopNeg**.

**iTcHydStatePcAccP:** The axis is in the displacement-controlled acceleration phase of a travelling motion in positive direction. The control value is set to a value specified by the travel command according to ST\_TcHydAxRtData.fDestAcc. The state then changes to **iTcHydStateConstVeloP**.

**iTcHydStatePcAccM:** The axis is in the displacement-controlled acceleration phase of a travelling motion in negative direction. The control value is set to a value specified by the travel command according to ST\_TcHydAxRtData.fDestAcc. The state then changes to **iTcHydStateConstVeloM**.

**iTcHydStateConstVeloP:** The axis travels in positive direction with constant control value. The control value is specified by the travel command.

**iTcHydStateConstVeloM:** The axis travels in negative direction with constant control value. The control value is specified by the travel command.

**iTcHydStatePcDecP:** The axis is in the displacement-controlled brake phase of a travelling motion in positive direction. The control value is reduced to ST\_TcHydAxParam.fCreepSpeed. The state then changes to **iTcHydStateCreepVeloP**.

**iTcHydStatePcDecM:** The axis is in the displacement-controlled brake phase of a travelling motion in negative direction. The control value is reduced to ST\_TcHydAxParam.fCreepSpeed. The state then changes to **iTcHydStateCreepVeloM**.

**iTcHydStateCreepVeloP:** The axis travels in positive direction with constant control value. The control value is specified by ST\_TcHydAxParam.fCreepSpeed.

**iTcHydStateCreepVeloM:** The axis travels in negative direction with constant control value. The control value is specified by ST\_TcHydAxParam.fCreepSpeed.

**iTcHydStateTcDecP:** The axis executes a regular stop, starting from a travelling motion in positive direction. The control value is reduced with ST\_TcHydAxParam.fStopRamp. The state then changes to **iTcHydStateIdle**.

**iTcHydStateTcDecM:** The axis executes a regular stop, starting from a travelling motion in negative direction. The control value is reduced with ST\_TcHydAxParam.fStopRamp. The state then changes to **iTcHydStateIdle**.

**iTcHydStateFeedStopPos:** The axis executes an intermediate stop, due to lack of feed enable in positive direction (dwTcHydDcDwFdPosEna is not set in ST\_TcHydAxRtData.nDeCtrlDWord). The control value is reduced with ST\_TcHydAxParam.fStopRamp. The axis then waits for a feed enable.

**iTcHydStateFeedStopNeg:** The axis executes an intermediate stop, due to lack of feed enable in negative direction (dwTcHydDcDwFdNegEna is not set in ST\_TcHydAxRtData.nDeCtrlDWord). The control value is reduced with ST\_TcHydAxParam.fStopRamp. The axis then waits for a feed enable.

**iTcHydStateDoBrake:** The axis executes a waiting time. This is necessary, if switching is required due to a brake or a switching valve.

**iTcHydStateCoupling:** The axis is in transition to state **iTcHydStateCoupled**.

**iTcHydStateCoupled:** The control value of the axis is derived from the control value of another axis based on the principle of electronic gearing.

**iTcHydStateExtCoupled**: The control value of the axis is calculated based on the principle of continuously variable transmission.

**iTcHydStateExtGenerated:** The control value of the axis is generated by an external block. This may be a library block or an application-specific block.

**iTcHydStateEmergencyBreak:** The axis executes an emergency stop. The control value is reduced with ST\_TcHydAxParam.fEmergencyRamp. The system then checks whether the axis is in an error state (ST\_TcHydAxRtData.nErrorCode not equal 0). If yes, the state is changed to **iTcHydStateFault**, otherwise **iTcHydStateIdle**.

**iTcHydStateFault:** The axis is in an error state. It does not carry out actively control movements and does not accept motion commands. To put the axis back in an undisturbed state, call a function block of type MC\_Reset\_BkPlcMc or MC\_ResetAndStop\_BkPlcMc.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
