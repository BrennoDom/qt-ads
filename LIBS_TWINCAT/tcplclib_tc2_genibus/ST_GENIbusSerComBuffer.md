# ST_GENIbusSerComBuffer

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusSerComBuffer

Serial communication buffer – for transmission and reception alike.

```
TYPE ST_GENIbusSerComBuffer :  
STRUCT  
  arrBuffer    : ARRAY[0..GENIBUS_MAX_TELEGRAM_LENGTH] OF BYTE;  
  uiDataLength : UINT;  
  bBlocked     : BOOL;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
