# ST_LON_SNVT_privacyzone

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_privacyzone

Used by: SNVT\_privacyzone

```
TYPE ST_LON_SNVT_privacyzone :  
STRUCT  
  eAction     : E_LON_privacyzone_t;  
  byNumber    : BYTE;  
  uiCamera_id : UINT;  
END_STRUCT  
END_TYPE
```

**eAction:** Privacy zone action type (privacy zone action type names) (see [E\_LON\_privacyzone\_t](ms-xhelp:///?Id=beckhoff-46ea-4d89-8e93-4ddf4bd8593b)).

**byNumber:** Min: 0 / Max: 255 / Zone number (zone number).

**uiCamera\_id:** Min: 0 / Max: 65535 / Camera ID (ID number).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
