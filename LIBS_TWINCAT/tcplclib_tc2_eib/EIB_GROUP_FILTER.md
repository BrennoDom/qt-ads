# EIB_GROUP_FILTER

## Library
tcplclib_tc2_eib

## Category
Motion Control

# EIB\_GROUP\_FILTER

Group filter

```
TYPE EIB_GROUP_FILTER :  
STRUCT  
  GROUP_ADDR : EIB_GROUP_ADDR;  
  GROUP_LEN  : WORD;  
END_STRUCT  
END_TYPE
```

**GROUP\_ADDR:** Group address (see [EIB\_GROUP\_ADDR](ms-xhelp:///?Id=beckhoff-b660-4bbb-871b-bcd96d7eaa4e))

**GROUP\_LEN:** iMode 0 - 0..63, iMode 1 - 0..31

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_EIB from 3.3.4.0 |
