# ST_SMIResponseTable

## Library
tcplclib_tc2_smi

## Category
Motion Control

# ST\_SMIResponseTable

```
TYPE ST_SMIResponseTable :  
STRUCT  
  arrResponseTable               : ARRAY [1..SMI_COMMAND_BUFFER_ENTRIES] OF ST_SMIResponseTableItem;  
  byResponseTableCounter         : BYTE;  
  byResponseTableMaxCounter      : BYTE;  
  uiResponseTableOverflowCounter : UINT;  
  bLockSemaphore                 : BOOL;  
END_STRUCT  
END_TYPE
```

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
