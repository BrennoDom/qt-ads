# E_LON_tilt_dir_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_tilt\_dir\_t

Used by: SNVT\_ptz

```
TYPE E_LON_tilt_dir_t :  
(  
  eLON_TILT_NUL  := -1,  
  eLON_TILT_STOP := 0,  
  eLON_TILT_UP   := 1,  
  eLON_TILT_DOWN := 2  
)  
END_TYPE
```

**eLON\_TILT\_NUL:**  Invalid Value

**eLON\_TILT\_STOP:**  Stop tilting

**eLON\_TILT\_UP:**  Tilt up

**eLON\_TILT\_DOWN:**  Tilt down

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
