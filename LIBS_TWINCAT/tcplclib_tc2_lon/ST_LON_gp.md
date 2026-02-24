# ST_LON_gp

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_gp

Used by: SNVT\_file\_req

```
TYPE ST_LON_gp :  
STRUCT  
  byType     : BYTE;  
  bySize     : BYTE;  
  bDomain    : BOOL;  
  byUnused   : BYTE;  
  byRetry    : BYTE;  
  byTx_timer : BYTE;  
  byGroup    : BYTE;  
END_STRUCT  
END_TYPE
```

**byType:** Min: 0 / Max: 1 / Address type (boolean). The group address type is 1.

**bySize:** Min: 0 / Max: 65 / Size (LonWorks group size). An acknowledged group can have from 0-64 addressees, plus the sender.

**bDomain:** Min: 0 / Max: 1 / Domain (LonWorks domain index).

**byUnused:** Unused field. This field is reserved.

**byRetry:** Min: 0 / Max: 15 / Retry count (number of retries).

**byTx\_timer:** Min: 0 / Max: 15 / Transaction timer (timer code value).

**byGroup:** Min: 0 / Max: 255 / Group. There can be 256 groups (0-255) in a domain.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
