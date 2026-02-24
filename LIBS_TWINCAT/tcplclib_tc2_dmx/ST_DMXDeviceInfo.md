# ST_DMXDeviceInfo

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_DMXDeviceInfo

```
TYPE ST_DMXDeviceInfo :  
STRUCT  
  uliUID               : ST_DMXMac;  
  stRDMProtocolVersion : ST_DMXRDMProtocolVersion;  
  uiDeviceModelId      : UINT;  
  stProductCategory    : ST_DMXProductCategory;  
  udiSoftwareVersionId : UDINT;  
  uiDMX512Footprint    : UINT;  
  stDMX512Personality  : ST_DMX512Personality;  
  uiDMX512StartAddress : UINT;  
  uiSubDeviceCount     : UINT;  
  bySensorCount        : BYTE;  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
