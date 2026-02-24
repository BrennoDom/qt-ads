# ST_LON_addr_talk

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_addr\_talk

Used by: SNVT\_rac\_ctrl

```
TYPE ST_LON_addr_talk :  
STRUCT  
  byUnit_id          : BYTE;  
  byLocation         : BYTE;  
  byCar_id           : BYTE;  
  byReserved         : BYTE;  
  eAudio_sensor_type : E_LON_rail_audio_sensor_type_t;  
END_STRUCT  
END_TYPE
```

**byUnit\_id:** Min: 0 / Max: 15

**byLocation:** Min: 0 / Max: 15

**byCar\_id:** Min: 0 / Max: 31

**byReserved:**

**eAudio\_sensor\_type:** (see [E\_LON\_rail\_audio\_sensor\_type\_t](ms-xhelp:///?Id=beckhoff-c6e3-40fb-91a3-1c8d00218580)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
