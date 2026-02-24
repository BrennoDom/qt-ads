# ST_LON_Parameter_IN_36B

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_Parameter\_IN\_36B

Process image of the inputs

This variable must be linked with the KL6401.

```
TYPE ST_LON_Parameter_IN_36B :  
STRUCT  
  wParameterStatus     : WORD;  
  wDummy               : WORD;  
  stParameterReadValue : ST_LON_ParameterInterface;  
  byParameterType      : BYTE;  
  byLONStatus          : BYTE;  
END_STRUCT  
END_TYPE
```

**wParameterStatus:** Status word.

**wDummy:** Dummy for CX9000.

**stParameterReadValue:** Data structure.

**stParameterReadValue. arrParameterInterface:** 8 word data (see [ST\_LON\_ParameterInterface](ms-xhelp:///?Id=beckhoff-8d8c-42a3-802b-eb053d58cb35)).

**byParameterType:** Parameter type

**byLONStatus:** LON status.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
