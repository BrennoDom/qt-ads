# ST_LON_range

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_range

Used by: SNVT\_ctrl\_resp

```
TYPE ST_LON_range :  
STRUCT  
  uiLower : UINT;  
  uiUpper : UINT;  
END_STRUCT  
END_TYPE
```

**uiLower:** Min: 1 / Max: 65535 / Invalid: 65535 / Sender range lower ID (ID number).

**uiUpper:** Min: 1 / Max: 65535 / Invalid: 65535 / Sender range upper ID (ID number).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
