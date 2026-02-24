# E_LON_color_encoding_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_color\_encoding\_t

Used by: SNVT\_color\_2

```
TYPE E_LON_color_encoding_t :  
(  
  eLON_COLOR_NUL           := -1,  
  eLON_COLOR_CIE31_LUMEN   := 0,  
  eLON_COLOR_CIE31_PERCENT := 1,  
  eLON_COLOR_RGB           := 2,  
  eLON_COLOR_TEMPERATURE   := 3  
)  
END_TYPE
```

**eLON\_COLOR\_NUL:**  Invalid value

**eLON\_COLOR\_CIE31\_LUMEN:**  CIE 1931 color space; Y output in lumen

**eLON\_COLOR\_CIE31\_PERCENT:**  CIE 1931 color space; Y output in percent of maximum lumen output of the lamp

**eLON\_COLOR\_RGB:**  No color space, RGB color value

**eLON\_COLOR\_TEMPERATURE:**  Color temperature

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
