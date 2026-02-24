# E_GENIbusActCtrlMode

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# E\_GENIbusActCtrlMode

The read-out current control mode.

```
TYPE E_GENIbusActCtrlMode :  
(  
  eGENIbusActCtrlModeUnknown    := 0,  
  eGENIbusActCtrlModeConstFreq  := 1,  
  eGENIbusActCtrlModeConstPress := 2,  
  eGENIbusActCtrlModePropPress  := 3,  
  eGENIbusActCtrlModeAutoAdapt  := 4  
);  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
