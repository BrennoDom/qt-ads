# ST_SMIMessageQueue

## Library
tcplclib_tc2_smi

## Category
Motion Control

# ST\_SMIMessageQueue

```
TYPE ST_SMIMessageQueue :  
STRUCT  
  arrBuffer                    : ARRAY [1..SMI_COMMAND_BUFFER_ENTRIES] OF ST_SMIMessageQueueItem;  
  byBufferReadPointer          : BYTE;  
  byBufferWritePointer         : BYTE;  
  byBufferDemandCounter        : BYTE;  
  byBufferMaximumDemandCounter : BYTE;  
  uiBufferOverflowCounter      : UINT;  
  bLockSemaphore               : BOOL;  
END_STRUCT  
END_TYPE
```

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
