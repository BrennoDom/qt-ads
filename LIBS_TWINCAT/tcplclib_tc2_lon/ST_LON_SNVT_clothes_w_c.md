# ST_LON_SNVT_clothes_w_c

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_clothes\_w\_c

Used by: SNVT\_clothes\_w\_c

```
TYPE ST_LON_SNVT_clothes_w_c :  
STRUCT  
  eCycle           : E_LON_appl_cwc_t;  
  eSubcycle        : E_LON_appl_cws_t;  
  byRervd          : BYTE;  
  station          : ST_LON_action;  
  stFunction       : ST_LON_function;  
  uiTime_remaining : UINT;  
END_STRUCT  
END_TYPE
```

**eCycle:** (see [E\_LON\_appl\_cwc\_t](ms-xhelp:///?Id=beckhoff-a76b-4df7-82dc-a74935295643)).

**eSubcycle:** (see [E\_LON\_appl\_cws\_t](ms-xhelp:///?Id=beckhoff-64fd-4be8-80d0-87f2674858a9)).

**byRervd:**

**stAction:** (see [ST\_LON\_action](ms-xhelp:///?Id=beckhoff-5799-429f-b90c-5673251b5e78)).

**stFunction:** (see [ST\_LON\_function](ms-xhelp:///?Id=beckhoff-c44e-46ef-b6a5-9fd81267c6c1)).

**uiTime\_remaining:** Min: 0 / Max: 65535.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
