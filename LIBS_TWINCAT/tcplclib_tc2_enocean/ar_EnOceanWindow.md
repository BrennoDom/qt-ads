# ar_EnOceanWindow

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# ar\_EnOceanWindow

This structure indicates the state of the window.

```
TYPE AR_EnOceanWindow :  
STRUCT  
  bUp    : BOOL;  
  bOpen  : BOOL;  
  bClose : BOOL;  
END_STRUCT  
END_TYPE
```

**bUp:** The window is tilted.

**bOpen:** The window is open.

**bClose:** The window is closed.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
