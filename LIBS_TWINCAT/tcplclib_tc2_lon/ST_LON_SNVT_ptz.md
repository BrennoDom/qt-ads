# ST_LON_SNVT_ptz

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_ptz

Used by: SNVT\_ptz

```
TYPE ST_LON_SNVT_ptz :  
STRUCT  
  ePan_dir    : E_LON_pan_dir_t;  
  rPan_speed  : REAL;  
  eTilt_dir   : E_LON_tilt_dir_t;  
  rTilt_speed : REAL;  
  eZoom       : E_LON_zoom_t;  
  rZoom_speed : REAL;  
END_STRUCT  
END_TYPE
```

**ePan\_dir:** Pan direction (pan direction names) (see [E\_LON\_pan\_dir\_t](ms-xhelp:///?Id=beckhoff-02f5-4129-8ca8-37c64eb01e8e)).

**rPan\_speed:** Min: 0 / Max: 100 / Pan speed (% of full level).

**eTilt\_dir:** Tilt direction (tilt direction names) (see [E\_LON\_tilt\_dir\_t](ms-xhelp:///?Id=beckhoff-b247-4a04-b633-ac33caf9ee2a)).

**rTilt\_speed:** Min: 0 / Max: 100 / Tilt speed (% of full level).

**eZoom:** Zoom direction (zoom direction names) (see [E\_LON\_zoom\_t](ms-xhelp:///?Id=beckhoff-3af1-4c62-8ed1-e4a51abcc12c)).

**rZoom\_speed:** Min: 0 / Max: 100 / Zoom speed (% of full level).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
