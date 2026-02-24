# MP_PTH

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_PTH

# MP\_PTH

![33115615](/tcplclib_tc2_mpbus/1033/Images/gif/181478283__en-US__Web.gif)

This function block is used to control and monitor a PTH sensor.

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. If *bStart* remains TRUE, the device is addressed cyclically with a period specified by the time in *TMPolling*. The time should be set longer than 1 second. *bError* is used to indicate an error in communication with the sensor. The type of the error can be read with *iErrorID*.

If an external sensor is connected to the sensor, *iSensorTyp* should be used to specify the sensor type. If no sensor is connected, the value "0" should be entered, or the variable should be left blank. A digital sensor should be parameterized with "3". The state of the sensor is output through the variable *iYSensor*.

## VAR\_INPUT

```
MP_Address    : USINT := 1;  
bStart        : BOOL;  
iSensorTyp    : INT;  
strDataKL6771 : DataKL6771;  
TMpolling     : TIME := t#10s;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in *TMPolling*.

**iSensorTyp:** "0" or blank: no sensor is connected; "1": an analog sensor is connected with voltage output in mV; "2": an output of a resistance in ohms - 1.0 ohm; "3": an output of a resistance in ohms - 0.1 ohm; "4": digital sensor

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**TMpolling:** The time for which the function block should address the drive. Default 10 s. Minimum time 1 s.

## VAR\_OUTPUT

```
bBusy        : BOOL;  
bError       : BOOL;  
iErrorId     : MP_Error;  
iDampness    : INT;  
iPressure    : INT;  
iTemperature : INT;  
iYSensor     : INT;  
byPTH_Error  : BYTE;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_Error](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**iDampness:** Relative humidity in 0.01%

**iPressure:** Differential pressure, output in 0.1 Pa.

**iTemperature:** Temperature in 0.01 °C

**iYSensor:** Y-input, iSensorTyp = "1": voltage 0..10 V output in mV; iSensorTyp = "2": resistance output in 1.0 ohm; iSensorTyp = "3": resistance output in 0.1 ohm; iSensorTyp = "3": digital switch 0 or 1

**byPTH\_Error:** Sensor error - 0 - no error.

| byPTH\_Error | Description |
| --- | --- |
| Bit 0 | Servicing error |
| Bit 1 | Error message, sensor faulty |
| Bit 2 | - |
| Bit 3 | - |
| Bit 4 | Sensor (temperature/humidity) faulty |
| Bit 5 | A/D converter (pressure) faulty |
| Bit 6 | A/D converter (Y-input) faulty |
| Bit 7 | - |

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
