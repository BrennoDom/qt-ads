# E_DMXProductDetail

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# E\_DMXProductDetail

```
TYPE E_DMXProductDetail :  
(  
  eDMXProductDetailNotDeclared          := 16#0000,  
  eDMXProductDetailArc                  := 16#0001,  
  eDMXProductDetailMetalHalide          := 16#0002,  
  eDMXProductDetailIncandescent         := 16#0003,  
  eDMXProductDetailLED                  := 16#0004,  
  eDMXProductDetailFluroescent          := 16#0005,  
  eDMXProductDetailColdcathode          := 16#0006,  
  eDMXProductDetailElectroluminescent   := 16#0007,  
  eDMXProductDetailLaser                := 16#0008,  
  eDMXProductDetailFlashtube            := 16#0009,  
  eDMXProductDetailColorscroller        := 16#0100,  
  eDMXProductDetailColorwheel           := 16#0101,  
  eDMXProductDetailColorchange          := 16#0102,  
  eDMXProductDetailIrisDouser           := 16#0103,  
  eDMXProductDetailDimmingShutter       := 16#0104,  
  eDMXProductDetailProfileShutter       := 16#0105,  
  eDMXProductDetailBarndoorShutter      := 16#0106,  
  eDMXProductDetailEffectsDisc          := 16#0107,  
  eDMXProductDetailGoboRotator          := 16#0108,  
  eDMXProductDetailVideo                := 16#0200,  
  eDMXProductDetailSlide                := 16#0201,  
  eDMXProductDetailFilm                 := 16#0202,  
  eDMXProductDetailOilwheel             := 16#0203,  
  eDMXProductDetailLCDGate              := 16#0204,  
  eDMXProductDetailFoggerGlycol         := 16#0300,  
  eDMXProductDetailFoggerMineraloil     := 16#0301,  
  eDMXProductDetailFoggerWater          := 16#0302,  
  eDMXProductDetailCO2                  := 16#0303,  
  eDMXProductDetailLN2                  := 16#0304,  
  eDMXProductDetailBubble               := 16#0305,  
  eDMXProductDetailFlamePropane         := 16#0306,  
  eDMXProductDetailFlameOther           := 16#0307,  
  eDMXProductDetailOlefactoryStimulator := 16#0308,  
  eDMXProductDetailSnow                 := 16#0309,  
  eDMXProductDetailWaterJet             := 16#030A,  
  eDMXProductDetailWind                 := 16#030B,  
  eDMXProductDetailConfetti             := 16#030C,  
  eDMXProductDetailHazard               := 16#030D,  
  eDMXProductDetailPhaseControl         := 16#0400,  
  eDMXProductDetailReversePhaseControl  := 16#0401,  
  eDMXProductDetailSine                 := 16#0402,  
  eDMXProductDetailPWM                  := 16#0403,  
  eDMXProductDetailDC                   := 16#0404,  
  eDMXProductDetailHfballast            := 16#0405,  
  eDMXProductDetailHfhvNeonballast      := 16#0406,  
  eDMXProductDetailHfhvEl               := 16#0407,  
  eDMXProductDetailMhrBallast           := 16#0408,  
  eDMXProductDetailBitangleModulation   := 16#0409,  
  eDMXProductDetailFrequencyModulation  := 16#040A,  
  eDMXProductDetailHighfrequency12V     := 16#040B,  
  eDMXProductDetailRelayMechanical      := 16#040C,  
  eDMXProductDetailRelayElectronic      := 16#040D,  
  eDMXProductDetailSwitchElectronic     := 16#040E,  
  eDMXProductDetailContactor            := 16#040F,  
  eDMXProductDetailMirrorballRotator    := 16#0500,  
  eDMXProductDetailOtherRotator         := 16#0501,  
  eDMXProductDetailKabukiDrop           := 16#0502,  
  eDMXProductDetailCurtain              := 16#0503,  
  eDMXProductDetailLineset              := 16#0504,  
  eDMXProductDetailMotorControl         := 16#0505,  
  eDMXProductDetailDamperControl        := 16#0506,  
  eDMXProductDetailSplitter             := 16#0600,  
  eDMXProductDetailEthernetNode         := 16#0601,  
  eDMXProductDetailMerge                := 16#0602,  
  eDMXProductDetailDatapatch            := 16#0603,  
  eDMXProductDetailWirelessLink         := 16#0604,  
  eDMXProductDetailProtocolConvertor    := 16#0701,  
  eDMXProductDetailAnalogDemultiplex    := 16#0702,  
  eDMXProductDetailAnalogMultiplex      := 16#0703,  
  eDMXProductDetailSwitchPanel          := 16#0704,  
  eDMXProductDetailRouter               := 16#0800,  
  eDMXProductDetailFader                := 16#0801,  
  eDMXProductDetailMixer                := 16#0802,  
  eDMXProductDetailChangeoverManual     := 16#0900,  
  eDMXProductDetailChangeoverAuto       := 16#0901,  
  eDMXProductDetailTest                 := 16#0902,  
  eDMXProductDetailGfiRcd               := 16#0A00,  
  eDMXProductDetailBattery              := 16#0A01,  
  eDMXProductDetailControllableBreaker  := 16#0A02,  
  eDMXProductDetailOther                := 16#7FFF  
);  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
