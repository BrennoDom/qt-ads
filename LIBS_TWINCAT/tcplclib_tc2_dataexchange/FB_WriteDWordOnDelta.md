# FB_WriteDWordOnDelta

## Library
tcplclib_tc2_dataexchange

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
2. [Event driven data exchange](ms-xhelp:///?Id=beckhoff-1404-441c-98ad-cda0f6801510)
3. FB\_WriteDWordOnDelta

# FB\_WriteDWordOnDelta

![35632194](/tcplclib_tc2_dataexchange/1033/Images/gif/9007199309560843__en-US__Web.gif)

The function block enables event-driven writing of a variable of type DWORD.

The FB\_WriteDWordOnDelta function block checks cyclically whether the value at the *nSignal* input has changed. The cycle time for checking is determined by the parameter *tCycleTime*. If 0 s is given for *tCycleTime*, the input signal is examined during every PLC cycle. If the comparison establishes that the current value is greater than the value *nUpperLimit* or lower than the value *nLowerLimit*, then the value of the signal is sent to the ADS device that is to be specified. The receiver is addressed by means of the AMS-NetId and the port number (see also ADS Device Identification). The position within the receiver is specified by the index group/index offset or by the symbol name. Usually this is the input image or the flags area.

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
    nSignal          :  BYTE;  
    nLowerLimit      :  BYTE;  
    nUpperLimit      :  BYTE;  
    tCycleTime       :  TIME := t#0s;  
    bSendNow         :  BOOL;  
END_VAR
```

**bEnable:** Enable function block.

**sNetId:** AMS NetID of the ADS device to which the value is to be transmitted. (Type T\_AmsNetId)

**nPort:** AMS port number of the ADS device to which the value is to be transmitted. (Type T\_AmsPort)

**nIdxGrp:** Index group within the ADS device into which the value is to be transmitted.

**nIdxOffs:** Index offset within the ADS device into which the value is to be transmitted.

**sVarName:** Symbol name within the ADS device into which the value is to be transmitted.

**nSignal:** Variable whose value is to be transmitted.

**nLowerLimit:** Lower limit value.

**nUpperLimit:** Upper limit value.

**tCycleTime:** Cycle time in which the input signal is examined to see whether it has exceeded the limit values.

**bSendNow:** The value is transmitted immediately in response to a positive edge.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy            :  BOOL := FALSE;  
    nLastSignal      :  DWORD;  
    bError           :  BOOL := FALSE;  
    nErrorId         :  UDINT := 0;  
    nErrorCnt        :  UDINT := 0;  
END_VAR
```

**bBusy:** The transmission is active.

**nLastSignal:** Most recently transmitted value.

**bError:** An error occurred during the transmission.

**nErrorId:** Error number if an error has occurred.

**nErrorCnt:** Number of transmission attempts that have returned faults.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.0.0 | Tc2\_DataExchange |

[TwinCAT 3 | PLC Library: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
