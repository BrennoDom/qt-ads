# FB_EnOceanSTM250

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# FB\_EnOceanSTM250

![1220438](/tcplclib_tc2_enocean/1033/Images/gif/173357579__en-US__Web.gif)

The function block *FB\_EnOceanSTM250()* provides a user-friendly evaluation of the data of an EnOcean STM250 module. The function block [FB\_EnOceanReceive()](ms-xhelp:///?Id=beckhoff-839a-4586-a2a0-666455178ef5) is required for this purpose.

|  |  |
| --- | --- |
| 10983950 | A new instance of this function block must be created for each STM100 module used. |

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
bState   : BOOL;  
bLearn   : BOOL;  
bError   : BOOL := FALSE;  
nErrorId : UDINT := 0;
```

**bState:** Upon activation of the reed contact in the STM250 module, this output becomes *TRUE* (contact closed).

**bLearn:** This output becomes *FALSE* if the teach-in button at the STM250 module is activated.

**bError:** this output goes TRUE as soon as an error occurs. This error is described via the variable *nErrorId*.

**nErrorId:** Describes the error type (see [error codes](ms-xhelp:///?Id=beckhoff-b80a-476f-a411-558c74468ff6)).

The following sample program illustrates the operating principle of this block:

```
PROGRAM MAIN  
VAR  
    fbEnOceanReceive : FB_EnOceanReceive;  
    fbEnOceanSTM250 : FB_EnOceanSTM250;  
    bState : BOOL;  
    bLearn : BOOL;  
END_VAR  
  
fbEnOceanReceive(  
    bEnable := TRUE,  
    stEnOceanInData := stEnOceanInData,  
    stEnOceanOutData := stEnOceanOutData);  
  
fbEnOceanSTM250(  
    bEnable := NOT fbEnOceanReceive.bError AND fbEnOceanReceive.bEnable,  
    nTransmitterId := 16#000008CA,  
    tWatchdog:=t#0s,  
    stEnOceanReceivedData := fbEnOceanReceive.stEnOceanReceivedData  
    bState => bState,  
    bLearn => bLearn);
```

In this example program an STM250 module with the transmitter ID 16#000008CA is queried. To this end the function block *FB\_EnOceanSTM250* is created. This function blocks obtains its information from the upstream receive block [FB\_EnOceanReceive](ms-xhelp:///?Id=beckhoff-839a-4586-a2a0-666455178ef5) and is only active (input *bEnable*) if the receive block is active and not in error. The output values at the function blocks are assigned variables for further evaluation.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
