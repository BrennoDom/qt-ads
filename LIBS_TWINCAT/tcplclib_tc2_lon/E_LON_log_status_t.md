# E_LON_log_status_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_log\_status\_t

Used by: SCPTlogRecord / SNVT\_log\_status

```
TYPE E_LON_log_status_t :  
(  
  eLON_LS_NUL             := -1,  
  eLON_LS_ENABLED         := 0,  
  eLON_LS_DISABLED        := 1,  
  eLON_LS_FULL            := 2,  
  eLON_LS_OVERFLOW_ERR    := 3,  
  eLON_LS_INVALID_LOG_ERR := 4,  
  eLON_LS_APP_ERR         := 5  
)  
END_TYPE
```

**eLON\_LS\_NUL:**  Invalid value

**eLON\_LS\_ENABLED:**  Log enabled

**eLON\_LS\_DISABLED:**  Log disabled

**eLON\_LS\_FULL:**  Log enabled and full

**eLON\_LS\_OVERFLOW\_ERR:**  Log enabled, overflow occurred

**eLON\_LS\_INVALID\_LOG\_ERR:**  Invalid log selected

**eLON\_LS\_APP\_ERR:**  Other application error

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
