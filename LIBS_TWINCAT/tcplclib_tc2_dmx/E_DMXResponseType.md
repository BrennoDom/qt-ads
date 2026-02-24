# E_DMXResponseType

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# E\_DMXResponseType

```
TYPE E_DMXResponseType :  
(  
  eDMXResponseTypeAck         := 16#0000,  
  eDMXResponseTypeAckTimer    := 16#0001,  
  eDMXResponseTypeNackReason  := 16#0002,  
  eDMXResponseTypeAckOverflow := 16#0003  
);  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
