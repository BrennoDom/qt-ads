# FB_CXReadKBusCycleUpdateTime

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Function Blocks](ms-xhelp:///?Id=beckhoff-ec9d-42ff-9fdd-c53aca476e55)
3. FB\_CXReadKBusCycleUpdateTime

# FB\_CXReadKBusCycleUpdateTime

The function block can be used for all CXs that are operated directly with K-bus terminals. The function block determines the update time of the K-bus (K-bus runtime) with min. and max. values. The min. and max. values can be reset.

The K-bus runs task-synchronously with the PLC program. When the PLC program is completed, the K-bus is started, the outputs are written and the inputs are read. This means that a complete cycle always consists of the PLC runtime plus the K-bus update time.

* If the sum of both values is smaller than the set task cycle time, your system runs synchronously and thus optimally.
* If the sum is greater than your task cycle time, your system is no longer running in real-time. It is recommended to avoid this state.   
  You fix it by adjusting the task time, revising your PLC program or reducing the size of the K-bus.

## VAR\_INPUT

| Name | Type | Description |
| --- | --- | --- |
| bExecute | BOOL | A positive edge starts the function block. |
| bReset | BOOL | Reset of min. and max. values |

## VAR\_OUTPUT

| Name | Type | Description |
| --- | --- | --- |
| bBusy | BOOL | The function block is active and working. |
| bError | BOOL | The function block has an error. |
| nErrorID | UDINT | ADS error code |
| nKBusMinUpdateTime | UINT | Minimum update time in [µs] of the K-bus |
| nKBusMaxUpdateTime | UINT | Maximum update time in [µs] of the K-bus |
| nKBusLastUpdateTime | UINT | Last update time in [µs] of the K-bus |

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.22 | CX (x86, x64, ARM) | Tc2\_SystemCX (System) >= 3.4.7.0 |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
