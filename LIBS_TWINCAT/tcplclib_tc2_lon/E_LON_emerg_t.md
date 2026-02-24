# E_LON_emerg_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_emerg\_t

Used by: SNVT\_hvac\_emerg

```
TYPE E_LON_emerg_t :  
(  
  eLON_EMERG_NUL          := -1,  
  eLON_EMERG_NORMAL       := 0,  
  eLON_EMERG_PRESSURIZE   := 1,  
  eLON_EMERG_DEPRESSURIZE := 2,  
  eLON_EMERG_PURGE        := 3,  
  eLON_EMERG_SHUTDOWN     := 4,  
  eLON_EMERG_FIRE         := 5  
)  
END_TYPE
```

**eLON\_EMERG\_NUL:**  Invalid Value

**eLON\_EMERG\_NORMAL:**  No emergency mode

**eLON\_EMERG\_PRESSURIZE:**  Emergency pressurize mode

**eLON\_EMERG\_DEPRESSURIZE:**  Emergency depressurize mode

**eLON\_EMERG\_PURGE:**  Emergency purge mode

**eLON\_EMERG\_SHUTDOWN:**  Emergency shutdown mode

**eLON\_EMERG\_FIRE:**  Emergency fire mode

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
