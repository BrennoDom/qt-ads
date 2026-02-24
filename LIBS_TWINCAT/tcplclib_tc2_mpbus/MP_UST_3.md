# MP_UST_3

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_UST\_3

# MP\_UST\_3

![40158284](/tcplclib_tc2_mpbus/1033/Images/gif/181481483__en-US__Web.gif)

This function block is used to control and monitor a multi-IO module UST3.

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. If *bStart* remains TRUE, the device is addressed cyclically with a period specified by the time in *TMPolling*. The time should be set to greater than one second. *bError* indicates an error in the communication with the drive. The type of the error can be read with *iErrorID*.

![25880244](/tcplclib_tc2_mpbus/1033/Images/gif/511318795__Web.gif)

The input data bRelay\_R1 to bRelay\_R3 switch the relays R1 to R3 (PIN 15 to PIN 17). The variable iUa switches the analog output 0...10 V to PIN 5. One digit corresponds to 1 mV.

The data structure SETTINGS is used for parameterization of the UST3. The scaling of the analog input data can be set, and the resistance measurement can be enabled on PIN4. The scaling of the measured resistance value can be changed for the resistance measurement. This can be done during operation. iU1 is the analog input on PIN 3. One digit corresponds to 1 mV, or 250 µV if the scaling in the data structure SETTINGS was changed. The same applies to the analog inputs iU2\_YSensor (PIN 4) and iU3 (PIN 7).iU2\_YSensor can also be used for resistance measurement. This must be set via the data structure SETTINGS. bDigital\_S1 to bDigital\_S3 correspond to the digital inputs of UST3, PIN 7 to PIN 9.

All data is automatically polled by the KL6771. The polling speed depends on the number of connected MP-Bus devices and the set polling time. The digital inputs are unsuitable for connecting buttons or sensors, which only issue short pulses. In order to be able to register a change in signal level reliably, it must be present for at least one second.

## VAR\_INPUT

```
MP_Address    : USINT := 1;  
bStart        : BOOL;  
strDataKL6771 : DataKL6771;  
TMpolling     : TIME := t#10s;  
bRelay_R1     : BOOL;  
bRelay_R2     : BOOL;  
bRelay_R3     : BOOL;  
iUa           : UINT;  
SETTINGS      : UST3_SET;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in *TMPolling*.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**TMpolling:** The time for which the function block should address the drive. Default 10 s. Minimum time 1 s.

**bRelay\_R1:** Relay PIN 15

**bRelay\_R2:** Relay PIN 16

**bRelay\_R3:** Relay PIN 17

**iUa:** Analog output PIN 5 (1 mV = 1 digit)

**SETTINGS:** Data structure for setting the scaling and the resistance measurement (see [UST3\_SET](ms-xhelp:///?Id=beckhoff-7d75-4b39-8509-0524f47302ff)).

## VAR\_OUTPUT

```
bBusy       : BOOL;  
bError      : BOOL;  
iErrorId    : MP_Error;  
iU1         : INT;  
iU2_YSensor : INT;  
iU3         : INT;  
bDigital_S1 : BOOL;  
bDigital_S2 : BOOL;  
bDigital_S3 : BOOL;  
iResistor   : INT;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the iErrorId variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_Error](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). bError goes TRUE at the same time.

**iU1:** analog input PIN 3 (1 digit = 1 mV or 1 digit = 250 µV)

**iU2\_YSensor:** analog input PIN 4 (1 digit = 1 mV or 1 digit = 250 µV)

**iU3:** analog input PIN 7 (1 digit = 1 mV or 1 digit = 250 µV)

**bDigital\_S1:** digital input PIN 8

**bDigital\_S2:** digital input PIN 9

**bDigital\_S3:** digital input PIN 7

**iResistor:** resistance value PIN 4

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
