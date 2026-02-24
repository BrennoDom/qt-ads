# FB_CxGetDeviceIdentificationEx

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Function Blocks](ms-xhelp:///?Id=beckhoff-ec9d-42ff-9fdd-c53aca476e55)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-e017-4829-99e7-b191fda213bd)
4. FB\_CxGetDeviceIdentificationEx

# FB\_CxGetDeviceIdentificationEx

![40261524](/tcplclib_tc2_systemcx/1033/Images/png/2242886795__Web.png)

The function block FB\_CxGetDeviceIdentificationEx can be used to read device ID data of the CX. The function block is an extension of the function block FB\_CxGetDeviceIdentification. The read device data are stored in the variable stDevIdent of type [ST\_CxDeviceIdentificationEx](ms-xhelp:///?Id=beckhoff-8e91-4d66-a38f-1943aca9cfa8).

|  |  |
| --- | --- |
| 26809401 | Obsolete functionality    * Use the FB\_GetDeviceIdentificationEx from the Tc2\_Utilities library. |

## VAR\_INPUT

```
VAR_INPUT  
    bExecute  :  BOOL;  
    tTimeout  :  TIME;  
END_VAR
```

**bExecute**: The command is executed with a rising edge.

**tTimeout**: States the time before the function is cancelled.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy      :  BOOL;  
    bError     :  BOOL;  
    nErrorId   :  UDINT;  
    stDevIdent :  ST_CxDeviceIdentificationEx;  
END_VAR
```

**bBusy**: The data are read from the CX. After error-free execution, the data are in the structure stDevIdent if bBusy = FALSE.

**bError**: Becomes TRUE, as soon as an error occurs.

**nErrorID**: Supplies the error number when the bError output is set.

**stDevIdent**: Contains the read device data (type: [ST\_CxDeviceIdentificationEx](ms-xhelp:///?Id=beckhoff-8e91-4d66-a38f-1943aca9cfa8))

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 | CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7 :TC TR x86, WEC7: TC CE7 ARMV7) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
