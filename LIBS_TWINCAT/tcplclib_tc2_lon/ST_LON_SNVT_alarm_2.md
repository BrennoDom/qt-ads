# ST_LON_SNVT_alarm_2

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_alarm\_2

Used by: SNVT\_alarm\_2

```
TYPE ST_LON_SNVT_alarm_2 :  
STRUCT  
  eAlarm_type       : E_LON_alarm_type_t;  
  ePriority_level   : E_LON_priority_level_t;  
  udiAlarm_time     : UDINT;  
  iMilliseconds     : INT;  
  bySequence_number : BYTE;  
  sDescription      : STRING(22);  
END_STRUCT  
END_TYPE
```

**eAlarm\_type:** Alarm type (alarm type names).Alarm condition reported by this update (see [E\_LON\_alarm\_type\_t](ms-xhelp:///?Id=beckhoff-8d76-4977-ac66-fe03e814ac0c)).

**ePriority\_level:** Priority level (priority level names).Priority level of the alarm reported by this update (see [E\_LON\_priority\_level\_t](ms-xhelp:///?Id=beckhoff-547f-4059-a509-dba364144176)).

**udiAlarm\_time:** Alarm time (seconds). Alarm time in seconds since 2000-01-01T00:00:00Z (the 0 hour of 1 January 2000, Coordinated Universal Time)

**iMilliseconds:** Milliseconds (milliseconds). Alarm time in milliseconds since the second specified by the alarm\_time field

**bySequence\_number:** Sequence number(count). Sequence number for this update. Incremented by one for each update from an alarm source. Wraps to zero after reaching 255. An alarm receiver can use the sequence number to detect missed alarm messages.

**sDescription:** Description (array of 22 characters). Alarm description with NUL terminator. The terminator is not required if the description requires 22 characters. May include a reference to a language string, delimited by a 0x80 value.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
