# MP_RoomSensor

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_RoomSensor

# MP\_RoomSensor

![29605080](/tcplclib_tc2_mpbus/1033/Images/gif/8668266251__Web.gif)

This function block is used to read room sensors.

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. If *bStart* remains TRUE, the device is addressed cyclically with a period specified by the time in *TMPolling*. The time should be set longer than 1 second. *bError* is used to indicate an error in communication with the drive. The type of the error can be read with *iErrorID*.

## VAR\_INPUT

```
MP_Address    : USINT := 1;  
bStart        : BOOL;  
bReadDISensor : BOOL;   
strDataKL6771 : DataKL6771;  
TMpolling     : TIME := t#10s;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in *TMPolling*.

**bReadDISensor:** If TRUE, the DI sensor is read and the result is available in *bDigitalInput*.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**TMpolling:** The time for which the function block should address the drive. Default 10 s, minimum time 1 s.

## VAR\_OUTPUT

```
bBusy         : BOOL;  
bError        : BOOL;  
iErrorId      : MP_ERROR;  
rSensTemp     : LREAL;   
rDewPointTemp : LREAL;   
rHumid        : LREAL;   
uiCo2         : UINT;   
stUnit        : STRING;  
bDigitalInput : BOOL;   
bSensorError  : BOOL;   
st_SensorType : STRING;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_ERROR](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**rSensTemp:** Sensor temperature in °C or °F.

**rDewPointTemp:** Temperature of the calculated dew point in °C or °F.

**rHumid:** Humidity in percent (% 0.01).

**uiCo2:** CO2 content in ppm.

**stUnit:** C = °C or F = °F, ? = not read.

**bDigitalInput:** DI sensor read if *bReadDISensor* is TRUE.

**bSensorError:** One of the sensors has an error.

**st\_SensorType:** Sensor type '?' = not read / type / 'unknown' = number unknown.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.10 | Tc2\_MPBus from 3.4.12.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
