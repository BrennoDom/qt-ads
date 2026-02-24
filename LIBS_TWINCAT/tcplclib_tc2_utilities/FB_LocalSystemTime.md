# FB_LocalSystemTime

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_LocalSystemTime

![52618583](/tcplclib_tc2_utilities/1033/Images/png/9007199290273675__Web.png)

In some applications the local Windows system time is synchronized via the SNTP time server or a radio clock. In many cases the local Windows system time has to be used in the PLC (e.g. in the form of timestamp log messages to the HMI). The local Windows system time is displayed in the taskbar. For such applications the FB\_LocalSystemTime function block can be useful.

This function block internally combines the functions of the following function blocks: [RTC\_EX2](ms-xhelp:///?Id=beckhoff-9781-443d-9629-00a35143e9cd), [NT\_GetTime](ms-xhelp:///?Id=beckhoff-2f0c-4113-8d0b-40bd61b5771c), [FB\_GetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-e94e-4efc-8b9a-294d8ea2dae1) and [NT\_SetTimeToRTCTime](ms-xhelp:///?Id=beckhoff-ac7b-4d32-84f6-6f06db4a4da6). The RTC\_EX2 function block can be used for generating time stamps for log outputs, for example. However, this block has the disadvantage that its time is not synchronized with the local Windows system time and has to be resynchronized cyclically via the NT\_GetTime function block (see RTC block examples in the documentation). Cyclic synchronization of the internal time (*systemTime* output) is already implemented in the function block. The cycle time can be configured via the *dwCycle* input. The function block also provides time zone information (summer time/winter time).

The FB\_LocalSystemTime function block must be called cyclically (e.g. every second or during each PLC cycle). This is necessary to enable the time between synchronizations to be calculated.

|  |  |
| --- | --- |
| 3805200 | Jitter!  The local Windows system time is read with the aid of acyclic services (ADS function blocks). Due to the system characteristics the runtime of the ADS commands cannot be specified/estimated. Differences in command runtimes may lead to time jitter at the systemTime output, depending on the operating system, the synchronization interval and the PLC cycle time. For this reason, the time provided by the function block is only conditionally suitable for more precise measuring tasks. However, the accuracy is adequate, for example, for building automation applications. |

## Switching between daylight-saving time and standard time

The function block cannot be called exactly at the time when the switchover from daylight-saving time to standard time and vice versa takes place. In order to avoid complex calculations, the following implementation was chosen (explained in the example).

In our example the function block synchronises its own time with the local Windows system time (grey) every 60 seconds.  
 The PLC application needs and reads the time in the function block (e.g. every 30 seconds, blue). In our example the switchover between daylight-saving time and standard time is detected with a delay of 15 seconds. This behaviour should be unproblematic for most applications.

## Switching from standard time to daylight-saving time

* ...
* 30-03-2008-01:58:10, tzID = standard time
* 30-03-2008-01:58:15, after internal synchronisation
* 30-03-2008-01:58:40, tzID = standard time
* 30-03-2008-01:59:10, tzID = standard time
* 30-03-2008-01:59:15, after internal synchronisation
* 30-03-2008-01:59:40, tzID = standard time
* 30-03-2008-02:00:00, the operating system changes the time from 2 am to 3 am
* 30-03-2008-02:00:10, tzID = standard time (still!)
* 30-03-2008-03:00:15, after internal synchronisation, subsequent tzID = daylight-saving time
* 30-03-2008-03:00:40, tzID = daylight-saving time
* 30-03-2008-03:01:10, tzID = daylight-saving time
* 30-03-2008-03:01:15, after internal synchronisation
* 30-03-2008-03:01:40, tzID = daylight-saving time
* ...

## Switching from daylight-saving time to standard time

* ...
* 26-10-2008-02:58:10, tzID = daylight-saving time
* 26-10-2008-02:58:15, after internal synchronisation
* 26-10-2008-02:58:40, tzID = daylight-saving time
* 26-10-2008-02:59:10, tzID = daylight-saving time
* 26-10-2008-02:59:15, after internal synchronisation
* 26-10-2008-02:59:40, tzID = daylight-saving time
* 26-10-2008-03:00:00, the operating system changes the time from 3 am to 2 am
* 26-10-2008-03:00:10, tzID = daylight-saving time (still!)
* 26-10-2008-02:00:15, after internal synchronisation, subsequent tzID = standard time
* 26-10-2008-02:00:40, tzID = standard time
* 26-10-2008-02:01:10, tzID = standard time
* 26-10-2008-02:01:15, after internal synchronisation
* 26-10-2008-02:01:40, tzID = standard time
* ...

## VAR\_INPUT

```
VAR_INPUT  
    sNetID    : T_AmsNetID := '';  
    bEnable   : BOOL;  
    dwCycle   : DWORD(1..86400) := 5;  
    dwOpt     : DWORD := 1;  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetID**: A string containing the network address of the TwinCAT computer whose time is to be used for the synchronization can be given here (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**bEnable:** A rising edge at this input triggers immediate synchronization of the internal time with the local Windows system time. The output *bValid* remains set to FALSE until the synchronization is complete. The first rising edge activates the cyclic synchronization. The subsequent cyclic synchronizations are then executed automatically. In most cases the application only has to set this input to TRUE once.

**dwCycle**: Cycle time (in seconds) during which the function block resynchronizes its own time. Cyclic synchronization is activated after the first rising edge at the *bEnable* input. Default: Synchronization every 5 seconds.

**dwOpt**: Additional option parameters. The following parameters are currently available:

* Bit 0: If this is set, the Windows system time is additionally synchronized cyclically with the hardware clock (RTC) (corresponds to the function NT\_SetTimeToRTCTime). Default: Activated.  
   This option is irrelevant for a Windows CE system.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the internal ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bValid     : BOOL;  
    systemTime : TIMESTRUCT;  
    tzID       : E_TimeZoneID := eTimeZoneID_Invalid;  
END_VAR
```

**bValid**: The time at the *systemTime* output is invalid if this output is FALSE. The time is valid if TRUE (i.e. it was synchronized with the local Windows time at least once).

**systemTime**: Local Windows system time (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)).

