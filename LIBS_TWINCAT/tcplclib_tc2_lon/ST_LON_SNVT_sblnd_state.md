# ST_LON_SNVT_sblnd_state

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_sblnd\_state

Used by: SNVT\_sblnd\_state

```
TYPE ST_LON_SNVT_sblnd_state :  
STRUCT  
  stPos       : ST_LON_SNVT_setting;  
  eCmd_source : E_LON_sblnd_cmd_source_t;  
  eError_code : E_LON_sblnd_error_t;  
END_STRUCT  
END_TYPE
```

**stPos:** (see [ST\_LON\_SNVT\_setting](ms-xhelp:///?Id=beckhoff-1fe1-4340-91ce-247c7a5d8691)).

**eCmd\_source:** (see [E\_LON\_sblnd\_cmd\_source\_t](ms-xhelp:///?Id=beckhoff-82e1-403b-99d8-bff1761c69ae)).

**eError\_code:** (see [E\_LON\_sblnd\_error\_t](ms-xhelp:///?Id=beckhoff-d083-4488-95d2-ea62233afcdb)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
