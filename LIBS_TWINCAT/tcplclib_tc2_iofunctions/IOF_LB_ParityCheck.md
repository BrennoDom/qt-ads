# IOF_LB_ParityCheck

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Beckhoff Lightbus](ms-xhelp:///?Id=beckhoff-7965-4e27-8686-f7efca6c7cab)
4. IOF\_LB\_ParityCheck

# IOF\_LB\_ParityCheck

![45174131](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314066059__Web.png)

The IOF\_LB\_ParityCheck function block reads the parity error counters of the Beckhoff Lightbus modules (e.g. BK2000). In contrast to the function block [IOF\_LB\_ParityCheckWithReset](ms-xhelp:///?Id=beckhoff-6fb6-4eb2-8037-e57e093c82df), the counter states are not reset. The master maintains an 8-bit error counter for each module. These counters work without overflow. A maximum of **256** bytes of data, and therefore **256** counters, can be read. The number of error counters to be read is specified by the input variables **LEN** and **DESTADDR**. If, for instance, there are only 5 modules in the ring, then the **DESTADDR** parameter can be supplied with the address of a data buffer of 5 bytes, and the **LEN** parameter can be supplied with the value 5.

## VAR\_INPUT

```
VAR_INPUT  
    NETID     : T_AmsNetId;  
    DEVICEID  : UDINT;  
    LEN       : UDINT;  
    DESTADDR  : PVOID;  
    START     : BOOL;  
    TMOUT     : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: The network address of the TwinCAT computer on which the function is to be executed can be entered here (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**DEVICEID**: DeviceId specifies the device on which the function is to be executed. The device IDs are specified by the TwinCAT system during the hardware configuration.

**LEN**: The length in bytes of the data to be read.

**DESTADDR**: The address of the data buffer into which the parity data is to be written.

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
    IOF_LB_ParityCheck1 : IOF_LB_ParityCheck;  
    ParityData          : ARRAY[1..256] OF BYTE;  
    StartParityCheck    : BOOL;  
    ParityCheck_Busy    : BOOL;  
    ParityCheck_Err     : BOOL;  
    ParityCheck_ErrId   : UDINT;  
END_VAR
```

![3913996](/tcplclib_tc2_iofunctions/1033/Images/gif/59328267__en-US__Web.gif)

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | None. This functionality is not supported by TwinCAT 3 at present! | Beckhoff Lightbus Master: C1220 ISA; FC200x PCI | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
