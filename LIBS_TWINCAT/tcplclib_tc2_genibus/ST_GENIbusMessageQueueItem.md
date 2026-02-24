# ST_GENIbusMessageQueueItem

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusMessageQueueItem

Individual element in the command buffer.

```
TYPE ST_GENIbusMessageQueueItem :  
STRUCT  
  byAddr           : BYTE;  
  eAddrType        : E_GENIbusAddrType;  
  eSD              : E_GENIbusSD;  
  arrAPDUs         : ARRAY[1..GENIBUS_MAX_APDU_NUMBER] OF ST_GENIbusRequestClassEntry;  
  byRFS            : BYTE;  
  udiMessageHandle : UDINT;  
END_STRUCT  
END_TYPE
```

**byAddr:** device destination address.

**eAddrType:** single, multiple or collective command (see [E\_GENIbusAddrType](ms-xhelp:///?Id=beckhoff-c2dc-452a-98b5-24078f8840f4)).

**eSD:** start delimiter of the telegram (see [E\_GENIbusSD](ms-xhelp:///?Id=beckhoff-cb02-4c9a-a6d6-1d6383c0440c)).

**arrAPDUs:** collection of the APDUs (Application Program Data Units) to be transmitted (see [ST\_GENIbusRequestClassEntry](ms-xhelp:///?Id=beckhoff-cfa1-4da1-866f-2bbe4ed7ca47)).

**byRFS:** not yet used: "Request from Slave".

**udiMessageHandle:** pointer to the current buffer element.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
