# EIB_PHYS_ADDR

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_PHYS\_ADDR

Physical address

```
TYPE EIB_PHYS_ADDR :  
STRUCT  
  Area   : BYTE := 1;  
  Line   : BYTE := 2;  
  Device : BYTE := 3;  
END_STRUCT  
END_TYPE
```

**Area:** 0..15

**Line:** 0..15

**Device:** 0..255

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
