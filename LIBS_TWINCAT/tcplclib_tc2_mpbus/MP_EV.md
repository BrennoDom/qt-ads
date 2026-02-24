# MP_EV

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_EV

# MP\_EV

![33645886](/tcplclib_tc2_mpbus/1033/Images/gif/3420588555__Web.gif)

This function block is used to control a control ball valve of series P6..W..EV-BAC. For more information please visit [www.belimo.ch](http://www.belimo.ch).

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. If *bStart* remains TRUE, the device is addressed cyclically with a period specified by the time in *TMPolling*. The time should be set longer than 1 second. *bError* is used to indicate an error in communication with the drive. The type of the error can be read with *iErrorID*.

## VAR\_INPUT

```
MP_Address       : USINT := 1;  
bStart           : BOOL;  
strDataKL6771    : DataKL6771;  
TMpolling        : TIME := t#10s;  
nOverrideControl : E_MPBus_Override := MPBus_Override_Auto;  
nRelSetpoint     : INT;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in *TMPolling*.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**TMpolling:** The time for which the function block should address the drive. Default 10 s, minimum time 1 s.

**nOverrideControl:** In Override mode the relative set value *nRelSetpoint* is ignored (see [E\_MPBus\_Override](ms-xhelp:///?Id=beckhoff-c238-4dfc-baf7-fd72b45c0d09)). Overriding is disabled if the command is not repeated within 120 minutes.

**nRelSetpoint:** The set value is interpreted either as position set value or as advance set value.

## VAR\_OUTPUT

```
bBusy                         : BOOL;  
bError                        : BOOL;  
iErrorId                      : MP_ERROR;  
nAbsPos                       : INT;  
rT1_SI                        : REAL;  
rT2_SI                        : REAL;  
rDELTA_T                      : REAL;  
rP_SI                         : REAL;  
nE_COOLING_SI                 : DINT;  
nE_HEATING_SI                 : DINT;  
nRelFlow                      : INT;  
rAbsFlow_SI                   : REAL;  
nRelPos                       : INT;  
nRelSetPointRead              : INT;  
bErrorStateT1                 : BOOL;  
bErrorStateT2                 : BOOL;  
bErrorStateFlowSensorErr      : BOOL;  
bErrorStateMechanicalOverload : BOOL;  
st_StateEV                    : St_StateEV;  
bPositionSetByHand            : BOOL;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_ERROR](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**nAbsPos:** Absolute Position in °.

**rT1\_SI:** Temperature 1 (remote) in °C.

**rT2\_SI:** Temperature 2 (embedded) in °C.

**rDELTA\_T:** Delta temperature in °C.

**rP\_SI:** Energy in kWh.

**nE\_COOLING\_SI:** Cooling energy in kWh.

**nE\_HEATING\_SI:** Heating energy in kWh.

**nRelFlow:** Relative flow rate in %.

**rAbsFlow\_SI:** Absolute flow rate in l/min.

**nRelPos:** Relative Position in %.

**nRelSetPointRead:** The set value is interpreted either as position set value or as advance set value (relative to Vmax) in %.

**bErrorStateT1:** Error temperature sensor T1.

**bErrorStateT2:** Error temperature sensor T2.

**bErrorStateFlowSensorErr:** Flow sensor is faulty.

**bErrorStateMechanicalOverload:** Mechanical overload detected.

**st\_StateEV:** Only devices from 27 March 2014 (see [St\_StateEV](ms-xhelp:///?Id=beckhoff-f06e-49a6-b99c-78b233a76542)).

**bPositionSetByHand:** The drive position was changed manually.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
