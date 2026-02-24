# F_GetActualDcTime64

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [DCTIME64 and ULINT](ms-xhelp:///?Id=beckhoff-e560-4c02-a664-0d00df184ca7)
4. F\_GetActualDcTime64

# F\_GetActualDcTime64

![63883391](/tcplclib_tc2_ethercat/1033/Images/png/2268468619__Web.png)

This function returns the current time in TwinCAT distributed clock system time format ([T\_DCTIME64](ms-xhelp:///?Id=beckhoff-61c0-4c24-9dad-22f122397674)).

## FUNCTION F\_GetActaulDCTime: T\_DCTIME64

```
VAR_INPUT  
(*none*)  
END_VAR
```

**Sample in ST:**

```
PROGRAM MAIN  
VAR  
    actDC : T_DCTIME64;  
    sAct  : STRING;  
END_VAR  
  
actDC := F_GetActualDcTime64();  
sAct  := DCTIME64_TO_STRING( actDC );
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
