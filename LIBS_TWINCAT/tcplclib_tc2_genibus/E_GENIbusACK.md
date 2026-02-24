# E_GENIbusACK

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# E\_GENIbusACK

ACK (Acknowledge-Code) from the response telegram.

```
TYPE E_GENIbusACK :  
(  
  eGENIbusACKOk           := 0,  
  eGENIbusACKUnknownClass := 1,  
  eGENIbusACKUnknownId    := 2,  
  eGENIbusACKIllegalOp    := 3  
);  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
