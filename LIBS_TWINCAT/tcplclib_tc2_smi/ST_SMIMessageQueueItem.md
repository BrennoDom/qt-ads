# ST_SMIMessageQueueItem

## Library
tcplclib_tc2_smi

## Category
Motion Control

# ST\_SMIMessageQueueItem

```
TYPE ST_SMIMessageQueueItem :  
STRUCT  
  dwAddr                  : DWORD;  
  eAddrType               : E_SMIAddrType;  
  eCommandType            : E_SMICommandType;  
  eResponseFormat         : E_SMIResponseFormat;  
  arrIdentificationBytes  : ARRAY [0..2] OF BYTE;  
  arrParameters           : ARRAY [0..2] OF DWORD;  
  udiMessageHandle        : UDINT;  
  bSuppressResponseBuffer : BOOL;  
END_STRUCT  
END_TYPE
```

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
