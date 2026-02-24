# E_TimeZoneID

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_TimeZoneID

Additional information on the configured time zone of the operating system.

```
TYPE E_TimeZoneID :  
(  
    eTimeZoneID_Invalid  := -1,  
    eTimeZoneID_Unknown  := 0,  
    eTimeZoneID_Standard := 1,  
    eTimeZoneID_Daylight := 2  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| eTimeZoneID\_Invalid | The time zone configuration could not be read |
| eTimeZoneID\_Unknown | The time zone configuration could be read, but the standard/summer time information is unknown |
| eTimeZoneID\_Standard | Currently standard time is used |
| eTimeZoneID\_Daylight | Currently summer time is used |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
