# ST_SoE_DiagNumList

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [General SoE](ms-xhelp:///?Id=beckhoff-6ea8-4a69-b6e0-385b0019c130)
4. [List types](ms-xhelp:///?Id=beckhoff-1387-4a6e-9bf2-4c395815c183)
5. ST\_SoE\_DiagNumList

# ST\_SoE\_DiagNumList

The ST\_SoE\_DiagNumList structure contains the list length (Minimum, Maximum) in bytes as well as the history of the diagnosis numbers.

```
TYPE ST_SoE_DiagNumList :  
STRUCT  
    iActualSize     : UINT;  
    iMaxSize        : UINT;  
    arrDiagNumbers  : ARRAY [0..29] OF UDINT;  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| **iActualSize** | UINT | Current length of the string (without closing \0) |
| **iMaxSize** | UINT | Maximum length of the string (without closing \0) |
| **arrDiagNumbers** | ARRAY [0..29] OF UDINT | List of the maximum 30 last error numbers (as UDINT) |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
