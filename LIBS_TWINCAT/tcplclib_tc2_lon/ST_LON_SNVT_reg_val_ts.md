# ST_LON_SNVT_reg_val_ts

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_reg\_val\_ts

Used by: SNVT\_rac\_val\_ts

```
TYPE ST_LON_SNVT_reg_val_ts :  
STRUCT  
  diRaw         : DINT;  
  eUnit         : E_LON_reg_val_unit_t;  
  byNr_decimals : BYTE;  
  byStatus      : BYTE;  
  bReg_state    : BOOL;  
  uiYear        : UINT;  
  uiMonth       : UINT;  
  uiDay         : UINT;  
  uiHour        : UINT;  
  uiMinute      : UINT;  
  uiSecond      : UINT;  
END_STRUCT  
END_TYPE
```

**diRaw:** Min: -2147483648 / Max: 2147483647 / Raw value.

**eUnit:** Unit code (unit names) (see [E\_LON\_reg\_val\_unit\_t](ms-xhelp:///?Id=beckhoff-388f-4d03-98ae-5ddacd938137)).

**byNr\_decimals:** Min: 0 / Max: 7 / Number of decimals (digits to right of decimal point).

**byStatus:** Min: 0 / Max: 15 / Status (status or error during measuring period).

**bReg\_state:** Activation state (activation state of register).

**uiYear:** Min: -1 / Max: 3000 / Year (years). Zero (0) means year not specified. Minus one (-1) represents NULL date.

**uiMonth:** Min: 0 / Max: 12 / Month (months). Zero (0) means month not specified.

**uiDay:** Min: 0 / Max: 31 / Day (days). Zero (0) means day not specified.

**uiHour:** Min: 0 / Max: 23 / Hour (hours). This field uses a 24-hour value.

**uiMinute:** Min: 0 / Max: 59 / Minute (minutes).

**uiSecond:** Min: 0 / Max: 59 / Second (seconds).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
