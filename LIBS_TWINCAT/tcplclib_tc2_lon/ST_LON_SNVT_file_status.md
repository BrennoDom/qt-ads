# ST_LON_SNVT_file_status

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_file\_status

Used by: SNVT\_file\_status

```
TYPE ST_LON_SNVT_file_status :  
STRUCT  
  eStatus           : E_LON_file_status_t;  
  uiNumber_of_files : UINT;  
  uiSelected_file   : UINT;  
END_STRUCT  
END_TYPE
```

**eStatus:** Status (file status names) (see [E\_LON\_file\_status\_t](ms-xhelp:///?Id=beckhoff-a24c-4b32-8def-205cb470393b)).

**uiNumber\_of\_files:** Min: 0 / Max: 65535 / Number of files (count).

**uiSelected\_file:** Min: 0 / Max: 65535 / Selected file (file index).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
