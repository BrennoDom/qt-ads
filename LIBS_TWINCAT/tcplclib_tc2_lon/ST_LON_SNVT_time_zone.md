# ST_LON_SNVT_time_zone

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_time\_zone

Used by: SNVT\_time\_zone

```
TYPE ST_LON_SNVT_time_zone :  
STRUCT  
  diSecond_time_offset  : DINT;  
  eType_of_description  : E_LON_calendar_type_t;  
  byHour_of_start_DST   : BYTE;  
  byMinute_of_start_DST : BYTE;  
  bySecond_of_start_DST : BYTE;  
  stStart_DST           : ST_LON_start_DST;  
  byHour_of_end_DST     : BYTE;  
  byMinute_of_end_DST   : BYTE;  
  bySecond_of_end_DST   : BYTE;  
  stEnd_DST             : ST_LON_end_DST;  
END_STRUCT  
END_TYPE
```

**diSecond\_time\_offset:** Min: -86400 / Max: 86400 / Offset from GMT (seconds). West direction is negative offset .

**eType\_of\_description:** Calendar type (calendar type names) (see [E\_LON\_calendar\_type\_t](ms-xhelp:///?Id=beckhoff-91a4-43f9-9f5d-5009c90435ba)).

**byHour\_of\_start\_DST:** Min: 0 / Max: 23 / DST start hour (hours).

**byMinute\_of\_start\_DST:** Min: 0 / Max: 59 / DST start minute (minutes).

**bySecond\_of\_start\_DST:** Min: 0 / Max: 59 / DST start second (seconds).

**stStart\_DST:** DST start day (day descriptor). Daylight savings time start day (see [ST\_LON\_start\_DST](ms-xhelp:///?Id=beckhoff-2e8b-4b85-8ac6-307033f80ee1)).

**byHour\_of\_end\_DST:** Min: 0 / Max: 23 / DST end hour (hours).

**byMinute\_of\_end\_DST:** Min: 0 / Max: 59 / DST end minute (minutes).

**bySecond\_of\_end\_DST:** Min: 0 / Max: 59 / DST end second (seconds).

**stEnd\_DST:** DST end day (day descriptor). Daylight savings time end day (see [ST\_LON\_end\_DST](ms-xhelp:///?Id=beckhoff-cef9-4fff-9b1a-108c91faf8bd)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
