# ST_LON_SNVT_temp_setpt

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_temp\_setpt

Used by: SNVT\_temp\_setpt

```
TYPE ST_LON_SNVT_temp_setpt :  
STRUCT  
  rOccupied_cool   : REAL;  
  rStandby_cool    : REAL;  
  rUnoccupied_cool : REAL;  
  rOccupied_heat   : REAL;  
  rStandby_heat    : REAL;  
  rUnoccupied_heat : REAL;  
END_STRUCT  
END_TYPE
```

**rOccupied\_cool:** Min: -273,17 / Max: 237,67 / Occupied cooling setpoint (degrees Celsius).

**rStandby\_cool:** Min: -273,17 / Max: 237,67 / Standby cooling setpoint (degrees Celsius).

**rUnoccupied\_cool:** Min: -273,17 / Max: 237,67 / Unoccupied cooling setpoint (degrees Celsius).

**rOccupied\_heat:** Min: -273,17 / Max: 237,67 / Occupied heating setpoint (degrees Celsius).

**rStandby\_heat:** Min: -273,17 / Max: 237,67 / Standby heating setpoint (degrees Celsius).

**rUnoccupied\_heat:** Min: -273,17 / Max: 237,67 / Unoccupied heating setpoint (degrees Celsius).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
