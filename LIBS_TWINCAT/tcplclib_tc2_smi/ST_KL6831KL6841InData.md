# ST_KL6831KL6841InData

## Library
tcplclib_tc2_smi

## Category
Motion Control

# ST\_KL6831KL6841InData

```
TYPE ST_KL6831KL6841InData :  
STRUCT  
  wStateWord : WORD;  
  arrData    : ARRAY [0..21] OF BYTE;  
END_STRUCT  
END_TYPE
```

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
