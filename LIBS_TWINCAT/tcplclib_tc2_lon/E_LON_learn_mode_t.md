# E_LON_learn_mode_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_learn\_mode\_t

Used by: SNVT\_preset

```
TYPE E_LON_learn_mode_t :  
(  
  eLON_LN_NUL           := -1,  
  eLON_LN_RECALL        := 0,  
  eLON_LN_LEARN_CURRENT := 1,  
  eLON_LN_LEARN_VALUE   := 2,  
  eLON_LN_REPORT_VALUE  := 3  
)  
END_TYPE
```

**eLON\_LN\_NUL:**  Invalid Value

**eLON\_LN\_RECALL:**  Recall

**eLON\_LN\_LEARN\_CURRENT:**  Learn present value

**eLON\_LN\_LEARN\_VALUE:**  Learn given value

**eLON\_LN\_REPORT\_VALUE:**  Report the value

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
