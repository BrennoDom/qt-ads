# FB_ReadAdsTecSysData

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Third party devices](ms-xhelp:///?Id=beckhoff-8141-420b-ab48-e4c3c40c9d6b)
4. [ads-tec](ms-xhelp:///?Id=beckhoff-77ae-4730-b19a-a3d56d758ee3)
5. FB\_ReadAdsTecSysData

# FB\_ReadAdsTecSysData

![45027976](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314254859__Web.png)

The *FB\_ReadAdsTecSysData* function block reads the system data/diagnostic data of an ads-tec Industrial PC. The block is level triggered, which means that cyclic reading of the system data only occurs while the *bEnable* input is set. So that this only results in a low level of system loading, the read cycle is automatically repeated about every 100 ms (default value). When the *bValid* output is set, the most recently read data is valid (i.e. the last read cycle was carried out without error). If an error occurs, the *bError* output is set, and cyclic reading is halted. A new rising edge at the *bEnable* input can clear existing errors and restarts cyclic reading.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;  
    bEnable    : BOOL;  
    tCycleTime : TIME := T#100ms;  
END_VAR
```

**sNetId**: A string with the network address of the TwinCAT computer whose system data are to be read can be entered here (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**bEnable**: The block is reset by a rising edge (previous errors at the *bError* and *nErrId* outputs cleared). the system data are read cyclically if the input is set.

**tCycleTime**: The cyclic reading interval.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bValid    : BOOL;  
    bError    : BOOL;  
    nErrId    : UDINT;  
    stSysData : ST_AdsTecSysData;  
END_VAR
```

**bValid**: If this output is set, the data in the *ST\_AdsTecSysData* structure are valid (no error occurred during the last reading cycle).

**bError**: This output is set if an error occurred when executing the function. The error is cleared with a rising edge at the *bEnable* input.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) when the *bError* output is set.

**stSysData**: Structure with the system data/diagnostic data (type: [ST\_AdsTecSysData](ms-xhelp:///?Id=beckhoff-c9fd-4685-bd62-c6d9c87583b1)).

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | None. This functionality is not supported by TwinCAT 3 at present! | ads-tec PC | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
