# ST_LON_SNVT_hvac_status

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_hvac\_status

Used by: SNVT\_hvac\_status

```
TYPE ST_LON_SNVT_hvac_status :  
STRUCT  
  eMode                  : E_LON_hvac_t;  
  rHeat_output_primary   : REAL;  
  rHeat_output_secondary : REAL;  
  rCool_output           : REAL;  
  rEcon_output           : REAL;  
  rFan_output            : REAL;  
  byIn_alarm             : BYTE;  
END_STRUCT  
END_TYPE
```

**eMode:** HVAC status mode (HVAC mode names) (see [E\_LON\_hvac\_t](ms-xhelp:///?Id=beckhoff-a720-44d6-95f5-9acdc34712fc)).

**rHeat\_output\_primary:** Min: -163.8400 / Max: 163.8350 / Primary heat output (% of full scale).

**rHeat\_output\_secondary:** Min: -163.8400 / Max: 163.8350 / Secondary heat output (% of full scale).

**rCool\_output:** Min: -163.8400 / Max: 163.8350 / Cooling output (% of full scale).

**rEcon\_output:** Min: -163.8400 / Max: 163.8350 / Economizer output (% of full scale).

**rFan\_output:** Min: -163.8400 / Max: 163.8350 / Fan output (% of full scale).

**byIn\_alarm:** Min: 0 / Max: 255 / in\_alarm

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
