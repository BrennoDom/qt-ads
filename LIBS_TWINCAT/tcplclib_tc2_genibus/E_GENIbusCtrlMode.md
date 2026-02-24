# E_GENIbusCtrlMode

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# E\_GENIbusCtrlMode

Adjustable control modes.

```
TYPE E_GENIbusCtrlMode :  
(  
  eGENIbusCtrlModeUnknown    := 0,  
  eGENIbusCtrlModeConstFreq  := 1,  
  eGENIbusCtrlModeConstPress := 2,  
  eGENIbusCtrlModePropPress  := 3,  
  eGENIbusCtrlModeAutoAdapt  := 4  
);  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
