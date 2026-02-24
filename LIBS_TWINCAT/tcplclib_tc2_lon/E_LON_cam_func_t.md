# E_LON_cam_func_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_cam\_func\_t

Used by: SNVT\_pos\_ctrl

```
TYPE E_LON_cam_func_t :  
(  
  eLON_CMF_NUL  := -1,  
  eLON_CMF_REL  := 0,  
  eLON_CMF_TOUR := 1,  
  eLON_CMF_ABS  := 2  
)  
END_TYPE
```

eLON\_CMF\_ABSeLON\_CMF\_TOUReLON\_CMF\_RELeLON\_CMF\_NUL

**eLON\_CMF\_NUL:**  Invalid function call response

**eLON\_CMF\_REL:**  Relative positions, prepositions

**eLON\_CMF\_TOUR:**  Preposition tour tables

**eLON\_CMF\_ABS:**  Absolute positions

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
