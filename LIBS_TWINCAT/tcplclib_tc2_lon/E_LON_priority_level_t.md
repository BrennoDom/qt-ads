# E_LON_priority_level_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_priority\_level\_t

Used by: SNVT\_alarm / SNVT\_alarm\_2 / SNVT\_pumpset\_mn

```
TYPE E_LON_priority_level_t :  
(  
  eLON_PR_NUL     := -1,  
  eLON_PR_LEVEL_0 := 0,  
  eLON_PR_LEVEL_1 := 1,  
  eLON_PR_LEVEL_2 := 2,  
  eLON_PR_LEVEL_3 := 3,  
  eLON_PR_1       := 4,  
  eLON_PR_2       := 5,  
  eLON_PR_3       := 6,  
  eLON_PR_4       := 7,  
  eLON_PR_6       := 8,  
  eLON_PR_8       := 9,  
  eLON_PR_10      := 10,  
  eLON_PR_16      := 11  
)  
END_TYPE
```

**eLON\_PR\_NUL:**  Invalid Value

**eLON\_PR\_LEVEL\_0:**  Lowest alarm priority level

**eLON\_PR\_LEVEL\_1:**

**eLON\_PR\_LEVEL\_2:**

**eLON\_PR\_LEVEL\_3:**  Highest alarm priority level

**eLON\_PR\_1:**  Life Safety Fire Alarms (BACnet Priority 2)

**eLON\_PR\_2:**  Property Safety Fire Alarms (BACnet Priority 3)

**eLON\_PR\_3:**  Fire Supervisory Alarm (BACnet Priority 4)

**eLON\_PR\_4:**  Fire Trouble/Fault (Display) (BACnet Priority 5)

**eLON\_PR\_6:**  Fire Pre-Alarm, HVAC Critical Equipment Alarm (BACnet Priority 6)

**eLON\_PR\_8:**  HVAC Alarms (BACnet Priority 8)

**eLON\_PR\_10:**  HVAC Critical Equipment RTN, Fire RTN (Display) (BACnet Priority 10)

**eLON\_PR\_16:**  HVAC RTN (lowest priority) (BACnet Priority 16)

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
