# FB_CheckWatchdog

## Library
tcplclib_tc2_dataexchange

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
2. [Watchdog function blocks](ms-xhelp:///?Id=beckhoff-d87a-4b66-83d2-864965970a05)
3. FB\_CheckWatchdog

# FB\_CheckWatchdog

![4739572](/tcplclib_tc2_dataexchange/1033/Images/gif/9007199309570443__en-US__Web.gif)

Monitoring of a watchdog signal, which is transferred with the function block [FB\_WriteWatchdog](ms-xhelp:///?Id=beckhoff-a27e-412b-bbdb-d7f148c29676).

The device to be monitored regularly sends a variable counter value to the device that is to monitor the transmission. The function block FB\_CheckWatchdog is used there to monitor the state of the counter. If this does not change within a specific period, the *bWatchdog* output is set to TRUE. If a value of 0 s is specified for *tWatchdogTime*, the *bWatchdog* signal is set to FALSE. The period specified by *tWachtdogTime* should be a multiple (5-10 times) of the time in which the monitoring signal is transmitted.

## VAR\_INPUT

```
VAR_INPUT  
    bEnable        :  BOOL := FALSE;  
    tWatchdogTime  :  TIME := t#0s;  
    nCnt           :  UDINT;  
END_VAR
```

**bEnable:** Enable function block.

**tWatchdogTime:** Duration during which *nCnt* has to change.

**nCnt:** Current counter value of the watchdog signal.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bWatchdog  : BOOL := FALSE;  
    nLastCnt   : UDINT;  
END_VAR
```

**bWatchdog:** FALSE indicates a valid monitoring signal. The output will become TRUE if no change is detected in *nCnt* during the period of time specified by *tWatchdogTime*.

**nLastCnt:** Most recent successfully transmitted counter state of the monitoring signal.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.0.0 | Tc2\_DataExchange |

[TwinCAT 3 | PLC Library: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
