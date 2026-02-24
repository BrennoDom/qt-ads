# ST_Prm

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_Prm

Structure for configuration

```
TYPE ST_Prm :  
STRUCT  
  byCMD                 : BYTE;  
  byIDX                 : BYTE;  
  wControl              : WORD;  
  wStatus               : WORD;  
  wParameterControl     : WORD;  
  wError                : WORD;  
  arrParameterInterface : ARRAY[1..8] OF DWORD;  
END_STRUCT  
END_TYPE
```

**byCMD:** LON Command.

**byIDX:** LON Index.

**wControl:** Control Word.

**wStatus:** Status Word.

**wParameterControl:** Control Word.

**wError:** Error information.

**arrParameterInterface:** 8 Data Word.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
