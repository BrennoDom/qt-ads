# SYSTEMTIME_TO_ISO8601

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# SYSTEMTIME\_TO\_ISO8601

This function converts the Windows system time structure to a string with the format of the ISO 8601 standard.

The result conforms to the following pattern: **YYYY-MM-DDThh:mm:ss.xxxTZD**

## FUNCTION SYSTEMTIME\_TO\_ISO8601 : STRING(39)

## VAR\_INPUT

```
VAR_INPUT  
    systemTime  : TIMESTRUCT;  (* Input time in system time format (struct) *)  
    nBias       : INT;         (* Specifies the current bias, in minutes, for local time translation on this computer.  
                                The bias is the difference between Coordinated Universal Time (UTC) and local time.  
                                UTC = local time + bias *)      
    bUTC        : BOOL;        (* Specifies whether the systemTime is UTC or local time. *)  
    nPrecision  : USINT(0..9); (* Precision. Number of decimal places of seconds. (0..9) *)  
END_VAR
```

**systemTime**: Structure with the Windows system time to be converted (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)).

**nBias**: Specifies the current time offset in minutes between the Coordinated Universal Time (UTC) and the local time. The following applies: UTC = local time + time offset

**bUTC**: Specifies whether the time specified at the input corresponds to the UTC or the local time.

**nPrecision**: Specifies the accuracy of the seconds representation as a number of decimal places.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.46.0 |
