# ST_EL6851InDataEx

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_EL6851InDataEx

```
TYPE ST_EL6851InDataEx :  
STRUCT  
  bTransmitAccepted  : BOOL;  
  bReceiveToggle     : BOOL;  
  bCyclicTxDDisabled : BOOL;  
  bDefaultDataSent   : BOOL;  
  bFrameSentToggle   : BOOL;  
  bTxPDOToggle       : BOOL;  
  wChannelLength     : WORD;  
  byStartCode        : BYTE;  
  byDummy1           : BYTE;  
  arrData            : ARRAY [1..64] OF BYTE;  
  bWcState           : BOOL;  
  bInputToggle       : BOOL;  
  uiState            : UINT;  
  stAdsAddr          : ST_EL6851AdsAddr;  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
