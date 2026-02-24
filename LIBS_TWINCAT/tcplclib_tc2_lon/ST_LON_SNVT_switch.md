# ST_LON_SNVT_switch

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_switch

Used by: SNVT\_switch

```
TYPE ST_LON_SNVT_switch :  
STRUCT  
  rValue  : REAL;  
  siState : SINT;  
END_STRUCT  
END_TYPE
```

**rValue:** Min: 0 / Max: 100 / Value (% of full level).

**siState:** Min: -1 / Max: 1 / State (state code). This field can either be -1 (NULL), 0 (OFF), or 1 (ON).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
