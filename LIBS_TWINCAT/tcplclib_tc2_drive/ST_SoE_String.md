# ST_SoE_String

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [General SoE](ms-xhelp:///?Id=beckhoff-6ea8-4a69-b6e0-385b0019c130)
4. ST\_SoE\_String

# ST\_SoE\_String

The ST\_SoE\_String structure describes a string as it can be used in SoE accesses.

```
TYPE ST_SoE_String :  
STRUCT  
    iActualSize  : UINT;  
    iMaxSize     : UINT;  
    strData      : STRING(MAX_STRING_LENGTH);  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| **iActualSize** | UINT | Current length of the string (without closing \0) |
| **iMaxSize** | UINT | Maximum length of the string (without closing \0) |
| **strData** | STRING(MAX\_STRING\_LENGTH) | String |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
