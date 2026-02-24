# E_LON_device_c_mode_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_device\_c\_mode\_t

Used by: SNVT\_dev\_c\_mode

```
TYPE E_LON_device_c_mode_t :  
(  
  eLON_DCM_NUL             := -1,  
  eLON_DCM_SPEED_CONST     := 0,  
  eLON_DCM_PRESS_CONST     := 1,  
  eLON_DCM_PRESS_COMP      := 2,  
  eLON_DCM_FLOW_CONST      := 3,  
  eLON_DCM_FLOW_COMP       := 4,  
  eLON_DCM_TEMP_CONST      := 5,  
  eLON_DCM_TEMP_COMP       := 6,  
  eLON_DCM_PRESS_AUTO      := 7,  
  eLON_DCM_QUICK_OPEN      := 20,  
  eLON_DCM_LINEAR          := 21,  
  eLON_DCM_EQUAL_PERCENT   := 22,  
  eLON_DCM_QUADRATIC       := 23,  
  eLON_DCM_FREE_DEFINED    := 24,  
  eLON_DCM_2WAY_VALVE      := 27,  
  eLON_DCM_MIXING_VALVE    := 28,  
  eLON_DCM_DIVERTING_VALVE := 29,  
  eLON_DCM_INVFNC_QCK_OPN  := 30,  
  eLON_DCM_INVFNC_EQL_PERC := 31,  
  eLON_DCM_INVFNC_QUAD     := 32  
)  
END_TYPE
```

**eLON\_DCM\_NUL:**  Invalid Value

**eLON\_DCM\_SPEED\_CONST:**

**eLON\_DCM\_PRESS\_CONST:**

**eLON\_DCM\_PRESS\_COMP:**

**eLON\_DCM\_FLOW\_CONST:**

**eLON\_DCM\_FLOW\_COMP:**

**eLON\_DCM\_TEMP\_CONST:**

**eLON\_DCM\_TEMP\_COMP:**

**eLON\_DCM\_PRESS\_AUTO:**

**eLON\_DCM\_QUICK\_OPEN:**  Valve works with Quick-Open flow characteristic

**eLON\_DCM\_LINEAR:**  Valve works with Linear flow characteristic

**eLON\_DCM\_EQUAL\_PERCENT:**  Valve works with Equal Percent flow characteristic

**eLON\_DCM\_QUADRATIC:**  Valve works with Quadratic flow characteristic

**eLON\_DCM\_FREE\_DEFINED:**  Valve works with free defined flow characteristic

**eLON\_DCM\_2WAY\_VALVE:**

**eLON\_DCM\_MIXING\_VALVE:**

**eLON\_DCM\_DIVERTING\_VALVE:**

**eLON\_DCM\_INVFNC\_QCK\_OPN:**

**eLON\_DCM\_INVFNC\_EQL\_PERC:**

**eLON\_DCM\_INVFNC\_QUAD:**

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
