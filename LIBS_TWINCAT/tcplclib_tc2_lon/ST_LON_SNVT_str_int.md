# ST_LON_SNVT_str_int

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_str\_int

Used by: SNVT\_str\_int

```
TYPE ST_LON_SNVT_str_int :  
STRUCT  
  byChar_set   : BYTE;  
  arrWide_char : ARRAY[0..14] OF UINT;  
END_STRUCT  
END_TYPE
```

**byChar\_set:** Min: 0 / Max: 255 / Locale code (code value).

**arrWide\_char:** Min: 0 / Max: 65535 / Wide character string (array of 15 wide characters).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
