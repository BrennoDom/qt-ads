# ST_LON_duration

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_duration

Used by: SNVT\_clothes\_w\_c

```
TYPE ST_LON_duration :  
STRUCT  
  byTime   : BYTE;  
  eDryness : E_LON_discrete_levels_t;  
END_STRUCT  
END_TYPE
```

**byTime:** Min: 0 / Max: 255

**eDryness:** (see [E\_LON\_discrete\_levels\_t](ms-xhelp:///?Id=beckhoff-665f-4791-9993-37c4356161ae))

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
