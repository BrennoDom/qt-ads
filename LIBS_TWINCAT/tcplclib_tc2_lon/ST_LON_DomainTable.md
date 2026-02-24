# ST_LON_DomainTable

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_DomainTable

Used by: FB\_Write\_Domain\_Table / FB\_Read\_Domain\_Table

```
TYPE ST_LON_DomainTable :  
STRUCT  
  arrDomainID     : ARRAY[0..5] OF BYTE;  
  bySubNet        : BYTE;  
  bCloneDomainBit : BOOL;  
  byNode          : BYTE;  
  byLen           : BYTE;  
  arrKey          : ARRAY[0..5] OF BYTE := 16#FF;  
END_STRUCT  
END_TYPE
```

**arrDomainID:** domain id.

**bySubNet:** sub net.

**bCloneDomainBit:** Clone domain bit.

**byNode:** node.

**byLen:** Len.

**arrKey:** key.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
