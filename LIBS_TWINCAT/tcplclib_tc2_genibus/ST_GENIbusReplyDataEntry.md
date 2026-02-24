# ST_GENIbusReplyDataEntry

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusReplyDataEntry

Contents of an element of a response APDU: value and information.

```
TYPE ST_GENIbusReplyDataEntry :  
STRUCT  
  byValue      : BYTE;  
  byInfoHead   : BYTE;  
  byUnitIndex  : BYTE;  
  byZeroH      : BYTE;  
  byRangeZeroL : BYTE;  
END_STRUCT  
END_TYPE
```

**byValue:** raw value.

**byInfoHead:** information head containing among other things the scaling information.

**byUnitIndex:** sign and unit code.

**byZeroH:** zero point in the case of normal range zero-point scaling OR high-byte zero point in the case of extended scaling.

**byRangeZeroL:** range in the case of normal range zero-point scaling OR low-byte zero point in the case of extended scaling.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
