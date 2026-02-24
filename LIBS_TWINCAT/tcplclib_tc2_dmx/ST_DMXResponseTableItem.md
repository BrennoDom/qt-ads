# ST_DMXResponseTableItem

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_DMXResponseTableItem

```
TYPE ST_DMXResponseTableItem :  
STRUCT  
  bEntryIsEngaged            : BOOL;  
  uiErrorId                  : UINT;  
  iErrorParameter            : INT;  
  byMessageLength            : BYTE;  
  wDestinationManufacturerID : WORD;  
  dwDestinationDeviceID      : DWORD;  
  wSourceManufacturerID      : WORD;  
  dwSourceDeviceID           : DWORD;  
  byTransactionNumber        : BYTE;  
  byResponseType             : BYTE;  
  byMessageCount             : BYTE;  
  wSubDevice                 : WORD;  
  byCommandClass             : BYTE;  
  wParameterID               : WORD;  
  byParameterDataLength      : BYTE;  
  arrParameterData           : ARRAY [0..255] OF BYTE;  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
