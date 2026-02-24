# ST_SMIResponseTableItem

## Library
tcplclib_tc2_smi

## Category
Motion Control

# ST\_SMIResponseTableItem

```
TYPE ST_SMIResponseTableItem :  
STRUCT  
  arrResponseData      : ARRAY [0..7] OF BYTE;  
  byDataLength         : BYTE;  
  byIdentificationByte : BYTE;  
  udiMessageHandle     : UDINT;  
  udiErrorId           : UDINT;  
END_STRUCT  
END_TYPE
```

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
