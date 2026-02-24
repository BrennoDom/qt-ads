# E_DMXSensorType

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# E\_DMXSensorType

```
TYPE E_DMXSensorType :  
(  
  eDMXSensorTypeTemperature       := 16#00,  
  eDMXSensorTypeVoltage           := 16#01,  
  eDMXSensorTypeCurrent           := 16#02,  
  eDMXSensorTypeFrequency         := 16#03,  
  eDMXSensorTypeResistance        := 16#04,  
  eDMXSensorTypePower             := 16#05,  
  eDMXSensorTypeMass              := 16#06,  
  eDMXSensorTypeLength            := 16#07,  
  eDMXSensorTypeArea              := 16#08,  
  eDMXSensorTypeVolume            := 16#09,  
  eDMXSensorTypeDensity           := 16#0A,  
  eDMXSensorTypeVelocity          := 16#0B,  
  eDMXSensorTypeAcceleration      := 16#0C,  
  eDMXSensorTypeForce             := 16#0D,  
  eDMXSensorTypeEnergy            := 16#0E,  
  eDMXSensorTypePressure          := 16#0F,  
  eDMXSensorTypeTime              := 16#10,  
  eDMXSensorTypeAngle             := 16#11,  
  eDMXSensorTypePositionX         := 16#12,  
  eDMXSensorTypePositionY         := 16#13,  
  eDMXSensorTypePositionZ         := 16#14,  
  eDMXSensorTypeAngularVelocity   := 16#15,  
  eDMXSensorTypeLuminousIntensity := 16#16,  
  eDMXSensorTypeLuminousFlux      := 16#17,  
  eDMXSensorTypeIlluminance       := 16#18,  
  eDMXSensorTypeChrominanceRed    := 16#19,  
  eDMXSensorTypeChrominanceGreen  := 16#1A,  
  eDMXSensorTypeChrominanceBlue   := 16#1B,  
  eDMXSensorTypeContacts          := 16#1C,  
  eDMXSensorTypeMemory            := 16#1D,  
  eDMXSensorTypeItems             := 16#1E,  
  eDMXSensorTypeHumidity          := 16#1F,  
  eDMXSensorTypeCounter16Bit      := 16#20,  
  eDMXSensorTypeOther             := 16#7F  
);  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
