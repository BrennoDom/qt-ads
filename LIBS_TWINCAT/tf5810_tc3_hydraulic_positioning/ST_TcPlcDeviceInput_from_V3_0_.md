# ST_TcPlcDeviceInput (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcPlcDeviceInput (from V3.0)

# ST\_TcPlcDeviceInput (from V3.0)

This structure contains the input image variables of an axis.

```
TYPE ST_TcPlcDeviceInput :  
STRUCT  
    uiCount:         UINT:=0;  
    uiLatch:         UINT:=0;  
    usiStatus:       USINT:=0;  
  
    uiPZDL_RegDaten: UINT:=0;  
    uiPZDH:          UINT:=0;  
    usiRegStatus:    USINT:=0;  
  
    udiCount:        UDINT:=0;  
    uiStatus:        UINT:=0;  
  
    bTerminalState:  BYTE:=0;  
    uiTerminalData:  WORD:=0;  
    uiTerminalState2:WORD:=0;  
  
    bDigInA:         BOOL:=FALSE;  
    bDigInB:         BOOL:=FALSE;  
  
    bDigCamMM:       BOOL:=FALSE;  
    bDigCamM:        BOOL:=FALSE;  
    bDigCamP:        BOOL:=FALSE;  
    bDigCamPP:       BOOL:=FALSE;  
  
    DriveError:      UDINT:=0;  
    ActualPos:       ARRAY [0..1] OF UINT:=0;  
    DriveState:      ARRAY [0..3] OF BYTE:=0;  
  
    S_iReserve:      INT:=0;  
    S_DiReserve:     ARRAY [1..9] OF DINT:=0;  
  
    CiA_Reserve:     ARRAY [1..8] OF UINT:=0;  
  
    bPowerOk:        BOOL:=FALSE;  
    bEnAck:          BOOL:=FALSE;  
  
    wDriveDevState:  WORD:=0;  
    wDriveWcState:   BYTE:=0;  
    wEncDevState:    WORD:=0;  
    wEncWcState:     BYTE:=0;  
    uiDriveBoxState: UINT:=0;  
    uiEncBoxState:   UINT:=0;  
  
    sEncAdsAddr:     ST_TcPlcAdsAddr;  
    nEncAdsChannel:  BYTE:=0;  
    sDrvAdsAddr:     ST_TcPlcAdsAddr;  
    nDrvAdsChannel:  BYTE:=0;  
  
    nReserve:        ARRAY [1..20] OF BYTE;  
END_STRUCT  
END_TYPE
```

**uiCount**: Used for position detection. Used for **iTcMc\_EncoderEL3102**, **iTcMc\_EncoderEL3142**, **iTcMc\_EncoderEL5101**, **iTcMc\_EncoderKL2521**, **iTcMc\_EncoderKL2531**, **iTcMc\_EncoderKL2541**, **iTcMc\_EncoderKL3002**, **iTcMc\_EncoderKL3042**, **iTcMc\_EncoderKL3062**, **iTcMc\_EncoderKL3162**, **iTcMc\_EncoderKL5101**, **iTcMc\_EncoderKL5111**, **iTcMc\_EncoderM2510**, **iTcMc\_EncoderM3120**, **iTcMc\_DriveKL2531**, **iTcMc\_DriveKL2541**.

**uiLatch**: Used for position detection. Used for **iTcMc\_EncoderEL5101**, **iTcMc\_EncoderKL5101**, **iTcMc\_EncoderKL5111**.

**usiStatus**: Used for device state information. Used for **iTcMc\_EncoderEL5101**, **iTcMc\_EncoderKL3002**, **iTcMc\_EncoderKL3042**, **iTcMc\_EncoderKL3062**, **iTcMc\_EncoderKL3162**, **iTcMc\_EncoderKL5101**, **iTcMc\_EncoderKL5111**, **iTcMc\_EncoderM3120**.

**uiPZDL\_RegDaten**: Used for position detection and parameter communication. Used for **iTcMc\_EncoderKL5001**.

**uiPZDH**: Used for position detection. Used for **iTcMc\_EncoderKL5001**.

**usiRegStatus**: Used for device state information. Used for **iTcMc\_EncoderEL5001**, **iTcMc\_EncoderKL5001**.

