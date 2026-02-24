# ST_LON_Dev_type2

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_Dev\_type2

Used by: SNVT\_dev\_maint

```
TYPE ST_LON_Dev_type2 :  
STRUCT  
  stPump_ctrl : ST_LON_pump_ctrl2;  
  stValvePos  : ST_LON_valve_pos2;  
END_STRUCT  
END_TYPE
```

**stPump\_ctrl:** Pump controller device maintenance state (see [ST\_LON\_pump\_ctrl2](ms-xhelp:///?Id=beckhoff-cea3-4768-9cf1-e1570774ce14)).

**stValvePos:** Valve positioner device maintenance information (see [ST\_LON\_valve\_pos2](ms-xhelp:///?Id=beckhoff-ac64-4d15-b8eb-6833a5be9ce0)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
