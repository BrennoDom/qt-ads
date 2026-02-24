# E_LON_zoom_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_zoom\_t

Used by: SNVT\_ptz

```
TYPE E_LON_zoom_t :  
(  
  eLON_ZOOM_NUL  := -1,  
  eLON_ZOOM_STOP := 0,  
  eLON_ZOOM_TELE := 1,  
  eLON_ZOOM_WIDE := 2  
)  
END_TYPE
```

**eLON\_ZOOM\_NUL:**  Invalid Value

**eLON\_ZOOM\_STOP:**  Stop zooming

**eLON\_ZOOM\_TELE:**  Telephoto zoom / zoom in

**eLON\_ZOOM\_WIDE:**  Wide zoom / zoom out

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
