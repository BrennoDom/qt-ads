# F_TranslateFileTime64Bias

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_TranslateFileTime64Bias

![29516363](/tcplclib_tc2_utilities/1033/Images/gif/35855883__en-US__Web.gif)

This function converts the input time to the time in another time zone based on the specified bias time shift. The function can be used to convert the local time to UTC time (Universal Time Coordinates) and vice versa, for example.

## FUNCTION F\_TranslateFileTime64Bias: [T\_FILETIME64](ms-xhelp:///?Id=beckhoff-4145-4760-bacf-86b973e5260d)

## VAR\_INPUT

```
VAR_INPUT  
    in    : T_FILETIME64;  
    bias  : DINT;  
    toUTC : BOOL;  
END_VAR
```

**in**: Input time that is to be converted (type: [T\_FILETIME64](ms-xhelp:///?Id=beckhoff-4145-4760-bacf-86b973e5260d)).

**bias**: Difference between UTC time and local time in minutes (positive or negative values are permitted).

**toUTC**: This parameter can be used to specify the direction in which the input time is to be converted.

| toUTC | Direction | Internal formula |
| --- | --- | --- |
| FALSE | UTC -> local time | Local time := UTC - bias |
| TRUE | Local time -> UTC | UTC := local time + bias |

**Sample**:

The *in* variable contains the time to be converted. The *bToUTC* variable determines the conversion direction. If *bToUTC* = TRUE the local time is converted to UTC time, if *bToUTC* = FALSE the UTC time is converted to local time. The *WEST\_EUROPE\_TZI* constant contains the time zone information for Western Europe. The required bias value is calculated from the time zone information in the constant and the current bDST setting (Daylight Saving Time). The current time zone information of a TwinCAT system can alternatively be determined with the function block: [FB\_GetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-e94e-4efc-8b9a-294d8ea2dae1).

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
  
out := FILETIME64_TO_DT( F_TranslateFileTime64Bias( DT_TO_FILETIME64( in ), bias, bToUTC ) );
```

Further time and time zone functions and function blocks:

* [FB\_TzSpecificLocalTimeToSystemTime](ms-xhelp:///?Id=beckhoff-2d5a-443c-9aa9-97c8c02f3336)
* [FB\_TzSpecificLocalTimeToFileTime64](ms-xhelp:///?Id=beckhoff-4dc2-432c-b436-08e8f5b7e0ee)
* [FB\_SystemTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-20ad-46e0-9bae-a6b428b840f1)
* [FB\_FileTime46ToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-4d79-47b0-998c-83f3fc73b9dd)
* [FB\_GetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-e94e-4efc-8b9a-294d8ea2dae1)
* [FB\_SetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-4f69-47a9-b40b-5f2f878dd0cd)
* [NT\_SetLocalTime](ms-xhelp:///?Id=beckhoff-69e6-480d-9a57-f100d0f6f752)
* [NT\_GetTime](ms-xhelp:///?Id=beckhoff-2f0c-4113-8d0b-40bd61b5771c)
* [NT\_SetTimeToRTCTime](ms-xhelp:///?Id=beckhoff-ac7b-4d32-84f6-6f06db4a4da6)
* [FB\_LocalSystemTime](ms-xhelp:///?Id=beckhoff-40ca-431a-ad5c-7de4706ed264)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.44.0 |
