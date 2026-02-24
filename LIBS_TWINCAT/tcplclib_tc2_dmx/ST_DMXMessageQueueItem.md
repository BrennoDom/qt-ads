# ST_DMXMessageQueueItem

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_DMXMessageQueueItem

```
TYPE ST_DMXMessageQueueItem :  
STRUCT  
  bEntryIsEngaged             : BOOL;  
  byMessageLength             : BYTE;  
  wDestinationManufacturerID  : WORD;  
  dwDestinationDeviceID       : DWORD;  
  byTransactionNumber         : BYTE;  
  byPortID                    : BYTE;  
  byMessageCount              : BYTE;  
  wSubDevice                  : WORD;  
  byCommandClass              : BYTE;  
  wParameterID                : WORD;  
  byParameterDataLength       : BYTE;  
  arrParameterData            : ARRAY [0..255] OF BYTE;  
  bWaitingForDMXSlaveResponse : BOOL;  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
