# FB_SystemTimeToTzSpecificLocalTime

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_SystemTimeToTzSpecificLocalTime

![19079158](/tcplclib_tc2_utilities/1033/Images/gif/35587083__en-US__Web.gif)

The function block converts the UTC time (structured system time format) to local time (structured system time format), taking into account the specified time zone information. The function block [FB\_FileTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-ed55-4f54-90d2-a8293198c22f) has similar functionality but uses a different time format (file time format).

The block is only suitable for conversion of **continuous** UTC timestamp information. The function block uses the time zone information to calculate the required time steps (summer/winter time changeover) in local time. Time steps in UTC input time are not permitted and lead to incorrect conversion. The reason: the block stores the last converted time internally, so that it can detect the B times (see below) from the UTC input time and the stored value when the local time is changed.

The block is associated with an action: A\_Reset(). If this action is called the block outputs and the locally stored (last converted) time are reset to zero.

## VAR\_INPUT

```
VAR_INPUT  
    in     : TIMESTRUCT;  
    tzInfo : ST_TimeZoneInformation;  
END_VAR
```

**in**: UTC time (structured system time format) to be converted (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)).

**tzInfo**: Structure variable with the current time zone information of the operating system (type: [ST\_TimeZoneInformation](ms-xhelp:///?Id=beckhoff-fbaf-46ea-9f34-f9e4a2954fdc)).

## VAR\_OUTPUT

```
VAR_OUTPUT  
    out   : TIMESTRUCT;  
    eTzID : E_TimeZoneID := eTimeZoneID_Unknown;  
    bB    : BOOL;  
END_VAR
```

**out**: Converted local time (structured system time format) (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)).

**eTzID**: Additional summer/winter time information (type: [E\_TimeZoneID](ms-xhelp:///?Id=beckhoff-0c9b-48fa-97bf-e3de81dbfdb1)).

**bB**: TRUE => B time (e.g.:**02:05:00 CET B**), FALSE => other time (e.g.: **02:05:00 CEST A**). This output is set if the local time jumps back and is reset once the duplicate local time has passed.

**Example**:

```
PROGRAM MAIN  
VAR  
    in        : TIMESTRUCT := ( wYear := 2011, wMonth := 4, wDay := 29, wHour := 14, wMinute := 46, wSecond := 31, wMilliseconds := 99 );(* UTC time *)  
    out       : TIMESTRUCT; (* Local time result is:= ( wYear := 2011, wMonth := 4, wDay := 29, wHour := 16, wMinute := 46, wSecond := 31, wMilliseconds := 99 ) *)  
    fbToLocal : FB_SystemTimeToTzSpecificLocalTime;  
END_VAR
```

```
fbToLocal( in := in, tzInfo := WEST_EUROPE_TZI, out => out );
```

Further time and time zone functions and function blocks:

* [FB\_TzSpecificLocalTimeToSystemTime](ms-xhelp:///?Id=beckhoff-2d5a-443c-9aa9-97c8c02f3336)
* [FB\_TzSpecificLocalTimeToFileTime](ms-xhelp:///?Id=beckhoff-7cf2-4bdb-8eca-afac6ba61420)
* [FB\_FileTimeTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-ed55-4f54-90d2-a8293198c22f)
* [FB\_GetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-e94e-4efc-8b9a-294d8ea2dae1)
* [FB\_SetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-4f69-47a9-b40b-5f2f878dd0cd)
* [NT\_SetLocalTime](ms-xhelp:///?Id=beckhoff-69e6-480d-9a57-f100d0f6f752)
* [NT\_GetTime](ms-xhelp:///?Id=beckhoff-2f0c-4113-8d0b-40bd61b5771c)
* [NT\_SetTimeToRTCTime](ms-xhelp:///?Id=beckhoff-ac7b-4d32-84f6-6f06db4a4da6)
* [F\_TranslateFileTimeBias](ms-xhelp:///?Id=beckhoff-674d-4bec-8c10-02c5b94776c0)
* [FB\_LocalSystemTime](ms-xhelp:///?Id=beckhoff-40ca-431a-ad5c-7de4706ed264)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