**tzID:** Time zone information (summer time, winter time) (type: [E\_TimeZoneID](ms-xhelp:///?Id=beckhoff-0c9b-48fa-97bf-e3de81dbfdb1)).

**Example:**

In the example the FB\_LocalSystemTime function block is activated on program startup (rising edge at *bEnable* input). Once the time has been synchronized (*bValid* = TRUE), the PLC writes a message to the TwinCAT System Logview every 500 ms. The internal synchronization is carried out every second.

```
PROGRAM MAIN  
VAR  
    fbTime   : FB_LocalSystemTime := ( bEnable := TRUE, dwCycle := 1 );  
    logTimer : TON := ( IN := TRUE, PT := T#500ms );  
END_VAR
```

```
fbTime();  
  
logTimer( IN := fbTime.bValid );  
IF logTimer.Q THEN  
    logTimer( IN := FALSE ); logTimer( IN := fbTime.bValid );  
    ADSLOGSTR( ADSLOG_MSGTYPE_HINT OR ADSLOG_MSGTYPE_LOG, 'Local System Time:%s', SYSTEMTIME_TO_STRING(fbTime.systemTime));  
END_IF
```

The written messages can be viewed in the TwinCAT Logview.

![34246806](/tcplclib_tc2_utilities/1033/Images/gif/35535883__Web.gif)

Further functions and function blocks for time and time zone:

* [FB\_TzSpecificLocalTimeToSystemTime](ms-xhelp:///?Id=beckhoff-2d5a-443c-9aa9-97c8c02f3336)
* [FB\_TzSpecificLocalTimeToFileTime](ms-xhelp:///?Id=beckhoff-7cf2-4bdb-8eca-afac6ba61420)
* [FB\_SystemTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-20ad-46e0-9bae-a6b428b840f1)
* [FB\_FileTimeToTzSpecificLocalTime](ms-xhelp:///?Id=beckhoff-ed55-4f54-90d2-a8293198c22f)
* [FB\_GetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-e94e-4efc-8b9a-294d8ea2dae1)
* [FB\_SetTimeZoneInformation](ms-xhelp:///?Id=beckhoff-4f69-47a9-b40b-5f2f878dd0cd)
* [NT\_SetLocalTime](ms-xhelp:///?Id=beckhoff-69e6-480d-9a57-f100d0f6f752)
* [NT\_GetTime](ms-xhelp:///?Id=beckhoff-2f0c-4113-8d0b-40bd61b5771c)
* [NT\_SetTimeToRTCTime](ms-xhelp:///?Id=beckhoff-ac7b-4d32-84f6-6f06db4a4da6)
* [F\_TranslateFileTimeBias](ms-xhelp:///?Id=beckhoff-674d-4bec-8c10-02c5b94776c0)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7, TC/BSD: TC RT x64, TC OS ARMT2) | Tc2\_Utilities (System) |
