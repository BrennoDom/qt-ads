# E_LON_scene_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_scene\_t

Used by: SNVT\_scene

```
TYPE E_LON_scene_t :  
(  
  eLON_SC_NUL            := -1,  
  eLON_SC_RECALL         := 0,  
  eLON_SC_LEARN          := 1,  
  eLON_SC_DISPLAY        := 2,  
  eLON_SC_GROUP_OFF      := 3,  
  eLON_SC_GROUP_ON       := 4,  
  eLON_SC_STATUS_OFF     := 5,  
  eLON_SC_STATUS_ON      := 6,  
  eLON_SC_STATUS_MIXED   := 7,  
  eLON_SC_GROUP_STATUS   := 8,  
  eLON_SC_FLICK          := 9,  
  eLON_SC_TIMEOUT        := 10,  
  eLON_SC_TIMEOUT_FLICK  := 11,  
  eLON_SC_DELAYOFF       := 12,  
  eLON_SC_DELAYOFF_FLICK := 13,  
  eLON_SC_DELAYON        := 14,  
  eLON_SC_ENABLE_GROUP   := 15,  
  eLON_SC_DISABLE_GROUP  := 16,  
  eLON_SC_CLEANON        := 17,  
  eLON_SC_CLEANOFF       := 18,  
  eLON_SC_WINK           := 19,  
  eLON_SC_RESET          := 20,  
  eLON_SC_MODE1          := 21,  
  eLON_SC_MODE2          := 22,  
  eLON_SC_MODE3          := 23  
)  
END_TYPE
```

**eLON\_SC\_NUL:**  Invalid value

**eLON\_SC\_RECALL:**  Recall a specified scene.

**eLON\_SC\_LEARN:**  Store the current setting in the specified scene.

**eLON\_SC\_DISPLAY:**  Display the current scene.

**eLON\_SC\_GROUP\_OFF:**  Report current group is off.

**eLON\_SC\_GROUP\_ON:**  Report current group is on.

**eLON\_SC\_STATUS\_OFF:**  Report current status is off.

**eLON\_SC\_STATUS\_ON:**  Report current status is on.

**eLON\_SC\_STATUS\_MIXED:**  Report current status is mixed.

**eLON\_SC\_GROUP\_STATUS:**  Get group status.

**eLON\_SC\_FLICK:**  Toggle state off and then on.

**eLON\_SC\_TIMEOUT:**  Report a timeout occurred.

**eLON\_SC\_TIMEOUT\_FLICK:**  Report a timeout occurred for a flick warning.

**eLON\_SC\_DELAYOFF:**  Set the state to off after a delay.

**eLON\_SC\_DELAYOFF\_FLICK:**  Flick and then set the state to off after a delay.

**eLON\_SC\_DELAYON:**  Set the state to on after a delay.

**eLON\_SC\_ENABLE\_GROUP:**  Enable the current group.

**eLON\_SC\_DISABLE\_GROUP:**  Disable the current group.

**eLON\_SC\_CLEANON:**  Recall the cleaning scene.

**eLON\_SC\_CLEANOFF:**  Restore the previous scene.

**eLON\_SC\_WINK:**  Toggle to the opposite state and then restore the state.

**eLON\_SC\_RESET:**  Restore the factory default scene table.

**eLON\_SC\_MODE1:**  Manufacturer-specific mode 1.

**eLON\_SC\_MODE2:**  Manufacturer-specific mode 2.

**eLON\_SC\_MODE3:**  Manufacturer-specific mode 3.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
