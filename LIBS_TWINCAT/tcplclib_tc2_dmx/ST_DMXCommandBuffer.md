# ST_DMXCommandBuffer

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_DMXCommandBuffer

```
TYPE ST_DMXCommandBuffer :  
STRUCT  
  arrMessageQueue     : ST_DMXMessageQueue;  
  stResponseTable     : ST_DMXResponseTable;  
  byTransactionNumber : BYTE;  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
