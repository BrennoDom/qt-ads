# E_LON_therm_mode_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_therm\_mode\_t

Used by: SNVT\_therm\_mode

```
TYPE E_LON_therm_mode_t :  
(  
  eLON_THERM_NUL        := -1,  
  eLON_THERM_NO_CONTROL := 0,  
  eLON_THERM_IN_OUT     := 1,  
  eLON_THERM_MODULATING := 2  
)  
END_TYPE
```

**eLON\_THERM\_NUL:**  Invalid Value

**eLON\_THERM\_NO\_CONTROL:**  Thermostat disabled

**eLON\_THERM\_IN\_OUT:**  Cut in/out control

**eLON\_THERM\_MODULATING:**  Modulating control

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
