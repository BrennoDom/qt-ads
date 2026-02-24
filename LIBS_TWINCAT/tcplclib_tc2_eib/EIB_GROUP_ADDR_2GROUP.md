# EIB_GROUP_ADDR_2GROUP

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_GROUP\_ADDR\_2GROUP

2-stage group address

```
TYPE EIB_GROUP_ADDR_2GROUP :  
STRUCT  
  MAIN     : BYTE;  
  SUB_MAIN : WORD;  
END_STRUCT  
END_TYPE
```

**MAIN:** Main group (ranges 0..15)

**SUB\_MAIN:** Subgroup (ranges 0..2048)

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
