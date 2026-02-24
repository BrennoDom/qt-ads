# FB_WriteWatchdog

## Library
tcplclib_tc2_dataexchange

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
2. [Watchdog function blocks](ms-xhelp:///?Id=beckhoff-d87a-4b66-83d2-864965970a05)
3. FB\_WriteWatchdog

# FB\_WriteWatchdog

![42656148](/tcplclib_tc2_dataexchange/1033/Images/gif/9007199309573643__en-US__Web.gif)

Writing of a watchdog signal to another ADS device (TwinCAT PLC, Bus Terminal Controller, ...).

The FB\_WriteWatchdog function block cyclically writes the contents of a 32-bit counter into another ADS device. The counter is incremented every time the transmission is successful. The FB\_CheckWatchdog function block can be used at the receiver to evaluate this signal. The receiver is addressed by means of the AMS-NetId and the port number (see also ADS Device Identification). The position within the receiver is specified by the index group/index offset or by the symbol name. Usually this is the input image or the flags area.

The period for *tWachtdogTime* should not be shorter than 1 second, to avoid transmitting the counter state too frequently. If 0 s is given for *tWatchdogTime*, the signal is not transmitted. Please also note the description of the function block [FB\_CheckWatchdog ()](ms-xhelp:///?Id=beckhoff-29d0-4e07-aca2-b77369508a96).

If the input *bEnable* is set to FALSE, no further transfer of the watchdog signal takes place.

## VAR\_INPUT

```
VAR_INPUT  
    bEnable          :  BOOL := FALSE;  
    sNetId           :  T_AmsNetId;  
    nPort            :  T_AmsPort;  
    nIdxGrp          :  UDINT;  
    nIdxOffs         :  UDINT;  
    sVarName         :  STRING;  
    tWatchdogTime    :  TIME := t#0s;  
    bSendNow         :  BOOL;  
END_VAR
```

**bEnable:** Enable function block.

**sNetId:** AMS NetID of the ADS device to which the watchdog signal is to be transferred. (Type T\_AmsNetId)

**nPort:** AMS port number of the ADS device to which the watchdog signal is to be transferred. (Type T\_AmsPort)

**nIdxGrp:** Index group within the ADS device to which the watchdog signal is to be transferred.

**nIdxOffs:** Index offset within the ADS device to which the watchdog signal is to be transferred.

**sVarName:** Symbol name within the ADS device to which the watchdog signal is to be transferred.

**tWatchdogTime:** Cycle time in which the watchdog signal is transferred.

**bSendNow:** A positive edge triggers immediate transfer of the watchdog signal.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     :  BOOL := FALSE;  
    nLastCnt  :  UDINT := 0;  
    bError    :  BOOL := FALSE;  
    nErrorId  :  UDINT := 0;  
END_VAR
```

**bBusy:** Transmission is active.

**nLastCnt:** Most recently transmitted counter state.

**bError:** An error occurred during the transmission.

**nErrorId:** Error number if an error has occurred.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.0.0 | Tc2\_DataExchange |

[TwinCAT 3 | PLC Library: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
