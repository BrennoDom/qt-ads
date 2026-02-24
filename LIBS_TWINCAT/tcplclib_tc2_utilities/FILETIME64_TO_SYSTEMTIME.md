# FILETIME64_TO_SYSTEMTIME

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FILETIME64\_TO\_SYSTEMTIME

![42592467](/tcplclib_tc2_utilities/1033/Images/gif/35865483__en-US__Web.gif)

The function "FILETIME64\_TO\_SYSTEMTIME" converts the time in FILETIME format into the "readable" SYSTEMTIME format. The conversion fails if the most significant bit of the 64-bit FILETIME variables is set. In this case the TIMESTRUCT member variables have the value zero.

## FUNCTION FILETIME64\_TO\_SYSTEMTIME: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)

## VAR\_INPUT

```
VAR_INPUT  
    fileTime : T_FILETIME64;  
END_VAR
```

**fileTime:** The time to be converted in the FILETIME format (type: [T\_FILETIME64](ms-xhelp:///?Id=beckhoff-4145-4760-bacf-86b973e5260d)).

**Sample:**

```
PROGRAM MAIN  
VAR  
    timeAsFileTime   : T_FILETIME64;  
    timeAsSystemTime : TIMESTRUCT;  
END_VAR
```

```
timeAsFileTime := F_GetSystemTime();  
timeAsSystemTime := FILETIME64_TO_SYSTEMTIME( timeAsFileTime );
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.44.0 |
