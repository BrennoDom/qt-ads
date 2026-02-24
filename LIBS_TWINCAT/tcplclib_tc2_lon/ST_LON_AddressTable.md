# ST_LON_AddressTable

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_AddressTable

Used by: FB\_Write\_Address\_Table / FB\_Read\_Address\_Table

```
TYPE ST_LON_AddressTable :  
STRUCT  
  bType        : BOOL;  
  usiNode      : USINT;  
  bDomain      : BOOL;  
  usiMember    : USINT;  
  usiRPT_Timer : USINT;  
  usiRetry     : USINT;  
  usiRCV_Timer : USINT;  
  usiTx_Timer  : USINT;  
  byGroup      : BYTE;  
END_STRUCT  
END_TYPE
```

**bType:** Type.

**usiNode:** Node.

**bDomain:** Domain.

**usiMember:** Member.

**usiRPT\_Timer:** RPT Timer.

**usiRetry:** Retry.

**usiRCV\_Timer:** Rcv timer.

**usiTx\_Timer:** Tx timer.

**byGroup:** group.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
