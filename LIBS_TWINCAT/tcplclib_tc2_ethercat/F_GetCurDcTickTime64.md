# F_GetCurDcTickTime64

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [DCTIME64 and ULINT](ms-xhelp:///?Id=beckhoff-e560-4c02-a664-0d00df184ca7)
4. F\_GetCurDcTickTime64

# F\_GetCurDcTickTime64

![7172200](/tcplclib_tc2_ethercat/1033/Images/png/2268463499__Web.png)

The function returns the time of the current (last) tick in TwinCAT distributed clock system time format ([T\_DCTIME64](ms-xhelp:///?Id=beckhoff-61c0-4c24-9dad-22f122397674)).

## FUNCTION F\_GetCurDcTickTime64: T\_DCTIME64

```
VAR_INPUT  
(*none*)  
END_VAR
```

**Example:**

```
PROGRAM MAIN  
VAR  
    tDC : T_DCTIME64;  
    sDC : STRING;  
    tDCBack : T_DCTIME64;  
  
    sDCZero : STRING;(* DCTIME64 = zero time starts on 01.01.2000 *)  
    tDCBackFromZero : T_DCTIME64;  
  
    tDCFromString : T_DCTIME64;  
    sDCBackFromString : STRING;  
END_VAR  
  
tDC := F_GetCurDcTickTime64();  
sDC := DCTIME64_TO_STRING( tDC );  
tDCBack := STRING_TO_DCTIME64( sDC );  
  
sDCZero := DCTIME64_TO_STRING( ULARGE_INTEGER(0, 0) );  
tDCBackFromZero := STRING_TO_DCTIME64( sDCZero );  
  
tDCFromString := STRING_TO_DCTIME64( '2007-03-09-11:31:09.223456789' );  
sDCBackFromString := DCTIME64_TO_STRING( tDCFromString );
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
