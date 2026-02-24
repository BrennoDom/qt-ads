# FB_CXReadKBusError

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Function Blocks](ms-xhelp:///?Id=beckhoff-ec9d-42ff-9fdd-c53aca476e55)
3. FB\_CXReadKBusError

# FB\_CXReadKBusError

The function block enables further information to be read out about a K-bus error in order to obtain a more precise error image and to enable better diagnosis.

The prerequisite for this is that you use the K-bus terminals directly on your CX.

Example: If you are using the K-bus extension and the cable of the K-bus extension is disconnected, then you will see a K-bus interruption as `nErrorCode = 4` and the position where the K-bus has been interrupted as `nErrorArgument = Position`.

Further information on possible K-bus errors using the CX7000 as an example:  
<https://infosys.beckhoff.com/content/1033/cx7000/9948355595.html?id=6787792405096234356>

## VAR\_INPUT

| Name | Type | Description |
| --- | --- | --- |
| bEnable | BOOL | Link this variable to bit 0 of the K-bus state to activate the read process automatically in case of a K-bus error.  The K-bus State is a Word variable. To mask out bit 0 of your linked variables, you can use `<VariableName>.0`. |

## VAR\_OUTPUT

| Name | Type | Description |
| --- | --- | --- |
| bBusy | BOOL | The function block is active and working. |
| bError | BOOL | The function block has an error. |
| nErrorID | UDINT | ADS error code |
| bKBusError | BOOL | The K-bus has an error. Further information is available at the outputs `nKBusErrorCode` and `nKBusErrorArgument`. |
| nKBusErrorCode | UINT | K-bus error code |
| nKBusErrorArgument | UINT | K-bus error argument |

Once the error has been corrected, the K-bus can be restarted via the function block IOF\_DeviceReset (from the PLC library Tc2\_IoFunctions).

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.22 | CX (x86, x64, ARM) | Tc2\_SystemCX (System) >= 3.4.7.0 |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
