# ST_LON_SNVT_file_pos

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_file\_pos

Used by: SNVT\_file\_pos

```
TYPE ST_LON_SNVT_file_pos :  
STRUCT  
  diRw_ptr    : DINT;  
  uiRw_length : UINT;  
END_STRUCT  
END_TYPE
```

**diRw\_ptr:** Min: 0 / Max: 2147483647 / Read/Write pointer (file byte address).

**uiRw\_length:** Min: 0 / Max: 65535 / Read/Write length (number of bytes).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
