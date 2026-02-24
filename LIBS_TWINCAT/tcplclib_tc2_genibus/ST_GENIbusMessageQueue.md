# ST_GENIbusMessageQueue

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusMessageQueue

command buffer.

```
TYPE ST_GENIbusMessageQueue :  
STRUCT  
  arrBuffer                    : ARRAY[1..GENIBUS_COMMAND_BUFFER_ENTRIES] OF ST_GENIbusMessageQueueItem;  
  byBufferReadPointer          : BYTE;  
  byBufferWritePointer         : BYTE;  
  byBufferDemandCounter        : BYTE;  
  byBufferMaximumDemandCounter : BYTE;  
  uiBufferOverflowCounter      : UINT;  
  bLockSemaphore               : BOOL;   
END_STRUCT  
END_TYPE
```

**arrBuffer:** command buffer (see [ST\_GENIbusMessageQueueItem](ms-xhelp:///?Id=beckhoff-fc66-4cbf-83a7-ecc10d32932e)).

**byBufferReadPointer:** pointer to the current buffer element of the command buffer.

**byBufferWritePointer:** pointer to the current buffer element of the receive memory.

**byBufferDemandCounter:** current buffer demand.

**byBufferMaximumDemandCounter:** maximum buffer demand.

**uiBufferOverflowCounter:** number of buffer overflows.

**bLockSemaphore:** write protection during the processing of a command.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
