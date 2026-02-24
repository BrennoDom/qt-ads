# T_HFoe

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. T\_HFoe

# T\_HFoe

“File access over EtherCAT” handle. Before the handle can be used, it must be initialized once with the function block [FB\_EcFoeOpen](ms-xhelp:///?Id=beckhoff-c2ed-4017-b22a-f267db0d4f72). The variables of this structured type must not be written directly.

```
TYPE T_HFoe :  
STRUCT  
    sNetID : T_AmsNetId := '';  
    nPort  : T_AmsPort := 0;  
    handle : UDINT := 0;  
    eMode  : E_EcFoeMode := eFoeMode_Write;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
