# ST_LON_wash

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_wash

Used by: SNVT\_clothes\_w\_c

```
TYPE ST_LON_wash :  
STRUCT  
  eLoad_level : E_LON_discrete_levels_t;  
  byTemp      : BYTE;  
  byTime      : BYTE;  
  ePrewash    : E_LON_boolean_t;  
END_STRUCT  
END_TYPE
```

**eLoad\_level:** (see [E\_LON\_discrete\_levels\_t](ms-xhelp:///?Id=beckhoff-665f-4791-9993-37c4356161ae))

**byTemp:** Min: 0 / Max: 255

**byTime:** Min: 0 / Max: 255

**ePrewash:** (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90))

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
