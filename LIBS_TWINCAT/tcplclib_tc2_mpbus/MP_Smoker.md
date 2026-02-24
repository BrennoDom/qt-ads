# MP_Smoker

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_Smoker

# MP\_Smoker

![49201274](/tcplclib_tc2_mpbus/1033/Images/gif/181475083__en-US__Web.gif)

This function block is used to control and monitor a fire damper.

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. If *bStart* remains TRUE, the device is addressed cyclically with a period specified by the time in *TMPolling*. The time should be set longer than 1 s, maximum 30 s. *bError* is used to indicate an error in communication with the drive. The type of the error can be read with *iErrorID*.

A rising edge at *bReset* clears any pending error messages from the drive. A telegram is thus sent to the drive that acknowledges the errors in the drive.

If they persist, they remain set. This applies to all bErr\_\* error bits.

*bOpen\_Close* is used to open or close the fire damper. TRUE causes the fire damper to open, while FALSE closes it. *bOpen* indicates that the damper is open, *bClosed* indicates that it is closed. If both bits are FALSE, the drive is currently opening or closing.

A rising edge at *bTest* initiates a test run on the fire damper. Errors that have been set can be cleared with this if they are no longer present.

## VAR\_INPUT

```
MP_Address    : USINT := 1;  
bStart        : BOOL := TRUE;  
bTest         : BOOL;  
bOpen_Close   : BOOL;  
bReset        : BOOL;  
strDataKL6771 : DataKL6771;  
TMpolling     : TIME := t#10s;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in *TMPolling*.

**bTest:** A rising edge starts the test run at a fire damper.

**bOpen\_Close:** TRUE opens a damper, while FALSE closes a damper.

**bReset:** A rising edge resets the drive's error messages.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**TMpolling:** The time for which the function block should address the drive. Default 10 s. Minimum time 1 s.

## VAR\_OUTPUT

```
bBusy        : BOOL;  
bError       : BOOL;  
iErrorId     : MP_Error;  
bOpen        : BOOL;  
bClosed      : BOOL;  
bErr_MecTrv  : BOOL;  
bErr_MecOvld : BOOL;  
bErr_EmFlt   : BOOL;  
bErr_DmpTrv  : BOOL;  
bErr_DctAlm  : BOOL;  
bErr_SmAlm   : BOOL;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_Error](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**bOpen:** Fire damper is open.

**bClosed:** Fire damper is closed.

**bErr\_MecTrv:** Drive error, "Positioning angle exceeded"; the drive has passed more than 10° beyond the adaptation position.

**bErr\_MecOvld:** Drive error, "Overload"; the set position could not be reached.

**bErr\_EmFlt:** Drive error, "Safety-relevant error"; ambient temperature above 72°C or motor temperature above 85°C. Error can only be reset at the factory.

**bErr\_DmpTrv:** Drive error "Damper test error" is canceled if the test run is OK.

**bErr\_DctAlm:** Drive error, "Channel temperature too high"; the drive is swinging backwards and forwards.

**bErr\_SmAlm:** Drive error, "Smoke alarm"

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
