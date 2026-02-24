# E_DMXDataType

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# E\_DMXDataType

```
TYPE E_DMXDataType :  
(  
  eDMXDataTypeNotDefined    := 16#0000,  
  eDMXDataTypeBitField      := 16#0001,  
  eDMXDataTypeASCII         := 16#0002,  
  eDMXDataTypeUnsignedByte  := 16#0003,  
  eDMXDataTypeSignedByte    := 16#0004,  
  eDMXDataTypeUnsignedWord  := 16#0005,  
  eDMXDataTypeSignedWord    := 16#0006,  
  eDMXDataTypeUnsignedDWord := 16#0007,  
  eDMXDataTypeSignedDWord   := 16#0008  
);  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
