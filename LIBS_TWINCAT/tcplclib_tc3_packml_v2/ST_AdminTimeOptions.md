# ST_AdminTimeOptions

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Data types](ms-xhelp:///?Id=beckhoff-7fd7-46e9-b451-6cfc9a6b313e)
4. ST\_AdminTimeOptions

# ST\_AdminTimeOptions

**ST\_AdminTimeOptions**

```
TYPE ST_AdminTimeOptions :   
STRUCT  
    UseExternalTime          : BOOL;  
    ExternalPackMLTime       : ARRAY [0..6] OF DINT;  
END_STRUCT  
END_TYPE
```

|  |  |
| --- | --- |
| UseExternalTime | If this flag is set to TRUE, the time set at the input ExternalPackMLTime is used instead of the system time information. |
| ExternalPackMLTime | Externally set time |

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
