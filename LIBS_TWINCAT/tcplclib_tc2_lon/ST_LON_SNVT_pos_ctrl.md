# ST_LON_SNVT_pos_ctrl

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_pos\_ctrl

Used by: SNVT\_pos\_ctrl

```
TYPE ST_LON_SNVT_pos_ctrl :  
STRUCT  
  uiReceiver_id     : UINT;  
  uiController_id   : UINT;  
  byController_prio : BYTE;  
  eFunction         : E_LON_cam_func_t;  
  eAction           : E_LON_cam_act_t;  
  stValue           : ST_LON_Value;  
END_STRUCT  
END_TYPE
```

**uiReceiver\_id:** Min: 0 / Max: 65535 / Receiver ID (ID number).

**uiController\_id:** Min: 0 / Max: 65535 / Controller ID (ID number).

**byController\_prio:** Min: 0 / Max: 100 / Controller priority (priority value).

**eFunction:** Camera function (camera function names) (see [E\_LON\_cam\_func\_t](ms-xhelp:///?Id=beckhoff-0e1c-41cd-811e-50b057a55b4d)).

**eAction:** Camera action (camera action names) (see [E\_LON\_cam\_act\_t](ms-xhelp:///?Id=beckhoff-67c0-422b-aa54-ce9c77e5219b)).

**stValue:** Function value (see [ST\_LON\_Value](ms-xhelp:///?Id=beckhoff-8e18-444b-bdf8-658300ed4ed4)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
