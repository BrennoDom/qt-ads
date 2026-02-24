# ST_LON_dest_address

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_dest\_address

Used by: SNVT\_file\_req

```
TYPE ST_LON_dest_address :  
STRUCT  
  stAddrt : ST_LON_addrt;  
  stSn    : ST_LON_sn;  
  stGp    : ST_LON_gp;  
END_STRUCT  
END_TYPE
```

**stAddrt:** Address table entry (Address table entry). ANSI/CEA-709.1 address in device's internal address table entry (see [ST\_LON\_addrt](ms-xhelp:///?Id=beckhoff-2b25-488c-a2ff-90d14d46da11)).

**stSn:** Subnet-node address (LonWorks subnet-node address) (see [ST\_LON\_sn](ms-xhelp:///?Id=beckhoff-2aec-4694-b732-104882510ca4)).

**stGp:** Group address (LonWorks group address) (see [ST\_LON\_gp](ms-xhelp:///?Id=beckhoff-6870-4126-b4bf-3c82d7c46a19)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
