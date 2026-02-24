# FB_PcWatchDog_BAPI

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [Watchdog function blocks](ms-xhelp:///?Id=beckhoff-7834-4c9a-ab02-067d39dfeb64)
4. FB\_PcWatchDog\_BAPI

# FB\_PcWatchDog\_BAPI

|  |  |
| --- | --- |
| 3728830 | This functionality is only available on IPCs with the mainboards CBxx63 and Embedded PCs CX51x0, CX20x0, CX20x2 with a BIOS version from 0.44 or higher. |

![33559471](/tcplclib_tc2_system/1033/Images/png/9007201497609867__Web.png)

The function block FB\_PcWatchdog\_BAPI activates a hardware watchdog on the PC. The watchdog is activated via bExecute = TRUE and the watchdog time. The watchdog time can range between 1 and 15300 seconds (255 minutes). The watchdog is activated via bEnable = TRUE and nWatchdogTimeS >=1 s.

Once the watchdog has been activated, the function block must be called cyclically at shorter intervals than nWatchdogTimeS, since the PC restarts automatically when nWatchdogTimeS has elapsed. The watchdog can therefore be used to automatically reboot systems, which have entered an infinite loop or where the PLC has become stuck.

Note

PC reboot

The watchdog must be deactivated before breakpoints are used, before a PLC reset or an overall reset, before a TwinCAT stop, before switching to Config mode or before the configuration is activated, because otherwise the PC would reboot immediately once nWatchdogTimeS has elapsed.

## VAR\_INPUT

```
VAR_INPUT  
    sNetID         : T_AmsNetID;  
    nWatchdogTimeS : UDINT;  
    bExecute       : BOOL;  
    tTimeout       : TIME;  
END_VAR
```

**sNetID**: AMS network ID of the device (empty string or local network ID)

**nWatchdogTimeS**: Watchdog time in seconds, 0 = deactivated, >0 (max. 15300) = activated.

**bExecute**: The command is executed with a rising edge.

**tTimeout**: Indicates the time until the internal ADS communication is terminated.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bEnabled : BOOL;  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrorId : UDINT;  
END_VAR
```

**bEnabled**: TRUE = watchdog activated, FALSE = watchdog deactivated

**bBusy**: This output remains TRUE until the function block has executed a command.

**bError**: This output is switched to TRUE as soon as an error occurs during the execution of a command. It is reset to FALSE when a command is executed at the inputs.

**nErrorId**: [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or command-specific error code of the last executed command. Is reset to 0 by the execution of a command at the inputs.

## Sample of calling the function block in ST:

```
PROGRAM MAIN  
VAR  
    fbWatchdog     : FB_PcWatchdog_BAPI;  
    nWatchdogTimeS : UDINT := 10;  (* 10s *)  
    bEnabled       : BOOL; (* TRUE: watchdog is activated *)  
    bError         : BOOL;  
    nErrID         : UDINT;  
    fbTimer        : TON := (IN := TRUE, PT := T#0S);  
END_VAR
```

```
fbTimer();  
  
(* 1st enable, then refresh watchdog every 1s *)  
IF fbTimer.Q THEN  
    fbWatchdog(  
        sNetID         := '',   
        nWatchdogTimeS := nWatchdogTimeS,   
        bExecute       := TRUE,   
        tTimeout       := T#5S,   
    );  
      
    IF NOT fbWatchdog.bBusy THEN  
        bEnabled   := fbWatchdog.bEnabled;  
        bError     := fbWatchdog.bError;  
        nErrID     := fbWatchdog.nErrID;  
          
        fbWatchdog(bExecute := FALSE);  
      
        (* restart timer*)  
        fbTimer(IN := FALSE);  
        fbTimer(IN := TRUE, PT := T#1S); (* refresh watchdog every s *)  
    END_IF  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | IPCs with the mainboards CBxx63 and Embedded PCs CX51x0, CX20x0, CX20x2 with a BIOS version from 0.44 or higher | PLC Lib Tc2\_System-Version >=3.4.14.0 |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
