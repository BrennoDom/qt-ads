# ST_LON_ParameterInterface

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_ParameterInterface

LON parameter interface

```
TYPE ST_LON_ParameterInterface :  
STRUCT  
  arrParameterInterface : ARRAY[1..8] OF DWORD;  
END_STRUCT  
END_TYPE
```

**arrParameterInterface:** 8 word data.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
