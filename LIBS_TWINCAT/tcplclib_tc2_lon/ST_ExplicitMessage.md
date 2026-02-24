# ST_ExplicitMessage

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_ExplicitMessage

Explict Message

```
TYPE ST_ExplicitMessage :  
STRUCT  
  byEcpM_1        : BYTE;  
  byEcpM_2        : BYTE;  
  byLen           : BYTE;  
  byAddressingTyp : BYTE;  
  byRetry         : BYTE;  
  byRptTimer      : BYTE;  
  byTxTimer       : BYTE;  
  byRcvTimer      : BYTE;  
  bySubNet        : BYTE;  
  byDestSubNet    : BYTE;  
  byNode          : BYTE;  
  arrNeuronId     : ARRAY [0..7] OF BYTE;  
  byTyp           : BYTE;  
  arrData         : ARRAY [0..47] OF BYTE;  
END_STRUCT  
END_TYPE
```

**byEcpM\_1:** Ecp M1

**byEcpM\_2:** Ecp M2

**byLen:** Length

**byAddressingTyp:** Address type

**byRetry:** Retry

**byRptTimer:** Rpt Timer

**byTxTimer:** Tx Timer

**byRcvTimer:** Rcv Timer

**bySubNet:** Sub Net

**byDestSubNet:** Target Sub Net

**byNode:** Node

**arrNeuronId:** Neuron address

**byTyp:** Type

**arrData:** 48 data bytes

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
