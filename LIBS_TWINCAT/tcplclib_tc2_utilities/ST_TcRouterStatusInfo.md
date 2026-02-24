# ST_TcRouterStatusInfo

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_TcRouterStatusInfo

TwinCAT router status information.

```
TYPE ST_TcRouterStatusInfo :  
STRUCT  
    maxMem      : DWORD;(* Max. router memory byte size *)  
    maxMemAvail : DWORD;(* Available router memory byte size *)  
    regPorts    : DWORD;(* Number of registered ports *)  
    regDrivers  : DWORD;(* Number of registered TwinCAT server ports *)  
    amsDebugLog : BOOL;(* TRUE = Ams logging/debugging enabled, FALSE = Ams logging/debugging disabled *)  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
