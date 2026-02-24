# FILETIME64_TO_DT

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FILETIME64\_TO\_DT

![42015198](/tcplclib_tc2_utilities/1033/Images/gif/35862283__en-US__Web.gif)

The function "FILETIME64\_TO\_DT" converts the time in FILETIME format to DATE\_AND\_TIME format (DT). The DT format has a smaller value range than the FILETIME format and only offers second accuracy. For this reason the FILETIME value to be converted is limited. The permitted minimum corresponds to value *DT#1970-01-01-00:00:00* and the maximum to value *DT#2106-02-06-06:28:15*. Milliseconds are not considered in the conversion and are rounded down to the DATE\_AND\_TIME return value accordingly.

## FUNCTION FILETIME64\_TO\_DT : DT

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
    timeAsFileTime : T_FILETIME64;  
    timeAsDT       : DT;  
END_VAR
```

```
timeAsFileTime := F_GetSystemTime();  
timeAsDT := FILETIME64_TO_DT( timeAsFileTime );
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.44.0 |
