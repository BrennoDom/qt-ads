# ST_LON_WriteData

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_WriteData

Structure of the send buffer

```
TYPE ST_LON_WriteData :  
STRUCT  
  wNVIndex             : WORD;  
  udiSrcAddrWriteValue : PVOID;  
  uiLenWriteValue      : UINT;  
  udiAdrBusy           : PVOID;  
  udiAdrErrorKL        : PVOID;  
END_STRUCT  
END_TYPE
```

**wNVIndex:** NV index.

**udiSrcAddrWriteValue:** Address of the value to be sent.

**uiLenWriteValue:** Length of the value to be sent.

**udiAdrBusy:** Address of output "bBusy".

**udiAdrErrorKL:** Address of output "dwErrorKL".

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
