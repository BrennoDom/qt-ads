# ST_LON_Dev_type3

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_Dev\_type3

Used by: SNVT\_dev\_status

```
TYPE ST_LON_Dev_type3 :  
STRUCT  
  stPump_ctrl : ST_LON_pump_ctrl3;  
  stValvePos  : ST_LON_valve_pos3;  
END_STRUCT  
END_TYPE
```

**stPump\_ctrl:** Pump controller device status (see [ST\_LON\_pump\_ctrl3](ms-xhelp:///?Id=beckhoff-3d7b-42fd-abe9-dd8a10a0cc65)).

**stValvePos:** Valve positioner device status (see [ST\_LON\_valve\_pos3](ms-xhelp:///?Id=beckhoff-0042-4c6f-a7dd-dd73e1c4f424)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
