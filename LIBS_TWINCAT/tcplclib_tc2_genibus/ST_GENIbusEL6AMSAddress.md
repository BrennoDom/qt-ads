# ST_GENIbusEL6AMSAddress

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusEL6AMSAddress

Structure for linking in the input process image. The structure should be used for communication of an EL6xxx terminal.

```
TYPE ST_GENIbusEL6AMSAddress :  
STRUCT  
  arrNetId : ARRAY[0..5] OF USINT;  
  uiPort   : UINT;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
