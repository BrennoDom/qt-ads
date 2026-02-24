# ST_DMXParameterDescription

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_DMXParameterDescription

```
TYPE ST_DMXParameterDescription :  
STRUCT  
  byParameterDataLength : BYTE;  
  eDataType             : E_DMXDataType;  
  ePDCommandClass       : E_DMXParameterDescriptionCommandClass;  
  eType                 : E_DMXSensorType;  
  eUnit                 : E_DMXSensorUnit;  
  eUnitPrefix           : E_DMXSensorUnitPrefix;  
  dwMinValidValue       : DWORD;  
  dwMaxValidValue       : DWORD;  
  dwDefaultValue        : DWORD;  
  sDescription          : STRING;  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
