# F_TranslateFileTimeBias

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_TranslateFileTimeBias

![24474856](/tcplclib_tc2_utilities/1033/Images/gif/35855883__en-US__Web.gif)

This function converts the input time to the time in another time zone based on the specified bias time shift. The function can be used to convert the local time to UTC time (Universal Time Coordinates) and vice versa, for example.

## FUNCTION F\_TranslateFileTimeBias: [T\_FILETIME](ms-xhelp:///?Id=beckhoff-0450-4829-bf49-af9e07e7176d)

## VAR\_INPUT

```
VAR_INPUT  
    in    : T_FILETIME;  
    bias  : DINT;  
    toUTC : BOOL;  
END_VAR
```

**in**: Input time to be converted (type: [T\_FILETIME](ms-xhelp:///?Id=beckhoff-0450-4829-bf49-af9e07e7176d)).

**bias**: Difference between UTC time and local time in minutes (positive or negative values are permitted).

**toUTC**: This parameter can be used to specify the direction in which the input time is to be converted.

| toUTC | Direction | Internal formula |
| --- | --- | --- |
| FALSE | UTC -> local time | Local time := UTC - bias |
| TRUE | Local time -> UTC | UTC := local time + bias |

**Example**:

The *in* variable contains the time to be converted. The *bToUTC* variable determines the conversion direction. If *bToUTC* = TRUE the local time is converted to UTC time, if *bToUTC* = FALSE the UTC time is converted to local time. The *WEST\_EUROPE\_TZI* constant contains the time zone information for Western Europe. The required bias value is calculated from the time zone information in the constant and the current bDST setting (Daylight Saving Time). Alternatively, the current time zone information of a TwinCAT system can be determined with the function block: [FB\_GetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-e94e-4efc-8b9a-294d8ea2dae1).

**Important notice:** Data type DT was selected for the input time because of the visual control option in online mode. Conversions to other time formats are not necessarily recommend since the conversion functions can be very computing-intensive.

```
PROGRAM MAIN  
VAR  
    bDST    : BOOL := TRUE;(* TRUE => Daylight saving time, FALSE => Standard time *)  
    bToUTC  : BOOL := FALSE;(* TRUE => Convert local time to UTC time, FALSE => Convert UTC time to local time *)  
    in      : DT := DT#2011-08-29-15:15:31;  
    out     : DT;  
    bias    : DINT;  
END_VAR
```

```
IF bDST THEN  
    bias := WEST_EUROPE_TZI.bias + WEST_EUROPE_TZI.daylightBias;  
ELSE  
    bias := WEST_EUROPE_TZI.bias + WEST_EUROPE_TZI.standardBias;  
END_IF  
  
out := FILETIME_TO_DT( F_TranslateFileTimeBias( DT_TO_FILETIME( in ), bias, bToUTC ) );
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
