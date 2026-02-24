# ST_LON_spin

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_spin

Used by: SNVT\_clothes\_w\_c

```
TYPE ST_LON_spin :  
STRUCT  
  uiSpeed : UINT;  
  byTime  : BYTE;  
  eHold   : E_LON_boolean_t;  
END_STRUCT  
END_TYPE
```

**uiSpeed:** Min: 0 / Max: 65535

**byTime:** Min: 0 / Max: 255

**eHold:** (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90))

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
