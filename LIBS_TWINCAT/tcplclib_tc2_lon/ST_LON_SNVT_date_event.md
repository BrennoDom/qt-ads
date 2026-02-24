# ST_LON_SNVT_date_event

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_date\_event

Used by: SNVT\_date\_event

```
TYPE ST_LON_SNVT_date_event :  
STRUCT  
  iDays_to_active   : INT;  
  iDays_to_inactive : INT;  
  sName             : STRING(22);  
END_STRUCT  
END_TYPE
```

**iDays\_to\_active:** Min: -32768 / Max: 32767 / Invalid: 32767 / Days to active (days). Number of days until this schedule will be active. Positive if a schedule is inactive; zero or negative if a schedule is active.

**iDays\_to\_inactive:** Min: -32768 / Max: 32767 / Invalid: -32768 / Days to inactive (days). Number of days until this schedule will be inactive. Positive if a schedule is active; zero or negative if a schedule is inactive.

**sName:** 22 characters / Schedule name (array of 22 characters). Nul-terminated schedule name. The nul terminator is not required if the name is 22 characters.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
