# ST_EL6851OutData

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_EL6851OutData

```
TYPE ST_EL6851OutData :  
STRUCT  
  bTransmitRequest  : BOOL;  
  bDisableCyclicTxD : BOOL;  
  bSendDefaultData  : BOOL;  
  byDummy1          : BYTE;  
  wChannelLength    : WORD;  
  byStartCode       : BYTE;  
  byDummy2          : BYTE;  
  arrData           : ARRAY [1..512] OF BYTE;  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
