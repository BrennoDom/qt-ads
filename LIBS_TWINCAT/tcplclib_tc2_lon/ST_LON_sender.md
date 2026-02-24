# ST_LON_sender

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_sender

Used by: SNVT\_ctrl\_resp

```
TYPE ST_LON_sender :  
STRUCT  
  uiID    : UINT;  
  stRange : ST_LON_range;  
END_STRUCT  
END_TYPE
```

**uiID:** Min: 1 / Max: 65535 / Invalid: 65535 / Sender ID (ID number).

**stRange:** Sender ID range (lower, upper) (see [ST\_LON\_range](ms-xhelp:///?Id=beckhoff-2f9e-4e21-ba5e-2e79ff4700e6)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
