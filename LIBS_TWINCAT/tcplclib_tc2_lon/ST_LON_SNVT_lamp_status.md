# ST_LON_SNVT_lamp_status

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_lamp\_status

Used by: SNVT\_lamp\_status

```
TYPE ST_LON_SNVT_lamp_status :  
STRUCT  
  stTime_actual    : TIMESTRUCT;  
  stAlarm_actual   : ST_LON_Alarm_actual;  
  stTime_previous  : TIMESTRUCT;  
  stAlarm_previous : ST_LON_alarm_previous;  
END_STRUCT  
END_TYPE
```

**stTime\_actual:** Actual alarm message. This is the time stamp for the actual alarm message (see TIMESTRUCT).

**stAlarm\_actual:** (see [ST\_LON\_Alarm\_actual](ms-xhelp:///?Id=beckhoff-f8a1-4b6c-9c90-c943bd81de94)).

**stTime\_previous:** Time Stamp Old. This is the time stamp for an old alarm message (see TIMESTRUCT).

**stAlarm\_previous:** (see [ST\_LON\_alarm\_previous](ms-xhelp:///?Id=beckhoff-de79-49c6-89ca-1d99f77a8fde)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
