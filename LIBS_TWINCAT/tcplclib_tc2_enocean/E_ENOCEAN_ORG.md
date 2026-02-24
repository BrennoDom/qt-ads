# E_ENOCEAN_ORG

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# E\_ENOCEAN\_ORG

EnOcean telegram type.

```
TYPE E_ENOCEAN_Org :  
(  
  PTM_TELEGRAM       := 5,  
  STM_1BYTE_TELEGRAM := 6,  
  STM_4BYTE_TELEGRAM := 7,  
  CTM_TELEGRAM       := 8,  
  MODEM_TELEGRAM     := 16#A,  
  MODEM_ACK_TELEGRAM := 16#B  
)  
END_TYPE
```

**PTM\_TELEGRAM:** PTM telegram.

**STM\_1BYTE\_TELEGRAM:** 1-byte telegram.

**STM\_4BYTE\_TELEGRAM:** 4-byte telegram.

**CTM\_TELEGRAM:** CTM telegram.

**MODEM\_TELEGRAM:** Modem telegram.

**MODEM\_ACK\_TELEGRAM:** Modem telegram with acknowledgement.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
