# str_AddressTable

## Library
tcplclib_tc2_lon

## Category
Motion Control

# str\_AddressTable

Address table

```
TYPE str_AddressTable :  
STRUCT  
  bType     : BOOL;  
  Node      : USINT;  
  bDomain   : BOOL;  
  Member    : USINT;  
  RPT_Timer : USINT;  
  Retry     : USINT;  
  RCV_Timer : USINT;  
  Tx_Timer  : USINT;  
  Group     : BYTE;  
END_STRUCT  
END_TYPE
```

**bType:** Type

**Node:** Node

**bDomain:** Domain

**Member:** Member

**RPT\_Timer:** RPT\_Timer

**Retry:** Retry

**RCV\_Timer:** RCV\_Timer

**Tx\_Timer:** Tx\_Timer

**Group:** Group

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
