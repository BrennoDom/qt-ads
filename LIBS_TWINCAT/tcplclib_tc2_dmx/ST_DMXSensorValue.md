# ST_DMXSensorValue

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_DMXSensorValue

```
TYPE ST_DMXSensorValue :  
STRUCT  
  iPresentValue         : INT;  
  iLowestDetectedValue  : INT;  
  iHighestDetectedValue : INT;  
  iRecordedValue        : INT;  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
