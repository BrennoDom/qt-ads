# ST_GENIbusPcComDeviceOut64B

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusPcComDeviceOut64B

Structure for linking in the input process image. The structure must be used for communication of a serial PC interface.

```
TYPE ST_GENIbusPcComDeviceOut64B :  
STRUCT  
  wCtrl   : WORD;  
  arrData : ARRAY[0..63] OF BYTE;  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
