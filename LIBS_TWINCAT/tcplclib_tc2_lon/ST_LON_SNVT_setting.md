# ST_LON_SNVT_setting

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_setting

Used by: SNVT\_setting

```
TYPE ST_LON_SNVT_setting :  
STRUCT  
  eFunction : E_LON_setting_t;  
  rSetting  : REAL;  
  rRotation : REAL;  
END_STRUCT  
END_TYPE
```

**eFunction:** Setting control function (setting control function names) (see [E\_LON\_setting\_t](ms-xhelp:///?Id=beckhoff-af3b-49d8-a01c-3497357dfc12)).

**rSetting:** Min: 0 / Max: 100 / Scene setting level (% of full level).

**rRotation:** Min: -359.98 / Max: 360.00 / Rotation angle (degrees).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
