# FB_EnOceanPTM200

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# FB\_EnOceanPTM200

![13803553](/tcplclib_tc2_enocean/1033/Images/gif/173344779__en-US__Web.gif)

The function block *FB\_EnOceanPTM200*() provides a user-friendly evaluation of the state of an EnOcean PTM200 or PTM250 module. The function block [FB\_EnOceanReceive()](ms-xhelp:///?Id=beckhoff-839a-4586-a2a0-666455178ef5) is required for this purpose.

In contrast to the PTM100 module, in the PTM200/250 module two buttons can be pressed simultaneously. In addition, the PTM200/250 module supports four, not eight buttons.

|  |  |
| --- | --- |
| 57123120 | A new instance of this function block must be created for each button module used. |

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
bSwitches : ARRAY [0..3] OF BOOL;  
bError    : BOOL := FALSE;  
nErrorId  : UDINT := 0;
```

**bSwitches:** This field of 4 Boolean values describes the states of the 4 buttons on the button module.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the variable *nErrorId*.

**nErrorId:** Describes the error type (see [error codes](ms-xhelp:///?Id=beckhoff-b80a-476f-a411-558c74468ff6)).

The following sample program illustrates the operating principle of this block:

```
PROGRAM MAIN  
VAR  
    fbEnOceanReceive  : FB_EnOceanReceive;  
    fbEnOceanPTM100_1 : FB_EnOceanPTM200;  
    fbEnOceanPTM100_2 : FB_EnOceanPTM200;  
    bSwitches1   : ARRAY [0..3] OF BOOL;  
    bSwitches2_1 : BOOL;  
    bSwitches2_2 : BOOL;  
    bSwitches2_3 : BOOL;  
    bSwitches2_4 : BOOL;  
END_VAR  
  
fbEnOceanReceive(  
    bEnable := TRUE,  
    stEnOceanInData := stEnOceanInData  
    stEnOceanOutData := stEnOceanOutData);  
fbEnOceanPTM200_1(  
    bEnable := NOT fbEnOceanReceive.bError AND fbEnOceanReceive.bEnable,  
    nTransmitterId := 16#000000C6,  
    tWatchdog:=t#0s,  
    stEnOceanReceivedData := fbEnOceanReceive.stEnOceanReceivedData);  
    bSwitches1 := fbEnOceanPTM200_1.bSwitches;  
fbEnOceanPTM200_2(  
    bEnable := NOT fbEnOceanReceive.bError AND fbEnOceanReceive.bEnable,  
    nTransmitterId := 16#000000C7,  
    tWatchdog:=t#0s,  
    stEnOceanReceivedData := fbEnOceanReceive.stEnOceanReceivedData);  
bSwitches2_1 := fbEnOceanPTM200_2.bSwitches[0];  
bSwitches2_2 := fbEnOceanPTM200_2.bSwitches[1];  
bSwitches2_3 := fbEnOceanPTM200_2.bSwitches[2];  
bSwitches2_4 := fbEnOceanPTM200_2.bSwitches[3];
```

In this example program two transmitter modules (PTM200/PTM250) are queried; one with the transmitter ID 16#C6, another one with the transmitter ID 16#C7. A function block *FB\_EnOceanPTM200* is created for both transmitter modules. Both function blocks obtain their information from the upstream receive block [FB\_EnOceanReceive](ms-xhelp:///?Id=beckhoff-839a-4586-a2a0-666455178ef5) and are only active (input *bEnable*) if the receive block is active and not in error. The buttons of the first transmitter module are assigned to a Boolean array *bSwitches1* for further analysis, while the buttons of the second transmitter module are assigned to individual Boolean variables *bSwitches2\_1* to *bSwitches2\_8*; both options are conceivable.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
