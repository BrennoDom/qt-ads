# SYSTEMTIME_TO_STRING

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# SYSTEMTIME\_TO\_STRING

![33381819](/tcplclib_tc2_utilities/1033/Images/gif/35907083__en-US__Web.gif)

The function converts the Windows system time structure into a string with the following format: **YYYY-MM-DD-hh:mm:ss.xxx**:

* YYYY: Year (1601..9999)
* MM: Month (01..12);
* DD: Day (01..31)
* hh: Hour (00..23)
* mm: Minutes (00..59)
* ss: Second (00..59)
* xxx: Millisecond (000..999)

## FUNCTION SYSTEMTIME\_TO\_STRING: STRING(24)

## VAR\_INPUT

```
VAR_INPUT  
    in : TIMESTRUCT;  
END_VAR
```

**in**: The structure with the Windows system time requiring conversion (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)).

**Example:**

```
PROGRAM MAIN  
VAR  
    fbGetSystemTime  : GETSYSTEMTIME;  
    fileTime         : T_FILETIME;  
    sTime            : STRING;  
END_VAR
```

```
fbGetSystemTime(timeLoDW=>fileTime.dwLowDateTime, timeHiDW=>fileTime.dwHighDateTime );  
sTime := SYSTEMTIME_TO_STRING( FILETIME_TO_SYSTEMTIME( fileTime ) );
```

Online view:

![32000920](/tcplclib_tc2_utilities/1033/Images/gif/35910283__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
