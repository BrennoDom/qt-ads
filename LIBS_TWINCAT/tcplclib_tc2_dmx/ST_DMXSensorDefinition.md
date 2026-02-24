# ST_DMXSensorDefinition

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_DMXSensorDefinition

```
TYPE ST_DMXSensorDefinition :  
STRUCT  
  eSensorType          : E_DMXSensorType;  
  eSensorUnit          : E_DMXSensorUnit;  
  eSensorUnitPrefix    : E_DMXSensorUnitPrefix;  
  iRangeMinimumValue   : INT;  
  iRangeMaximumValue   : INT;  
  iNormalMinimumValue  : INT;  
  iNormalMaximumValue  : INT;  
  byRecordValueSupport : BYTE;  
  sDescription         : STRING;  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
