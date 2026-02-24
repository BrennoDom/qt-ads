# ST_LON_SNVT_currency

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_currency

Used by: SNVT\_currency

```
TYPE ST_LON_SNVT_currency :  
STRUCT  
  eCurrency     : E_LON_currency_t;  
  siPower_of_10 : SINT;  
  diValue       : DINT;  
END_STRUCT  
END_TYPE
```

**eCurrency:** Currency (currency names) (see [E\_LON\_currency\_t](ms-xhelp:///?Id=beckhoff-39c6-4e11-bb43-2d4804169383)).

**siPower\_of\_10:** Min: -128 / Max: 127 / Magnitude (power of 10).

**diValue:** Min: -2147483648 / Max: 2147483647 / Value (currency value). Credit is positive, debit is negative.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
