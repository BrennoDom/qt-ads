# E_LON_appl_cwc_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_appl\_cwc\_t

Used by: SNVT\_clothes\_w\_c / SNVT\_clothes\_w\_s

```
TYPE E_LON_appl_cwc_t :  
(  
  eLON_CWC_NUL   := -1,  
  eLON_CWC_WASH  := 0,  
  eLON_CWC_RINSE := 1,  
  eLON_CWC_SPIN  := 2,  
  eLON_CWC_DRY   := 3  
)  
END_TYPE
```

**eLON\_CWC\_NUL:**  Invalid Value

**eLON\_CWC\_WASH:**  Wash

**eLON\_CWC\_RINSE:**  Rinse

**eLON\_CWC\_SPIN:**  Spin

**eLON\_CWC\_DRY:**  Dry

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
