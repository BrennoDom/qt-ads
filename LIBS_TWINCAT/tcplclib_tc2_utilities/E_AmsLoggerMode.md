# E_AmsLoggerMode

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_AmsLoggerMode

AMS logger control modes. This data type is used by the function block: [FB\_AmsLogger](ms-xhelp:///?Id=beckhoff-43a8-4a1a-aa0c-e492eebbc366).

```
TYPE E_AmsLoggerMode :  
(  
    AMSLOGGER_RUN   := 1,  
    AMSLOGGER_STOP  := 2  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| AMSLOGGER\_RUN | Starts the AMS Logger |
| AMSLOGGER\_STOP | Stops the AMS Logger |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
