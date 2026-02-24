# E_GENIbusActOpMode

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# E\_GENIbusActOpMode

The read-out current operating mode.

```
TYPE E_GENIbusActOpMode :  
(  
  eGENIbusActOpModeUnknown := 0,  
  eGENIbusActOpModeStop    := 1,  
  eGENIbusActOpModeStart   := 2,  
  eGENIbusActOpModeMin     := 3,  
  eGENIbusActOpModeMax     := 4,  
  eGENIbusActOpModeHand    := 5,  
  eGENIbusActOpUserDef     := 6  
);  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