**udiCount**: Used for position detection. Used for **iTcMc\_EncoderEL5001**.

**uiStatus**: Used for device state information. Used for **iTcMc\_EncoderAx2000\_B110**, **iTcMc\_DriveAx2000\_B110**.

**bTerminalState**: Used for parameter communication. Used for **iTcMc\_EncoderKL2521**, **iTcMc\_EncoderKL2531**, **iTcMc\_EncoderKL2541**, **iTcMc\_DriveEL4132**, **iTcMc\_DriveKL2521**, **iTcMc\_DriveKL2531**, **iTcMc\_DriveKL2541**, **iTcMc\_DriveKL4032**.

**uiTerminalData**: Reserved.

**uiTerminalState2**: Used for position detection. Used for **iTcMc\_EncoderKL2541**.

**bDigInA**: Used for position detection. Used for **iTcMc\_EncoderDigIncrement**.

**bDigInB**: Used for position detection. Used for **iTcMc\_EncoderDigIncrement**.

**bDigCamMM**: Used for position detection. Used for **iTcMc\_EncoderDigCam**.

**bDigCamM**: Used for position detection. Used for **iTcMc\_EncoderDigCam**.

**bDigCamP**: Used for position detection. Used for **iTcMc\_EncoderDigCam**.

**bDigCamPP**: Used for position detection. Used for **iTcMc\_EncoderDigCam**.

**DriveError**: Used for device state information. Used for **iTcMc\_EncoderAx2000\_B200**, **iTcMc\_EncoderAx2000\_B900**.

**ActualPos**: Used for position detection. Used for **iTcMc\_EncoderAx2000\_B110**, **iTcMc\_EncoderAx2000\_B200**, **iTcMc\_EncoderAx2000\_B900**.

**DriveState**: Used for device state information. Used for **iTcMc\_EncoderAx2000\_B200**, **iTcMc\_EncoderAx2000\_B900**.

**nReserve**: Reserved.

**S\_iReserve**: Reserved.

**S\_DiReserve**: Reserved.

**CiA\_Reserve**: Reserved.

**bPowerOk**: Optionally used for monitoring of a mains contactor. Used for **iTcMc\_DriveAx2000\_B110**, **iTcMc\_EncoderAx2000\_B200**, **iTcMc\_EncoderAx2000\_B900**.

**bEnAck**: Reserved.

**wDriveDevState**: Reserved.

**wDriveWcState**: Used for monitoring the connection to the actuator. Used for **iTcMc\_EncoderAx2000\_B110**, **iTcMc\_DriveAx2000\_B110**.

**wEncDevState**: Reserved.

**wEncWcState**: Used for monitoring the connection to the encoder. Used for **iTcMc\_EncoderAx2000\_B110**, **iTcMc\_DriveAx2000\_B110**, **iTcMc\_EncoderEL3102**, **iTcMc\_EncoderEL3142**, **iTcMc\_EncoderEL5001**, **iTcMc\_EncoderEL5101**.

**uiDriveBoxState**: Used for monitoring the connection to the actuator. Used for **iTcMc\_DriveAx2000\_B200**, **iTcMc\_DriveAx2000\_B900**.

**uiEncBoxState**: Used for monitoring the connection to the encoder. Used for **iTcMc\_EncoderAx2000\_B200**, **iTcMc\_EncoderAx2000\_B900**.

**sEncAdsAddr**: Used for parameter communication. Used for **iTcMc\_EncoderAx2000\_B110**, **iTcMc\_DriveAx2000\_B110**, **iTcMc\_EncoderEL3102**, **iTcMc\_EncoderEL3142**, **iTcMc\_EncoderEL5001**, **iTcMc\_EncoderEL5101**.

**nEncAdsChannel**: Used for parameter communication. Used for **iTcMc\_EncoderAx2000\_B110**, **iTcMc\_DriveAx2000\_B110**.

**sDrvAdsAddr**: Used for parameter communication. Used for **iTcMc\_EncoderAx2000\_B110**, **iTcMc\_DriveAx2000\_B110**.

**nDrvAdsChannel**: Used for parameter communication. Used for **iTcMc\_EncoderAx2000\_B110**, **iTcMc\_DriveAx2000\_B110**.

**nReserve**: Reserved.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
