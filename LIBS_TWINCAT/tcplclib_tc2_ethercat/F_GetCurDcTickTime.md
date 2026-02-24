# F_GetCurDcTickTime

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME and T\_LARGE\_INTEGER]](ms-xhelp:///?Id=beckhoff-d3df-4f17-b490-c93b45508d82)
5. F\_GetCurDcTickTime

# F\_GetCurDcTickTime

![52483186](/tcplclib_tc2_ethercat/1033/Images/png/57303819__Web.png)

|  |  |
| --- | --- |
| 2586631 | Outdated function  The function is outdated. Use the function [F\_GetCurDcTickTime64](ms-xhelp:///?Id=beckhoff-e6a9-4568-af3f-a48b9d496afb) instead. |

The function returns the time of the current (last) tick in TwinCAT distributed clock system time format ([T\_DCTIME](ms-xhelp:///?Id=beckhoff-27de-43e4-9ec2-613239202c77)).

## FUNCTION F\_GetCurDcTickTime: T\_DCTIME

```
VAR_INPUT  
(*none*)  
END_VAR
```

**Example:**

```
PROGRAM MAIN  
VAR  
    tDC : T_DCTIME;  
    sDC : STRING;  
    tDCBack : T_DCTIME;  
  
    sDCZero : STRING;(* DCTIME = zero time starts on 01.01.2000 *)  
    tDCBackFromZero : T_DCTIME;  
  
    tDCFromString : T_DCTIME;  
    sDCBackFromString : STRING;  
END_VAR  
  
tDC := F_GetCurDcTickTime();  
sDC := DCTIME_TO_STRING( tDC );  
tDCBack := STRING_TO_DCTIME( sDC );  
  
sDCZero := DCTIME_TO_STRING( ULARGE_INTEGER(0, 0) );  
tDCBackFromZero := STRING_TO_DCTIME( sDCZero );  
  
tDCFromString := STRING_TO_DCTIME( '2007-03-09-11:31:09.223456789' );  
sDCBackFromString := DCTIME_TO_STRING( tDCFromString );
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
