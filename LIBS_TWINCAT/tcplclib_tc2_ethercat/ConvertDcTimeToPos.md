# ConvertDcTimeToPos

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [DCTIME32](ms-xhelp:///?Id=beckhoff-22d7-48fc-b02e-34ef4e63128a)
4. ConvertDcTimeToPos

# ConvertDcTimeToPos

![37418306](/tcplclib_tc2_ethercat/1033/Images/png/57313419__Web.png)

This function block converts a 32-bit distributed clock system time variable of type [T\_DCTIME32](ms-xhelp:///?Id=beckhoff-7eec-46ad-b309-87e976292f31) to a corresponding NC axis position (i.e. the NC axis position at precisely this time).

## VAR\_INPUT

```
VAR_INPUT  
    nAxisId : UDINT;  
    nSubIdx : UDINT;  
    dcTime  : T_DCTIME32;(* 32 bit distributed clock time *)  
END_VAR
```

**nAxisId:** ID of the NC axis

**nSubIdx:** This 32-bit input variable contains two different items of information, and is therefore divided into two 16-bit values:

* The low word (the 16 bits with the lowest value) contains the subindex for relative addressing of an encoder subelement at an axis. The subindex is counted upwards from zero. For the typical case of an axis that has just one encoder, the null subindex is correct.
* The high word (the 16 bits with the highest value) contains a control word (bit mask) that affects the way in which the position is calculated (e.g. the type of interpolation or extrapolation). A bit mask value of 0x0001 means that the set acceleration of the axis is to be included in the calculation.

**dcTime:** 32-bit distributed clock system time variable. This input magnitude is converted through calculation into the corresponding NC axis position.

Note

The 32-bit time may only be used in the narrow range of ± 2,147 seconds around the current system time, to ensure that it is unambiguous. Within the function block this prerequisite cannot be checked.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    fPosition : LREAL;  
    iErr : UDINT;  
END_VAR
```

**fPosition:** Supplies the NC axis position corresponding to dcTime. This is an NC axis position that has been scaled and provided with an offset, having, for instance, physical units of degrees or of millimetres.

**iErr:** Returns the error number if an error occurs, e.g. error 0x4012 (axis ID is not allowed, or axis does not exist within the system).

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
