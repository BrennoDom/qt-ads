# FB_PcWatchdog

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [Watchdog function blocks](ms-xhelp:///?Id=beckhoff-7834-4c9a-ab02-067d39dfeb64)
4. FB\_PcWatchdog

# FB\_PcWatchdog

|  |  |
| --- | --- |
| 50584809 | This functionality is only available on IPCs with the following mainboards: IP-4GVI63, CB1050, CB2050, CB3050, CB1051, CB2051, CB3051. |

![52610097](/tcplclib_tc2_system/1033/Images/png/9007199285927563__Web.png)

The function block FB\_PcWatchdog activates a hardware watchdog on the PC. The watchdog is activated via bEnable = TRUE and the timeout time. The timeout time can range between 1 and 255 seconds. The watchdog is activated via bEnable = TRUE and tTimeOut >= 1 s.

Once the watchdog has been activated, the function block must be called cyclically at shorter intervals than tTimeOut, since the PC restarts automatically when tTimeOut has elapsed. The watchdog can therefore be used to automatically reboot systems, which have entered an infinite loop or where the PLC has become stuck.

The watchdog can be deactivated via bEnable = FALSE or tTimeOut = 0.

Note

PC reboot

The watchdog must be deactivated before breakpoints are used, before a PLC reset or an overall reset, before a TwinCAT stop, before switching to Config mode or before the configuration is activated, because otherwise the PC would reboot immediately once the timeout has elapsed.

## VAR\_INPUT

```
VAR_INPUT  
    tTimeOut : TIME;  
    bEnable  : BOOL;  
END_VAR
```

**tTimeOut**: Watchdog time, after which a restart is performed.

**bEnable**: Activating or deactivating the watchdog.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bEnabled : BOOL;  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrId   : UDINT;  
END_VAR
```

**bEnabled**: TRUE = watchdog activated, FALSE = watchdog deactivated

**bBusy**: This output remains TRUE until the function block has executed a command.

**bError**: This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in nErrId. Is reset to FALSE by the execution of a command at the inputs.

**nErrId**: [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or command-specific error code of the last executed command. Is reset to 0 by the execution of a command at the inputs.

**Example of calling the function block in ST:**

```
PROGRAM MAIN  
VAR  
    fbPcWatchDog  : FB_PcWatchdog;  
    tWDTime       : TIME := T#10s;  
    bEnableWD     : BOOL;  
    bWDActive     : BOOL;  
END_VAR  
  
IF bEnableWD OR bWDActive THEN  
    fbPcWatchDog(tTimeOut := tWDTime, bEnable := bEnableWD);  
    bWDActive := fbPcWatchDog.bEnabled;  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | IPCs with the following mainboards: IP‑4GVI63, CB1050, CB2050, CB3050, CB1051, CB2051, CB3051 | PLC Lib Tc2\_System |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
