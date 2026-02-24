# FB_WriteRealOnDelta

## Library
tcplclib_tc2_dataexchange

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
2. [Event driven data exchange](ms-xhelp:///?Id=beckhoff-1404-441c-98ad-cda0f6801510)
3. FB\_WriteRealOnDelta

# FB\_WriteRealOnDelta

![52254296](/tcplclib_tc2_dataexchange/1033/Images/gif/9007199309564043__en-US__Web.gif)

The function block enables event-driven writing of a variable of type REAL.

The FB\_WriteRealOnDelta function block checks cyclically whether the value at the *fSignal* input has changed. The cycle time for checking is determined by the parameter *tCycleTime*. If 0 s is given for *tCycleTime*, the input signal is examined during every PLC cycle. If the comparison establishes that the current value is greater than the value *fUpperLimit* or lower than the value *fLowerLimit*, then the value of the signal is sent to the ADS device that is to be specified. The receiver is addressed by means of the AMS-NetId and the port number (see also ADS Device Identification). The position within the receiver is specified by the index group/index offset or by the symbol name. Usually this is the input image or the flags area.

The internal representation of floating point numbers differs according to the hardware being used. While Intel uses the "little endian" format, Motorola uses the "big endian" format. The input variable *bSwapLowHighWord* can be used to make the necessary adjustment in order to be able to exchange floating point numbers. This is necessary if floating point numbers are to be exchanged between the TwinCAT PLC on a PC and a BC9000, for example.

If the *bEnable* input is set to FALSE, no further signal transmission is carried out.

## VAR\_INPUT

```
VAR_INPUT  
    bEnable          :  BOOL := FALSE;  
    sNetId           :  T_AmsNetId;  
    nPort            :  T_AmsPort;  
    nIdxGrp          :  UDINT;  
    nIdxOffs         :  UDINT;  
    sVarName         :  STRING;  
    fSignal          :  REAL;  
    fLowerLimit      :  REAL;  
    fUpperLimit      :  REAL;  
    tCycleTime       :  TIME := t#0s;  
    bSendNow         :  BOOL;  
    bSwapLowHighWord :  BOOL := FALSE;  
END_VAR
```

**bEnable:** Enable function block.

**sNetId:** AMS NetID of the ADS device to which the value is to be transmitted. (Type T\_AmsNetId)

**nPort:** AMS port number of the ADS device to which the value is to be transmitted. (T\_AmsPort)

**nIdxGrp:** Index group within the ADS device into which the value is to be transmitted.

**nIdxOffs:** Index offset within the ADS device into which the value is to be transmitted.

**sVarName:** Symbol name within the ADS device into which the value is to be transmitted.

**fSignal:** Variable whose value is to be transmitted.

**fLowerLimit:** Lower limit value.

**fUpperLimit:** Upper limit value.

**tCycleTime:** Cycle time in which the input signal is examined to see whether it has exceeded the limit values.

**bSendNow:** The value is transmitted immediately in response to a positive edge.

**bSwapLowHighWord:** The least significant WORD and the most significant WORD are swapped.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy            :  BOOL := FALSE;  
    fLastSignal      :  REAL;  
    bError           :  BOOL := FALSE;  
    nErrorId         :  UDINT := 0;  
    nErrorCnt        :  UDINT := 0;  
END_VAR
```

**bBusy:** The transmission is active.

**fLastSignal:** Most recently transmitted value.

**bError:** An error occurred during the transmission.

**nErrorId:** Error number if an error has occurred.

**nErrorCnt:** Number of transmission attempts that have returned faults.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.0.0 | Tc2\_DataExchange |

[TwinCAT 3 | PLC Library: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
