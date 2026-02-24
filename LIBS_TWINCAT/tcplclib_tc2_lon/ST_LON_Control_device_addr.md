# ST_LON_Control_device_addr

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_Control\_device\_addr

Used by: SNVT\_ex\_control

```
TYPE ST_LON_Control_device_addr :  
STRUCT  
  arrDomain_id    : ARRAY [0..5] OF BYTE;  
  byDomain_length : BYTE;  
  bySubnet        : BYTE;  
  byNode          : BYTE;  
END_STRUCT  
END_TYPE
```

**arrDomain\_id:** Domain ID (array of 6 bytes). ANSI/CEA-709.1 domain ID

**byDomain\_length:** Domain length (ANSI/CEA-709.1 domain length). Valid domain lengths are 0, 1, 3, and 6.

**bySubnet:** Min: 1 / Max: 255 / Subnet (subnet number). There can be 255 subnets (1-255) in a domain.

**byNode:** Min: 1 / Max: 127 / Node (node number). There can be 127 nodes (1-127) in a subnet.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
