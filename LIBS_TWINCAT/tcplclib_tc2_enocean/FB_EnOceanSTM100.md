# FB_EnOceanSTM100

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# FB\_EnOceanSTM100

![44346036](/tcplclib_tc2_enocean/1033/Images/gif/173347979__en-US__Web.gif)

|  |  |
| --- | --- |
| 63570006 | Outdated  For new projects the block [FB\_EnOceanSTM100Generic()](ms-xhelp:///?Id=beckhoff-9dc5-4b02-8cda-5fde9d631674) should be used! |

The function block *FB\_EnOceanSTM100()* provides a user-friendly evaluation of the data of an EnOcean STM100 module. The function block [FB\_EnOceanReceive()](ms-xhelp:///?Id=beckhoff-839a-4586-a2a0-666455178ef5) is required for this purpose.

|  |  |
| --- | --- |
| 35259143 | A new instance of this function block must be created for each button module used. |

## VAR\_INPUT

```
bEnable               : BOOL := FALSE;  
tWatchdog             : TIME;  
nTransmitterId        : UDINT;  
stEnOceanReceivedData : ST_EnOceanReceivedData;
```

**bEnable:** A positive signal at this input activates the block. A negative signal at the input disables the block functionality, and all outputs are set to 0 or FALSE.

**tWatchdog:** Monitoring time. Within this time, new information must reach this block via the input *stEnOceanReceivedData* described below. If this time is set to t#0s, the watchdog function is inactive.

**nTransmitterId:** ID of the EnOcean module, to which the block should respond.

**stEnOceanReceivedData:** Information and required connection to the EnOcean receive block [FB\_EnOceanReceive()](ms-xhelp:///?Id=beckhoff-839a-4586-a2a0-666455178ef5). This information is stored in a structure (see [ST\_EnOceanReceivedData](ms-xhelp:///?Id=beckhoff-cc12-4397-a341-a293a6adc9d6)).

## VAR\_OUTPUT

```
eEnOceanRotarySwitch : E_EnOceanRotarySwitch;  
nSetpoint            : INT;  
nTemperature         : INT;  
bPresentSwitch       : BOOL;  
bLearnSwitch         : BOOL;  
bError               : BOOL := FALSE;  
nErrorId             : UDINT := 0;
```

**eEnOceanRotarySwitch:** The value at this output describes the position of the rotary switch at the room control unit (see [E\_EnOceanRotarySwitch](ms-xhelp:///?Id=beckhoff-a4b0-4c45-af9b-5d049475e25f)).

**nSetpoint:** This output variables indicates the value set at the device. The value range is -100 to +100.

**nTemperature:** This output provides the measured temperature in 1/10 °C, with a measuring range of 0 °C to 40 °C. If the watchdog is triggered, the block suspects a broken wire type error, and the value is set to 850 °C.

**bPresentSwitch:** If the presence button at the room control unit is activated, this output becomes *TRUE*.

**bLearnSwitch:** If the teach-in button at the room control unit is activated, this output becomes *TRUE*.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the variable *nErrorId*.

**nErrorId:** Describes the error type (see [error codes](ms-xhelp:///?Id=beckhoff-b80a-476f-a411-558c74468ff6)).

The following sample program illustrates the operating principle of this block:

```
PROGRAM MAIN  
VAR  
    fbEnOceanReceive  : FB_EnOceanReceive;  
    fbEnOceanSTM100_1 : FB_EnOceanSTM100;  
    fbEnOceanSTM100_2 : FB_EnOceanSTM100;  
    nTemperature : ARRAY [1..2] OF INT;  
    nSetpoint : ARRAY [1..2] OF INT;  
    nStateRotarySwitch : ARRAY [1..2] OF E_EnOceanRotarySwitch;  
    bPresentSwitch : ARRAY [1..2] OF BOOL;  
END_VAR  
  
fbEnOceanReceive(  
    bEnable := TRUE,  
    stEnOceanInData := stEnOceanInData,  
    stEnOceanOutData := stEnOceanOutData);  
  
fbEnOceanSTM100_1(  
    bEnable := NOT fbEnOceanReceive.bError AND fbEnOceanReceve.bEnable,  
    nTransmitterId := 16#000000C4,  
    tWatchdog:=t#1h,  
    stEnOceanReceivedData := fbEnOceanReceive.stEnOceanReceivedData  
    nTemperature => Temperature[1],  
    nSetpoint => nSetpoint[1] ,  
    eEnOceanRotarySwitch => nStateRotarySwitch[1],  
    bPresentSwitch => bPresentSwitch[1]);  
fbEnOceanSTM100_2(  
    bEnable := NOT fbEnOceanReceive.bError AND fbEnOceanReceive.bEnable,  
    nTransmitterId := 16#000000C5,  
    tWatchdog:=t#0s,  
    stEnOceanReceivedData := fbEnOceanReceive.stEnOceanReceivedData  
    nTemperature => Temperature[2],  
    nSetpoint => nSetpoint[2] ,  
    eEnOceanRotarySwitch => nStateRotarySwitch[2],  
    bPresentSwitch => bPresentSwitch[2]);
```

In this example program two room control units are queried; one with the transmitter ID 16#000000C4 and another one with the transmitter ID 16#000000C5. A function block *FB\_EnOceanSTM100* is created for both modules. Both function blocks obtain their information from the upstream receive block [FB\_EnOceanReceive](ms-xhelp:///?Id=beckhoff-839a-4586-a2a0-666455178ef5) and are only active (input *bEnable*) if the receive block is active and not in error. The first device monitored with the watchdog function. New values have to be transferred to the controller within 1 hour; the second device is programmed without watchdog monitoring. The output values at the function blocks are assigned flags for further evaluation.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
