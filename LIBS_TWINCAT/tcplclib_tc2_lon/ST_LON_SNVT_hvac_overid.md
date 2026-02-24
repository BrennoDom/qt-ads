# ST_LON_SNVT_hvac_overid

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_hvac\_overid

Used by: SNVT\_hvac\_overid

```
TYPE ST_LON_SNVT_hvac_overid :  
STRUCT  
  eState   : E_LON_hvac_overid_t;  
  rPercent : REAL;  
  uiFlow   : UINT;  
END_STRUCT  
END_TYPE
```

**eState:** HVAC override state (override state names) (see [E\_LON\_hvac\_overid\_t](ms-xhelp:///?Id=beckhoff-1964-411b-8763-664f0bb0352a)).

**rPercent:** Min: -163,84 / Max: 163,835 / Percent (% of full scale). Position or flow override value.

**uiFlow:** Min: 0 / Max: 65535 / Flow (liters/second).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
