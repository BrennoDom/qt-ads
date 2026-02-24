# SYSTEMTIME_TO_DCTIME64

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [DCTIME64](ms-xhelp:///?Id=beckhoff-4896-4dc7-a801-9f7bad5a1eb8)
4. SYSTEMTIME\_TO\_DCTIME64

# SYSTEMTIME\_TO\_DCTIME64

![52942405](/tcplclib_tc2_ethercat/1033/Images/png/2267453835__Web.png)

The function converts a structured Windows system time variable of type TIMESTRUCT to a 64-bit distributed clock system time variable of type [T\_DCTIME64](ms-xhelp:///?Id=beckhoff-61c0-4c24-9dad-22f122397674). In the event of a conversion error the function returns the value zero.

## FUNCTION SYSTEMTIME\_TO\_DCTIME64: T\_DCTIME64

```
VAR_INPUT  
    in : TIMESTRUCT;  
    micro : WORD(0..999); (* Microseconds: 0..999 *)  
    nano : WORD(0..999); (* Nanoseconds: 0..999 *)  
END_VAR
```

**in**: The Windows system time variable to be converted

**micro**: microseconds

**nano**: nanoseconds

**Example:**

```
PROGRAM P_TEST  
VAR  
    syst : TIMESTRUCT := ( wYear := 2009, wMonth := 9, wDay := 16, wHour := 12, wMinute := 22, wSecond := 44, wMilliseconds := 123 );  
END_VAR  
  
dct := SYSTEMTIME_TO_DCTIME64( syst, 456, 789 );
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
