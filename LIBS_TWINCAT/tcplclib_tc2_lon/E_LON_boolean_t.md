# E_LON_boolean_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_boolean\_t

Used by: SCPTautoAnswer / SCPTcoolingResetEnable / SCPTdefrostHold / SCPTdefrostInternalSchedule / SCPTheatingResetEnable / SCPThighLimit1Enable / SCPThighLimit2Enable / SCPTlowLimit1Enable / SCPTlowLimit2Enable / SCPTscheduleInternal / SNVT\_clothes\_w\_c / SNVT\_pump\_sensor / SNVT\_pumpset\_mn / SNVT\_pumpset\_sn

```
TYPE E_LON_boolean_t :  
(  
  eLON_BOOL_NUL   := -1,  
  eLON_BOOL_FALSE := 0,  
  eLON_BOOL_TRUE  := 1  
)  
END_TYPE
```

**eLON\_BOOL\_NUL:**  Invalid Value

**eLON\_BOOL\_FALSE:**  False

**eLON\_BOOL\_TRUE:**  True

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
