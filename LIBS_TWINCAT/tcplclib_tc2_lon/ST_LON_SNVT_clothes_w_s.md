# ST_LON_SNVT_clothes_w_s

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_clothes\_w\_s

Used by: SNVT\_clothes\_w\_s

```
TYPE ST_LON_SNVT_clothes_w_s :  
STRUCT  
  eCycle                : E_LON_appl_cwc_t;  
  eSubcycle             : E_LON_appl_cws_t;  
  stWasher_command_data : ST_LON_SNVT_clothes_w_c;  
  uiTime_remaining      : UINT;  
  stAlarm               : ST_LON_alarm;  
END_STRUCT  
END_TYPE
```

**eCycle:** (see [E\_LON\_appl\_cwc\_t](ms-xhelp:///?Id=beckhoff-a76b-4df7-82dc-a74935295643)).

**eSubcycle:** (see [E\_LON\_appl\_cws\_t](ms-xhelp:///?Id=beckhoff-64fd-4be8-80d0-87f2674858a9)).

**stWasher\_command\_data:** (see [ST\_LON\_SNVT\_clothes\_w\_c](ms-xhelp:///?Id=beckhoff-7b5d-4750-8645-0f0318c7b657)).

**uiTime\_remaining:** Min: 0 / Max: 65535

**stAlarm:** (see [ST\_LON\_alarm](ms-xhelp:///?Id=beckhoff-c451-421d-90ac-45035596f4d6)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
