# ST_LON_SNVT_tod_event

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_tod\_event

Used by: SNVT\_tod\_event

```
TYPE ST_LON_SNVT_tod_event :  
STRUCT  
  eCurrent_state       : E_LON_occup_t;  
  eNext_state          : E_LON_occup_t;  
  uiTime_to_next_state : UINT;  
END_STRUCT  
END_TYPE
```

**eCurrent\_state:** Occupancy, current (occupancy code names) (see [E\_LON\_occup\_t](ms-xhelp:///?Id=beckhoff-b931-4462-9cd0-33d215143690)).

**eNext\_state:** Occupancy, next (occupancy code names) (see [E\_LON\_occup\_t](ms-xhelp:///?Id=beckhoff-b931-4462-9cd0-33d215143690)).

**uiTime\_to\_next\_state:** Min: 0 / Max: 65535 / Time to next state (minutes).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
