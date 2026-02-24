# E_LON_fire_test_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_fire\_test\_t

Used by: SNVT\_fire\_test

```
TYPE E_LON_fire_test_t :  
(  
  eLON_FT_NUL    := -1,  
  eLON_FT_NORMAL := 0,  
  eLON_FT_RESET  := 1,  
  eLON_FT_TEST   := 2,  
  eLON_FT_NOTEST := 3  
)  
END_TYPE
```

**eLON\_FT\_NUL:**  Invalid Value

**eLON\_FT\_NORMAL:**  Return object to normal status

**eLON\_FT\_RESET:**  Perform a RESET function (for smoke detectors)

**eLON\_FT\_TEST:**  Go into TEST mode

**eLON\_FT\_NOTEST:**  Exit TEST mode

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
