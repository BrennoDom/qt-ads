# ST_TimeStamp

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine Functional Tag Description](ms-xhelp:///?Id=beckhoff-cfa1-4cf2-bed5-de71541a6707)
3. [DataTypes](ms-xhelp:///?Id=beckhoff-9ab3-480d-a692-669d690fad49)
4. [Alarm](ms-xhelp:///?Id=beckhoff-8226-41be-850c-2af8861f6f1b)
5. ST\_TimeStamp

# ST\_TimeStamp

This structure is used to store the time and date of an event or the acknowledge of an event.

```
TYPE ST_TimeStamp :   
STRUCT  
    Year                : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    Month               : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    Day                 : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    Hour                : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    Minute              : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    Second              : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    mSec                : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
