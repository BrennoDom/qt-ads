# ST_GENIbusComRegisterData

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# ST\_GENIbusComRegisterData

Register address and contents for the parameterization of terminals.

```
TYPE ST_GENIbusComRegisterData :  
STRUCT  
  byRegister : BYTE;  
  wValue     : WORD;  
END_STRUCT  
END_TYPE
```

**byRegister:** register address.

**wValue:** register contents.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
