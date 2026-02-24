# ST_LON_SNVT_chlr_status

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_chlr\_status

Used by: SNVT\_chlr\_status

```
TYPE ST_LON_SNVT_chlr_status :  
STRUCT  
  eChlr_run_mode : E_LON_chiller_t;  
  echlr_op_mode  : E_LON_hvac_t;  
  stChlr_state   : ST_LON_chlr_state;  
END_STRUCT  
END_TYPE
```

**eChlr\_run\_mode:** Chiller run mode (chiller run mode names) (see [E\_LON\_chiller\_t](ms-xhelp:///?Id=beckhoff-c7b1-481e-8e56-7bf57c206dc4)).

**echlr\_op\_mode:** Chiller operating mode (HVAC mode names) (see [E\_LON\_hvac\_t](ms-xhelp:///?Id=beckhoff-a720-44d6-95f5-9acdc34712fc)).

**stChlr\_state:** Chiller state flags (alarm, enabled, local, limited, chiller water flow, condenser water flow) (see [ST\_LON\_chlr\_state](ms-xhelp:///?Id=beckhoff-3cc7-4bf3-96e3-c732305f9293)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
