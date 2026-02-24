# ST_LON_rac_req_addr_init

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_rac\_req\_addr\_init

```
TYPE ST_LON_rac_req_addr_init :  
STRUCT  
  byUnit_id          : BYTE;  
  byLocation         : BYTE;  
  byCar_id           : BYTE;  
  byReserved         : BYTE;  
  eAudio_sensor_type : E_LON_rail_audio_sensor_type_t;  
END_STRUCT  
END_TYPE
```

**byUnit\_id:**

**byLocation:**

**byCar\_id:**

**byReserved:**

**eAudio\_sensor\_type:** (see [E\_LON\_rail\_audio\_sensor\_type\_t](ms-xhelp:///?Id=beckhoff-c6e3-40fb-91a3-1c8d00218580)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
