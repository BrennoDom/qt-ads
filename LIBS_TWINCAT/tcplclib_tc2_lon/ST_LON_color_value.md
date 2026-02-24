# ST_LON_color_value

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_color\_value

Used by: SNVT\_color\_2

```
TYPE ST_LON_color_value :  
STRUCT  
  stCIE1931_lumen     : ST_LON_CIE1931_lumen;  
  stCIE1931_percent   : ST_LON_CIE1931_percent;  
  stRGB               : ST_LON_RGB;  
  uiColor_temperature : UINT;  
END_STRUCT  
END_TYPE
```

**stCIE1931\_lumen:** CIE 1931 color space with lumen. CIE 1931 color space with Y output in lumen (see [ST\_LON\_CIE1931\_lumen](ms-xhelp:///?Id=beckhoff-b156-4ff2-a8fa-9c5644e4b094)).

**stCIE1931\_percent:** CIE 1931 color space with percent. CIE 1931 color space with Y output in percent of maximum lumen output of the lamp (see [ST\_LON\_CIE1931\_percent](ms-xhelp:///?Id=beckhoff-b0dc-4d6a-ba21-8444ebf53776)).

**stRGB:** RGB color value (see [ST\_LON\_RGB](ms-xhelp:///?Id=beckhoff-7ba6-4757-8397-9ea4f7ce4f05)).

**uiColor\_temperature:** Min: 2800 / Max: 7500 / Invalid: 12750 / Color temperature (degrees Kelvin).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
