# SYSTEMTIME_TO_DT

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# SYSTEMTIME\_TO\_DT

![45613538](/tcplclib_tc2_utilities/1033/Images/gif/35897483__en-US__Web.gif)

The "SYSTEMTIME\_TO\_DT" function allows the Windows system time structure to be converted to the DATE\_AND\_TIME format (DT) usual in a PLC. The system time has a resolution of 1ms, while the resolution of DATE\_AND\_TIME is 1s. The milliseconds from the system time are used in the course of the conversion to determine the direction of rounding for the returned DATE\_AND\_TIME value. To disable rounding, set the wMilliseconds element in the Windows system time structure to zero.

## FUNCTION SYSTEMTIME\_TO\_DT: DT

## VAR\_INPUT

```
VAR_INPUT  
    TIMESTR : TIMESTRUCT;  
END_VAR
```

**TIMESTR**: The structure with the Windows system time requiring conversion (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)).

**Example:**

```
PROGRAM SystemTimeTest  
VAR  
    SystemTimeStruct  : TIMESTRUCT;  
    DTFromSystemTime  : DT;  
END_VAR
```

![7868661](/tcplclib_tc2_utilities/1033/Images/gif/35900683__en-US__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
