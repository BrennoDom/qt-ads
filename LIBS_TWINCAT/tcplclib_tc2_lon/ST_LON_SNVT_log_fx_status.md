# ST_LON_SNVT_log_fx_status

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_log\_fx\_status

Used by: SNVT\_log\_fx\_status

```
TYPE ST_LON_SNVT_log_fx_status :  
STRUCT  
  byRequestor_subnet : BYTE;  
  byRequestor_node   : BYTE;  
  uiLog_number       : UINT;  
  rComplete          : REAL;  
END_STRUCT  
END_TYPE
```

**byRequestor\_subnet:** Min: 1 / Max: 255 / Requestor subnet ID. Subnet ID of the device that requested the current log file transfer. Invalid if a file transfer is not active.

**byRequestor\_node:** Min: 1 / Max: 255 / Requestor node ID. Node ID of the device that requested the current log file transfer. Invalid if a file transfer is not active.

**uiLog\_number:** Min: 1 / Max: 65535 / Data log number. Log number for the log file currently being transferred via FTP. Invalid if none.

**rComplete:** Min: 0 / Max: 100 / Data log file transfer percent complete. Percent of the current data log file transfer that has been completed. Invalid if none.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
