# MP_EV_Parameter

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_EV\_Parameter

# MP\_EV\_Parameter

![34377519](/tcplclib_tc2_mpbus/1033/Images/gif/3420594059__Web.gif)

This function block is used to parameterize drives.

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. *bError* is used to indicate an error in communication with the drive. The type of the error can be read with *iErrorID*.

## VAR\_INPUT

```
MP_Address        : USINT := 1;  
bStart            : BOOL;  
strDataKL6771     : DataKL6771;  
dwPassword        : DWORD;  
nControlMode      : E_MPBus_ControlMode := MPBus_ControlMode_Disable;  
nDetaTLimitation  : E_MPBus_DeltaTLimitation := MPBus_DeltaTLimitation_Disable;  
rSetPoint         : REAL := 0.0;  
rSpFlow_DeltaT_Si : REAL := 0.0;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in *TMPolling*.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**dwPassword:** The drive password is usually 0x0000.

**nControlMode:** Specifies the control mode (see [E\_MPBus\_ControlMode](ms-xhelp:///?Id=beckhoff-fef3-4ce9-a937-922df8e4f9e4)).

**nDetaTLimitation:** dT limitation (see [E\_MPBus\_DeltaTLimitation](ms-xhelp:///?Id=beckhoff-8f40-49d1-90ae-e31750897e60)).

**rSetPoint:** dT limit value.

**rSpFlow\_DeltaT\_Si:** Flow rate at saturation.

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
iErrorId : MP_ERROR;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_ERROR](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.32 | Tc2\_MPBus from 3.4.6.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
