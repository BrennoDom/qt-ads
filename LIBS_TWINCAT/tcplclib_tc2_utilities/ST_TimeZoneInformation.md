# ST_TimeZoneInformation

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_TimeZoneInformation

Time zone information. The standard time is also referred to as winter time. The bias parameter can also have negative values.

```
TYPE ST_TimeZoneInformation :  
STRUCT  
    bias         : DINT  
    standardName : STRING(31);  
    standardDate : TIMESTRUCT;  
    standardBias : DINT;  
    daylightName : STRING(31);  
    daylightDate : TIMESTRUCT;  
    daylightBias : DINT;  
END_STRUCT  
END_TYPE
```

**bias**: Defines the current difference between the local time and the UTC time in minutes. UTC = local time + bias.

**standardName**: Name of the standard time as string.

**standardDate**: This structure contains information on the transition from summer time to standard time (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)). The structure parameters *wMonth* is zero if this value is not used. If this parameter is used, the *daylightDate*-parameter must also be used. In order to be able to configure *standardDate,* set the *wYear* parameter to zero, select the required day of the week for *wDayOfWeek* and select a value between 1 and 5 for *wDay* (week of the month, 5 is the last week).

**standardBias**: Time difference in minutes for calculating the local time during standard time. This value is usually zero.

**daylightName**: Name of the summer time as string.

**daylightDate**: This structure contains information on the transition from standard time to summer time (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)). The structure parameters *wMonth* is zero if this value is not used. If this parameter is used, the *standardDate*-parameter must also be used. In order to be able to configure *daylightDate,* set the *wYear* parameter to zero, select the required day of the week for *wDayOfWeek* and select a value between 1 and 5 for *wDay* (week of the month, 5 is the last week).

**daylightBias**: Time difference in minutes for calculating the local time during summer time.

## Example:

See: [FB\_SetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-4f69-47a9-b40b-5f2f878dd0cd).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
