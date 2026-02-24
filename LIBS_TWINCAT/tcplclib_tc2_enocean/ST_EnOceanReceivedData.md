# ST_EnOceanReceivedData

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# ST\_EnOceanReceivedData

Internal structure.

This structure is used to link the block [FB\_EnOceanReceive()](ms-xhelp:///?Id=beckhoff-839a-4586-a2a0-666455178ef5) with the receive blocks.

```
TYPE ST_EnOceanReceivedData :  
STRUCT  
  bReceived          : BOOL;  
  nLength            : BYTE;  
  eEnOceanSensorType : E_EnOceanSensorType;  
  nData              : ARRAY[0..3] OF BYTE;  
  nStatus            : BYTE;  
  nTransmitterId     : UDINT;  
END_STRUCT  
END_TYPE
```

**bReceived:** Data received.

**nLength:** Length.

**eEnOceanSensorType:** Sensor type (see [E\_EnOceanSensorType](ms-xhelp:///?Id=beckhoff-36ea-4246-b787-4e922c1b8f67)).

**nData:** Data bytes.

**nStatus :** Status.

**nTransmitterId:** Transmitter ID.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
