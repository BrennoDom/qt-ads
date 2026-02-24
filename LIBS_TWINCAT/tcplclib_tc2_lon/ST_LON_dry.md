# ST_LON_dry

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_dry

Used by: SNVT\_clothes\_w\_c

```
TYPE ST_LON_dry :  
STRUCT  
  byTemp     : BYTE;  
  stDuration : ST_LON_Duration;  
END_STRUCT  
END_TYPE
```

**byTemp:** Min: 0 / Max: 1

**stDuration:** (see [ST\_LON\_Duration](ms-xhelp:///?Id=beckhoff-5e82-4ab5-b54c-ca577f29220e))

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
