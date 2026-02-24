# ST_LON_SNVT_switch_2

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_switch\_2

Used by: SNVT\_switch\_2

```
TYPE ST_LON_SNVT_switch_2 :  
STRUCT  
  eState         : E_LON_switch_state_t;  
  stSetting      : ST_LON_setting;  
  byScene_number : BYTE;  
END_STRUCT  
END_TYPE
```

**eState:** Switch state (see [E\_LON\_switch\_state\_t](ms-xhelp:///?Id=beckhoff-ec46-4057-bde4-30e9529e5b09)). Switch state; maybe a state of the switch or other switch properties such as scene, occupancy state, and level multiplier

**stSetting:** Switch setting. Sets or reports the level, change, or angle for a switch (see [ST\_LON\_setting](ms-xhelp:///?Id=beckhoff-ca30-47fc-8e83-712148d6f92d)).

**byScene\_number:** Min: 1 / Max: 255 / Scene number. Scene number that is applied based on the function specified in the state field.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
