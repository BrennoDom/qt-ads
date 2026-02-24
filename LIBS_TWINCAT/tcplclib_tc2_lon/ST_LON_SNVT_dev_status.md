# ST_LON_SNVT_dev_status

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_dev\_status

Used by: SNVT\_dev\_status

```
TYPE ST_LON_SNVT_dev_status :  
STRUCT  
  eDevice_select : E_LON_device_select_t;  
  stDev_type     : ST_LON_Dev_type3;  
END_STRUCT  
END_TYPE
```

**eDevice\_select:** Device selection (device selection names) (see [E\_LON\_device\_select\_t](ms-xhelp:///?Id=beckhoff-248c-471f-8643-2c8efe6477d6)). Determines the interpretation of the network-variable content

**stDev\_type:** Union of device status for various devices (see [ST\_LON\_Dev\_type3](ms-xhelp:///?Id=beckhoff-8ca5-4e85-a656-9093a08620e8)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
