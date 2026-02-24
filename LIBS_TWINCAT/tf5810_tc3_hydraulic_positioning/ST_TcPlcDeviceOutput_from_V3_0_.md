# ST_TcPlcDeviceOutput (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcPlcDeviceOutput (from V3.0)

# ST\_TcPlcDeviceOutput (from V3.0)

This structure contains the output image variables of an axis.

```
TYPE ST_TcPlcDeviceOutput :  
STRUCT  
    nDacOut:          INT:=0;  
    bDigOutAp:        BOOL:=FALSE;  
    bDigOutAn:        BOOL:=FALSE;  
    bDigOutBp:        BOOL:=FALSE;  
    bDigOutBn:        BOOL:=FALSE;  
    uiCount:          UINT:=0;  
    uiDacOutA:        UINT:=0;  
    uiDacOutB:        UINT:=0;  
    bMovePos:         BOOL:=FALSE;  
    bMoveNeg:         BOOL:=FALSE;  
    bBrakeOff:        BOOL:=FALSE;  
    bBrakeOffInverted:BOOL:=FALSE;  
    DriveCtrl:        ARRAY [0..3] OF BYTE:=0;  
    NominalVelo:      DINT:=0;  
    uiDriveCtrl:      UINT:=0;  
    S_iReserve:       ARRAY [1..2] OF INT:=0;  
    S_DiReserve:      ARRAY [1..7] OF DINT:=0;  
    CiA_Reserve:      ARRAY [1..7] OF UINT:=0;  
    bPowerOn:         BOOL:=FALSE;  
    bEnable:          BOOL:=FALSE;  
    bEnablePos:       BOOL:=FALSE;  
    bEnableNeg:       BOOL:=FALSE;  
    nResetState:      BYTE:=0;  
    usiCtrl:          USINT:=0;  
    uiTerminalData:   WORD:=0;  
    bTerminalCtrl:    BYTE:=0;  
    uiTerminalCtrl2:  WORD:=0;  
    nReserve:         ARRAY [1..20] OF BYTE;  
END_STRUCT  
END_TYPE
```

**nDacOut**: Used for control value outputs or parameter communication. Used for **iTcMc\_EncoderKL2531**, **iTcMc\_EncoderKL2541**, **iTcMc\_DriveEL4132**, **iTcMc\_DriveKL2521**, **iTcMc\_DriveKL2531**, **iTcMc\_DriveKL2541**, **iTcMc\_DriveKL4032**, **iTcMc\_DriveM2400\_Dn**.

**bDigOutAp**: Used for control value output. Used for **iTcMc\_DriveLowCostStepper**.

**bDigOutAn**: Used for control value output. Used for **iTcMc\_DriveLowCostStepper**.

**bDigOutBp**: Used for control value output. Used for **iTcMc\_DriveLowCostStepper**.

**bDigOutBn**: Used for control value output. Used for **iTcMc\_DriveLowCostStepper**.

**uiCount**: Reserved.

**uiDacOutA**: Used for control value output. Used for **iTcMc\_EncoderIx2512\_1Coil**, **iTcMc\_EncoderIx2512\_2Coil**.

**uiDacOutB**: Used for control value output. Used for **iTcMc\_EncoderIx2512\_2Coil**.

**bMovePos** : Reserved.

**bMoveNeg** : Reserved.

**bBrakeOff**: Reserved.

**bBrakeOffInverted**: Reserved.

**DriveCtrl**: Used for device control signals. Used for **iTcMc\_EncoderAx2000\_B200**, **iTcMc\_DriveAx2000\_B200**, **iTcMc\_EncoderAx2000\_B900**, **iTcMc\_DriveAx2000\_B900**.

**NominalVelo**: Used for control value output. Used for **iTcMc\_DriveAx2000\_B110**, **iTcMc\_EncoderAx2000\_B200**, **iTcMc\_EncoderAx2000\_B900**.

**uiDriveCtrl**: Used for device control signals. Used for **iTcMc\_EncoderAx2000\_B110**, **iTcMc\_DriveAx2000\_B110**.

**S\_iReserve**: Reserved.

**S\_DiReserve**: Reserved.

**CiA\_Reserve**: Reserved.

**bPowerOn**: Optionally used for controlling a mains contactor. Used for **iTcMc\_DriveAx2000\_B110**, **iTcMc\_EncoderAx2000\_B200**, **iTcMc\_EncoderAx2000\_B900**.

**bEnable**: Reserved.

**bEnablePos**: Reserved.

**bEnableNeg**: Reserved.

**nResetState**: Reserved.

**usiCtrl**: Used for device control signals or parameter communication. Used for **iTcMc\_EncoderEL5101**, **iTcMc\_EncoderKL3002**, **iTcMc\_EncoderKL3042**, **iTcMc\_EncoderKL3062**, **iTcMc\_EncoderKL3162**, **iTcMc\_EncoderKL5101**, **iTcMc\_EncoderKL5111**, **iTcMc\_EncoderM3120**.

**uiTerminalData**: Used for parameter communication. Used for **iTcMc\_EncoderKL2521**, **iTcMc\_EncoderKL5001**, **iTcMc\_EncoderKL5101**, **iTcMc\_EncoderKL5111**, **iTcMc\_DriveEL4132**, **iTcMc\_DriveKL2521**, **iTcMc\_DriveKL4032**.

**bTerminalCtrl**: Used for parameter communication. Used for **iTcMc\_EncoderKL2521**, **iTcMc\_EncoderKL2531**, **iTcMc\_EncoderKL2541**, **iTcMc\_DriveEL4132**, **iTcMc\_DriveKL2521**, **iTcMc\_DriveKL2531**, **iTcMc\_DriveKL2541**, **iTcMc\_DriveKL4032**.

**uiTerminalCtrl2**: Used for device control signals. Used for **iTcMc\_EncoderKL2541**, **iTcMc\_DriveKL2531**, **iTcMc\_DriveKL2541**.

**nReserve**: Reserved.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
