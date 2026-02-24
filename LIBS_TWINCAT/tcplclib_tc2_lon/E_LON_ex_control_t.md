# E_LON_ex_control_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_ex\_control\_t

Used by: SNVT\_ex\_control

```
TYPE E_LON_ex_control_t :  
(  
  eLON_EX_CONTROL_NUL       := -1,  
  eLON_EX_CONTROL_NONE      := 0,  
  eLON_EX_CONTROL_OTHER     := 1,  
  eLON_EX_CONTROL_THIS_ADDR := 2  
)  
END_TYPE
```

**eLON\_EX\_CONTROL\_NUL:**  The control status of the item is unknown

**eLON\_EX\_CONTROL\_NONE:**  Nothing has control of the item.

**eLON\_EX\_CONTROL\_OTHER:**  Some unidentified entity has control of the item.

**eLON\_EX\_CONTROL\_THIS\_ADDR:**  A device has control of the item. The network address of this device is specified in the control\_device\_addr

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
