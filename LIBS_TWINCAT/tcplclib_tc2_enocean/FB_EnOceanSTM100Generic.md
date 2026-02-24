# FB_EnOceanSTM100Generic

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# FB\_EnOceanSTM100Generic

![48896832](/tcplclib_tc2_enocean/1033/Images/gif/173354379__en-US__Web.gif)

The function block *FB\_EnOceanSTM100Generic*() provides a user-friendly evaluation of the data of an EnOcean STM100 module. The function block [FB\_EnOceanReceive()](ms-xhelp:///?Id=beckhoff-839a-4586-a2a0-666455178ef5) is required for this purpose.

|  |  |
| --- | --- |
| 37418306 | A new instance of this function block must be created for each button module used. |

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
nDataBytes : ARRAY [0..3] OF BYTE;  
bError     : BOOL := FALSE;  
nErrorId   : UDINT := 0;
```

**nDataBytes:** 4-byte array with the user data sent by the STM100 module. The purpose of the individual bytes is manufacturer-specific.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the variable *nErrorId*.

**nErrorId:** Describes the error type (see [error codes](ms-xhelp:///?Id=beckhoff-b80a-476f-a411-558c74468ff6)).

The following sample program illustrates the operating principle of this block:

```
PROGRAM MAIN  
VAR  
    fbEnOceanReceive  : FB_EnOceanReceive;  
    fbEnOceanSTM100_1 : FB_EnOceanSTM100Generic;  
    fbEnOceanSTM100_2 : FB_EnOceanSTM100Generic;  
    nTemperature : ARRAY [1..2] OF BYTE;  
    nSetpoint : ARRAY [1..2] OF BYTE;  
    nStateRotarySwitch : ARRAY [1..2] OF BYTE;  
    nPresentSwitch : ARRAY [1..2] OF BYTE;  
END_VAR  
  
fbEnOceanReceive(  
    bEnable := TRUE,  
    stEnOceanInData := stEnOceanInData,  
    stEnOceanOutData := stEnOceanOutData);  
fbEnOceanSTM100_1(  
    bEnable := NOT fbEnOceanReceive.bError AND fbEnOceanReceive.bEnable,  
    nTransmitterId := 16#000000C4,  
    tWatchdog:=t#1h,  
    stEnOceanReceivedData := fbEnOceanReceive.stEnOceanReceivedData);  
nTemperature[1] := fbEnOceanSTM100_1.nDataBytes[0];  
nSetpoint[1] := fbEnOceanSTM100_1.nDataBytes[1];  
nStateRotarySwitch[1] := fbEnOceanSTM100_1.nDataBytes[2];  
nPresentSwitch[1] := fbEnOceanSTM100_1.nDataBytes[3];  
fbEnOceanSTM100_2(  
    bEnable := NOT fbEnOceanReceive.bError AND fbEnOceanReceive.bEnable,  
    nTransmitterId := 16#000000C5,  
    tWatchdog:=t#0s,  
    stEnOceanReceivedData := fbEnOceanReceive.stEnOceanReceivedData);  
nTemperature[2] := fbEnOceanSTM100_2.nDataBytes[0];  
nSetpoint[2] := fbEnOceanSTM100_2.nDataBytes[1];  
nStateRotarySwitch[2] := fbEnOceanSTM100_2.nDataBytes[2];  
nPresentSwitch[2] := fbEnOceanSTM100_2.nDataBytes[3];
```

In this example program two EnOcean transmitter modules are queried; one with the transmitter ID 16#000000C4, another one with the transmitter ID 16#000000C5. A function block *FB*\_*EnOceanSTM100Generic* is created for both transmitters. Both function blocks obtain their information from the upstream receive block [FB\_EnOceanReceive](ms-xhelp:///?Id=beckhoff-839a-4586-a2a0-666455178ef5) and are only active (input bEnable) if the receive block is active and not in error. The first device monitored with the watchdog function. New values have to be transferred to the controller within 1 hour; the second device is programmed without watchdog monitoring. The output values at the function blocks are assigned variables for further evaluation. Before the values can be used further, they have to be scaled to physical values. Details of the conversion can be found in the data sheet for the sensor.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
