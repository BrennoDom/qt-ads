# KL6581_Output

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# KL6581\_Output

Process image of the KL6581 outputs.

Linked to the terminal in the System Manager.

```
TYPE KL6581_Output :  
STRUCT  
  nControl : BYTE;  
  CNODE    : BYTE;  
  ORG      : BYTE;  
  DB0      : BYTE;  
  DB1      : BYTE;  
  DB2      : BYTE;  
  DB3      : BYTE;  
  ID0      : BYTE;  
  ID1      : BYTE;  
  ID2      : BYTE;  
  ID3      : BYTE;  
  STATUS   : BYTE;  
END_STRUCT  
END_TYPE
```

**nControl:** Control byte.

**CNODE:** Data byte.

**ORG:** Data byte.

**DB0:** Data byte.

**DB1:** Data byte.

**DB2:** Data byte.

**DB3:** Data byte.

**ID0:** Data byte.

**ID1:** Data byte.

**ID2:** Data byte.

**ID3:** Data byte.

**STATUS:** Data byte.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
