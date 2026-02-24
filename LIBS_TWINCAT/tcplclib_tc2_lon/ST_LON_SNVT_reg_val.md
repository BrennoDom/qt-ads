# ST_LON_SNVT_reg_val

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_reg\_val

Used by: SNVT\_rac\_val

```
TYPE ST_LON_SNVT_reg_val :  
STRUCT  
  diRaw         : DINT;  
  eUnit         : E_LON_reg_val_unit_t;  
  byNr_decimals : BYTE;  
END_STRUCT  
END_TYPE
```

**diRaw:** Raw value.

**eUnit:** Unit code (defines unit of measure) (see [E\_LON\_reg\_val\_unit\_t](ms-xhelp:///?Id=beckhoff-388f-4d03-98ae-5ddacd938137)).

**byNr\_decimals:** Number of decimals (digits to right of decimal point).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
