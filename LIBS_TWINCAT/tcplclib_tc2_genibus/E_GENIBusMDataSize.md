# E_GENIBusMDataSize

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# E\_GENIBusMDataSize

Bit size of the value to be read from the GENIbus device.

```
TYPE E_GENIBusMDataSize :  
(  
  eGENIbusMSize8Bit  := 0,  
  eGENIbusMSize16Bit := 1,  
  eGENIbusMSize24Bit := 2,  
  eGENIbusMSize32Bit := 3  
);  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
