# NT_GetTime

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# NT\_GetTime

![64964848](/tcplclib_tc2_utilities/1033/Images/png/9007199290363275__Web.png)

The function block "NT\_GetTime" can be used to determine the local Windows system time of a TwinCAT system (the local Windows system time is displayed in the taskbar). The year, month, day, day of the week, hour, minute, second and millisecond are stored in variables of the structure [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1).

## VAR\_INPUT

```
VAR_INPUT  
    NETID  : T_AmsNetId;  
    START  : BOOL;  
    TMOUT  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: This parameter can be used to specify the AmsNetID of the TwinCAT computer whose local Windows system time is to be determined (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY    : BOOL;  
    ERR     : BOOL;  
    ERRID   : UDINT;  
    TIMESTR : TIMESTRUCT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the ERR output is set.

**TIMESTR**: Structure with the local Windows system time (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)).

**Example**:

See: [Sample: Software clocks (RTC, RTC\_EX, RTC\_EX2)](ms-xhelp:///?Id=beckhoff-17d7-43b3-b210-58197fb4d298).

Further time and time zone functions and function blocks:

* [FB\_TzSpecificLocalTimeToSystemTime](ms-xhelp:///?Id=beckhoff-2d5a-443c-9aa9-97c8c02f3336)
* [FB\_TzSpecificLocalTimeToFileTime](ms-xhelp:///?Id=beckhoff-7cf2-4bdb-8eca-afac6ba61420)
* [FB\_SystemTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-20ad-46e0-9bae-a6b428b840f1)
* [FB\_FileTimeTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-ed55-4f54-90d2-a8293198c22f)
* [FB\_GetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-e94e-4efc-8b9a-294d8ea2dae1)
* [FB\_SetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-4f69-47a9-b40b-5f2f878dd0cd)
* [NT\_SetLocalTime](ms-xhelp:///?Id=beckhoff-69e6-480d-9a57-f100d0f6f752)
* [NT\_SetTimeToRTCTime](ms-xhelp:///?Id=beckhoff-ac7b-4d32-84f6-6f06db4a4da6)
* [F\_TranslateFileTimeBias](ms-xhelp:///?Id=beckhoff-674d-4bec-8c10-02c5b94776c0)
* [FB\_LocalSystemTime](ms-xhelp:///?Id=beckhoff-40ca-431a-ad5c-7de4706ed264)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7, TC/BSD: TC RT x64, TC OS ARMT2) | Tc2\_Utilities (System) |
