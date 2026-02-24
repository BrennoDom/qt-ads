# FILETIME64_TO_ISO8601

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FILETIME64\_TO\_ISO8601

This function converts the Windows system time in the T\_FILETIME64 format to a string with the format of the ISO 8601 standard.

The result conforms to the following pattern: **YYYY-MM-DDThh:mm:ss.xxxTZD**

## FUNCTION FILETIME64\_TO\_ISO8601 : STRING(39)

## VAR\_INPUT

```
VAR_INPUT  
    fileTime   : T_FILETIME64; (* Time to be converted (file time format), 64-bit value representing the number of 100-nanosecond intervals since January 1, 1601 *)  
    nBias      : INT;          (* Specifies the current bias, in minutes, for local time translation on this computer.  
                                The bias is the difference, in minutes, between Coordinated Universal Time (UTC) and local time.  
                                UTC = local time + bias *)      
    bUTC       : BOOL;         (* Specifies whether the fileTime is UTC or local time. *)  
    nPrecision : USINT(0..9);  (* Precision. Number of decimal places of seconds. (0..9) *)  
END_VAR
```

**fileTime**: Specifies the time to be converted (Type: [T\_FILETIME64](ms-xhelp:///?Id=beckhoff-4145-4760-bacf-86b973e5260d)).

**nBias**: Specifies the current time offset in minutes between the Coordinated Universal Time (UTC) and the local time. The following applies: UTC = local time + time offset

**bUTC**: Specifies whether the time specified at the input corresponds to the UTC or the local time.

**nPrecision**: Specifies the accuracy of the seconds representation as a number of decimal places.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.46.0 |
