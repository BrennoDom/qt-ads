# Function blocks

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. Function blocks

# Function blocks

The PLC library Tc3\_IPCDiag provides function blocks for reading and setting IPC diagnostic parameters. The available parameters are listed in the enumeration [E\_IPCDiag\_ParameterKey](ms-xhelp:///?Id=beckhoff-a43e-4ae7-94cf-ccf5dddf0869).

The IPC diagnostic modules available on the IPC must be registered before a parameter can be accessed. The function block [FB\_IPCDiag\_Register](ms-xhelp:///?Id=beckhoff-40f5-4c32-904a-27fa7d3f2bab) is used for this. This function block doesn't need to be called again afterwards.

All function blocks are called by a positive edge on the `bExecute` input. Afterwards, cyclic calling of the function block (`bExecute` = FALSE) returns the result of the query at the output as soon as the processing of the query has been completed (`bBusy` = FALSE). Each function block must be called (`bExecute` = FALSE) for as long as it takes for the internal processing (`bBusy` = FALSE) to be completed. During that time, leave all inputs of the function block unchanged.

## Reading parameters

Parameters are read with the function block [FB\_IPCDiag\_ReadParameter](ms-xhelp:///?Id=beckhoff-41de-431c-804d-3aa55cec49b6). If the function block body is called, the parameter is read from the entire system into the PLC. Parameters that could exist several times (e.g. IP addresses) are all read in one call. This takes place asynchronously, therefore the function block body has to be called until the procedure is complete and valid parameter values are available.  
The parameter is then assigned to a PLC variable using its `GetParameter()` method. Parameters that exist several times can be assigned to an array at once (with `GetParameter()` or `GetParameterStrings()`) or individually in a targeted way (with `GetParameterByIdx()`).

The function block [FB\_IPCDiag\_ReadParameterPeriodic](ms-xhelp:///?Id=beckhoff-9a5b-4fe1-ae2d-e530f7797ee1) is available if the periodic reading of a parameter is desired.

## Setting parameters

Parameters are written with the function block [FB\_IPCDiag\_WriteParameter](ms-xhelp:///?Id=beckhoff-adf3-48f9-b5c9-7b7caf01a2c4). If the function block body is called, the parameter is written from the PLC into the entire system. This similarly asynchronous call sets a single parameter at a time. For parameters that potentially exist several times, the desired parameter must be explicitly selected via the function block inputs.

See the [Samples](ms-xhelp:///?Id=beckhoff-1d42-4e53-94fb-823f23239395) for further programming information.

|  |  |
| --- | --- |
| 21192109 | Restricted access at the time of system start  MDP forms an interface to the hardware. This is independent of TwinCAT. MDP can be accessed from TwinCAT with the PLC library. This is done internally by means of ADS communication. The versatility of the hardware configuration justifies a different initialization phase of the MDP service. It is possible that first PLC cycles are executed while the MDP initialization is not yet completed.  Either the possible error outputs as well as timeouts of the function blocks from the library can be reacted and a new query can be triggered or the queries are executed deliberately delayed after the system start. It is recommended in the PLC program not to query values from the MDP immediately after the system start, but to consider a small waiting time. How large this should be depends on various parameters (such as the performance of your control computer), and can therefore not be given as a general rule. Typically it is in the range of 10-60 seconds. |

Further Information

* [FB\_IPCDiag\_ReadParameter](ms-xhelp:///?Id=beckhoff-41de-431c-804d-3aa55cec49b6)
* [FB\_IPCDiag\_ReadParameterPeriodic](ms-xhelp:///?Id=beckhoff-9a5b-4fe1-ae2d-e530f7797ee1)
* [FB\_IPCDiag\_WriteParameter](ms-xhelp:///?Id=beckhoff-adf3-48f9-b5c9-7b7caf01a2c4)
* [FB\_IPCDiag\_Register](ms-xhelp:///?Id=beckhoff-40f5-4c32-904a-27fa7d3f2bab)
* [Access by index specification](ms-xhelp:///?Id=beckhoff-ecbf-4c31-85ef-3a2175d6c259)

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
