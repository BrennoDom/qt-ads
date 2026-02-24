# E_DMXParameterId

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# E\_DMXParameterId

```
TYPE E_DMXParameterId :  
(  
  eDMXParameterIdNone                           := 16#0000,  
  eDMXParameterIdDiscUniqueBranch               := 16#0001,  
  eDMXParameterIdDiscMute                       := 16#0002,  
  eDMXParameterIdDiscUnMute                     := 16#0003,  
  eDMXParameterIdProxiedDevices                 := 16#0010,  
  eDMXParameterIdProxiedDeviceCount             := 16#0011,  
  eDMXParameterIdCommsStatus                    := 16#0015,  
  eDMXParameterIdQueuedMessage                  := 16#0020,  
  eDMXParameterIdStatusMessages                 := 16#0030,  
  eDMXParameterIdStatusIdDescription            := 16#0031,  
  eDMXParameterIdClearStatusId                  := 16#0032,  
  eDMXParameterIdSubDeviceStatusReportThreshold := 16#0033,  
  eDMXParameterIdSupportedParamaters            := 16#0050,  
  eDMXParameterIdParameterDescription           := 16#0051,  
  eDMXParameterIdDeviceInfo                     := 16#0060,  
  eDMXParameterIdProductDetailIdList            := 16#0070,  
  eDMXParameterIdDeviceModelDescription         := 16#0080,  
  eDMXParameterIdManufacturerLabel              := 16#0081,  
  eDMXParameterIdDeviceLabel                    := 16#0082,  
  eDMXParameterIdFactoryDefaults                := 16#0090,  
  eDMXParameterIdLanguageCapabilities           := 16#00A0,  
  eDMXParameterIdLanguage                       := 16#00B0,  
  eDMXParameterIdSoftwareVersionLabel           := 16#00C0,  
  eDMXParameterIdBootSoftwareVersionId          := 16#00C1,  
  eDMXParameterIdBootSoftwareVersionLabel       := 16#00C2,  
  eDMXParameterIdDMXPersonality                 := 16#00E0,  
  eDMXParameterIdDMXPersonalityDescription      := 16#00E1,  
  eDMXParameterIdDMXStartAddress                := 16#00F0,  
  eDMXParameterIdSlotInfo                       := 16#0120,  
  eDMXParameterIdSlotDescription                := 16#0121,  
  eDMXParameterIdDefaultSlotValue               := 16#0122,  
  eDMXParameterIdSensorDefinition               := 16#0200,  
  eDMXParameterIdSensorValue                    := 16#0201,  
  eDMXParameterIdRecordSensors                  := 16#0202,  
  eDMXParameterIdDeviceHours                    := 16#0400,  
  eDMXParameterIdLampHours                      := 16#0401,  
  eDMXParameterIdLampStrikes                    := 16#0402,  
  eDMXParameterIdLampState                      := 16#0403,  
  eDMXParameterIdLampOnMode                     := 16#0404,  
  eDMXParameterIdDevicePowerCycles              := 16#0405,  
  eDMXParameterIdDisplayInvert                  := 16#0500,  
  eDMXParameterIdDisplayLevel                   := 16#0501,  
  eDMXParameterIdPanInvert                      := 16#0600,  
  eDMXParameterIdTiltInvert                     := 16#0601,  
  eDMXParameterIdPanTiltSwap                    := 16#0602,  
  eDMXParameterIdRealTimeClock                  := 16#0603,  
  eDMXParameterIdIdentifyDevice                 := 16#1000,  
  eDMXParameterIdResetDevice                    := 16#1001,  
  eDMXParameterIdPowerState                     := 16#1010,  
  eDMXParameterIdPerformSelftest                := 16#1020,  
  eDMXParameterIdSelfTestDescription            := 16#1021,  
  eDMXParameterIdCapturePreset                  := 16#1030,  
  eDMXParameterIdPresetPlayBack                 := 16#1031  
);  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
