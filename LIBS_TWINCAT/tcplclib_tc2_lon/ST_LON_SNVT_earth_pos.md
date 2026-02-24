# ST_LON_SNVT_earth_pos

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_earth\_pos

Used by: SNVT\_earth\_pos

```
TYPE ST_LON_SNVT_earth_pos :  
STRUCT  
  bLatitude_direction  : BOOL;  
  bLongitude_direction : BOOL;  
  byLatitude_deg       : BYTE;  
  rLatitude_min        : REAL;  
  bylongitude_deg      : BYTE;  
  rLongitude_min       : REAL;  
  rHeight_above_sea    : REAL;  
END_STRUCT  
END_TYPE
```

**bLatitude\_direction:** FALSE = South latitude, TRUE = North latitude.

**bLongitude\_direction:** FALSE = East longitude, TRUE = West longitude.

**byLatitude\_deg:** Min: 0 / Max: 90 / Invalid: 255 / Latitude degrees (degrees).

**rLatitude\_min:** Min: 0.0 / Max: 59.999 / Invalid: 65.535/ Latitude minutes (minutes).

**bylongitude\_deg:** Min: 0 / Max: 180 / Invalid: 255 / Longitude degrees (degrees).

**rLongitude\_min:** Min: 0.0 / Max: 59.999 / Invalid: 65.535/ Longitude minutes (minutes).

**rHeight\_above\_sea:** Min: -3.40E+38 / Max: 3.40E+38 / Height above sea level (meters).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
