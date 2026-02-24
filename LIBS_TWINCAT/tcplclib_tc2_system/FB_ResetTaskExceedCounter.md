# FB_ResetTaskExceedCounter

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [General function blocks](ms-xhelp:///?Id=beckhoff-8c7f-4e24-ae22-527914ce956b)
4. FB\_ResetTaskExceedCounter

# FB\_ResetTaskExceedCounter

The function block can reset the Exceed Counter. The Exceed Counter is incremented whenever the selected task exceeds the set task time. This means that the real time could not be maintained in the cycle.

The reasons for exceeding the real time can be very diverse, but usually it is due to the PLC runtime and the application within this runtime. An example of this are programming loops such as FOR, WHILE, REPEAT, since these are always processed in one cycle.

## VAR\_INPUT

| Name | Type | Description |
| --- | --- | --- |
| bExecute | BOOL | A positive edge activates the function block. |
| nTaskAdsPort | UINT | ADS Port of the selected task. Example of a possible assignment: TwinCAT\_SystemInfoVarList.\_TaskInfo[GETCURTASKINDEXEX()].AdsPort |

## VAR\_OUTPUT

| Name | Type | Description |
| --- | --- | --- |
| bBusy | BOOL | The function block is active and working. |
| bError | BOOL | The function block has an error. |
| nErrorID | UDINT | ADS error code |

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.22 | PC or CX (x86, x64, ARM) | Tc2\_System (system) >= 3.4.25.0 |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
