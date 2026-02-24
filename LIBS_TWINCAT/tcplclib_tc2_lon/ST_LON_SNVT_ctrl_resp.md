# ST_LON_SNVT_ctrl_resp

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_ctrl\_resp

Used by: SNVT\_ctrl\_resp

```
TYPE ST_LON_SNVT_ctrl_resp :  
STRUCT  
  eStatus         : E_LON_control_resp_t;  
  stSender        : ST_LON_sender;  
  uiController_id : UINT;  
END_STRUCT  
END_TYPE
```

**eStatus:** Control response type (control response type names) (see [E\_LON\_control\_resp\_t](ms-xhelp:///?Id=beckhoff-5e3e-4879-a510-b7ecb50c5363)).

**stSender:** Sender ID (see [ST\_LON\_sender](ms-xhelp:///?Id=beckhoff-3d0c-467e-858b-46e5f913d72e)).

**uiController\_id:** Min: 1 / Max: 65535 / Invalid: 65535 / Controller ID (ID number).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
