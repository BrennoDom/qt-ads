# ST_LON_SNVT_dev_fault

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_dev\_fault

Used by: SNVT\_dev\_fault

```
TYPE ST_LON_SNVT_dev_fault :  
STRUCT  
  eDevice_select : E_LON_device_select_t;  
  stDev_type     : ST_LON_Dev_type1;  
END_STRUCT  
END_TYPE
```

**eDevice\_select:** Device selection (device selection names) (see [E\_LON\_device\_select\_t](ms-xhelp:///?Id=beckhoff-248c-471f-8643-2c8efe6477d6)). Determines the interpretation of the network-variable content.

**stDev\_type:** Union of device fault structures for various devices (see [ST\_LON\_Dev\_type1](ms-xhelp:///?Id=beckhoff-f183-42fc-a058-71c4aef331d0)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
