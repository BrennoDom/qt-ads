# E_LON_device_select_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_device\_select\_t

Used by: SNVT\_dev\_fault / SNVT\_dev\_maint / SNVT\_dev\_status

```
TYPE E_LON_device_select_t :  
(  
  eLON_DV_NUL       := -1,  
  eLON_DV_PUMP_CTRL := 0,  
  eLON_DV_VALVE_POS := 1  
)  
END_TYPE
```

**eLON\_DV\_NUL:**  Invalid value

**eLON\_DV\_PUMP\_CTRL:**  Use union for SFPTpumpController values

**eLON\_DV\_VALVE\_POS:**  Use union for SFPTvalvePositioner values

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
