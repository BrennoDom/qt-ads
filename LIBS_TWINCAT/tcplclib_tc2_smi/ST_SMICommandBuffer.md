# ST_SMICommandBuffer

## Library
tcplclib_tc2_smi

## Category
Motion Control

# ST\_SMICommandBuffer

```
TYPE ST_SMICommandBuffer :  
STRUCT  
  arrMessageQueue  : ARRAY [0..2] OF ST_SMIMessageQueue;  
  stResponseTable  : ST_SMIResponseTable;  
  udiMessageHandle : UDINT;  
END_STRUCT  
END_TYPE
```

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
