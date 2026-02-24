# ST_GENIbusRequestClassEntry

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusRequestClassEntry

Command or query structure containing the data of a request APDU for processing within the library.

```
TYPE ST_GENIbusRequestClassEntry :  
STRUCT  
  byClass      : BYTE;  
  eOS          : E_GENIbusOS;  
  byEntryCount : BYTE;  
  arrEntry     : ARRAY[0..GENIBUS_MAX_APDU_LENGTH] OF ST_GENIbusRequestDataEntry;  
END_STRUCT  
END_TYPE
```

**byClass:** data class.

**eOS:** operation display (GET/SET/INFO) (see [E\_GENIbusOS](ms-xhelp:///?Id=beckhoff-5209-4ab6-8150-113ff8a468dc)).

**byEntryCount:** number of data points (ID codes) used within the APDU.

**arrEntry:** field with addresses of the data points (ID codes) and, if applicable, the values to be written (see [ST\_GENIbusRequestDataEntry](ms-xhelp:///?Id=beckhoff-1a61-4c6b-9b6f-6f2327ac8780)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
