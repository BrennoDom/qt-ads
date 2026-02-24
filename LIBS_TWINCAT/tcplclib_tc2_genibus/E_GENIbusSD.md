# E_GENIbusSD

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# E\_GENIbusSD

SD (Start Delimiter) in the command or response telegram.

```
TYPE E_GENIbusSD :  
(  
  eGENIbusNull        := 16#0,  
  eGENIbusDatareply   := 16#24,  
  eGENIbusDatamessage := 16#26,  
  eGENIbusDatarequest := 16#27  
);  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
