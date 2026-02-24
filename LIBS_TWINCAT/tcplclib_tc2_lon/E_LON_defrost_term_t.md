# E_LON_defrost_term_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_defrost\_term\_t

Used by: SNVT\_defr\_term

```
TYPE E_LON_defrost_term_t :  
(  
  eLON_DFT_NUL            := -1,  
  eLON_DFT_TERM_TEMP      := 0,  
  eLON_DFT_TERM_TIME      := 1,  
  eLON_DFT_TERM_FIRST     := 2,  
  eLON_DFT_TERM_LAST      := 3,  
  eLON_DFT_TERM_SENSOR    := 4,  
  eLON_DFT_TERM_DISCHARGE := 5,  
  eLON_DFT_TERM_RETURN    := 6,  
  eLON_DFT_TERM_SW_OPEN   := 7,  
  eLON_DFT_TERM_SW_CLOSE  := 8,  
  eLON_DFT_TERM_MANUF     := 100  
)  
END_TYPE
```

**eLON\_DFT\_NUL:**  Invalid Value

**eLON\_DFT\_TERM\_TEMP:**  Terminate on temperature

**eLON\_DFT\_TERM\_TIME:**  Terminate on time

**eLON\_DFT\_TERM\_FIRST:**  Terminate on first occurring

**eLON\_DFT\_TERM\_LAST:**  Terminate on last occurring

**eLON\_DFT\_TERM\_SENSOR:**  Terminate on sensor

**eLON\_DFT\_TERM\_DISCHARGE:**  Terminate on discharge

**eLON\_DFT\_TERM\_RETURN:**  Terminate on return

**eLON\_DFT\_TERM\_SW\_OPEN:**  Terminate on "Switch Open"

**eLON\_DFT\_TERM\_SW\_CLOSE:**  Terminate on "Switch Closed"

**eLON\_DFT\_TERM\_MANUF:**  Manufacturer-Defined termination state

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
