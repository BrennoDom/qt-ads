# FILETIME_TO_SYSTEMTIME

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FILETIME\_TO\_SYSTEMTIME

![36306286](/tcplclib_tc2_utilities/1033/Images/gif/35865483__en-US__Web.gif)

The function "FILETIME\_TO\_SYSTEMTIME" converts the time in FILETIME format into the "readable" SYSTEMTIME format. The conversion fails if the most significant bit of the 64-bit FILETIME variables is set. In this case the TIMESTRUCT member variables have the value zero.

## FUNCTION FILETIME\_TO\_SYSTEMTIME: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)

## VAR\_INPUT

```
VAR_INPUT  
    fileTime : T_FILETIME;  
END_VAR
```

**fileTime:** The time to be converted in FILETIME format (type: [T\_FILETIME](ms-xhelp:///?Id=beckhoff-0450-4829-bf49-af9e07e7176d)).

**Example:**

```
PROGRAM MAIN  
VAR  
    fbSystemTime     : GETSYSTEMTIME;  
    timeAsFileTime   : T_FILETIME;  
    timeAsSystemTime : TIMESTRUCT;  
END_VAR
```

```
fbSystemTime( timeLoDW=>timeAsFileTime.dwLowDateTime, timeHiDW=>timeAsFileTime.dwHighDateTime );  
timeAsSystemTime := FILETIME_TO_SYSTEMTIME( timeAsFileTime );
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
