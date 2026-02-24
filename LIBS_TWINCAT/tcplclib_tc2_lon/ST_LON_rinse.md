# ST_LON_rinse

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_rinse

Used by: SNVT\_clothes\_w\_c

```
TYPE ST_LON_rinse :  
STRUCT  
  byTemp   : BYTE;  
  byRepeat : BYTE;  
  eOption  : E_LON_appl_rin_t;  
END_STRUCT  
END_TYPE
```

**byTemp:** Min: 0 / Max: 255

**byRepeat:** Min: 0 / Max: 9

**eOption:** (see [E\_LON\_appl\_rin\_t](ms-xhelp:///?Id=beckhoff-67e2-457c-9aa5-7e24437ea4eb))

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
