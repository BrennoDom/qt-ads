# ST_LON_SNVT_dev_maint

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_dev\_maint

Used by: SNVT\_dev\_maint

```
TYPE ST_LON_SNVT_dev_maint :  
STRUCT  
  eDevice_select : E_LON_device_select_t;  
  stDev_type     : ST_LON_Dev_type2;  
END_STRUCT  
END_TYPE
```

**eDevice\_select:** Device selection (device selection names) (see [E\_LON\_device\_select\_t](ms-xhelp:///?Id=beckhoff-248c-471f-8643-2c8efe6477d6)). Determines the interpretation of the network-variable content.

**stDev\_type:** Union of device maintenance state structures for various devices (see [ST\_LON\_Dev\_type2](ms-xhelp:///?Id=beckhoff-c15b-4d0e-9693-1ae5f32af621)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
