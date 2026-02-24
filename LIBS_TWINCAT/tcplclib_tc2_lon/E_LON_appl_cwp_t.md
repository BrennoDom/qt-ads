# E_LON_appl_cwp_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_appl\_cwp\_t

Used by: SNVT\_clothes\_w\_c

```
TYPE E_LON_appl_cwp_t :  
(  
  eLON_CWP_NUL             := -1,  
  eLON_CWP_GENERAL         := 0,  
  eLON_CWP_BOIL            := 1,  
  eLON_CWP_FAST_WASH       := 2,  
  eLON_CWP_LINGERIE        := 3,  
  eLON_CWP_WOOL            := 4,  
  eLON_CWP_TOWEL           := 5,  
  eLON_CWP_BED_LINENS      := 6,  
  eLON_CWP_CURTAIN         := 7,  
  eLON_CWP_RINSE_SPIN_ONLY := 8,  
  eLON_CWP_DELICATE_RINSE  := 9,  
  eLON_CWP_SPIN_ONLY       := 10,  
  eLON_CWP_DRY_ONLY        := 11  
)  
END_TYPE
```

**eLON\_CWP\_NUL:**  Invalid Value

**eLON\_CWP\_GENERAL:**  Normal Wash

**eLON\_CWP\_BOIL:**  Boil

**eLON\_CWP\_FAST\_WASH:**  Fast Wash

**eLON\_CWP\_LINGERIE:**  Lingerie

**eLON\_CWP\_WOOL:**  Wool

**eLON\_CWP\_TOWEL:**  Towel

**eLON\_CWP\_BED\_LINENS:**  Bed Linens

**eLON\_CWP\_CURTAIN:**  Curtain

**eLON\_CWP\_RINSE\_SPIN\_ONLY:**  Rinse and Spin Only

**eLON\_CWP\_DELICATE\_RINSE:**  Delicate Rinse

**eLON\_CWP\_SPIN\_ONLY:**  Spin Only

**eLON\_CWP\_DRY\_ONLY:**  Dry Only

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
