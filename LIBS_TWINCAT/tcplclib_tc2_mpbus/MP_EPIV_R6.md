# MP_EPIV_R6

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_EPIV\_R6

# MP\_EPIV\_R6

![14499957](/tcplclib_tc2_mpbus/1033/Images/gif/5206623243__Web.gif)

This function block is used to control a control ball valve of series EP..R-R6+BAC.

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. If *bStart* remains TRUE, the device is addressed cyclically with a period specified by the time in *TMPolling*. The time should be set longer than 1 second. *bError* is used to indicate an error in communication with the drive. The type of the error can be read with *iErrorID*.

## VAR\_INPUT

```
MP_Address             : USINT := 1;  
bStart                 : BOOL;  
strDataKL6771          : DataKL6771;  
TMpolling              : TIME := t#10s;  
nOverrideControl_Write : E_MPBus_Override_6wayMPIV := MPBus_6wayMPIV_None;  
rSetPoint_Write        : LREAL;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in *TMPolling*.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**TMpolling:** The time for which the function block should address the drive. Default 10 s, minimum time 1 s.

**nOverrideControl\_Write:** The relative set value is ignored in override control mode (see [E\_MPBus\_Override\_6wayMPIV](ms-xhelp:///?Id=beckhoff-363e-4a8a-b958-18444b878737)). Overriding is disabled if the command is not repeated within 120 minutes.

**rSetPoint\_Write:** 0…100%.

## VAR\_OUTPUT

```
bBusy                            : BOOL;  
bError                           : BOOL;  
iErrorId                         : MP_Error;  
nOverrideControl_Read            : E_MPBus_Override_6wayMPIV;  
rSetPoint_Read                   : LREAL;  
rRelativePos_Read                : LREAL;  
rAbsolutePos_Read                : LREAL;  
rRelativeFlow_Read               : LREAL;  
bErrorStateFlowSensorErr         : BOOL;  
bErrorStateActuator_can_not_move : BOOL;  
st_StateEV                       : st_StateEV;  
rAbsoluteFlow_UnitSel            : LREAL;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_Error](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**nOverrideControl\_Read:** Current override control mode (see [E\_MPBus\_Override\_6wayMPIV](ms-xhelp:///?Id=beckhoff-363e-4a8a-b958-18444b878737)).

**rSetPoint\_Read:** Set value in % (0...100%).

**rRelativePos\_Read:** Relative position in % (0...100%).

**rAbsolutePos\_Read:** Absolute position in °.

**rRelativeFlow\_Read:** Relative flow rate in % (0...100%).

**bErrorStateFlowSensorErr:** Flow sensor is faulty.

**bErrorStateActuator\_can\_not\_move:** Drive cannot move.

**st\_StateEV:** Only devices from 27 March 2014 (see [St\_StateEV](ms-xhelp:///?Id=beckhoff-f06e-49a6-b99c-78b233a76542)).

**rAbsoluteFlow\_UnitSel:** Absolute flow rate in UnitSel (0...4294967295).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.14 | Tc2\_MPBus from 3.4.8.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
