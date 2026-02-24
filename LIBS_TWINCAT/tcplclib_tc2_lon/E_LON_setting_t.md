# E_LON_setting_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_setting\_t

Used by: SNVT\_setting

```
TYPE E_LON_setting_t :  
(  
  eLON_SET_NUL   := -1,  
  eLON_SET_OFF   := 0,  
  eLON_SET_ON    := 1,  
  eLON_SET_DOWN  := 2,  
  eLON_SET_UP    := 3,  
  eLON_SET_STOP  := 4,  
  eLON_SET_STATE := 5  
)  
END_TYPE
```

**eLON\_SET\_NUL:**  Invalid value

**eLON\_SET\_OFF:**  Change state to off

**eLON\_SET\_ON:**  Change state to on, restoring the last on setting

**eLON\_SET\_DOWN:**  Decrease the setting by the offset supplied in the setting field

**eLON\_SET\_UP:**  Increase the setting by the offset supplied in the setting field

**eLON\_SET\_STOP:**  Stop any motion, for example for blinds

**eLON\_SET\_STATE:**  Change the setting to the value specified

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
