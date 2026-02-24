# E_LON_hvac_overid_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_hvac\_overid\_t

Used by: SNVT\_hvac\_overid

```
TYPE E_LON_hvac_overid_t :  
(  
  eLON_HVO_NUL            := -1,  
  eLON_HVO_OFF            := 0,  
  eLON_HVO_POSITION       := 1,  
  eLON_HVO_FLOW_VALUE     := 2,  
  eLON_HVO_FLOW_PERCENT   := 3,  
  eLON_HVO_OPEN           := 4,  
  eLON_HVO_CLOSE          := 5,  
  eLON_HVO_MINIMUM        := 6,  
  eLON_HVO_MAXIMUM        := 7,  
  eLON_HVO_UNUSED8        := 8,  
  eLON_HVO_UNUSED9        := 9,  
  eLON_HVO_UNUSED10       := 10,  
  eLON_HVO_UNUSED11       := 11,  
  eLON_HVO_UNUSED12       := 12,  
  eLON_HVO_UNUSED13       := 13,  
  eLON_HVO_UNUSED14       := 14,  
  eLON_HVO_UNUSED15       := 15,  
  eLON_HVO_UNUSED16       := 16,  
  eLON_HVO_POSITION_1     := 17,  
  eLON_HVO_FLOW_VALUE_1   := 18,  
  eLON_HVO_FLOW_PERCENT_1 := 19,  
  eLON_HVO_OPEN_1         := 20,  
  eLON_HVO_CLOSE_1        := 21,  
  eLON_HVO_MINIMUM_1      := 22,  
  eLON_HVO_MAXIMUM_1      := 23,  
  eLON_HVO_UNUSED24       := 24,  
  eLON_HVO_UNUSED25       := 25,  
  eLON_HVO_UNUSED26       := 26,  
  eLON_HVO_UNUSED27       := 27,  
  eLON_HVO_UNUSED28       := 28,  
  eLON_HVO_UNUSED29       := 29,  
  eLON_HVO_UNUSED30       := 30,  
  eLON_HVO_UNUSED31       := 31,  
  eLON_HVO_UNUSED32       := 32,  
  eLON_HVO_POSITION_2     := 33,  
  eLON_HVO_FLOW_VALUE_2   := 34,  
  eLON_HVO_FLOW_PERCENT_2 := 35,  
  eLON_HVO_OPEN_2         := 36,  
  eLON_HVO_CLOSE_2        := 37,  
  eLON_HVO_MINIMUM_2      := 38,  
  eLON_HVO_MAXIMUM_2      := 39,  
  eLON_HVO_UNUSED40       := 40,  
  eLON_HVO_UNUSED41       := 41,  
  eLON_HVO_UNUSED42       := 42,  
  eLON_HVO_UNUSED43       := 43,  
  eLON_HVO_UNUSED44       := 44,  
  eLON_HVO_UNUSED45       := 45,  
  eLON_HVO_UNUSED46       := 46,  
  eLON_HVO_UNUSED47       := 47,  
  eLON_HVO_UNUSED48       := 48  
)  
END_TYPE
```

**eLON\_HVO\_NUL:**  Invalid Value

**eLON\_HVO\_OFF:**  Not overridden

**eLON\_HVO\_POSITION:**

**eLON\_HVO\_FLOW\_VALUE:**  Override flow in liters/sec - use flow field

**eLON\_HVO\_FLOW\_PERCENT:**  Override flow percentage - use percent field

**eLON\_HVO\_OPEN:**  Override to position = 100%

**eLON\_HVO\_CLOSE:**  Override to position = 0%

**eLON\_HVO\_MINIMUM:**  Override to configured minimum

**eLON\_HVO\_MAXIMUM:**  Override to configured maximum

**eLON\_HVO\_UNUSED8:**

**eLON\_HVO\_UNUSED9:**

**eLON\_HVO\_UNUSED10:**

**eLON\_HVO\_UNUSED11:**

**eLON\_HVO\_UNUSED12:**

**eLON\_HVO\_UNUSED13:**

**eLON\_HVO\_UNUSED14:**

**eLON\_HVO\_UNUSED15:**

**eLON\_HVO\_UNUSED16:**

**eLON\_HVO\_POSITION\_1:**

**eLON\_HVO\_FLOW\_VALUE\_1:**  Override flow in liters/sec - use flow field

**eLON\_HVO\_FLOW\_PERCENT\_1:**  Override flow percentage - use percent field

**eLON\_HVO\_OPEN\_1:**  Override to position = 100%

**eLON\_HVO\_CLOSE\_1:**  Override to position = 0%

**eLON\_HVO\_MINIMUM\_1:**  Override to configured minimum

**eLON\_HVO\_MAXIMUM\_1:**  Override to configured maximum

**eLON\_HVO\_UNUSED24:**

**eLON\_HVO\_UNUSED25:**

**eLON\_HVO\_UNUSED26:**

**eLON\_HVO\_UNUSED27:**

**eLON\_HVO\_UNUSED28:**

**eLON\_HVO\_UNUSED29:**

**eLON\_HVO\_UNUSED30:**

**eLON\_HVO\_UNUSED31:**

**eLON\_HVO\_UNUSED32:**

**eLON\_HVO\_POSITION\_2:**

**eLON\_HVO\_FLOW\_VALUE\_2:**  Override flow in liters/sec - use flow field

**eLON\_HVO\_FLOW\_PERCENT\_2:**  Override flow percentage - use percent field

**eLON\_HVO\_OPEN\_2:**  Override to position = 100%

**eLON\_HVO\_CLOSE\_2:**  Override to position = 0%

**eLON\_HVO\_MINIMUM\_2:**  Override to configured minimum

**eLON\_HVO\_MAXIMUM\_2:**  Override to configured maximum

**eLON\_HVO\_UNUSED40:**

**eLON\_HVO\_UNUSED41:**

**eLON\_HVO\_UNUSED42:**

**eLON\_HVO\_UNUSED43:**

**eLON\_HVO\_UNUSED44:**

**eLON\_HVO\_UNUSED45:**

**eLON\_HVO\_UNUSED46:**

**eLON\_HVO\_UNUSED47:**

**eLON\_HVO\_UNUSED48:**

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
