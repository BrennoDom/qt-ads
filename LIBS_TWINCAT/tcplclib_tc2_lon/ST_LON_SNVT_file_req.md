# ST_LON_SNVT_file_req

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_file\_req

Used by: SNVT\_file\_req

```
TYPE ST_LON_SNVT_file_req :  
STRUCT  
  eRequest          : E_LON_file_request_t;  
  uiIndex           : UINT;  
  uiReceive_timeout : UINT;  
  stDest_address    : ST_LON_dest_address;  
  byAuth_on         : BYTE;  
  byPrio_on         : BYTE;  
END_STRUCT  
END_TYPE
```

**eRequest:** Request (file request names) (see [E\_LON\_file\_request\_t](ms-xhelp:///?Id=beckhoff-0df4-416a-82c7-df88525ee5fd)).

**uiIndex:** Min: 0 / Max: 65535 / Index (file index).

**uiReceive\_timeout:** Min: 0 / Max: 65535 / Receive timeout (milliseconds).

**stDest\_address:** Destination address (LonWorks address) (see [ST\_LON\_dest\_address](ms-xhelp:///?Id=beckhoff-5023-4087-a3f4-3dca43cb1d0c)).

**byAuth\_on:** Min: 0 / Max: 1 / Authentication on (boolean). This field specifies whether the message requires authentication.

**byPrio\_on:** Min: 0 / Max: 1 / Priority on (boolean). This field specifies whether the message is to be sent with priority.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
