# FB_CxGetDeviceIdentification

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Function Blocks](ms-xhelp:///?Id=beckhoff-ec9d-42ff-9fdd-c53aca476e55)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-e017-4829-99e7-b191fda213bd)
4. FB\_CxGetDeviceIdentification

# FB\_CxGetDeviceIdentification

![21209668](/tcplclib_tc2_systemcx/1033/Images/png/9007199440647563__Web.png)

The function block FB\_CxGetDeviceIdentification can be used to read device ID data of the CX.

|  |  |
| --- | --- |
| 56669285 | Obsolete functionality    * Use the FB\_GetDeviceIdentificationEx from the Tc2\_Utilities library. |

## VAR\_INPUT

```
VAR_INPUT  
    bExecute : BOOL;  
    tTimeout : TIME;  
END_VAR
```

**bExecute**: The command is executed with the rising edge.

**tTimeout**: States the time before the function is canceled.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy      : BOOL;  
    bError     : BOOL;  
    nErrorID   : UDINT;  
    stDevIdent : ST_CxDeviceIdentification;  
END_VAR
```

**bBusy**: Data are read from the CX-Device. Data are stored in stDevIdent if bBusy = FALSE and bError = FALSE.

**bError**: gets TRUE, with any error.

**nErrorID**: contains the error id if bErr is TRUE.

**stDevIdent**: Contains the read data (type: [ST\_CxDeviceIdentification](ms-xhelp:///?Id=beckhoff-fda7-431a-9034-b66729aaf8b6))

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 | CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7 :TC TR x86, WEC7: TC CE7 ARMV7) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
