# ST_EnOceanOutData

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# ST\_EnOceanOutData

Process image of the KL6021-0023 outputs.

Linked to the terminals in the System Manager.

```
TYPE ST_EnOceanOutData :  
STRUCT  
  nCtrl : BYTE;  
  nData : ARRAY[0..10] OF BYTE;  
END_STRUCT  
END_TYPE
```

**nCtrl:** Control byte.

**nData:** 11 bytes for the output data.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
