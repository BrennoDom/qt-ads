# ST_LON_SNVT_obj_request

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_obj\_request

Used by: SNVT\_obj\_request

```
TYPE ST_LON_SNVT_obj_request :  
STRUCT  
  uiObject_id     : UINT;  
  eObject_request : E_LON_object_request_t;  
END_STRUCT  
END_TYPE
```

**uiObject\_id:** Min: 0 / Max: 65535 / Object ID (object index).

**eObject\_request:** Object request (object request names) (see [E\_LON\_object\_request\_t](ms-xhelp:///?Id=beckhoff-b801-481b-b222-eab5b0a95771)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
