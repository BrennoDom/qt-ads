# EIB_GROUP_ADDR

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_GROUP\_ADDR

3-stage group address

```
TYPE EIB_GROUP_ADDR :  
STRUCT  
  MAIN     : BYTE;  
  SUB_MAIN : BYTE;  
  NUMBER   : BYTE;  
END_STRUCT  
END_TYPE
```

**MAIN:** Main group (range 0..31)

**SUB\_MAIN:** Medium group (range 0..7)

**NUMBER:** Subgroup (range 0..255)

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
