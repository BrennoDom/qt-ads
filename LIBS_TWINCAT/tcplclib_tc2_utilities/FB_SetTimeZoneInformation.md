# FB_SetTimeZoneInformation

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_SetTimeZoneInformation

![29760277](/tcplclib_tc2_utilities/1033/Images/png/9007199290321675__Web.png)

This function block can be used to modify or set the time zone settings of the operating system.

|  |  |
| --- | --- |
| 66515904 | Time settings  The operating system may change some time settings after the new time zone settings were set.  The time can be reset with the function block: [NT\_SetLocalTime](ms-xhelp:///?Id=beckhoff-69e6-480d-9a57-f100d0f6f752). |

## VAR\_INPUT

```
VAR_INPUT  
    sNetID    : T_AmsNetID;  
    tzInfo    : ST_TimeZoneInformation;  
    bExecute  : BOOL;  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetID**: Here you can enter a string with the network address of the TwinCAT computer whose time zone configuration is to be changed (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**tzInfo**: Structure with the new time zone settings that are to be set (type: [ST\_TimeZoneInformation](ms-xhelp:///?Id=beckhoff-fbaf-46ea-9f34-f9e4a2954fdc)).

**bExecute**: the block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the *bError* output is set.

**Sample:**

On the local TwinCAT system the time zone: "Western Europe Standard Time" is to be set. As an example a constant: **WEST\_EUROPE\_TZI** with suitable parameter values was already declared in the PLC library. To configure other time zones, the *tzInfo* input of the function block must be assigned corresponding values (see description of the [ST\_TimeZoneInformation](ms-xhelp:///?Id=beckhoff-fbaf-46ea-9f34-f9e4a2954fdc) structure).

```
VAR_GLOBAL CONSTANT  
...  
    (* West Europa Standard Time Zone settings *)  
    WEST_EUROPE_TZI : ST_TimeZoneInformation := (bias:=-60,  
                    standardName:='W. Europe Standard Time',  
                    standardDate:=(wYear:=0,wMonth:=10,wDayOfWeek:=0,wDay:=5,wHour:=3),  
                    standardBias:=0,  
                    daylightName:='W. Europe Daylight Time',  
                    daylightDate:=(wYear:=0,wMonth:=3,wDayOfWeek:=0,wDay:=5,wHour:=2),  
                    daylightBias:=-60);  
...  
END_VAR
```

The declaration section:

```
PROGRAM MAIN  
VAR  
    fbGet   : FB_GetTimeZoneInformation;  
    fbSet   : FB_SetTimeZoneInformation;  
    tzi_get : ST_TimeZoneInformation;  
    tzID    : E_TimeZoneID;  
    bGet    : BOOL := TRUE;  
    bSet    : BOOL := FALSE;  
END_VAR
```

A rising edge at the *bSet* variables results in setting of the required time zone setting. For verification the current settings can be read with a rising edge at the *bGet* variable.

```
IF bGet THEN  
    bGet := FALSE;  
    fbGet(bExecute := TRUE);  
ELSE  
    fbGet(bExecute := FALSE, tzInfo => tzi_get, tzID => tzID );  
END_IF  
  
IF bSet THEN  
    bSet := FALSE;  
    fbSet( bExecute := TRUE, tzInfo := WEST_EUROPE_TZI );  
ELSE  
    fbSet( bExecute := FALSE );  
END_IF
```

Further time and time zone functions and function blocks:

* [FB\_TzSpecificLocalTimeToSystemTime](ms-xhelp:///?Id=beckhoff-2d5a-443c-9aa9-97c8c02f3336)
* [FB\_TzSpecificLocalTimeToFileTime](ms-xhelp:///?Id=beckhoff-7cf2-4bdb-8eca-afac6ba61420)
* [FB\_SystemTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-20ad-46e0-9bae-a6b428b840f1)
* [FB\_FileTimeTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-ed55-4f54-90d2-a8293198c22f)
* [FB\_GetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-e94e-4efc-8b9a-294d8ea2dae1)
* [NT\_SetLocalTime](ms-xhelp:///?Id=beckhoff-69e6-480d-9a57-f100d0f6f752)
* [NT\_GetTime](ms-xhelp:///?Id=beckhoff-2f0c-4113-8d0b-40bd61b5771c)
* [NT\_SetTimeToRTCTime](ms-xhelp:///?Id=beckhoff-ac7b-4d32-84f6-6f06db4a4da6)
* [F\_TranslateFileTimeBias](ms-xhelp:///?Id=beckhoff-674d-4bec-8c10-02c5b94776c0)
* [FB\_LocalSystemTime](ms-xhelp:///?Id=beckhoff-40ca-431a-ad5c-7de4706ed264)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7) | Tc2\_Utilities (System) |
