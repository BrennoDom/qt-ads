# ST_LON_addrt

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_addrt

Used by: SNVT\_file\_req

```
TYPE ST_LON_addrt :  
STRUCT  
  byType  : BYTE;  
  uiIndex : UINT;  
END_STRUCT  
END_TYPE
```

**byType:** Min: 0 / Max: 33 / Address type (8-bit unsigned value). The address-table address type is 33 (0x21).

**uiIndex:** Min: 0 / Max: 65535 / Address table index (16-bit unsigned value).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
