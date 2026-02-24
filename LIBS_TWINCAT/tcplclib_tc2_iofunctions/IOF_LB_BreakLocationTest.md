# IOF_LB_BreakLocationTest

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Beckhoff Lightbus](ms-xhelp:///?Id=beckhoff-7965-4e27-8686-f7efca6c7cab)
4. IOF\_LB\_BreakLocationTest

# IOF\_LB\_BreakLocationTest

![42302050](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314062859__Web.png)

The IOF\_LB\_BreakLocationTest function block carries out a break location test in a Beckhoff Lightbus optical fiber ring and can locate possible break locations. If no break location is detected during the test, the output variable **BOXNO** returns the current number of Lightbus modules in the ring. If a break location is detected before the Nth module in front of the receiver input, the **BREAK** flag is set and the module number is provided via the output variable **BOXNO**. If the **BOXNO** variable returns a value of **0xFF** the break location is situated immediately in front of the receiver input, and cannot be located.

## VAR\_INPUT

```
VAR_INPUT  
    NETID     : T_AmsNetId;  
    DEVICEID  : UDINT;  
    START     : BOOL;  
    TMOUT     : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: The network address of the TwinCAT computer on which the function is to be executed can be entered here (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**DEVICEID**: DeviceId specifies the device on which the function is to be executed. The device IDs are specified by the TwinCAT system during the hardware configuration.

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded during execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY     : BOOL;  
    ERR      : BOOL;  
    ERRID    : UDINT;  
    BREAK    : BOOL;  
    BOXNO    : WORD;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) when the ERR output is set.

**BREAK**: This flag is set if a break location is detected in the optical fiber ring.

**BOXNO**: The module number before the receiver input in front of which the break location has been detected.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | None. This functionality is not supported by TwinCAT 3 at present! | Beckhoff Lightbus Master: C1220 ISA; FC200x PCI | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
