# ST_LON_ConfigTable

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_ConfigTable

Used by: FB\_Write\_Config\_Table / FB\_Read\_Config\_Table

```
TYPE ST_LON_ConfigTable :  
STRUCT  
  bPriority    : BOOL;  
  bDirection   : BOOL;  
  wSelector    : WORD;  
  bTurnaround  : BOOL;  
  usiService   : USINT;  
  bAuth        : BOOL;  
  usiAddrIndex : USINT;  
END_STRUCT  
END_TYPE
```

**bPriority:** priority.

**bDirection:** direction.

**wSelector:** selector.

**bTurnaround:** turn around.

**usiService:** service.

**bAuth:** auth.

**usiAddrIndex:** Address index.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
