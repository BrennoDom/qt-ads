# ST_GENIbusResponseTable

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusResponseTable

Response buffer.

```
TYPE ST_GENIbusResponseTable :  
STRUCT  
  arrResponseTableItem           : ARRAY[1..GENIBUS_COMMAND_BUFFER_ENTRIES] OF ST_GENIbusResponseTableItem;  
  byResponseTableCounter         : BYTE;  
  byResponseTableMaxCounter      : BYTE;  
  uiResponseTableOverflowCounter : UINT;  
  bLockSemaphore                 : BOOL;   
END_STRUCT  
END_TYPE
```

**arrResponseTableItem:** Response buffer (see [ST\_GENIbusResponseTableItem](ms-xhelp:///?Id=beckhoff-2012-40ed-ae89-6d782296098a)).

**byResponseTableCounter:** current buffer demand.

**byResponseTableMaxCounter:** maximum buffer demand.

**uiResponseTableOverflowCounter:** number of buffer overflows.

**bLockSemaphore:** write protection during the processing of a command.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
