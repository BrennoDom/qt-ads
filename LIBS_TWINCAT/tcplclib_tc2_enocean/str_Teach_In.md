# str_Teach_In

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# str\_Teach\_In

Data structure manufacturer ID, type and profile.

```
TYPE STR_Teach_In :  
STRUCT  
  nManufacturerID : WORD;  
  nTYPE           : BYTE;  
  nProfile        : BYTE;  
END_STRUCT  
END_TYPE
```

**nManufacturerID:** Manufacturer ID.

**nTYPE:** Type.

**nProfile:** Profile.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
