# ST_LON_M_end_DST

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_M\_end\_DST

Used by: SNVT\_time\_zone

```
TYPE ST_LON_M_end_DST :  
STRUCT  
  byMonth_of_end_DST  : BYTE;  
  byWeek_of_end_DST   : BYTE;  
  eDateday_of_end_DST : E_LON_days_of_week_t;  
END_STRUCT  
END_TYPE
```

[E\_LON\_days\_of\_week\_t](ms-xhelp:///?Id=beckhoff-40cf-4a53-ae19-e7d42bc572c2)

**byMonth\_of\_end\_DST:** Min: 1 / Max: 12 / Month of end DST (months).

**byWeek\_of\_end\_DST:** Min: 1 / Max: 5 / Week of end DST (weeks).

**eDateday\_of\_end\_DST:** Day of week (day names).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
