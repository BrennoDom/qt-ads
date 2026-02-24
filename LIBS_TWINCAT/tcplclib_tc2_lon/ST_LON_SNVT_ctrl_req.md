# ST_LON_SNVT_ctrl_req

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_ctrl\_req

Used by: SNVT\_ctrl\_req

```
TYPE ST_LON_SNVT_ctrl_req :  
STRUCT  
  uiReceiver_id : UINT;  
  uiSender_id   : UINT;  
  bySender_prio : BYTE;  
END_STRUCT  
END_TYPE
```

**uiReceiver\_id:** Min: 1 / Max: 65535 / Invalid / 0 / Receiver ID (ID number).

**uiSender\_id:** Min: 1 / Max: 65535 / Invalid / 65535 / Sender ID (ID number).

**bySender\_prio:** Min: 0 / Max: 200 / Sender priority (priority value).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
