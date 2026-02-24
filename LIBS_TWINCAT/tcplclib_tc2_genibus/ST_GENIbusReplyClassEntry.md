# ST_GENIbusReplyClassEntry

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusReplyClassEntry

Response structure containing the data of a response APDU for processing within the library.

```
TYPE ST_GENIbusReplyClassEntry :  
STRUCT  
  byClass      : BYTE;  
  eACK         : E_GENIbusACK;  
  eOS          : E_GENIbusOS;  
  iEntryCount  : INT;  
  arrEntry     : ARRAY[0..GENIBUS_MAX_APDU_LENGTH] OF ST_GENIbusReplyDataEntry;  
  sASCIIString : STRING(64);  
END_STRUCT  
END_TYPE
```

**byClass:** data class.

**eACK:** acknowledgement of the GENIbus device (see [E\_GENIbusACK](ms-xhelp:///?Id=beckhoff-b103-4d93-9604-9bfa84b29e04)).

**eOS:** operation display (GET/SET/INFO) (see [E\_GENIbusOS](ms-xhelp:///?Id=beckhoff-5209-4ab6-8150-113ff8a468dc)).

**iEntryCount:** number of data points (ID codes) used within the APDU.

**arrEntry:** contents of the data points (ID codes) (see [ST\_GENIbusReplyDataEntry](ms-xhelp:///?Id=beckhoff-9f2e-41d3-8534-ba9166e4c131)).

**sASCIIString:** string evaluation for data class 7.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
