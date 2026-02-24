# ST_LON_SNVT_log_status

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_log\_status

Used by: SNVT\_log\_status

```
TYPE ST_LON_SNVT_log_status :  
STRUCT  
  eStatus                      : E_LON_log_status_t;  
  uiLog_number                 : UINT;  
  rLevel                       : REAL;  
  diRecord_count               : DINT;  
  diByte_count                 : DINT;  
  diTotal_record_count         : DINT;  
  diRecords_since_notification : DINT;  
  stCurrent_notify_time        : TIMESTRUCT;  
  stPrevious_notify_time       : TIMESTRUCT;  
END_STRUCT  
END_TYPE
```

**eStatus:** Log state. State of the selected data log (see [E\_LON\_log\_status\_t](ms-xhelp:///?Id=beckhoff-9265-4af8-957e-437c784012fe)).

**uiLog\_number:** Min: 1 / Max: 65535 / Selected log number. The log number of the reported data log. Logs are numbered from 1 to number\_of\_logs.

**rLevel:** Min: 0 / Max: 100 / Log level (Percent). The percent of maximum records in the selected data log.

**diRecord\_count:** Min: -2147483648 / Max: 2147483647 / Record count.(records). Number of records in the selected data log. A record is a logged value and any associated data such as a timestamp.

**diByte\_count:** Min: -2147483648 / Max: 2147483647 / Byte count. (bytes). Number of bytes in the selected data log.

**diTotal\_record\_count:** Min: -2147483648 / Max: 2147483647 / Total record count. (records). Total records collected in the selected data log since the data log was created. Wraps to 0 on overflow.

**diRecords\_since\_notification:** Min: -2147483648 / Max: 2147483647 / Records since notification. (records). The number of log records collected since the last notification.

**stCurrent\_notify\_time:** Current notify time (see TIMESTRUCT). Timestamp of the most recently collected data point.

**stPrevious\_notify\_time:** Previous notify time (seconds) (see TIMESTRUCT). Timestamp of the most recently collected data point in the previous update to the log status.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
