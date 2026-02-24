# E_LON_calendar_type_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_calendar\_type\_t

Used by: SNVT\_time\_zone

```
TYPE E_LON_calendar_type_t :  
(  
  eLON_CAL_NUL  := -1,  
  eLON_CAL_GREG := 0,  
  eLON_CAL_JUL  := 1,  
  eLON_CAL_MEU  := 2  
)  
END_TYPE
```

**eLON\_CAL\_NUL:**  Invalid Value

**eLON\_CAL\_GREG:**  Gregorian calendar

**eLON\_CAL\_JUL:**  Julian calendar

**eLON\_CAL\_MEU:**  Calendar Method European/US "MEU"

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
