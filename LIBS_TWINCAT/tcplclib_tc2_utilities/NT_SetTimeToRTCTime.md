# NT_SetTimeToRTCTime

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# NT\_SetTimeToRTCTime

|  |  |
| --- | --- |
| 47625437 | This functionality is not available in the PLC runtime system under Windows CE! |

![25975757](/tcplclib_tc2_utilities/1033/Images/png/9007199290372875__Web.png)

The function block "Nt\_SetTimeToRtcTime" can be used to synchronize the local Windows system time (displayed in the taskbar) with the real-time clock of the PC (RTC time in the BIOS).

**Comments**

When the function block is called, the real-time clock of the TwinCAT PC is compared with the local Windows system time, and the local Windows system time is corrected by the difference. Time zones and summer time are taken into account. Please note that the correction can lead to time jumps during measurements or log book entries.

When the local Windows system time is set, the operating system automatically sets the RTC time to the new local Windows system time. Due to the conversion and delay the new RTC time is inevitably subject to a small error. The error is in the millisecond range. This means that the real-time clock is falsified a little each time NT\_SetTimeToRTCTime is called. In order to minimize deviations over a prolonged period, the compensation should be carried out every 24 hours, for example, rather than during each PLC cycle.

## VAR\_INPUT

```
VAR_INPUT  
    NETID  : T_AmsNetId;  
    SET    : BOOL;  
    TMOUT  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: This parameter can be used to specify the AmsNetID of the TwinCAT computer on which the local Windows system time is to be synchronized (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**SET**: the block is activated by a positive edge at this input.

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
* [NT\_SetLocalTime](ms-xhelp:///?Id=beckhoff-69e6-480d-9a57-f100d0f6f752)
* [NT\_GetTime](ms-xhelp:///?Id=beckhoff-2f0c-4113-8d0b-40bd61b5771c)
* [F\_TranslateFileTimeBias](ms-xhelp:///?Id=beckhoff-674d-4bec-8c10-02c5b94776c0)
* [FB\_LocalSystemTime](ms-xhelp:///?Id=beckhoff-40ca-431a-ad5c-7de4706ed264)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64) | Tc2\_Utilities (System) |
