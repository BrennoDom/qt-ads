# E_DMXCommandClass

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# E\_DMXCommandClass

```
TYPE E_DMXCommandClass :  
(  
  eDMXCommandClassNotDefined               := 16#0000,  
  eDMXCommandClassDiscoveryCommand         := 16#0010,  
  eDMXCommandClassDiscoveryCommandResponse := 16#0011,  
  eDMXCommandClassGetCommand               := 16#0020,  
  eDMXCommandClassGetCommandResponse       := 16#0021,  
  eDMXCommandClassSetCommand               := 16#0030,  
  eDMXCommandClassSetCommandResponse       := 16#0031  
);  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
