# ST_DMXStatusMessage

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_DMXStatusMessage

```
TYPE ST_DMXStatusMessage :  
STRUCT  
  bEntryIsValid    : BOOL;  
  iSubDeviceId     : INT;  
  eStatusType      : E_DMXStatusType;  
  iStatusMessageId : INT;  
  iDataValue01     : INT;  
  iDataValue02     : INT;  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
