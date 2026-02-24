# E_LON_cam_act_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_cam\_act\_t

Used by: SNVT\_pos\_ctrl

```
TYPE E_LON_cam_act_t :  
(  
 eLON_CMA_NUL  := -1,  
 eLON_CMA_SAVE := 0,  
 eLON_CMA_CALL := 1,  
 eLON_CMA_READ := 2  
)  
END_TYPE
```

**eLON\_CMA\_NUL:**  Invalid action call response

**eLON\_CMA\_SAVE:**  Save the values defined by the function

**eLON\_CMA\_CALL:**  Preposition tour tables

**eLON\_CMA\_READ:**  Absolute positions

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
