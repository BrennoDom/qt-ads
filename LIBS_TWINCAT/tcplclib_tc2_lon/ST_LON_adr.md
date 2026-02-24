# ST_LON_adr

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_adr

Used by: SNVT\_file\_status

```
TYPE ST_LON_adr :  
STRUCT  
  stDescriptor : ST_LON_descriptor;  
  stAddress    : ST_LON_address;  
END_STRUCT  
END_TYPE
```

**stDescriptor:** Descriptor (see [ST\_LON\_descriptor](ms-xhelp:///?Id=beckhoff-7147-4c29-aec1-4ee00859cb94)).

**stAddress:** Address (see [ST\_LON\_address](ms-xhelp:///?Id=beckhoff-5f5e-4235-b2f0-57494f916756)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
