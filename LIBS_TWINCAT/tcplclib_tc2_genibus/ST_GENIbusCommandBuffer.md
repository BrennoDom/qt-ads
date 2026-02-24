# ST_GENIbusCommandBuffer

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusCommandBuffer

Global command buffer for commands and their responses.

```
TYPE ST_GENIbusCommandBuffer :  
STRUCT  
  arrMessageQueue  : ARRAY[0..2] OF ST_GENIbusMessageQueue;  
  stResponseTable  : ST_GENIbusResponseTable;  
  udiMessageHandle : UDINT;  
END_STRUCT  
END_TYPE
```

**arrMessageQueue:** input buffer for the commands (see [ST\_GENIbusMessageQueue](ms-xhelp:///?Id=beckhoff-551e-4bf6-b30a-16e12daa13d8)). Through the field declaration there is a choice of 3 different buffers: for high, medium and low priority.

**stResponseTable:** buffer for the command response (see [ST\_GENIbusResponseTable](ms-xhelp:///?Id=beckhoff-50d1-4af3-ad7b-99cbd5b43f9a)).

**udiMessageHandle:** pointer to the current buffer element.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
