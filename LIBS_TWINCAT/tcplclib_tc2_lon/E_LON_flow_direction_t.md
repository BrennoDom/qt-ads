# E_LON_flow_direction_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_flow\_direction\_t

Used by: SNVT\_flow\_dir

```
TYPE E_LON_flow_direction_t :  
(  
  eLON_FD_NUL  := -1,  
  eLON_FD_NONE := 0,  
  eLON_FD_OUT  := 1,  
  eLON_FD_IN   := 2,  
  eLON_FD_ANY  := 3  
)  
END_TYPE
```

**eLON\_FD\_NUL:**  Invalid Value

**eLON\_FD\_NONE:**  No flow/movement allowed

**eLON\_FD\_OUT:**  Exit/out/away direction only

**eLON\_FD\_IN:**  Entry/in/toward direction only

**eLON\_FD\_ANY:**  No restriction on flow/movement

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
