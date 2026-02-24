# FB_ReadAdsSymByName

## Library
tcplclib_tc2_dataexchange

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
2. [Event driven data exchange](ms-xhelp:///?Id=beckhoff-1404-441c-98ad-cda0f6801510)
3. FB\_ReadAdsSymByName

# FB\_ReadAdsSymByName

![56677584](/tcplclib_tc2_dataexchange/1033/Images/gif/9007201040415243__en-US__Web.gif)

The function block enables reading of any value from another controller using the symbol name.

On a positive edge at the *bRead* input the function block reads the value of the variable *sVarName* from the selected ADS device (e.g. PLC). The ADS device is indicated by the AMS-NetId (*sNetId*) and the AMS Port number (*nPort*). The value is written into the variable to which *nDestAddr* points.

The internal mode of operation of the function block can be changed with the aid of the *eComMode* input:

* *eComMode := eAdsComModeSecureCom:* Following each read procedure the handle of the PLC variable is released again. This mode should be used when values are exchanged very slowly.
* *eComMode := eAdsComModeFastCom:* As long as the *sVarName*, *sNetID* and *nPort* inputs do not change, the handle of the PLC variable will not be released after each read procedure. This mode should be used when values are exchanged very frequently.

## VAR\_INPUT

```
VAR_INPUT  
    bRead            :  BOOL;  
    sNetId           :  T_AmsNetId;  
    nPort            :  T_AmsPort := 851;  
    sVarName         :  STRING (255);  
    nDestAddr        :  PVOID;  
    nLen             :  UDINT;  
    tTimeout         :  TIME := DEFAULT_ADS_TIMEOUT;  
    eComMode         :  E_AdsComMode := eAdsComModeSecureCom;  
END_VAR
```

**bRead:** Thefunction block reads the content of the variables *sVarName* of the selected ADS devices and writes it to the variable to which the pointer *nDestAddr* points.

**sNetId:** AMS-NetId of the ADS device from which the value is to be read. (Type T\_AmsNetId)

**nPort:** AMS Port number of the ADS device from which the value is to be read. (Type T\_AmsPort)

**sVarName:** Symbol name of the variable to be read on the selected ADS device (max. 255 characters).

**nDestAddr:** Address of the variable into which the read value is written.

**nLen:** Length of the variable to be read in bytes.

**tTimeout:** Time until processing is aborted.

**eComMode:** Enum used to specify whether the handle of the PLC variable is released again after each read procedure.

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
