# ST_DMXMessageQueue

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_DMXMessageQueue

```
TYPE ST_DMXMessageQueue :  
STRUCT  
  arrBuffer                    : ARRAY [1..20] OF ST_DMXMessageQueueItem;  
  byBufferReadPointer          : BYTE;  
  byBufferWritePointer         : BYTE;  
  byBufferDemandCounter        : BYTE;  
  byBufferMaximumDemandCounter : BYTE;  
  uiBufferOverflowCounter      : UINT;  
  bLockSemaphore               : BOOL;  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
