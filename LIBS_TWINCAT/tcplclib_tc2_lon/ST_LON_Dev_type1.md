# ST_LON_Dev_type1

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_Dev\_type1

Used by: SNVT\_dev\_fault

```
TYPE ST_LON_Dev_type1 :  
STRUCT  
  stPump_ctrl : ST_LON_pump_ctrl1;  
  stValvePos  : ST_LON_valve_pos1;  
END_STRUCT  
END_TYPE
```

**stPump\_ctrl:** Pump controller device fault information (see [ST\_LON\_pump\_ctrl1](ms-xhelp:///?Id=beckhoff-648e-4c56-a176-ad4bf3f3d662)).

**stValvePos:** Valve positioner device fault information (see [ST\_LON\_valve\_pos1](ms-xhelp:///?Id=beckhoff-83d4-4b51-bc98-d58750b5a06b)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
