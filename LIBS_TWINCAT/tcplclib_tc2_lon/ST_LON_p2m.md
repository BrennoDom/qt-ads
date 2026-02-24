# ST_LON_p2m

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_p2m

Used by: SNVT\_rac\_req / SNVT\_rac\_ctrl

```
TYPE ST_LON_p2m :  
STRUCT  
  byMask_unit      : BYTE;  
  arrMask_car      : ARRAY[0..3] OF BYTE;  
  arrMask_location : ARRAY[0..1] OF BYTE;  
  arrMask_audio    : ARRAY[0..2] OF BYTE;  
END_STRUCT  
END_TYPE
```

**byMask\_unit:** Min: 0 / Max: 255

**arrMask\_car:** unsigned char [4]

**arrMask\_location:** unsigned char [2]

**arrMask\_audio:** unsigned char [3]

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
