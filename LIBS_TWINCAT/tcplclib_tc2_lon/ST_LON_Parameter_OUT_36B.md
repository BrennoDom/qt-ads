# ST_LON_Parameter_OUT_36B

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_Parameter\_OUT\_36B

Process image of the outputs

This variable must be linked with the KL6401.

```
TYPE ST_LON_Parameter_OUT_36B :  
STRUCT  
  wParameterControl : WORD;  
  wDummy            : WORD;  
  stParametervalue  : ST_LON_ParameterInterface;  
  byCMD             : BYTE;  
  byIdx             : BYTE;  
END_STRUCT  
END_TYPE
```

**wParameterControl:** Control word.

**wDummy:** Dummy for CX9000.

**stParametervalue:** Data structure.

**stParametervalue. arrParameterInterface:** 8 word data (see [ST\_LON\_ParameterInterface](ms-xhelp:///?Id=beckhoff-8d8c-42a3-802b-eb053d58cb35)).

**byCMD:** LON command

**byIdx:** LON index

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
