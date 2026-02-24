# ST_EnOceanInData

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# ST\_EnOceanInData

Process image of the KL6021-0023 inputs.

Linked to the terminals in the System Manager.

```
TYPE ST_EnOceanInData :  
STRUCT  
  nStatus : BYTE;  
  nData   : ARRAY[0..10] OF BYTE;  
END_STRUCT  
END_TYPE
```

**nStatus:** Status byte.

**nData:** 11 bytes for the input data.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
