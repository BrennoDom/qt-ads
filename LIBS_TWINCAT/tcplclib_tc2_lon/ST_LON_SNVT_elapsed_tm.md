# ST_LON_SNVT_elapsed_tm

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_elapsed\_tm

Used by: SNVT\_elapsed\_tm

```
TYPE ST_LON_SNVT_elapsed_tm :  
STRUCT  
  uiDay         : UINT;  
  uiHour        : UINT;  
  uiMinute      : UINT;  
  uiSecond      : UINT;  
  uiMillisecond : UINT;  
END_STRUCT  
END_TYPE
```

**uiDay:** Min: 0 / Max: 65535 / Days (days). The value 65535 represents NULL or unknown elapsed time.

**uiHour:** Min: 0 / Max: 23 / Hours (hours). This field uses a 24-hour value.

**uiMinute:** Min: 0 / Max: 59 / Minutes (minutes).

**uiSecond:** Min: 0 / Max: 59 / Seconds (seconds).

**uiMillisecond:** Min: 0 / Max: 999 / Milliseconds (milliseconds).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
