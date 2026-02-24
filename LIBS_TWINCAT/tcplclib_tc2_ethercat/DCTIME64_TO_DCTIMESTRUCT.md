# DCTIME64_TO_DCTIMESTRUCT

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [DCTIME64](ms-xhelp:///?Id=beckhoff-4896-4dc7-a801-9f7bad5a1eb8)
4. DCTIME64\_TO\_DCTIMESTRUCT

# DCTIME64\_TO\_DCTIMESTRUCT

![57887863](/tcplclib_tc2_ethercat/1033/Images/png/2267471755__Web.png)

The function converts a 64-bit distributed clock system time variable of type [T\_DCTIME64](ms-xhelp:///?Id=beckhoff-61c0-4c24-9dad-22f122397674) to a structured variable of type [DCTIMESTRUCT](ms-xhelp:///?Id=beckhoff-8f59-4ff7-aabf-851c8fa233f6).

## FUNCTION DCTIME64\_TO\_DCTIMESTRUCT

```
VAR_INPUT  
    in : T_DCTIME64;  
END_VAR
```

**in**: The distributed clock system time variable to be converted

**Example:**

```
PROGRAM P_TEST  
VAR  
    dcStruct : DCTIMESTRUCT;  
    dcTime : T_DCTIME64;  
END_VAR  
  
dcTime : F_GetCurDcTickTime64();  
dcStruct := DCTIME64_TO_DCTIMESTRUCT (dcTIME);
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
