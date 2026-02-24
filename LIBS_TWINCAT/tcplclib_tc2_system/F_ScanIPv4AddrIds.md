# F_ScanIPv4AddrIds

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. F\_ScanIPv4AddrIds

# F\_ScanIPv4AddrIds

![47570623](/tcplclib_tc2_system/1033/Images/png/9007199286042763__Web.png)

The function F\_ScanIPv4AddrIds converts a string with the (IPv4) Internet Protocol network address into single address bytes. The single address bytes are converted from left to right. They are returned as an array of bytes. The address bytes are represented in network byte order.

## FUNCTION F\_ScanIPv4AddrIds: T\_IPv4AddrArr

```
VAR_INPUT  
    sIPv4 : T_IPv4Addr;  
END_VAR
```

**sIPv4**: Internet Protocol network address as string (type: [T\_IPv4Addr](ms-xhelp:///?Id=beckhoff-d1ea-41e5-97bf-578ae4a6ed31)). E. g. 172.16.7.199.

| Input value | Return value | Description |
| --- | --- | --- |
| sIPv4 ≠ '' (empty string)  and sIPv4 ≠ '0.0.0.0' | All bytes are zero | Error during conversion. Please check the format of sIPv4 input string. |

Example in structured text:

Internet Protocol (IPv4) network address string: '172.16.7.199' is converted to an array of address bytes.

```
PROGRAM MAIN  
VAR  
    ids    : T_IPv4AddrArr;  
    sIPv4  : T_IPv4Addr := '172.16.7.199';  
END_VAR  
  
ids := F_ScanIPv4AddrIds( sIPv4 ); (* Result: ids[0]:=172, ids[1]:=16, ids[2]:=7, ids[3]:=199 *) 
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
