# ST_LON_end_DST

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_end\_DST

Used by: SNVT\_time\_zone

```
TYPE ST_LON_end_DST :  
STRUCT  
  uiG_day_of_end_DST : UINT;  
  uiJ_day_of_end_DST : UINT;  
  stM_end_DST        : ST_LON_M_end_DST;  
END_STRUCT  
END_TYPE
```

**uiG\_day\_of\_end\_DST:** Min: 0 / Max: 365 / Gregorian calendar day of end DST (days).

**uiJ\_day\_of\_end\_DST:** Min: 1 / Max: 365 / Julian calendar day of end DST (days).

**stM\_end\_DST:** Meu calendar day of end DST (month, week, dateday) (see [ST\_LON\_M\_end\_DST](ms-xhelp:///?Id=beckhoff-ef6d-4f19-9854-980adb3db6d8)).

**stM\_end\_DST. byMonth\_of\_end\_DST:** Min: 1 / Max: 12 / Month of end DST (months).

**stM\_end\_DST. byWeek\_of\_end\_DST:** Min: 1 / Max: 5 / Week of end DST (weeks).

**stM\_end\_DST. eDateday\_of\_end\_DST:** [E\_LON\_days\_of\_week\_t](ms-xhelp:///?Id=beckhoff-40cf-4a53-ae19-e7d42bc572c2) / Day of week (day names).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
