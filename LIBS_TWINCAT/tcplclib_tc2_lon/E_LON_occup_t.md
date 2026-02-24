# E_LON_occup_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_occup\_t

Used by: SNVT\_occupancy / SNVT\_tod\_event

```
TYPE E_LON_occup_t :  
(  
  eLON_OC_NUL        := -1,  
  eLON_OC_OCCUPIED   := 0,  
  eLON_OC_UNOCCUPIED := 1,  
  eLON_OC_BYPASS     := 2,  
  eLON_OC_STANDBY    := 3  
)  
END_TYPE
```

**eLON\_OC\_NUL:**  Invalid Value

**eLON\_OC\_OCCUPIED:**  Area is occupied

**eLON\_OC\_UNOCCUPIED:**  Area is unoccupied

**eLON\_OC\_BYPASS:**  Area is temporarily occupied for the bypass period

**eLON\_OC\_STANDBY:**  Area is temporarily unoccupied

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
