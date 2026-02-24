# ST_LON_abspos

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_abspos

Used by: SNVT\_pos\_ctrl

```
TYPE ST_LON_abspos :  
STRUCT  
  rPan  : REAL;  
  rTilt : REAL;  
  rZoom : REAL;  
END_STRUCT  
END_TYPE
```

**rPan:** Min: -359.98 / Max: 360 / Pan position.

**rTilt:** Min: -359.98 / Max: 360 / Tilt position.

**rZoom:** Min: -163.84 / Max: 163.835 / Zoom position.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
