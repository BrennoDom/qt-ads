# ST_GENIbusKL6DeviceIn22B

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusKL6DeviceIn22B

Structure for linking in the input process image. The structure must be used for communication of a KL6xxx terminal with 22-byte process image.

```
TYPE ST_GENIbusKL6DeviceIn22B :  
STRUCT  
  wStatus : WORD;  
  arrData : ARRAY[0..21] OF BYTE;  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
