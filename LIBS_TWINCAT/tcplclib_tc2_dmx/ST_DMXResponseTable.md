# ST_DMXResponseTable

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_DMXResponseTable

```
TYPE ST_DMXResponseTable :  
STRUCT  
  arrResponseTable               : ARRAY [1..20] OF ST_DMXResponseTableItem;  
  byResponseTableCounter         : BYTE;  
  byResponseTableMaxCounter      : BYTE;  
  uiResponseTableOverflowCounter : UINT;  
  bLockSemaphore                 : BOOL;  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
