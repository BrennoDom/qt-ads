# T_IPv4AddrArr

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. T\_IPv4AddrArr

# T\_IPv4AddrArr

The variable of this type is a array of bytes containing the (IPv4) Internet Protocol network address.

```
TYPE T_IPv4AddrArr: ARRAY[0..3] OF BYTE;  
END_TYPE
```

The address bytes are represented in network byte order.  
E.g. '172.16.7.199' is represented as:

byte[0] := 172  
byte[1] := 16  
byte[2] := 7  
byte[3] := 199

**Example:** [F\_ScanIPv4AddrIds](ms-xhelp:///?Id=beckhoff-5604-47cd-b3b2-ef7beb7efdcd)

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
