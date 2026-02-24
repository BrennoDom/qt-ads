# ConvertPathPosToDcTime

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [DCTIME32](ms-xhelp:///?Id=beckhoff-22d7-48fc-b02e-34ef4e63128a)
4. ConvertPathPosToDcTime

# ConvertPathPosToDcTime

![31746690](/tcplclib_tc2_ethercat/1033/Images/png/57323019__Web.png)

This function block converts a relative Nci path distance to a corresponding 32-bit distributed clock system time variable of type [T\_DCTIME32](ms-xhelp:///?Id=beckhoff-7eec-46ad-b309-87e976292f31) (i.e. the time that corresponds or corresponded to the relative Nci path distance).

## VAR\_INPUT

```
VAR_INPUT  
    nGrpId    : UDINT;  
    nSubIdx   : UDINT;  
    fPosition : LREAL;  
END_VAR
```

**nGrpId:** Group ID of the corresponding Nci channel

**nSubIdx:** This 32-bit input variable contains two different items of information, and is therefore divided into two 16-bit values:

* The low word (the 16 bits with the lowest value) contains the subindex for relative addressing of an encoder subelement at an axis. The subindex is counted upwards from zero. For the typical case of an axis that has just one encoder, the null subindex is correct.
* The high word (the 16 bits with the highest value) contains a control word (bit mask) that affects the way in which the position is calculated (e.g. the type of interpolation or extrapolation).  
  A bit mask value of 0x0001 means that the set acceleration of the axis is to be included in the calculation.  
  Bit mask 0x0010 means that the calculation is relative and currently compulsory. Otherwise the call is rejected with an error.

**fPosition:** Relative Nci path distance, which is converted to the corresponding 32-bit distributed clock system time.  
If the distributed clock system time that corresponds to the relative Nci path distance is outside the expected time window of ± 2,147 seconds, this conversion is rejected with an error number.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    dcTime : T_DCTIME32;(* 32 bit distributed clock time *)  
    iErr   : UDINT;  
END_VAR
```

**dcTime:** Returns the 32-bit distributed clock system time variable that corresponds to input fPosition.

**iErr:** Supplies an error number if an error occurs, e.g.

* Error 0x4361: time window exceeded (future),
* Error 0x4362: time window exceeded (past),
* Error 0x4363: position cannot be found mathematically.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
