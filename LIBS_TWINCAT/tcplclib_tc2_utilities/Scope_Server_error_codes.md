# Scope Server error codes

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Scope Server error codes

The following error codes are returned by the [FB\_ScopeServerControl](ms-xhelp:///?Id=beckhoff-d943-4605-855c-46da3b86c1b9) function block.

```
TYPE E_UTILITIES_ERRORCODES :  
(  
   eUtilError_NoError                 := 0,  
   eUtilError_ScopeServerNotAvailable := 16#8001,  
   eUtilError_ScopeServerStateChange  := 16#8002  
);  
END_TYPE
```

| Error code | Enum | Meaning |
| --- | --- | --- |
| 0x0000 | eUtilError\_NoError | No error |
| 0x8001 | eUtilError\_ScopeServerNotAvailable | TwinCAT Scope Server is not available. It may not be installed. |
| 0x8002 | eUtilError\_ScopeServerStateChange | The requested change of status is not permitted. For list of valid changes of status see B\_ScopeServerControl [state diagram](ms-xhelp:///?Id=beckhoff-d943-4605-855c-46da3b86c1b9). |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
