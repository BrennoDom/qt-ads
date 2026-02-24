# T_AmsNetIdArr

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. T\_AmsNetIdArr

# T\_AmsNetIdArr

```
TYPE T_AmsNetIdArr : ARRAY[0..5] OF BYTE;  
END_TYPE
```

The variable of this type is a array of bytes containing the AMS network identifier. The address bytes are represented in network byte order. E.g. '127.16.17.3.1.1' is represented as:

byte[0] = 127  
byte[1] = 16  
byte[2] = 17  
byte[3] = 3  
byte[4] = 1  
byte[5] = 1

**Example:** [F\_ScanAmsNetIds](ms-xhelp:///?Id=beckhoff-52cc-4b33-a9f0-92dd0c84d1c9)

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
