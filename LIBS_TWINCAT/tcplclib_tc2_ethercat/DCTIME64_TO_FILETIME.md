# DCTIME64_TO_FILETIME

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. DCTIME64\_TO\_FILETIME

# DCTIME64\_TO\_FILETIME

![57883273](/tcplclib_tc2_ethercat/1033/Images/gif/2267469195__Web.gif)

The function converts a 64-bit distributed clock system time variable of type [T\_DCTIME64](ms-xhelp:///?Id=beckhoff-61c0-4c24-9dad-22f122397674) to a 64-bit Windows file time variable of type T\_FILETIME.

## FUNCTION DCTIME64\_TO\_FILETIME: T\_FILETIME

```
VAR_INPUT  
    in : T_DCTIME64:  
END_VAR;
```

**in**: The distributed clock system time variable to be converted

**Example:**

```
PROGRAM P_TEST  
VAR  
    ft  : T_FILETIME;  
    dct : T_DCTIME64;  
END_VAR  
  
dct := F_GetCurDcTickTime64();  
ft  := DCTIME64_TO_FILETIME(dct);
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
