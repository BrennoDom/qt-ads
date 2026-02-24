# T_AmsNetId

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. T\_AmsNetId

# T\_AmsNetId

The variable of this type is a string containing the AMS network identifier of the target device to which the ADS command is directed. The string consists of six numerical fields, separated by dots. Each numerical field contains a number between 1 and 254. Valid AMS network addresses are, for example, '1.1.1.2.7.1' or '200.5.7.170.1.7'. If an empty string is passed, the AMS network identifier of the local device is automatically assumed.

```
TYPE T_AmsNetId : STRING(23);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
