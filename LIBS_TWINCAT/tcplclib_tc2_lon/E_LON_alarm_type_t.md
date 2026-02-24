# E_LON_alarm_type_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_alarm\_type\_t

Used by: SNVT\_alarm / SNVT\_alarm\_2

```
TYPE E_LON_alarm_type_t :  
(  
  eLON_AL_HEADER           := -13,  
  eLON_AL_FOOTER           := -12,  
  eLON_AL_DEBUG            := -11,  
  eLON_AL_INFO             := -10,  
  eLON_AL_SYSTEM_INFO      := -6,  
  eLON_AL_VALUE_INVALID    := -5,  
  eLON_AL_CONSTANT         := -4,  
  eLON_AL_OFFLINE          := -3,  
  eLON_AL_UNKNOWN          := -2,  
  eLON_AL_NUL              := -1,  
  eLON_AL_NO_CONDITION     := 0,  
  eLON_AL_ALM_CONDITION    := 1,  
  eLON_AL_TOT_SVC_ALM_1    := 2,  
  eLON_AL_TOT_SVC_ALM_2    := 3,  
  eLON_AL_TOT_SVC_ALM_3    := 4,  
  eLON_AL_LOW_LMT_CLR_1    := 5,  
  eLON_AL_LOW_LMT_CLR_2    := 6,  
  eLON_AL_HIGH_LMT_CLR_1   := 7,  
  eLON_AL_HIGH_LMT_CLR_2   := 8,  
  eLON_AL_LOW_LMT_ALM_1    := 9,  
  eLON_AL_LOW_LMT_ALM_2    := 10,  
  eLON_AL_HIGH_LMT_ALM_1   := 11,  
  eLON_AL_HIGH_LMT_ALM_2   := 12,  
  eLON_AL_FIR_ALM          := 13,  
  eLON_AL_FIR_PRE_ALM      := 14,  
  eLON_AL_FIR_TRBL         := 15,  
  eLON_AL_FIR_SUPV         := 16,  
  eLON_AL_FIR_TEST_ALM     := 17,  
  eLON_AL_FIR_TEST_PRE_ALM := 18,  
  eLON_AL_FIR_ENVCOMP_MAX  := 19,  
  eLON_AL_FIR_MONITOR_COND := 20,  
  eLON_AL_FIR_MAINT_ALERT  := 21,  
  eLON_AL_FATAL_ERROR      := 30,  
  eLON_AL_ERROR            := 31,  
  eLON_AL_WARNING          := 32  
)  
END_TYPE
```

**eLON\_AL\_HEADER:**  Update sequence header

**eLON\_AL\_FOOTER:**  Update sequence footer

**eLON\_AL\_DEBUG:**  Debug information (not an alarm)

**eLON\_AL\_INFO:**  Information update (not an alarm)

**eLON\_AL\_SYSTEM\_INFO:**  System information (not an alarm)

**eLON\_AL\_VALUE\_INVALID:**  The value is invalid

**eLON\_AL\_CONSTANT:**  The value is a constant value (not an alarm)

**eLON\_AL\_OFFLINE:**  The device is offline

**eLON\_AL\_UNKNOWN:**  Alarm condition unknown (may be due to a communication failure or hardware failure)

**eLON\_AL\_NUL:**  Invalid alarm type value (alarm condition not specified)

**eLON\_AL\_NO\_CONDITION:**  No alarm condition present

**eLON\_AL\_ALM\_CONDITION:**  Unspecified alarm condition present

**eLON\_AL\_TOT\_SVC\_ALM\_1:**  Total/service interval alarm 1 (component requires service or maintenance)

**eLON\_AL\_TOT\_SVC\_ALM\_2:**  Total/service interval alarm 2

**eLON\_AL\_TOT\_SVC\_ALM\_3:**  Total/service interval alarm 3

**eLON\_AL\_LOW\_LMT\_CLR\_1:**  Alarm low limit alarm clear 1

**eLON\_AL\_LOW\_LMT\_CLR\_2:**  Alarm low limit alarm clear 2

**eLON\_AL\_HIGH\_LMT\_CLR\_1:**  Alarm high limit alarm clear 1

**eLON\_AL\_HIGH\_LMT\_CLR\_2:**  Alarm high limit alarm clear 2

**eLON\_AL\_LOW\_LMT\_ALM\_1:**  Alarm low limit alarm 1

**eLON\_AL\_LOW\_LMT\_ALM\_2:**  Alarm low limit alarm 2

**eLON\_AL\_HIGH\_LMT\_ALM\_1:**  Alarm high limit alarm 1

**eLON\_AL\_HIGH\_LMT\_ALM\_2:**  Alarm high limit alarm 2

**eLON\_AL\_FIR\_ALM:**  Fire alarm condition

**eLON\_AL\_FIR\_PRE\_ALM:**  Fire pre-alarm condition

**eLON\_AL\_FIR\_TRBL:**  Fire-related trouble (fault) condition

**eLON\_AL\_FIR\_SUPV:**  Fire-related supervisory condition (e.g., sprinkler pressure)

**eLON\_AL\_FIR\_TEST\_ALM:**  Fire-related test-mode alarm condition

**eLON\_AL\_FIR\_TEST\_PRE\_ALM:**  Fire-related test-mode pre-alarm condition

**eLON\_AL\_FIR\_ENVCOMP\_MAX:**  Fire-related maximum environmental compensation level reached

**eLON\_AL\_FIR\_MONITOR\_COND:**  Fire-related abnormal input condition

**eLON\_AL\_FIR\_MAINT\_ALERT:**  Fire-related maintenance alert

**eLON\_AL\_FATAL\_ERROR:**  Fatal application error

**eLON\_AL\_ERROR:**  Other error condition

**eLON\_AL\_WARNING:**  Other warning condition

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
