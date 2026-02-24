# F_CreateAmsNetId

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [ADS functions](ms-xhelp:///?Id=beckhoff-5576-4d9d-9f14-f989dcb02fd7)
4. F\_CreateAmsNetId

# F\_CreateAmsNetId

![52618583](/tcplclib_tc2_system/1033/Images/png/9007199286119563__Web.png)

The function generates a formatted NetID string (type: [T\_AmsNetID](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)) and returns it as return parameter (e.g. '127.16.17.3.1.1').

## FUNCTION F\_CreateAmsNetId : T\_AmsNetId

```
VAR_INPUT  
    nIds : T_AmsNetIdArr;  
END_VAR
```

**nIds**: Byte array (type: [T\_AmsNetIdArr](ms-xhelp:///?Id=beckhoff-df02-4290-a2ea-8872fba602a2)). Each byte corresponds to a number of the network address. The address bytes have a network byte order.

**Example of a call in ST:**

```
PROGRAM MAIN  
VAR  
    ids    : T_AmsNetIdArr := 127, 16, 17, 3, 1, 1;  
    sNetID : T_AmsNetID := '';  
END_VAR  
  
sNetID := F_CreateAmsNetId( ids );(* Result: '127.16.17.3.1.1' *)
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
