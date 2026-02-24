# DT_TO_SYSTEMTIME

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# DT\_TO\_SYSTEMTIME

![23924539](/tcplclib_tc2_utilities/1033/Images/gif/35743883__en-US__Web.gif)

The "DT\_TO\_SYSTEMTIME" function allows a PLC variable in DATE\_AND\_TIME format (DT) to be converted to a Windows system time structure. The system time has a resolution of 1ms, while the resolution of DATE\_AND\_TIME is 1s. The "wMilliseconds" variable in the system time structure therefore always returns the value zero.

## FUNCTION DT\_TO\_SYSTEMTIME: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)

## VAR\_INPUT

```
VAR_INPUT  
    DTIN  : DT;  
END_VAR
```

**DTIN:** The date and time to be converted, in DATE\_AND\_TIME format.

**Example:**

```
PROGRAM SystemTimeTest  
VAR  
    SystemTimeStruct : TIMESTRUCT;  
END_VAR
```

![13994266](/tcplclib_tc2_utilities/1033/Images/gif/35747083__en-US__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
