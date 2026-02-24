# ST_LON_SNVT_rac_ctrl

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_rac\_ctrl

Used by: SNVT\_rac\_ctrl

```
TYPE ST_LON_SNVT_rac_ctrl :  
STRUCT  
  byAudio_line : BYTE;  
  bDuplex_full : BOOL;  
  bDest_p2p    : BOOL;  
  byReserved   : BYTE;  
  eAudio_type  : E_LON_rail_audio_type_t;  
  stAddr_init  : ST_LON_addr_init;  
  stAddr_talk  : ST_LON_addr_talk;  
  stAddr_dest  : ST_LON_addr_dest;  
END_STRUCT  
END_TYPE
```

**byAudio\_line:** Min: 0 / Max: 7

**bDuplex\_full:**

**bDest\_p2p:**

**byReserved:**

**eAudio\_type:** (see [E\_LON\_rail\_audio\_type\_t](ms-xhelp:///?Id=beckhoff-5667-460a-80c2-779e2ecbe001)).

**stAddr\_init:** (see [ST\_LON\_addr\_init](ms-xhelp:///?Id=beckhoff-0e40-4e3c-94fa-56de6d1b8bf4)).

**stAddr\_talk:** (see [ST\_LON\_addr\_talk](ms-xhelp:///?Id=beckhoff-5055-4e03-bb06-de4f8607c0a9)).

**stAddr\_dest:** (see [ST\_LON\_addr\_dest](ms-xhelp:///?Id=beckhoff-37c9-40d5-8196-ebfd5e8fc2a8)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
