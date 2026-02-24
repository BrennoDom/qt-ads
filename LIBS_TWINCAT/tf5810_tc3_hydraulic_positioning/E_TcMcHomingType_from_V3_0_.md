# E_TcMcHomingType (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. E\_TcMcHomingType (from V3.0)

# E\_TcMcHomingType (from V3.0)

The constants listed here are used to identify the referencing method of the axes.

```
TYPE E_TcMcHomingType :(  
iTcMc_HomingOnBlock,  
iTcMc_HomingOnIndex,  
iTcMc_HomingOnSync,  
iTcMc_HomingOnMultiSync,  
iTcMc_HomingOnExec  
);  
END_TYPE
```

**iTcMc\_HomingOnBlock**: The axis is moved in the direction specified by ST\_TcHydAxParam.bEnc\_RefIndexPositive with ST\_TcHydAxParam.fEnc\_RefIndexVelo. If no movement is detected over a period of 2 seconds, the fixed stop (block) is considered to have been reached. The actual value for the axis is set to the value of the reference position.

**iTcMc\_HomingOnIndex**: The axis is moved in the direction specified by ST\_TcHydAxParam.bEnc\_RefIndexPositive with ST\_TcHydAxParam.fEnc\_RefIndexVelo. The axis is stopped if the reference cam (bit 5, dwTcHydDcDwRefIndex) is detected in ST\_TcHydAxRtData.nDeCtrlDWord. It is then moved with ST\_TcHydAxParam.fEnc\_RefSyncVelo in the direction specified by ST\_TcHydAxParam.bEnc\_RefSyncPositive until the reference cam has again been left. The actual value for the axis is set to the value of the reference position.

**iTcMc\_HomingOnSync**: The axis is moved in the direction specified by ST\_TcHydAxParam.bEnc\_RefIndexPositive with ST\_TcHydAxParam.fEnc\_RefIndexVelo. The axis is stopped if the reference cam (bit 5, dwTcHydDcDwRefIndex) is detected in ST\_TcHydAxRtData.nDeCtrlDWord. It is then moved with ST\_TcHydAxParam.fEnc\_RefSyncVelo in the direction specified by ST\_TcHydAxParam.bEnc\_RefSyncPositive until the reference cam has again been left. The encoder's hardware latch is then activated, and the axis is moved on until the latch becomes valid. After the axis has stopped, the actual value for the axis is set to a value that is calculated from the reference position and from the distance covered since the encoder's sync pulse was detected.

**iTcMc\_HomingOnExec**: The actual value of the axis is immediately set to the value of the reference position.

**iTcMc\_HomingOnMultiSync**: The hardware latch of the encoder is activated. The axis is moved with ST\_TcHydAxParam.fEnc\_RefSyncVelo in the direction specified by ST\_TcHydAxParam.bEnc\_RefIndexPositive, until the latch has become valid twice. If the end of path is detected before two sync pulses were detected, the process is repeated in the opposite direction. If this does not succeed either, the homing is aborted. Otherwise the current actual position is determined from the distance of the sync pulses and the fEnc\_BaseDistance.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
