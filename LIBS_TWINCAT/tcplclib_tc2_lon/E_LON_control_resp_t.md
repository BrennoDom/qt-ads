# E_LON_control_resp_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_control\_resp\_t

Used by: SNVT\_ctrl\_resp

```
TYPE E_LON_control_resp_t :  
(  
  eLON_CTRLR_NUL   := -1,  
  eLON_CTRLR_NO    := 0,  
  eLON_CTRLR_PEND  := 1,  
  eLON_CTRLR_REL   := 2,  
  eLON_CTRLR_QUERY := 3,  
  eLON_CTRLR_RES   := 4,  
  eLON_CTRLR_ERR   := 5  
)  
END_TYPE
```

**eLON\_CTRLR\_NUL:**  Invalid value

**eLON\_CTRLR\_NO:**  Number of current controller

**eLON\_CTRLR\_PEND:**  Request pending due to control query to current operator

**eLON\_CTRLR\_REL:**  Current control released

**eLON\_CTRLR\_QUERY:**  Query to current controller

**eLON\_CTRLR\_RES:**  Controllable device has been reset

**eLON\_CTRLR\_ERR:**  Error in control

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
