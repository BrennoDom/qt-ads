# ST_LON_SNVT_geo_loc

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_geo\_loc

Used by: SNVT\_geo\_loc

```
TYPE ST_LON_SNVT_geo_loc :  
STRUCT  
  lrLongitude : LREAL;  
  lrLatitude  : LREAL;  
  rElevation  : REAL;  
  sName       : STRING(19);  
END_STRUCT  
END_TYPE
```

**lrLongitude:** Min: -180.0 / Max: 180.0 / Longitude. Longitude is given as an angular measurement ranging from 0° at the prime meridian to +180° eastward and -180° westward.

**lrLatitude:** Min: -90.0 / Max: 90.0 / Latitude. Latitude is given as an angular measurement ranging from 0° at the equator to +90° northward and -90° southward.

**rElevation:** Min: -3.40E+51 / Max: 3..40+51 / Elevation (meters).

**sName:**

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
