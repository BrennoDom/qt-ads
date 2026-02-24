# ST_LON_function

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_function

Used by: SNVT\_clothes\_w\_c

```
TYPE ST_LON_function :  
STRUCT  
  eProgram : E_LON_appl_cwp_t;  
  stWash   : ST_LON_wash;  
  stRinse  : ST_LON_rinse;  
  stSpin   : ST_LON_spin;  
  stDry    : ST_LON_dry;  
END_STRUCT  
END_TYPE
```

**eProgram:** (see [E\_LON\_appl\_cwp\_t](ms-xhelp:///?Id=beckhoff-8bf2-4805-a1d0-3ca4a199bae5))

**stWash:** (see [ST\_LON\_wash](ms-xhelp:///?Id=beckhoff-7cac-4cf1-8061-c7c88f2d7304))

**stRinse:** (see [ST\_LON\_rinse](ms-xhelp:///?Id=beckhoff-7447-468b-9331-c2104a2a9be5))

**stSpin:** (see [ST\_LON\_spin](ms-xhelp:///?Id=beckhoff-ef6f-43c8-9231-62340007ed31))

**stDry:** (see [ST\_LON\_dry](ms-xhelp:///?Id=beckhoff-6f83-4ebb-9576-e4099f8ee2f7))

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
