# ST_LON_M_start_DST

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_M\_start\_DST

Used by: SNVT\_time\_zone

```
TYPE ST_LON_M_start_DST :  
STRUCT  
  byMonth_of_start_DST  : BYTE;  
  byWeek_of_start_DST   : BYTE;  
  eDateday_of_start_DST : E_LON_days_of_week_t;  
END_STRUCT  
END_TYPE
```

**byMonth\_of\_start\_DST:** Min: 1 / Max: 12 / Month of start DST (months).

**byWeek\_of\_start\_DST:** Min: 1 / Max: 5 / Week of start DST (weeks).

**eDateday\_of\_start\_DST:** Day of week (day names) (see [E\_LON\_days\_of\_week\_t](ms-xhelp:///?Id=beckhoff-40cf-4a53-ae19-e7d42bc572c2)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
