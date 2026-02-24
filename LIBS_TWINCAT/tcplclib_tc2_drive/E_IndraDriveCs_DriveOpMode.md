# E_IndraDriveCs_DriveOpMode

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [IndraDrive Cs](ms-xhelp:///?Id=beckhoff-aad7-4312-ad09-5757e62b4866)
4. E\_IndraDriveCs\_DriveOpMode

# E\_IndraDriveCs\_DriveOpMode

```
TYPE E_IndraDriveCs_DriveOpMode : (  
    eIDC_NoModeOfOperation := 0,  
    eIDC_TorqueCtrl        := 1,  
    eIDC_VeloCtrl          := 2,  
  
    eIDC_PosCtrlFbk1        := 3,  
    eIDC_PosCtrlFbk2        := 4,  
    eIDC_PosCtrlFbk1LagLess := 11,  
    eIDC_PosCtrlFbk2LagLess := 12,  
  
    eIDC_DrvInternInterpolFbk1        := 19,  
    eIDC_DrvInternInterpolFbk2        := 20,  
    eIDC_DrvInternInterpolFbk1LagLess := 27,  
    eIDC_DrvInternInterpolFbk2LagLess := 28,  
  
    eIDC_PosBlockModeFbk1        := 51,  
    eIDC_PosBlockModeFbk2        := 52,  
    eIDC_PosBlockModeFbk1LagLess := 59,  
    eIDC_PosBlockModeFbk2LagLess := 60,  
  
    eIDC_PosCtrlDrvCtrldFbk1        := 259,  
    eIDC_PosCtrlDrvCtrldFbk2        := 260,  
    eIDC_PosCtrlDrvCtrldFbk1LagLess := 267,  
    eIDC_PosCtrlDrvCtrldFbk2LagLess := 268,  
  
    eIDC_DrvCtrldPositioningFbk1        := 531,  
    eIDC_DrvCtrldPositioningFbk2        := 532,  
    eIDC_DrvCtrldPositioningFbk1LagLess := 539,  
    eIDC_DrvCtrldPositioningFbk2LagLess := 540,  
  
    eIDC_CamFbk1VirtMaster        := -30717,  
    eIDC_CamFbk2VirtMaster        := -30716,  
    eIDC_CamFbk1VirtMasterLagLess := -30709,  
    eIDC_CamFbk2VirtMasterLagLess := -30708,  
  
    eIDC_CamFbk1RealMaster        := -30701,  
    eIDC_CamFbk2RealMaster        := -30700,  
    eIDC_CamFbk1RealMasterLagLess := -30693,  
    eIDC_CamFbk2RealMasterLagLess := -30692,  
  
    eIDC_PhaseSyncFbk1VirtMaster        := -28669,  
    eIDC_PhaseSyncFbk2VirtMaster        := -28668,  
    eIDC_PhaseSyncFbk1VirtMasterLagLess := -28661,  
    eIDC_PhaseSyncFbk2VirtMasterLagLess := -28660,  
  
    eIDC_PhaseSyncFbk1RealMaster        := -28653,  
    eIDC_PhaseSyncFbk2RealMaster        := -28652,  
    eIDC_PhaseSyncFbk1RealMasterLagLess := -28645,  
    eIDC_PhaseSyncFbk2RealMasterLagLess := -28644,  
  
    eIDC_VeloSyncVirtMaster := -24574,  
    eIDC_VeloSyncRealMaster := -24558,  
  
    eIDC_MotionProfileFbk1VirtMaster        := -26621,  
    eIDC_MotionProfileFbk2VirtMaster        := -26620,  
    eIDC_MotionProfileLagLessFbk1VirtMaster := -26613,  
    eIDC_MotionProfileLagLessFbk2VirtMaster := -26612,  
  
    eIDC_MotionProfileFbk1RealMaster        := -26605,  
    eIDC_MotionProfileFbk2RealMaster        := -26604,  
    eIDC_MotionProfileLagLessFbk1RealMaster := -26597,  
    eIDC_MotionProfileLagLessFbk2RealMaster := -26596,  
  
    eIDC_PosCtrlDrvCtrld     := 773,  
    eIDC_DrvCtrldPositioning := 533,  
    eIDC_PosBlockMode        := 565,  
    eIDC_VeloSynchronization := 66,  
  
    eIDC_PosSynchronization := 581  
  
);  
  
END_TYPE
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
