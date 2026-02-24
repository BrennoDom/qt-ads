# F_ScanAmsNetIds

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [ADS functions](ms-xhelp:///?Id=beckhoff-5576-4d9d-9f14-f989dcb02fd7)
4. F\_ScanAmsNetIds

# F\_ScanAmsNetIds

![3805200](/tcplclib_tc2_system/1033/Images/png/9007199286122763__Web.png)

The function F\_ScanAmsNetIds can be used to convert a string containing the TwinCAT network address to individual address bytes. The individual address bytes are converted from left to right and returned as an array of bytes (type: [T\_AmsNetIdArr](ms-xhelp:///?Id=beckhoff-df02-4290-a2ea-8872fba602a2)). The address bytes have a network byte order.

## FUNCTION F\_ScanAmsNetIds : T\_AmsNetIdArr

```
VAR_INPUT  
    sNetID : T_AmsNetID;  
END_VAR
```

**sNetID**: TwinCAT network address as string (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)). E.g. '127.16.17.3.1.1''

| Input parameters | Return parameter | Description |
| --- | --- | --- |
| sNetID ≠ '' (empty string)  and sNetID ≠ '0.0.0.0.0.0' | All bytes are null | Error during the conversion, check the formatting of the sNetID string. |

**Example of a call in ST:**

In the following example, a string with the network address '127.16.17.3.1.1' is converted to an array of address bytes.

```
PROGRAM MAIN  
VAR  
    ids    : T_AmsNetIDArr;  
    sNetID : T_AmsNetID := '127.16.17.3.1.1';  
END_VAR  
  
ids := F_ScanAmsNetIds( sNetID );(* Result: ids[0]:=127, ids[1]:=16, ids[2]:=17, ids[3]:=3, ids[4]:=1, ids[5]:=1 *) 
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
