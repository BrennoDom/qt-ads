# E_LON_valve_mode_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_valve\_mode\_t

Used by: SNVT\_valve\_mode

```
TYPE E_LON_valve_mode_t :  
(  
  eLON_VALVE_NUL        := -1,  
  eLON_VALVE_NORMAL     := 0,  
  eLON_VALVE_COOLING    := 1,  
  eLON_VALVE_HEATING    := 2,  
  eLON_VALVE_EMERGENCY  := 3,  
  eLON_VALVE_STROKE_ADP := 4,  
  eLON_VALVE_STROKE_SYN := 5,  
  eLON_VALVE_ERROR      := 6,  
  eLON_VALVE_OVERRIDDEN := 7  
)  
END_TYPE
```

**eLON\_VALVE\_NUL:**  Invalid value

**eLON\_VALVE\_NORMAL:**  Valve works as normal valve

**eLON\_VALVE\_COOLING:**  Valve works as cooling valve only

**eLON\_VALVE\_HEATING:**  Valve works as heating valve only

**eLON\_VALVE\_EMERGENCY:**  Valve works in emergency operation

**eLON\_VALVE\_STROKE\_ADP:**  Valve adapt its stroke and its end positions

**eLON\_VALVE\_STROKE\_SYN:**  Valve resynchronizes its position

**eLON\_VALVE\_ERROR:**  Valve is in error mode

**eLON\_VALVE\_OVERRIDDEN:**  Value is overridden

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
