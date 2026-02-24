# ST_LON_SNVT_scene

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_scene

Used by: SNVT\_scene

```
TYPE ST_LON_SNVT_scene :  
STRUCT  
  eFunction      : E_LON_Scene_t;  
  byScene_number : BYTE;  
END_STRUCT  
END_TYPE
```

**eFunction:** Scene control function (scene control function names) (see [E\_LON\_Scene\_t](ms-xhelp:///?Id=beckhoff-217c-4a48-9fe5-7bae8cfbda6a)).

**byScene\_number:** Min: 0 / Max: 255 / Scene number.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
