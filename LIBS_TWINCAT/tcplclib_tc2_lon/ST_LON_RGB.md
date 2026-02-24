# ST_LON_RGB

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_RGB

Used by: SNVT\_color\_2

```
TYPE ST_LON_RGB :  
STRUCT  
  byRed   : BYTE;  
  byGreen : BYTE;  
  byBlue  : BYTE;  
END_STRUCT  
END_TYPE
```

**byRed:** Min: 0 / Max: 250 / Red component. Red component for RGB color

**byGreen:** Min: 0 / Max: 250 / Green component. Green component for RGB color

**byBlue:** Min: 0 / Max: 250 / Blue component. Blue component for RGB color

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
