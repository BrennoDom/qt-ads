# E_LON_evap_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_evap\_t

Used by: SNVT\_evap\_state

```
TYPE E_LON_evap_t :  
(  
  eLON_EVAP_NUL           := -1,  
  eLON_EVAP_NO_COOLING    := 0,  
  eLON_EVAP_COOLING       := 1,  
  eLON_EVAP_EMERG_COOLING := 2  
)  
END_TYPE
```

**eLON\_EVAP\_NUL:**  Invalid Value

**eLON\_EVAP\_NO\_COOLING:**  Object not performing cooling (off cycle or disabled)

**eLON\_EVAP\_COOLING:**  Object currently cooling

**eLON\_EVAP\_EMERG\_COOLING:**  Object performing emergency cooling

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
