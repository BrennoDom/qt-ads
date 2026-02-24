# ST_LON_SNVT_log_fx_request

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_log\_fx\_request

Used by: SNVT\_log\_fx\_request

```
TYPE ST_LON_SNVT_log_fx_request :  
STRUCT  
  uiRequested_log : UINT;  
  udiRecord_count : UDINT;  
  stStart_time    : TIMESTRUCT;  
  stEnd_time      : TIMESTRUCT;  
END_STRUCT  
END_TYPE
```

**uiRequested\_log:** Min: 1 / Max: 65535 / Requested log number. The log number of the data log to be transferred. Logs are numbered from 1 to number\_of\_logs.

**udiRecord\_count:** Min: 0 / Max: 4294967295 / Record count. The maximum number of log records to be transferred.

**stStart\_time:** Start time. (seconds) (see TIMESTRUCT). Timestamp of first record to be transferred. If no records exist with this timestamp, the first record with a timestamp after this timestamp is the starting record.

**stEnd\_time:** End time. (seconds) (see TIMESTRUCT). Timestamp of last record to be transferred. If no records exist with this timestamp, the last record with a timestamp before this timestamp is the ending record.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
