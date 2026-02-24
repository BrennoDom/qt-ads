# E_EnumCmdType

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_EnumCmdType

Control parameter for enumeration blocks. Not all parameters are used by each enumeration block!

```
TYPE E_EnumCmdType :  
(  
    eEnumCmd_First := 0,  
    eEnumCmd_Next,  
    eEnumCmd_Abort  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| eEnumCmd\_First | Lists the first element |
| eEnumCmd\_Next | Lists the next element |
| eEnumCmd\_Abort | Cancels the listing (closes open handles) |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
