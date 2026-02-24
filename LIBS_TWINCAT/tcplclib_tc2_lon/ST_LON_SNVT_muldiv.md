# ST_LON_SNVT_muldiv

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_muldiv

Used by: SNVT\_muldiv

```
TYPE ST_LON_SNVT_muldiv :  
STRUCT  
  uiMultiplier : UINT;  
  uiDivisor    : UINT;  
END_STRUCT  
END_TYPE
```

**uiMultiplier:** Min: 0 / Max: 65535 / Multiplier (16-bit unsigned value).

**uiDivisor:** Min: 0 / Max: 65535 / Divisor (16-bit unsigned value).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
