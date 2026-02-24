# FB_CX5010SetWatchdog

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Function Blocks](ms-xhelp:///?Id=beckhoff-ec9d-42ff-9fdd-c53aca476e55)
3. FB\_CX5010SetWatchdog

# FB\_CX5010SetWatchdog

![4139237](/tcplclib_tc2_systemcx/1033/Images/png/9007199440673163__Web.png)

The function block FB\_CX5010SetWatchdog activates a hardware watchdog on the CX5010. The watchdog is activated via bEnable = TRUE and the tTimeOut time. The tTimeOut time can be a minimum of 2 seconds and a maximum of 255 seconds.

Once the watchdog has been activated, the function block instance must be called cyclically at shorter intervals than tTimeOut, since the CX5010 restarts automatically when tTimeOut has elapsed. The watchdog can therefore be used to automatically reboot systems, which have entered an infinite loop or where the PLC has become stuck.

The watchdog can be deactivated via bEnable = FALSE or tTimeOut = T#0s.

Note

The watchdog must be deactivated before breakpoints are used, before a PLC reset or an overall reset, before a TwinCAT stop, before switching to Config mode or before the configuration is activated, because otherwise the CX5010 would reboot immediately once tTimeOut has elapsed.

## VAR\_INPUT

```
VAR_INPUT  
    tTimeout : TIME;  
    bEnable  : BOOL;  
END_VAR
```

**tTimeOut**: Watchdog time, if expired a reboot is automatically executed.

**bEnable**: Activate or deactivate the watchdog.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bEnabled : BOOL;  
    bError   : BOOL;  
END_VAR
```

**bEnabled**: TRUE = Watchdog is activated, FALSE = Watchdog is not activated.

**bError**: Error when activate or deactivate the watchdog.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | CX (x86) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
