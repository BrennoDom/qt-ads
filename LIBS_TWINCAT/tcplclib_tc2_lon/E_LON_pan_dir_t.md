# E_LON_pan_dir_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_pan\_dir\_t

Used by: SNVT\_ptz

```
TYPE E_LON_pan_dir_t :  
(  
  eLON_PAN_NUL   := -1,  
  eLON_PAN_STOP  := 0,  
  eLON_PAN_RIGHT := 1,  
  eLON_PAN_LEFT  := 2  
)  
END_TYPE
```

**eLON\_PAN\_NUL:**  Invalid Value

**eLON\_PAN\_STOP:**  Stop panning

**eLON\_PAN\_RIGHT:**  Pan to the right

**eLON\_PAN\_LEFT:**  Pan to the left

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
