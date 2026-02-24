# ST_LON_start_DST

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_start\_DST

Used by: SNVT\_time\_zone

```
TYPE ST_LON_start_DST :  
STRUCT  
  uiG_day_of_start_DST : UINT;  
  uiJ_day_of_start_DST : UINT;  
  stM_start_DST        : ST_LON_M_start_DST;  
END_STRUCT  
END_TYPE
```

**uiG\_day\_of\_start\_DST:** Min: 0 / Max: 365 / Gregorian calendar day of start DST (days).

**uiJ\_day\_of\_start\_DST:** Min: 1 / Max: 365 / Julian calendar day of start DST (days).

**stM\_start\_DST:** Meu calendar day of start DST (month, week, dateday) (see [ST\_LON\_M\_start\_DST](ms-xhelp:///?Id=beckhoff-ab03-40e5-bd2a-53ffe1a6c2eb)).

**stM\_start\_DST. byMonth\_of\_start\_DST:** Min: 1 / Max: 12 / Month of start DST (months).

**stM\_start\_DST. byWeek\_of\_start\_DST:** Min: 1 / Max: 5 / Week of start DST (weeks).

**stM\_start\_DST. eDateday\_of\_start\_DST:** [E\_LON\_days\_of\_week\_t](ms-xhelp:///?Id=beckhoff-40cf-4a53-ae19-e7d42bc572c2) / Day of week (day names).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
