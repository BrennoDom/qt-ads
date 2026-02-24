# FB_FileTime64ToTzSpecificLocalTime

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_FileTime64ToTzSpecificLocalTime

![50810959](/tcplclib_tc2_utilities/1033/Images/png/9007199290225675__Web.png)

The function block converts the UTC time (file time format) to local time (file time format), taking into account the specified time zone information. The function block: [FB\_SystemTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-20ad-46e0-9bae-a6b428b840f1) has a similar function, the difference being that it converts to a different time format (structured system time format).

The function block is only suitable for conversion of **continuous** UTC timestamp information. The function block uses the time zone information to calculate the required time steps (summer/winter time changeover) in local time. Time steps in UTC input time are not permitted and lead to incorrect conversion. The reason: the function block stores the last converted time internally, so that it can detect the B times (see below) from the UTC input time and the stored value when the local time is changed.

The function block is associated with an action: A\_Reset(). If this action is called the function block outputs and the locally stored (last converted) time are reset to zero.

1. Graphic representation of the changeover from summer time to winter time (tzInfo = WEST\_EUROPE\_TZI ):

![54645451](/tcplclib_tc2_utilities/1033/Images/gif/35487883__en-US__Web.gif)

The UTC input time (green) is continuous. The local time (red) jumps back. The local time: **02h:59m:59s:999ms..** is directly followed by: **02h:00m:00s:000ms..** The times between 2h and 3h occur twice. The duplicate time before the changeover is referred to as **02:05:00 CEST A**, for example, the time after the changeover as **02:05:00 CET B.** The output variable *bB* indicates whether it is the first or the second *pass*. During the second *pass* the *bB* output variable (blue) is set to TRUE. The *bB* output variable is automatically reset once the duplicate time has passed. The time zone ID (orange) changes from *eTimeZoneID\_Daylight* (summer time) to *eTimeZoneID\_Standard* (winter time).

2. Graphic representation of the change-over from winter time to summer time (tzInfo = WEST\_EUROPE\_TZI):

![22047016](/tcplclib_tc2_utilities/1033/Images/gif/35491083__en-US__Web.gif)

The UTC input time (green) is continuous. The local time (green) jumps forward. The local time: **2h:59m:59s:999ms..** is directly followed by: **3h:00m:00s:000ms..** The time zone ID (orange) changes from *eTimeZoneID\_Standard* (winter time) to *eTimeZoneID\_Daylight* (summer time).

## VAR\_INPUT

```
VAR_INPUT  
    in     : T_FILETIME64;  
    tzInfo : ST_TimeZoneInformation;  
END_VAR
```

**in**: UTC time (file time format) that is to be converted (type: [T\_FILETIME64](ms-xhelp:///?Id=beckhoff-4145-4760-bacf-86b973e5260d)).

**tzInfo**: Structure variable with the current time zone information of the operating system (type: [ST\_TimeZoneInformation](ms-xhelp:///?Id=beckhoff-fbaf-46ea-9f34-f9e4a2954fdc)).

## VAR\_OUTPUT

```
VAR_OUTPUT  
    out   : T_FILETIME64;  
    eTzID : E_TimeZoneID := eTimeZoneID_Unknown;  
    bB    : BOOL;  
END_VAR
```

**out**: Converted local time (file time format, type: [T\_FILETIME64](ms-xhelp:///?Id=beckhoff-4145-4760-bacf-86b973e5260d)).

**eTzID**: Additional summer/winter time information. (Type: [E\_TimeZoneID](ms-xhelp:///?Id=beckhoff-0c9b-48fa-97bf-e3de81dbfdb1))

**bB**: TRUE => B-time (e.g.:**02:05:00 CET B**), FALSE => remaining time (e.g.: **02:05:00 CEST A**). This output is set if the local time jumps back and is reset once the duplicate local time has passed.

**Sample**:

The UTC time: DT#2011-09-02-09:01:31 is converted to local time. The result is: DT#2011-09-02-11:01:31.

```
PROGRAM MAIN  
VAR  
    in        : DT := DT#2011-09-02-09:01:31;(* UTC time *)  
    out       : DT;(* Local time *)  
    fbToLocal : FB_FileTime64ToTzSpecificLocalTime;  
END_VAR
```

```
fbToLocal( in := DT_TO_FILETIME64( in ), tzInfo := WEST_EUROPE_TZI );  
out := FILETIME64_TO_DT( fbToLocal.out );
```

Further time and time zone functions and function blocks:

* [FB\_TzSpecificLocalTimeToSystemTime](ms-xhelp:///?Id=beckhoff-2d5a-443c-9aa9-97c8c02f3336)
* [FB\_TzSpecificLocalTimeToFileTime64](ms-xhelp:///?Id=beckhoff-4dc2-432c-b436-08e8f5b7e0ee)
* [FB\_SystemTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-20ad-46e0-9bae-a6b428b840f1)
* [FB\_GetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-e94e-4efc-8b9a-294d8ea2dae1)
* [FB\_SetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-4f69-47a9-b40b-5f2f878dd0cd)
* [NT\_SetLocalTime](ms-xhelp:///?Id=beckhoff-69e6-480d-9a57-f100d0f6f752)
* [NT\_GetTime](ms-xhelp:///?Id=beckhoff-2f0c-4113-8d0b-40bd61b5771c)
* [NT\_SetTimeToRTCTime](ms-xhelp:///?Id=beckhoff-ac7b-4d32-84f6-6f06db4a4da6)
* [F\_TranslateFileTime64Bias](ms-xhelp:///?Id=beckhoff-45ee-416a-9620-599a55124417)
* [FB\_LocalSystemTime](ms-xhelp:///?Id=beckhoff-40ca-431a-ad5c-7de4706ed264)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.44.0 |
