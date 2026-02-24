# IOF_CAN_Layer2Command

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [CANopen](ms-xhelp:///?Id=beckhoff-f5e3-4f91-b23b-f7fbd0797d25)
4. IOF\_CAN\_Layer2Command

# IOF\_CAN\_Layer2Command

![9911889](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314078859__Web.png)

The IOF\_CAN\_Layer2Command function block sends a 10-byte long command to layer 2 of a CAN master.

## VAR\_INPUT

```
VAR_INPUT  
    NETID     : T_AmsNetId;  
    DEVICEID  : UDINT;  
    LEN       : UDINT;  
    SRCADDR   : PVOID;  
    START     : BOOL;  
    TMOUT     : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: The network address of the TwinCAT computer on which the function is to be executed can be entered here (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**DEVICEID**: DeviceId specifies the device (CAN master) on which the function is to be executed. The device IDs are specified by the TwinCAT system during the hardware configuration.

**LEN**: The length of the layer 2 command in bytes.

**SRCADDR**: The address of the first data word in the CAN layer 2 command.°

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded during execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY    : BOOL;  
    ERR     : BOOL;  
    ERRID   : UDINT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) when the ERR output is set.

## Example:

```
PROGRAM MAIN  
VAR  
    IOF_CAN_Layer2Command1 : IOF_CAN_Layer2Command;  
    Layer2Data             : ARRAY[1..5] OF WORD;  
    StartLayer2            : BOOL;  
    Layer2_Busy            : BOOL;  
    Layer2_Err             : BOOL;  
    Layer2_ErrId           : UDINT;  
END_VAR
```

![22098140](/tcplclib_tc2_iofunctions/1033/Images/gif/59341067__en-US__Web.gif)

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | None. This functionality is not supported by TwinCAT 3 at present! | HILSCHER CIF3xx COM master card | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
