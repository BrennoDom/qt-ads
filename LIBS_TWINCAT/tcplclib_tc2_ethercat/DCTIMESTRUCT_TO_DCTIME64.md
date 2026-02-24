# DCTIMESTRUCT_TO_DCTIME64

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [DCTIME64](ms-xhelp:///?Id=beckhoff-4896-4dc7-a801-9f7bad5a1eb8)
4. DCTIMESTRUCT\_TO\_DCTIME64

# DCTIMESTRUCT\_TO\_DCTIME64

![33212803](/tcplclib_tc2_ethercat/1033/Images/png/2267461515__Web.png)

The function converts a structured variable of type of type [DCTIMESTRUCT](ms-xhelp:///?Id=beckhoff-8f59-4ff7-aabf-851c8fa233f6) to a 64-bit distributed clock system time variable [T\_DCTIME64](ms-xhelp:///?Id=beckhoff-61c0-4c24-9dad-22f122397674). The structure components wDayofWeek is ignored in the conversion. The structure components wYear must be greater than or equal to 2000 and less than 2584. For invalid values of the structure components the function returns the value zero.

## FUNCTION DCTIMESTRUCT\_TO\_DCTIME64: T\_DCTIME64

```
VAR_INPUT  
    in : DCTIMESTRUCT;  
END_VAR
```

**in**: The structured variable to be converted

**Example:**

```
PROGRAM P_TEST  
VAR  
    dcStruct : DCTIMESTRUCT := ( wYear := 2008, wMonth := 3, wDay := 13,  
                    wHour := 1, wMinute := 2, wSecond :=3,  
                    wMilliseconds := 123, wMicroseconds := 456, wNanoseconds := 789 );  
    dc64 : T_DCTIME64;  
END_VAR  
  
dc64 := DCTIMESTRUCT_TO_DCTIME64( dcStruct );
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
