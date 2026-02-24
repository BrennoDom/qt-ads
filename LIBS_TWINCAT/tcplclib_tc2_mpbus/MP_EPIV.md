# MP_EPIV

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_EPIV

# MP\_EPIV

![31437268](/tcplclib_tc2_mpbus/1033/Images/gif/3420598795__Web.gif)

This function block is used to control a pressure-independent control ball valve. For more information please visit [www.belimo.ch](http://www.belimo.ch).

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. If *bStart* remains TRUE, the device is addressed cyclically with a period specified by the time in *TMPolling*. The time should be set longer than 1 second. *bError* is used to indicate an error in communication with the drive. The type of the error can be read with *iErrorID*.

## VAR\_INPUT

```
MP_Address    : USINT := 1;  
bStart        : BOOL;  
bSet          : BOOL;  
bOpen         : BOOL;  
bClose        : BOOL;  
bReset        : BOOL;  
iSensorTyp    : INT;  
SetPoint      : USINT;  
MaxVol        : WORD;  
strDataKL6771 : DataKL6771;  
TMpolling     : TIME := t#10s;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in *TMPolling*.

**bSet:** A rising edge writes the *MaxVol* and *MinVol* data to the drive.

**bOpen:** A rising edge opens the dampers of the drive, while a falling edge cancels the forced ventilation.

**bClose:** A rising edge closes the dampers of the drive, while a falling edge cancels the forced closure.

**bReset:** A rising edge resets the drive's error messages.

**iSensorTyp:** 0: no sensor connected, 1: digital sensor connected, 2: analog sensor connected (0..35 V), 3..6: Output of a resistor in Ohm (3...5 applies to PT1000, NI1000 and NI1000LuS; 6 applies to NTC). To convert to a temperature, use the corresponding conversion functions.

**SetPoint:** Set volume flow (0..100 %).

**MaxVol:** Maximum volume flow (30..100 %).

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**TMpolling:** The time for which the function block should address the drive. Default 10 s, minimum time 1 s.

## VAR\_OUTPUT

```
bBusy                  : BOOL;  
bError                 : BOOL;  
iErrorId               : MP_ERROR;  
ActValue               : WORD;  
bMP_Sensor_Digi        : BOOL;  
iMP_Sensor_Analog      : INT;  
Volume_lmin            : WORD;  
iVnom_lmin             : INT;  
act_MaxVol             : INT;  
act_MinVol             : INT;  
bErr_ActHunt           : BOOL;  
bErr_MecTrv            : BOOL;  
bErr_MecOvld           : BOOL;  
bPositionSetByHand     : BOOL;  
bSynchronisationActive : BOOL;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_ERROR](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**ActValue:** Contains the current position of the drive (0..100%).

**bMP\_Sensor\_Digi:** If a digital sensor is connected, its state is indicated through this variable. *iSensorTyp* must be 1.

**iMP\_Sensor\_Analog:** If an analog sensor is connected, its value is indicated through this variable. *iSensorTyp* must be between 2 and 6.

**Volume\_lmin:** Output of volume flow in lmin.

**iVnom\_lmin:** Nominal air volume flow in lmin.

**act\_MaxVol:** Maximum set volume flow rate in %.

**act\_MinVol:** Minimum set volume flow in %.

**bErr\_ActHunt:** Drive error "regulating oscillation": drive oscillates.

**bErr\_MecTrv:** Drive error "Adjustment angle exceeded": drive rotation angle exceeded by more than 10° compared with adaptation.

**bErr\_MecOvld:** Drive error "Overload": set position could not be reached.

**bPositionSetByHand:** The drive position was changed manually.

**bSynchronisationActive:** The drive is synchronizing.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.32 | Tc2\_MPBus from 3.4.6.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
