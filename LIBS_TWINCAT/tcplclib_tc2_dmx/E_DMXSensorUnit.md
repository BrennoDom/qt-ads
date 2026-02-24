# E_DMXSensorUnit

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# E\_DMXSensorUnit

```
TYPE E_DMXSensorUnit :  
(  
  eDMXSensorUnitNone                     := 16#00,  
  eDMXSensorUnitCentigrade               := 16#01,  
  eDMXSensorUnitVoltsDC                  := 16#02,  
  eDMXSensorUnitVoltsACPeak              := 16#03,  
  eDMXSensorUnitVoltsACRms               := 16#04,  
  eDMXSensorUnitAmpereDC                 := 16#05,  
  eDMXSensorUnitAmpereACPeak             := 16#06,  
  eDMXSensorUnitAmpereACRms              := 16#07,  
  eDMXSensorUnitHertz                    := 16#08,  
  eDMXSensorUnitOhm                      := 16#09,  
  eDMXSensorUnitWatt                     := 16#0A,  
  eDMXSensorUnitKilogram                 := 16#0B,  
  eDMXSensorUnitMeters                   := 16#0C,  
  eDMXSensorUnitMetersSquared            := 16#0D,  
  eDMXSensorUnitMetersCubed              := 16#0E,  
  eDMXSensorUnitKilogrammesPerMeterCubed := 16#0F,  
  eDMXSensorUnitMetersPerSecond          := 16#10,  
  eDMXSensorUnitMetersPerSecondSquared   := 16#11,  
  eDMXSensorUnitNewton                   := 16#12,  
  eDMXSensorUnitJoule                    := 16#13,  
  eDMXSensorUnitPascal                   := 16#14,  
  eDMXSensorUnitSecond                   := 16#15,  
  eDMXSensorUnitDegree                   := 16#16,  
  eDMXSensorUnitSteradian                := 16#17,  
  eDMXSensorUnitCandela                  := 16#18,  
  eDMXSensorUnitLumen                    := 16#19,  
  eDMXSensorUnitLux                      := 16#1A,  
  eDMXSensorUnitIre                      := 16#1B,  
  eDMXSensorUnitByte                     := 16#1C  
);  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
