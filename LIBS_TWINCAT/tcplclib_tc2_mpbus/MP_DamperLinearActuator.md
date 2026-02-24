# MP_DamperLinearActuator

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_DamperLinearActuator

# MP\_DamperLinearActuator

![3493029](/tcplclib_tc2_mpbus/1033/Images/gif/181468683__en-US__Web.gif)

This function block is used to control and monitor a drive of a damper and of a globe valve.

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. If *bStart* remains TRUE, the device is addressed cyclically with a period specified by the time in *TMPolling*. The time should be set longer than 1 second. *bError* is used to indicate an error in communication with the drive. The type of the error can be read with *iErrorID*.

A rising edge at *bReset* clears any pending error messages from the drive. This resets errors that affect the output variables *bErr\_MecOcld*, *bErr\_ActHunt* and *bErrMecTrv*. If the error itself is still present, the drive will set these error bits again.

*SetPoint* is used to adjust the position of the damper from 0…100%. The current position of the drive can be read through *ActValue*.

If a sensor is connected to the drive, *iSensorTyp* should be used to specify the sensor type. If no sensor is connected, the value "0" should be entered, or the variable should be left blank. A digital sensor should be parameterized with "1". The state of the sensor can be interrogated through *bMP\_Sensor\_Digi*. Analog sensors "2...6" are output in variable *iMP\_Sensor\_Analog*.

## VAR\_INPUT

```
MP_Address    : USINT := 1;  
bStart        : BOOL;  
bReset        : BOOL;  
iSensorTyp    : INT;  
SetPoint      : USINT;  
strDataKL6771 : DataKL6771;  
TMpolling     : TIME := t#10s;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in *TMPolling*.

**bReset:** A rising edge resets the drive's error messages.

**iSensorTyp:** 0: no sensor connected, 1: digital sensor connected, 2: analog sensor connected (0..35 V), 3..6: Output of a resistor in Ohm (3...5 applies to PT1000, NI1000 and NI1000LuS; 6 applies to NTC). To convert to a temperature, use the corresponding conversion functions.

**SetPoint:** 0..100 % the set damper position specified for the drive.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**TMpolling:** The time for which the function block should address the drive. Default 10 s, minimum time 1 s.

## VAR\_OUTPUT

```
bBusy             : BOOL;  
ActValue          : WORD;  
bMP_Sensor_Digi   : BOOL;  
iMP_Sensor_Analog : INT;  
iErrorID          : MP_Error;  
bError            : BOOL;  
bErr_MecOvld      : BOOL;  
bErr_ActHunt      : BOOL;  
bErr_MecTrv       : BOOL;
```

**bBusy:** This bit is set for as long as the function block is active.

**ActValue:** Contains the current position of the drive (0..100%).

**bMP\_Sensor\_Digi:** If a digital sensor is connected, its state is indicated through this variable. iSensorTyp must be "1".

**iMP\_Sensor\_Analog:** If an analog sensor is connected, its value is indicated through this variable. iSensorTyp must be in the range "2..6".

**iErrorID:** This output outputs an error code in the event of an error (see [MP\_Error](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). bError goes TRUE at the same time.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**bErr\_MecOvld:** Drive error, "Overload"; the set position could not be reached.

**bErr\_ActHunt:** Drive error, "Regulating oscillation"; the drive is swinging backwards and forwards.

**bErr\_MecTrv:** Drive error, "Positioning angle exceeded"; the drive has passed more than 10° beyond the adaptation position.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
