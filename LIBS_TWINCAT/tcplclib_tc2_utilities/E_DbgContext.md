# E_DbgContext

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_DbgContext

This variable type can be used by protocol blocks. It determines the context of the debug output.

```
TYPE E_DbgContext :  
(  
    eDbgContext_NONE := 0,(* Not used *)  
    eDbgContext_USER := 1,(* Service user *)  
    eDbgContext_PROV := 2 (* Service provider *)  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| eDbgContext\_NONE | Parameter not used |
| eDbgContext\_USER | The debug output was triggered by the service user |
| eDbgContext\_PROV | The debug output was triggered by the service provider |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
