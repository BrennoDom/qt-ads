# IOF_SER_GetPhase

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [SERCOS](ms-xhelp:///?Id=beckhoff-3607-4eaf-b256-e8662f77e8c2)
4. IOF\_SER\_GetPhase

# IOF\_SER\_GetPhase

![32481801](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314085259__Web.png)

The “IOF\_SER\_GetPhase” function block determines the current communication phase on the SERCOS ring. The communication phase can have a value from 0 to 4.

## VAR\_INPUT

```
VAR_INPUT  
    NETID     : T_AmsNetId;  
    DEVICEID  : UDINT;  
    GET       : BOOL;  
    TMOUT     : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: The network address of the TwinCAT computer on which the ADS command is to be executed can be entered here (type: T\_AmsNetId). If it is to be run on the local computer, an empty string can be entered.

**DEVICEID**: The DeviceId is used to specify the SERCOS master whose communication phase is to be determined. The device IDs are specified by the TwinCAT system during the hardware configuration.

**GET**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded during execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY    : BOOL;  
    ERR     : BOOL;  
    ERRID   : UDINT;  
    PHASE   : BYTE;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) when the ERR output is set.

**PHASE**: The current communication phase in the SERCOS ring.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC (x86) | Sercans SCS-P ISA; Sercans SCS-P PCI; Beckhoff FC750x PCI | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
