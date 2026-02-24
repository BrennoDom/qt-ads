# E_EnOceanSensorType

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# E\_EnOceanSensorType

Sensor type.

```
TYPE E_EnOceanSensorType :  
(  
  eEnOceanSensorTypePTM      := 5,  
  eEnOceanSensorTypeSTM1Byte := 6,  
  eEnOceanSensorTypeSTM4Byte := 7,  
  eEnOceanSensorTypeCTM      := 8  
)  
END_TYPE
```

**eEnOceanSensorTypePTM:** PTM.

**eEnOceanSensorTypeSTM1Byte:** STM 1 Byte.

**eEnOceanSensorTypeSTM4Byte:** STM 4 Byte.

**eEnOceanSensorTypeCTM:** CTM.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
