# MP_Window

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_Window

# MP\_Window

![14859795](/tcplclib_tc2_mpbus/1033/Images/gif/181487883__en-US__Web.gif)

This function block is used to control and monitor a window ventilation system (FLS).

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. If *bStart* remains TRUE, the device is addressed cyclically with a period specified by the time in *TMPolling*. The time should be set longer than 1 second. *bError* is used to indicate an error in communication with the FLS. The type of the error can be read with iErrorID.

*ManualMode* can be used to enable or disable manual operation. The type of ventilation can be specified through WindowSettings.

## VAR\_INPUT

```
MP_Address     : USINT := 1;  
bStart         : BOOL;  
WindowSettings : Data_Window;  
ManuelMode     : BOOL;  
strDataKL6771  : DataKL6771;  
TMpolling      : TIME := t#10s;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in *TMPolling*.

**WindowSettings:** Nominal ventilation settings (see [DataWindow](ms-xhelp:///?Id=beckhoff-2e91-4784-b615-d0719dc09319)).

**ManuelMode:** FALSE = manual operation permitted, TRUE = manual operation disabled.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**TMpolling:** The time for which the function block should address the sensor. Default 10 s. Minimum time 1 s.

## VAR\_OUTPUT

```
bBusy             : BOOL;  
bError            : BOOL;  
iErrorId          : MP_Error;  
WindowState       : Data_Window;  
Window_Mech_Error : BOOL;  
Memory_Error      : BOOL;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_Error](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**WindowState:** Target settings for ventilation (see [Data\_Window](ms-xhelp:///?Id=beckhoff-2e91-4784-b615-d0719dc09319)).

**Window\_Mech\_Error:** The window or drive is blocked.

**Memory\_Error:** The drive has a memory error. Reprogram or replace.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
