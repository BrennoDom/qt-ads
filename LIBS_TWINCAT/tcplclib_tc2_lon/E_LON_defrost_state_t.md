# E_LON_defrost_state_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_defrost\_state\_t

Used by: SNVT\_defr\_state

```
TYPE E_LON_defrost_state_t :  
(  
  eLON_DFS_NUL        := -1,  
  eLON_DFS_STANDBY    := 0,  
  eLON_DFS_PUMPDOWN   := 1,  
  eLON_DFS_DEFROST    := 2,  
  eLON_DFS_DRAINDOWN  := 3,  
  eLON_DFS_INJECT_DLY := 4  
)  
END_TYPE
```

**eLON\_DFS\_NUL:**  Invalid Value

**eLON\_DFS\_STANDBY:**  Defrost in standby

**eLON\_DFS\_PUMPDOWN:**  Defrost in pump-down mode

**eLON\_DFS\_DEFROST:**  In defrost mode

**eLON\_DFS\_DRAINDOWN:**  Defrost in drain-down

**eLON\_DFS\_INJECT\_DLY:**  Defrost in injection delay

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
