# FB_WriteAdsSymByName

## Library
tcplclib_tc2_dataexchange

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
2. [Event driven data exchange](ms-xhelp:///?Id=beckhoff-1404-441c-98ad-cda0f6801510)
3. FB\_WriteAdsSymByName

# FB\_WriteAdsSymByName

![40336211](/tcplclib_tc2_dataexchange/1033/Images/gif/9007201040423179__en-US__Web.gif)

The function block enables writing of any value to another controller using the symbol name.

On a positive edge at the *bWrite* input the function block writes the value to which the pointer *nSrcAddr* points into the variable *sVarName* of the selected ADS device (e.g. PLC). The ADS device is indicated by the AMS-NetId (*sNetId*) and the AMS Port number (*nPort*).

The internal mode of operation of the function block can be changed with the aid of the *eComMode* input:

* *eComMode := eAdsComModeSecureCom:* Following each write procedure the handle of the PLC variable is released again. This mode should be used when values are exchanged very slowly.
* *eComMode := eAdsComModeFastCom:* As long as the *sVarName*, *sNetID* and *nPort* inputs do not change, the handle of the PLC variable will not be released after each write procedure. This mode should be used when values are exchanged very frequently.

## VAR\_INPUT

```
VAR_INPUT  
    bWrite           :  BOOL;  
    sNetId           :  T_AmsNetId;  
    nPort            :  T_AmsPort := 851;  
    sVarName         :  STRING (255);  
    nSrcAddr         :  PVOID;  
    nLen             :  UDINT;  
    tTimeout         :  TIME := DEFAULT_ADS_TIMEOUT;  
    eComMode         :  E_AdsComMode := eAdsComModeSecureCom;  
END_VAR
```

**bWrite:** This function block writes the contents of the variable to which pointer *nSrcAddr* points into the variable *sVarName* of the selected ADS device.

**sNetId:** AMS NetID of the ADS device to which the value is to be transmitted. (Type T\_AmsNetId)

**nPort:** AMS port number of the ADS device to which the value is to be transmitted. (Type T\_AmsPort)

**sVarName:** Symbol name of the variable to be written on the selected ADS device (max 255 characters).

**nSrcAddr:** Address of the variable in which the value to written is located.

**nLen:** Length in bytes of the variable to be written.

**tTimeout:** Time until processing is aborted.

**eComMode:** Enum used to specify whether the handle of the PLC variable is released again after each write procedure.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     :  BOOL;  
    bError    :  BOOL;  
    nErrorId  :  UDINT;  
END_VAR
```

**bBusy:** The transmission is active.

**bError:** An error occurred during the transmission.

**nErrorId:** ADS error number if an error has occurred.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.0 | Tc2\_DataExchange |

[TwinCAT 3 | PLC Library: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
