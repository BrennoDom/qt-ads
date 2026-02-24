# ST_PMLSubUnitInfo

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Data types](ms-xhelp:///?Id=beckhoff-7fd7-46e9-b451-6cfc9a6b313e)
4. ST\_PMLSubUnitInfo

# ST\_PMLSubUnitInfo

**ST\_PMLSubUnitInfo**

```
TYPE ST_PMLSubUnitInfo :   
STRUCT  
    bActive  : BOOL;  
    eState   : E_PMLState;  
END_STRUCT  
END_TYPE
```

|  |  |
| --- | --- |
| bActive | Signals that this subordinated machine part is active and follows the state presets of the state machine. |
| eState | Enumeration that reflects the current state of the subordinated machine part. |

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
