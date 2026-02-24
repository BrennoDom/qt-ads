# ST_DMXMac

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# ST\_DMXMac

```
TYPE ST_DMXMac :  
STRUCT  
  wHighPart  : WORD;    (* Manufacturer ID / Higher word *)  
  dwLowPart  : DWORD;   (* Device ID / Lower double word *)  
END_STRUCT  
END_TYPE
```

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
