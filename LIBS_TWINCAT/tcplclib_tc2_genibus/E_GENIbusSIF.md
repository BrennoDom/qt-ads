# E_GENIbusSIF

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# E\_GENIbusSIF

SIF (Scale Information Format) in the response telegram.

```
TYPE E_GENIbusSIF :  
(  
  eGENIbusNoScaleInfo   := 0,  
  eGENIbusBitWiseScaled := 1,  
  eGENIbusScaled816     := 2,  
  eGENIbusScaledExt     := 3  
);  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
