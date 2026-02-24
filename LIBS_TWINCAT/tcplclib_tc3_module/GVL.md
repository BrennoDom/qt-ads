# GVL

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Global Constants](ms-xhelp:///?Id=beckhoff-d32b-492d-9e6b-517143d996d6)
3. GVL

# GVL

```
VAR_GLOBAL CONSTANT GVL  
    S_OK               : HRESULT := 0;  
    S_FALSE            : HRESULT := 1;  
    S_PENDING          : HRESULT := 16#203;  
    S_WATCHDOG_TIMEOUT : HRESULT := 16#256;  
    OTCID_CreateNewId  : OTCID := 16#FFFFFFFF;  
    OTCID_FirstFreeId  : OTCID := 16#71010000;  
    OTCID_LastFreeId   : OTCID := 16#710FFFFF;  
    NULL : PVOID := 0;  
END_VAR
```

| Name | Type | Value | Use | Meaning |
| --- | --- | --- | --- | --- |
| S\_OK | HRESULT | 0 |  | This constant can be used, to designate error-free processing in an HRESULT status code. |
| S\_FALSE | HRESULT | 1 |  | This constant indicates successful processing, although the result was negative or incomplete. |
| S\_PENDING | HRESULT | 16#203 |  | This constant indicates successful processing, although no result is available yet. |
| S\_WATCHDOG\_TIMEOUT | HRESULT | 16#256 |  | This constant indicates successful processing, although a timeout occurred. Depending on the function, the desired processing was aborted. |
| OTCID\_CreateNewId | OTCID | 16#FFFFFFFF | [FW\_ObjMgr\_CreateAndInitInstance](ms-xhelp:///?Id=beckhoff-6fd2-4107-995b-fcb0b3c16870) | This constant is used to generate a new object ID. |
| OTCID\_FirstFreeId | OTCID | 16#71010000 |  |  |
| OTCID\_LastFreeId | OTCID | 16#710FFFFF |  |  |
| NULL | PVOID | 0 |  | NULL pointer |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
