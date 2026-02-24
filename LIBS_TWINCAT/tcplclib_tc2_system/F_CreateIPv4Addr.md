# F_CreateIPv4Addr

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. F\_CreateIPv4Addr

# F\_CreateIPv4Addr

![27655246](/tcplclib_tc2_system/1033/Images/png/9007199286039563__Web.png)

The function generates a formatted (IPv4) Internet protocol network address and returns it as a return parameter of type string (e.g. 172.16.7.199).

## FUNCTION **F\_CreateIPv4Addr** : T\_IPv4Addr

```
VAR_INPUT  
    nIds : T_IPv4AddrArr;  
END_VAR
```

**nIds**: Byte array. Every byte is equivalent to one number of the (IPv4) Internet Protocol network adress. The address bytes are represented in network byte order (type: [T\_IPv4AddrArr](ms-xhelp:///?Id=beckhoff-a745-4749-b99d-3d892c9cbd33)).

**Example in structured text:**

```
PROGRAM MAIN  
VAR  
    ids   : T_IPv4AddrArr := 172, 16, 7, 199;  
    sIPv4 : T_IPv4Addr := '';  
END_VAR  
  
sIPv4 := F_CreateIPv4Addr( ids );(* Result: '172.16.7.199' *) 
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
