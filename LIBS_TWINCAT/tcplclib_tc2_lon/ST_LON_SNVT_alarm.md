# ST_LON_SNVT_alarm

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_alarm

Used by: SNVT\_alarm

```
TYPE ST_LON_SNVT_alarm :  
STRUCT  
  arrLocation     : ARRAY[0..5] OF BYTE;  
  uiObject_Id     : UINT;  
  eAlarm_type     : E_LON_alarm_type_t;  
  ePriorty_level  : E_LON_priority_level_t;  
  uiIndex_To_SNVT : WORD;  
  arrValue        : ARRAY[0..3] OF BYTE;  
  uiYear          : UINT;  
  uiMonth         : UINT;  
  uiDay           : UINT;  
  uiHour          : UINT;  
  uiMinute        : UINT;  
  uiSecond        : UINT;  
  uiMilliseconds  : UINT;  
  arrAlarm_limit  : ARRAY[0..3] OF BYTE;  
END_STRUCT  
END_TYPE
```

**arrLocation:** Location (array of 6 bytes). Location code for the node

**uiObject\_Id:** Object ID (object index). ID of object within node

**eAlarm\_type:** Alarm type (alarm type names) (see [E\_LON\_alarm\_type\_t](ms-xhelp:///?Id=beckhoff-8d76-4977-ac66-fe03e814ac0c)).

**ePriorty\_level:** Priority level (priority level names) (see [E\_LON\_priority\_level\_t](ms-xhelp:///?Id=beckhoff-547f-4059-a509-dba364144176)).

**uiIndex\_To\_SNVT:** Index of NV (index of NV causing alarm).

**arrValue:** Value (array of 4 bytes). The type of this field is dependent on the NV causing the alarm condition.

**uiYear:** Year (years). Zero (0) means year not specified.

**uiMonth:** Month (months). Zero (0) means month not specified.

**uiDay:** Day (days). Zero (0) means day not specified.

**uiHour:** Hour (hours). This field uses a 24-hour value.

**uiMinute:** Minute (minutes).

**uiSecond:** Second (seconds).

**uiMilliseconds:** Millisecond (milliseconds).

**arrAlarm\_limit:** Alarm limit (array of 4 bytes). The type of this field is dependent on the NV causing the alarm condition.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
