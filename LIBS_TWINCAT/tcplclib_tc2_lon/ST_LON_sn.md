# ST_LON_sn

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_sn

Used by: SNVT\_file\_req

```
TYPE ST_LON_sn :  
STRUCT  
  byType     : BYTE;  
  bDomain    : BOOL;  
  byNode     : BYTE;  
  byRetry    : BYTE;  
  byTx_timer : BYTE;  
  bySubnet   : BYTE;  
END_STRUCT  
END_TYPE
```

**byType:** Min: 1 / Max: 1 / Address type (8-bit unsigned value). The subnet-node address type is 1.

**bDomain:** Domain (LonWorks domain index).

**byNode:** Min: 0 / Max: 127 / Node (node number). There can be 127 nodes (1-127) in a subnet.

**byRetry:** Min: 0 / Max: 15 / Retry count (number of retries).

**byTx\_timer:** Min: 0 / Max: 15 / Transaction timer (timer code value).

**bySubnet:** Min: 0 / Max: 255 / Subnet (subnet number). There can be 255 subnets (1-255) in a domain.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
