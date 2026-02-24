# MP_MPX

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_MPX

# MP\_MPX

![40962215](/tcplclib_tc2_mpbus/1033/Images/gif/181471883__en-US__Web.gif)

For BELIMO room sensor MS24A-R..-MPX

MS24A-R01-MPX temperature

MS24A-R02-MPX temperature, CO2

MS24A-R03-MPX temperature, VOC

MS24A-R04-MPX temperature, CO2, VOC

MS24A-R05-MPX temperature, air humidity

MS24A-R06-MPX temperature, air humidity, CO2

MS24A-R07-MPX temperature, air humidity, VOC

MS24A-R08-MPX temperature, air humidity, CO2, VOC

## VAR\_INPUT

```
MP_Address    : USINT := 1;  
bStart        : BOOL;  
strDataKL6771 : DataKL6771;  
TMpolling     : TIME := t#10s;  
bTemp_C_F     : BOOL;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A rising edge starts the function block. If this remains continuously TRUE, the function block will be activated cyclically with a period specified in *TMPolling*.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**TMpolling:** The time for which the function block should address the drive. Default 10 s. Minimum time 1 s.

**bTemp\_C\_F:** FALSE = °C / TRUE = F

## VAR\_OUTPUT

```
bBusy        : BOOL;  
bError       : BOOL;  
iErrorId     : MP_Error;  
strMPX_ERR   : MP_BUS_MPX_ERROR;  
iU           : INT;  
bDigital     : BOOL;  
iTemp        : INT;  
iCO2         : INT;  
iVOC         : INT;  
iHumidity    : INT;  
bFlushStatus : BOOL;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_Error](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**strMPX\_ERR:** Sensor error messages (see [MP\_BUS\_MPX\_ERROR](ms-xhelp:///?Id=beckhoff-801c-4342-b9a9-ecf32b9e82fd)).

**iU:** 0..10 V UNIT 1 mV

**bDigital:** DI 24 V

**iTemp:** 0..50 °C Unit:0.01 °C

**iCO2:** 0..2000 ppm Unit:1 ppm

**iVOC:** 0..2000 ppm Unit:1 ppm (pseudo)

**iHumidity:** 10...90 % Unit: 0.01 %

**bFlushStatus:** VOC gradient threshold exceeded, FALSE = air quality OK, 1 TRUE = air quality not OK, flush

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
