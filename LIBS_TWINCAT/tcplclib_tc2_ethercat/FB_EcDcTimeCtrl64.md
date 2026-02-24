# FB_EcDcTimeCtrl64

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [DCTIME64](ms-xhelp:///?Id=beckhoff-4896-4dc7-a801-9f7bad5a1eb8)
4. FB\_EcDcTimeCtrl64

# FB\_EcDcTimeCtrl64

![6719600](/tcplclib_tc2_ethercat/1033/Images/png/2267420555__Web.png)

This function block can be used to read the individual components such as year, month, day etc. of a 64-bit distributed clock system time variable of type [T\_DCTIME64](ms-xhelp:///?Id=beckhoff-61c0-4c24-9dad-22f122397674). The function block has several A\_GETXYZ actions. Once the required action has been called, the value of the XYZ component is available in the “get” output variable. The “put” input variable is currently not used.

The function block features the following tasks:

* A\_GetYear
* A\_GetMonth
* A\_GetDay
* A\_GetDayOfWeek
* A\_GetHour
* A\_GetMinute
* A\_GetSecond
* A\_GetMilli
* A\_GetMicro
* A\_GetNano

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    in : T_DCTIME64;  
END_VAR
```

**in**: TwinCAT distributed clock system time variable

## VAR\_INPUT

```
VAR_IN_OUT  
    put : WORD;  
END_VAR
```

**put**: Input parameter (currently not used)

## VAR\_OUTPUT

```
VAR_IN_OUT  
    bError : BOOL;  
    get    : WORD;  
END_VAR
```

**bError**: This output is set if an error has occurred during the action call.

**get**: Output parameter (year, month, day, etc.)

## Example of an implementation in ST:

```
PROGRAM P_TEST  
VAR  
    dcStruct   : DCTIMESTRUCT;  
    dcTime     : T_DCTIME64;  
    fbCtrl     : FB_EcDcTimeCtrl;  
  
    wYear      : WORD;  
    wMonth     : WORD;  
    wDay       : WORD;  
    wDayOfWeek : WORD;  
    wHour      : WORD;  
    wMinute    : WORD;  
    wSecond    : WORD;  
    wMilli     : WORD;  
    wMicro     : WORD;  
    wNano      : WORD;  
END_VAR  
  
dcTime := F_GetCurDcTickTime64();  
fbCtrl.A_GetYear( in := dcTime, get => wYear );  
fbCtrl.A_GetMonth( in := dcTime, get => wMonth );  
fbCtrl.A_GetDay( in := dcTime, get => wDay );  
fbCtrl.A_GetDayOfWeek( in := dcTime, get => wDayOfWeek );  
fbCtrl.A_GetHour( in := dcTime, get => wHour );  
fbCtrl.A_GetMinute( in := dcTime, get => wMinute );  
fbCtrl.A_GetSecond( in := dcTime, get => wSecond );  
fbCtrl.A_GetMilli( in := dcTime, get => wMilli );  
fbCtrl.A_GetMicro( in := dcTime, get => wMicro );  
fbCtrl.A_GetNano( in := dcTime, get => wNano );
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
