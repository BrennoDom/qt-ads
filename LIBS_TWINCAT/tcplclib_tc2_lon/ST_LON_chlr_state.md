# ST_LON_chlr_state

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_chlr\_state

Used by: SNVT\_chlr\_status

```
TYPE ST_LON_chlr_state :  
STRUCT  
  bIn_alarm    : BOOL;  
  bRun_enabled : BOOL;  
  bLocal       : BOOL;  
  bLimited     : BOOL;  
  bChw_flow    : BOOL;  
  bCondw_flow  : BOOL;  
END_STRUCT  
END_TYPE
```

**bIn\_alarm:** Alarm flag (boolean).

**bRun\_enabled:** Run-enabled flag (boolean).

**bLocal:** Locally-controlled flag (boolean).

**bLimited:** Limited-condition flag (boolean). Conditions may exist that prevent reaching the setpoint

**bChw\_flow:** Chiller-water-flow flag (boolean).

**bCondw\_flow:** Condenser-water-flow flag (boolean).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
