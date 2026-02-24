# ST_LON_Value

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_Value

Used by: SNVT\_pos\_ctrl

```
TYPE ST_LON_Value :  
STRUCT  
  byNumber : BYTE;  
  stAbspos : ST_LON_abspos;  
END_STRUCT  
END_TYPE
```

**byNumber:** Min: 0 / Max: 255 / Action number (action number).

**stAbspos:** Function absolute values (pan, tilt, zoom) (see [ST\_LON\_abspos](ms-xhelp:///?Id=beckhoff-05b1-46ae-badd-e301eed07c36)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
