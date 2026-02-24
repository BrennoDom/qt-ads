# E_GENIbusComMode

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# E\_GENIbusComMode

Selection of the serial communication interface.

```
TYPE E_GENIbusComMode :  
(  
  eGENIbusComMode_Unknown := 0,  
  eGENIbusComMode_KL6_5B  := 1,  
  eGENIbusComMode_KL6_22B := 2,  
  eGENIbusComMode_EL6_22B := 3,  
  eGENIbusComMode_PC_64B  := 4  
);  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
