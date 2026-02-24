# ST_LON_SNVT_zerospan

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_zerospan

Used by: SNVT\_zerospan

```
TYPE ST_LON_SNVT_zerospan :  
STRUCT  
  rZero : REAL;  
  rSpan : REAL;  
END_STRUCT  
END_TYPE
```

**rZero:** Min: -163.840 / Max: 163.835 / Zero-term (16-bit signed value).

**rSpan:** Min: 0.0 / Max: 32.7675 / Span-factor (16-bit unsigned value).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
