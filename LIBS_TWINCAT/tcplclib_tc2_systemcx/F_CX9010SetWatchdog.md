# F_CX9010SetWatchdog

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Functions](ms-xhelp:///?Id=beckhoff-48c8-4ac6-bc46-6e026efec7f3)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-b9c9-4bdc-9c56-d28accda9e89)
4. F\_CX9010SetWatchdog

# F\_CX9010SetWatchdog

![2922015](/tcplclib_tc2_systemcx/1033/Images/png/9007199440692363__Web.png)

The function F\_CX9010SetWatchdog activates a hardware watchdog on the CX9000. The watchdog is activated via bEnable = TRUE and the tTimeOut time. The tTimeOut time can be a maximum of 65 seconds and 535 milliseconds.

Once the watchdog has been activated, the function must be called cyclically at shorter intervals than tTimeOut, since the CX9010 restarts automatically when tTimeOut has elapsed. The watchdog can therefore be used to automatically reboot systems, which have entered an infinite loop or where the PLC has become stuck.

The watchdog can be deactivated via bEnable = FALSE or tTimeOut = T#0s.

Note

The watchdog must be deactivated before breakpoints are used, before a PLC reset or an overall reset, before a TwinCAT stop, before switching to Config mode or before the configuration is activated, because otherwise the CX9010 would reboot immediately once tTimeOut has elapsed.

## FUNCTION F\_CX9010SetWatchdog: BOOL

```
VAR_INPUT  
    tTimeout : TIME;  
    bEnable  : BOOL;  
END_VAR
```

**tTimeOut**: Watchdog time, if expired a reboot is automatically executed.

**bEnable**: Activate or deactivate the watchdog.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | CX (ARM) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
