# MPL_DamperLinearActuator

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MPL\_DamperLinearActuator

# MPL\_DamperLinearActuator

![66629291](/tcplclib_tc2_mpbus/1033/Images/gif/3423532299__Web.gif)

This function block is used to control and monitor a drive of a damper and of a globe valve.

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. If *bStart* remains TRUE, the device is addressed cyclically with a period specified by the time in *TMPolling*. The time should be set longer than 1 second. *bError* is used to indicate an error in communication with the drive. The type of the error can be read with *iErrorID*.

*SetPoint* is used to adjust the position of the damper from 0..100%. The current position of the drive can be read through *ActValue*.

## VAR\_INPUT

```
MP_Address    : USINT := 1;  
bStart        : BOOL;  
SetPoint      : USINT;  
strDataKL6771 : DataKL6771;  
TMpolling     : TIME := t#10s;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in TMPolling.

**SetPoint:** 0..100% the set damper position specified for the drive.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**TMpolling:** The time for which the function block should address the drive. Default 10 s, minimum time 1 s.

## VAR\_OUTPUT

```
bBusy    : BOOL;  
ActValue : WORD;  
iErrorID : MP_ERROR;  
bError   : BOOL;
```

**bBusy:** This bit is set for as long as the function block is active.

**ActValue:** Contains the current position of the drive (0..100%).

**iErrorID:** This output outputs an error code in the event of an error (see [MP\_ERROR](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
