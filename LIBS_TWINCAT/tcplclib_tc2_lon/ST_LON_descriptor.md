# ST_LON_descriptor

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_descriptor

Used by: SNVT\_file\_status

```
TYPE ST_LON_descriptor :  
STRUCT  
  sFile_info : STRING(16);  
  udiSize    : UDINT;  
  uiType     : UINT;  
END_STRUCT  
END_TYPE
```

**sFile\_info:** File info (array of 16 characters)

**udiSize:** Min: 0 / Max: 2147483647 / Size (bytes)

**uiType:** Min: 0 / Max: 65535 / Type

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
