# ST_GENIbusResponseTableItem

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusResponseTableItem

Individual element in the response buffer.

```
TYPE ST_GENIbusResponseTableItem :  
STRUCT  
  byAddr           : BYTE;  
  byLength         : BYTE;  
  eSD              : E_GENIbusSD;  
  arrAPDUs         : ARRAY[1..GENIBUS_MAX_APDU_NUMBER] OF ST_GENIbusReplyClassEntry;  
  byRFS            : BYTE;  
  udiMessageHandle : UDINT;  
  udiErrorId       : UDINT;  
END_STRUCT  
END_TYPE
```

**byAddr:** device destination address.

**eAddrType:** single, multiple or collective command.

**eSD:** start delimiter of the telegram (see [E\_GENIbusSD](ms-xhelp:///?Id=beckhoff-cb02-4c9a-a6d6-1d6383c0440c)).

**arrAPDUs:** collection of the APDUs (Application Program Data Units) to be transmitted (see [ST\_GENIbusReplyClassEntry](ms-xhelp:///?Id=beckhoff-cab5-4d9f-838b-beb70904e3f4)).

**byRFS:** not yet used: "Request from Slave".

**udiMessageHandle:** pointer to the current buffer element.

**udiErrorId:** If an error has occurred in the FB\_GENIbusCommunication() function block, the corresponding error code will be saved here for further evaluation.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
