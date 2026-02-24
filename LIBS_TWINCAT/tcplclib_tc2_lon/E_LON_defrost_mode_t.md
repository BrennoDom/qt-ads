# E_LON_defrost_mode_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_defrost\_mode\_t

Used by: SNVT\_defr\_mode

```
TYPE E_LON_defrost_mode_t :  
(  
  eLON_DFM_NUL          := -1,  
  eLON_DFM_MODE_AMBIENT := 0,  
  eLON_DFM_MODE_FORCED  := 1,  
  eLON_DFM_MODE_SYNC    := 2  
)  
END_TYPE
```

**eLON\_DFM\_NUL:**  Invalid Value

**eLON\_DFM\_MODE\_AMBIENT:**  No forced heating required

**eLON\_DFM\_MODE\_FORCED:**  Start-up after defrost ignored

**eLON\_DFM\_MODE\_SYNC:**  Synchronized

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
