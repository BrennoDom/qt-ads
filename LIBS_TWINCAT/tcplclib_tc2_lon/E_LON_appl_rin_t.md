# E_LON_appl_rin_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_appl\_rin\_t

Used by: SNVT\_clothes\_w\_c

```
TYPE E_LON_appl_rin_t :  
(  
  eLON_RIN_NUL            := -1,  
  eLON_RIN_PRE_WASH       := 0,  
  eLON_RIN_WATER_PLUS     := 1,  
  eLON_RIN_DETERGENT_PLUS := 2,  
  eLON_RIN_RINSE_HOLD     := 3  
)  
END_TYPE
```

**eLON\_RIN\_NUL:**  Invalid Value

**eLON\_RIN\_PRE\_WASH:**  Pre-wash

**eLON\_RIN\_WATER\_PLUS:**  Water Plus

**eLON\_RIN\_DETERGENT\_PLUS:**  Detergent Plus

**eLON\_RIN\_RINSE\_HOLD:**  Rinse Hold

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
