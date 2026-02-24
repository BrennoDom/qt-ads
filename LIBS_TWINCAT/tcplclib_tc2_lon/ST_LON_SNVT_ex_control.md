# ST_LON_SNVT_ex_control

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_ex\_control

Used by: SNVT\_ex\_control

```
TYPE ST_LON_SNVT_ex_control :  
STRUCT  
  eControl_status       : E_LON_ex_control_t;  
  stControl_device_addr : ST_LON_Control_device_addr;  
END_STRUCT  
END_TYPE
```

**eControl\_status:** Control type (control type names) (see [E\_LON\_ex\_control\_t](ms-xhelp:///?Id=beckhoff-da32-4b74-b47e-0ccc66fe6981)).

**stControl\_device\_addr:** Control device address (LonWorks subnet-node address) (see [ST\_LON\_Control\_device\_addr](ms-xhelp:///?Id=beckhoff-74e7-4946-a5f0-b4193999ac49)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
