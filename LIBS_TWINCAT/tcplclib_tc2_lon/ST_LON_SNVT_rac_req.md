# ST_LON_SNVT_rac_req

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_rac\_req

Used by: SNVT\_rac\_req

```
TYPE ST_LON_SNVT_rac_req :  
STRUCT  
  bDest_def   : BOOL;  
  bDest_p2p   : BOOL;  
  byReserved  : BYTE;  
  eAudio_type : E_LON_rail_audio_type_t;  
  stAddr_init : ST_LON_addr_init;  
  stAddr_dest : ST_LON_addr_dest;  
END_STRUCT  
END_TYPE
```

**bDest\_def:**

**bDest\_p2p:**

**byReserved:**

**eAudio\_type:** (see [E\_LON\_rail\_audio\_type\_t](ms-xhelp:///?Id=beckhoff-5667-460a-80c2-779e2ecbe001)).

**stAddr\_init:** (see [ST\_LON\_addr\_init](ms-xhelp:///?Id=beckhoff-0e40-4e3c-94fa-56de6d1b8bf4)).

**stAddr\_dest:** (see [ST\_LON\_addr\_dest](ms-xhelp:///?Id=beckhoff-37c9-40d5-8196-ebfd5e8fc2a8)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
