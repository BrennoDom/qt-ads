# E_LON_chiller_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_chiller\_t

Used by: SNVT\_chlr\_status

```
TYPE E_LON_chiller_t :  
(  
  eLON_CHLR_NUL       := -1,  
  eLON_CHLR_OFF       := 0,  
  eLON_CHLR_START     := 1,  
  eLON_CHLR_RUN       := 2,  
  eLON_CHLR_PRESHUTDN := 3,  
  eLON_CHLR_SERVICE   := 4  
)  
END_TYPE
```

**eLON\_CHLR\_NUL:**  Invalid Value

**eLON\_CHLR\_OFF:**  Chiller off

**eLON\_CHLR\_START:**  Chiller in start mode

**eLON\_CHLR\_RUN:**  Chiller in run mode

**eLON\_CHLR\_PRESHUTDN:**  Chiller in pre shutdown mode

**eLON\_CHLR\_SERVICE:**  Chiller in service mode

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
