# FB_TzSpecificLocalTimeToSystemTime

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_TzSpecificLocalTimeToSystemTime

![20328083](/tcplclib_tc2_utilities/1033/Images/png/9007199290340875__Web.png)

The function block converts the local time (structured system time format) to UTC time (structured system time format), taking into account the specified time zone information. The function block [FB\_TzSpecificLocalTimeToFileTime](ms-xhelp:///?Id=beckhoff-7cf2-4bdb-8eca-afac6ba61420) has similar functionality but uses a different time format (file time format).

The block is only suitable for conversion of **continuous** local timestamp information. Step changes in local time caused by summer/winter time changeover are permitted and are correctly detected by the block. Arbitrary changes in local time result in incorrect conversion. The reason: the last converted time is stored internally in block in order to be able to identify the summer time/winter time information and the B times (see below) when the local time is reset. The block is associated with an action: A\_Reset(). If this action is called the block outputs and the locally stored (last converted) time are reset to zero.

The step changes in the local time are problematic, since they have to be converted to a linear UTC time. It is therefore advisable to use the (continuous) UTC time for time stamping tasks and to convert the time to respective local time only for display purposes (e.g. in a visualization).

Further information can be found in the documentation for the [FB\_TzSpecificLocalTimeToFileTime](ms-xhelp:///?Id=beckhoff-7cf2-4bdb-8eca-afac6ba61420) function block.

## VAR\_INPUT

```
VAR_INPUT  
    in     : TIMESTRUCT;  
    tzInfo : ST_TimeZoneInformation;  
END_VAR
```

**in**: Local time (structured system time format) to be converted (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)).

**tzInfo**: Structure variable with the current time zone information of the operating system (type: [ST\_TimeZoneInformation](ms-xhelp:///?Id=beckhoff-fbaf-46ea-9f34-f9e4a2954fdc)).

## VAR\_OUTPUT

```
VAR_OUTPUT  
    out    : TIMESTRUCT;  
    eTzID  : E_TimeZoneID := eTimeZoneID_Unknown;  
    bB     : BOOL;  
END_VAR
```

**out**: Converted UTC time (structured system time format) (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)).

**eTzID**: Additional summer/winter time information (type: [E\_TimeZoneID](ms-xhelp:///?Id=beckhoff-0c9b-48fa-97bf-e3de81dbfdb1)).

**bB**: TRUE => B time (e.g.:**02:05:00 CET B**), FALSE => other time (e.g.: **02:05:00 CEST A**). This output is set if the local time jumps back and is reset once the duplicate local time has passed.

**Example**:

```
PROGRAM MAIN  
VAR  
    in      : TIMESTRUCT := ( wYear := 2011, wMonth := 4, wDay := 29, wHour := 16, wMinute := 46, wSecond := 31, wMilliseconds := 99 );(* Local time *)  
    out     : TIMESTRUCT;(* UTC time result is:= ( wYear := 2011, wMonth := 4, wDay := 29, wHour := 14, wMinute := 46, wSecond := 31, wMilliseconds := 99 ) *)  
    fbToUTC : FB_TzSpecificLocalTimeToSystemTime;  
END_VAR
```

```
fbToUTC( in := in, tzInfo := WEST_EUROPE_TZI, out => out );
```

Further functions and function blocks for time and time zone:

* [FB\_TzSpecificLocalTimeToFileTime](ms-xhelp:///?Id=beckhoff-7cf2-4bdb-8eca-afac6ba61420)
* [FB\_SystemTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-20ad-46e0-9bae-a6b428b840f1)
* [FB\_FileTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-ed55-4f54-90d2-a8293198c22f)
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
