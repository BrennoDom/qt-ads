# ST_GENIbusMValue

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusMValue

Structure with the contents of a read device value, e.g. flow rate or speed.

```
TYPE ST_GENIbusMValue :  
STRUCT  
  lrValue      : LREAL;  
  lrPrefix     : LREAL;  
  sUnit        : STRING(8);  
  eDataSize    : E_GENIBusMDataSize;  
  byValueH     : BYTE;  
  byValueL1    : BYTE;  
  byValueL2    : BYTE;  
  byValueL3    : BYTE;  
  byInfoHead   : BYTE;  
  byUnitIndex  : BYTE;  
  byZeroH      : BYTE;  
  byRangeZeroL : BYTE;  
END_STRUCT  
END_TYPE
```

**lrValue:** final value determined from the raw data.

**lrPrefix:** sign and division (+/- and e.g. 0.1).

**sUnit:** Unit.

**eDataSize:** size of the measured value (8, 16, 24 or 32 bytes) (see [E\_GENIBusMDataSize](ms-xhelp:///?Id=beckhoff-d457-41be-b760-9ce71d64a0c4)).

**byValueH:** high byte of the measured value.

**byValueL1:** low byte.

**byValueL2:** low byte.

**byValueL3:** low byte.

**byInfoHead:** scaling information

**byUnitIndex:** sign and unit – coded.

**byZeroH:** zero point in the case of normal range zero-point scaling OR high-byte zero point in the case of extended scaling.

**byRangeZeroL:** range in the case of normal range zero-point scaling OR low-byte zero point in the case of extended scaling.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
