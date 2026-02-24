# ST_LON_CIE1931_percent

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_CIE1931\_percent

Used by: SNVT\_color\_2

```
TYPE ST_LON_CIE1931_percent :  
STRUCT  
  rX         : REAL;  
  rY         : REAL;  
  rPercent_Y : REAL;  
END_STRUCT  
END_TYPE
```

**rX:** Min: 0.0 / Max: 0.740 / Invalid: 1.275 / CIE 1931 x value (CIE 1931 color space coordinate). CIE 1931 x-axis color value

**rY:** Min: 0.0 / Max: 0.840 / Invalid: 1.275 / CIE 1931 y value (CIE 1931 color space coordinate). CIE 1931 y-axis color value

**rPercent\_Y:** Min: 0.0 / Max: 100.0 / Invalid: 655.35 / Luminance (% of full level). Y output in percent of maximum lumen output of the lamp

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
