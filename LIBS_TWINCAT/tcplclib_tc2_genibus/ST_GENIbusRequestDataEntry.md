# ST_GENIbusRequestDataEntry

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusRequestDataEntry

Address and, if applicable, the value to be written within a request APDU.

```
TYPE ST_GENIbusRequestDataEntry :  
STRUCT  
  byIDCode : BYTE;  
  byValue  : BYTE;  
END_STRUCT  
END_TYPE
```

**byIDCode:** address.

**byValue:** value to be written.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
