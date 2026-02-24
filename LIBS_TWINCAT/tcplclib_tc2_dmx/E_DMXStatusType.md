# E_DMXStatusType

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# E\_DMXStatusType

```
TYPE E_DMXStatusType :  
(  
  eDMXStatusTypeNone            := 16#00,  
  eDMXStatusTypeGetLastMessage  := 16#01,  
  eDMXStatusTypeAdvisory        := 16#02,  
  eDMXStatusTypeWarning         := 16#03,  
  eDMXStatusTypeError           := 16#04,  
  eDMXStatusTypeAdvisoryCleared := 16#12,  
  eDMXSensorTypeWarningCleared  := 16#13,  
  eDMXSensorTypeErrorCleared    := 16#14  
);  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
