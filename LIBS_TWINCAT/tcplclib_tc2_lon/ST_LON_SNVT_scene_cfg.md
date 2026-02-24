# ST_LON_SNVT_scene_cfg

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_scene\_cfg

Used by: SNVT\_scene\_cfg

```
TYPE ST_LON_SNVT_scene_cfg :  
STRUCT  
  eFunction      : E_LON_Scene_config_t;  
  byScene_number : BYTE;  
  rSetting       : REAL;  
  rRotation      : REAL;  
  rFade_time     : REAL;  
  rDelay_time    : REAL;  
  scene_priority : BYTE;  
END_STRUCT  
END_TYPE
```

**eFunction:** Scene configuration function (scene configuration function names) (see [E\_LON\_Scene\_config\_t](ms-xhelp:///?Id=beckhoff-3595-4a31-ae2e-21de913c0e45)).

**byScene\_number:** Min: 0 / Max: 255 / Scene number.

**rSetting:** Min: 0 / Max: 100.0 Invalid: 255 / Scene setting level (% of full level).

**rRotation:** Min: -359,98 / Max: 360,00 / Scene rotation angle (degrees).

**rFade\_time:** Min: 0 / Max: 6553.5 / Scene fade time (seconds).

**rDelay\_time:** Min: 0 / Max: 6553.5 / Scene delay time (seconds).

**scene\_priority:** Min: 0 / Max: 255 / scene\_priority

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
