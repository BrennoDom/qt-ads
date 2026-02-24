# NT_SetLocalTime

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# NT\_SetLocalTime

![27661336](/tcplclib_tc2_utilities/1033/Images/png/9007199290369675__Web.png)

The function block "NT\_SetLocalTime" can be used to set the local Windows system time of a TwinCAT system (the local Windows system time is displayed in the taskbar).

## VAR\_INPUT

```
VAR_INPUT  
    NETID   : T_AmsNetId;  
    START   : BOOL;  
    TIMESTR : TIMESTRUCT;  
    TMOUT   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: This parameter can be used to specify the AmsNetID of the TwinCAT computer whose local Windows system time is to be set (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**START**: the block is activated by a positive edge at this input.

**TIMESTR**: Structure with the new local Windows system time (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)).

**TMOUT**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY  : BOOL;  
    ERR   : BOOL;  
    ERRID : UDINT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the ERR output is set.

Further functions and function blocks for time and time zone:

* [FB\_TzSpecificLocalTimeToSystemTime](ms-xhelp:///?Id=beckhoff-2d5a-443c-9aa9-97c8c02f3336)
* [FB\_TzSpecificLocalTimeToFileTime](ms-xhelp:///?Id=beckhoff-7cf2-4bdb-8eca-afac6ba61420)
* [FB\_SystemTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-20ad-46e0-9bae-a6b428b840f1)
* [FB\_FileTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-ed55-4f54-90d2-a8293198c22f)
* [FB\_GetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-e94e-4efc-8b9a-294d8ea2dae1)
* [FB\_SetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-4f69-47a9-b40b-5f2f878dd0cd)
* [NT\_GetTime](ms-xhelp:///?Id=beckhoff-2f0c-4113-8d0b-40bd61b5771c)
* [NT\_SetTimeToRTCTime](ms-xhelp:///?Id=beckhoff-ac7b-4d32-84f6-6f06db4a4da6)
* [F\_TranslateFileTimeBias](ms-xhelp:///?Id=beckhoff-674d-4bec-8c10-02c5b94776c0)
* [FB\_LocalSystemTime](ms-xhelp:///?Id=beckhoff-40ca-431a-ad5c-7de4706ed264)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7) | Tc2\_Utilities (System) |
