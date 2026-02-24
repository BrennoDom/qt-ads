# ST_LON_SNVT_preset

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_preset

Used by: SNVT\_preset

```
TYPE ST_LON_SNVT_preset :  
STRUCT  
  eLearn        : E_LON_learn_mode_t;  
  uiSelector    : UINT;  
  arrValue      : ARRAY[0..3] OF BYTE;  
  uiDay         : UINT;  
  uiHour        : UINT;  
  uiMinute      : UINT;  
  uiSecond      : UINT;  
  uiMillisecond : UINT;  
END_STRUCT  
END_TYPE
```

**eLearn:** Learn mode (learn mode names) (see [E\_LON\_learn\_mode\_t](ms-xhelp:///?Id=beckhoff-f921-4a46-b40d-07d873cc5707)).

**uiSelector:** Min: 0 / Max: 65535 / Selector (16-bit unsigned value). The selector is used to choose which preset.

**arrValue:** Value (array of 4 bytes).

**uiDay:** Min: 0 / Max: 65535 / Days (days). The value 65535 represents NULL or unknown elapsed time.

**uiHour:** Min: 0 / Max: 23 / Hours (hours). This field uses a 24-hour value.

**uiMinute:** Min: 0 / Max: 59 / Minutes (minutes).

**uiSecond:** Min: 0 / Max: 59 / Seconds (seconds).

**uiMillisecond:** Min: 0 / Max: 999 / Milliseconds (milliseconds).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
