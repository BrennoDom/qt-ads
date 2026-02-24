# E_LON_sec_status_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_sec\_status\_t

Used by: SNVT\_sec\_status

```
TYPE E_LON_sec_status_t :  
(  
  eLON_SSS_NUL                   := -1,  
  eLON_SSS_POWER_UP              := 0,  
  eLON_SSS_ALARM_RESET           := 1,  
  eLON_SSS_ALARM                 := 2,  
  eLON_SSS_TAMPER_RESET          := 3,  
  eLON_SSS_TAMPER                := 4,  
  eLON_SSS_MAINTENANCE           := 5,  
  eLON_SSS_TROUBLE               := 6,  
  eLON_SSS_FAULT                 := 7,  
  eLON_SSS_RECOVERED_SENSOR      := 8,  
  eLON_SSS_LOST_SENSOR           := 9,  
  eLON_SSS_POLL_ACTIVE           := 10,  
  eLON_SSS_POLL_INACTIVE         := 11,  
  eLON_SSS_POLL_TAMPER           := 12,  
  eLON_SSS_POLL_ON               := 13,  
  eLON_SSS_POLL_OFF              := 14,  
  eLON_SSS_POLL_INHIBIT          := 15,  
  eLON_SSS_POLL_TEST             := 16,  
  eLON_SSS_CONFIRM_OFF           := 17,  
  eLON_SSS_CONFIRM_ON            := 18,  
  eLON_SSS_CONFIRM_INHIBIT_RESET := 19,  
  eLON_SSS_CONFIRM_INHIBIT       := 20,  
  eLON_SSS_CONFIRM_WALK_TEST_OFF := 21,  
  eLON_SSS_CONFIRM_WALK_TEST_ON  := 22,  
  eLON_SSS_CONFIRM_TEST_MODE_OFF := 23,  
  eLON_SSS_CONFIRM_TEST_MODE_ON  := 24,  
  eLON_SSS_CONFIRM_UNSUPPORTED   := 25  
)  
END_TYPE
```

**eLON\_SSS\_NUL:**

**eLON\_SSS\_POWER\_UP:**

**eLON\_SSS\_ALARM\_RESET:**

**eLON\_SSS\_ALARM:**

**eLON\_SSS\_TAMPER\_RESET:**

**eLON\_SSS\_TAMPER:**

**eLON\_SSS\_MAINTENANCE:**

**eLON\_SSS\_TROUBLE:**

**eLON\_SSS\_FAULT:**

**eLON\_SSS\_RECOVERED\_SENSOR:**

**eLON\_SSS\_LOST\_SENSOR:**

**eLON\_SSS\_POLL\_ACTIVE:**

**eLON\_SSS\_POLL\_INACTIVE:**

**eLON\_SSS\_POLL\_TAMPER:**

**eLON\_SSS\_POLL\_ON:**

**eLON\_SSS\_POLL\_OFF:**

**eLON\_SSS\_POLL\_INHIBIT:**

**eLON\_SSS\_POLL\_TEST:**

**eLON\_SSS\_CONFIRM\_OFF:**

**eLON\_SSS\_CONFIRM\_ON:**

**eLON\_SSS\_CONFIRM\_INHIBIT\_RESET:**

**eLON\_SSS\_CONFIRM\_INHIBIT:**

**eLON\_SSS\_CONFIRM\_WALK\_TEST\_OFF:**

**eLON\_SSS\_CONFIRM\_WALK\_TEST\_ON:**

**eLON\_SSS\_CONFIRM\_TEST\_MODE\_OFF:**

**eLON\_SSS\_CONFIRM\_TEST\_MODE\_ON:**

**eLON\_SSS\_CONFIRM\_UNSUPPORTED:**

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
