# FB_EcGetSlaveCrcErrorEx

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Diagnostic](ms-xhelp:///?Id=beckhoff-b52f-4e72-8bb2-a127b94ebdc5)
3. FB\_EcGetSlaveCrcErrorEx

# FB\_EcGetSlaveCrcErrorEx

![34122637](/tcplclib_tc2_ethercat/1033/Images/png/2239762571__Web.png)

The function block `FB_EcGetSlaveCrcErrorEx` allows the CRC error counters of the individual ports (A, D, B and C) of a slave to be read. If the call is successful, the output variable crcError, whose type is `ST_EcCrcErrorEx`, contains the requested CRC error counter.

The function block `FB_EcGetSlaveCrcErrorEx` can also be used with slaves with up to 4 ports (e.g. EK1122). The function block `FB_EcGetSlaveCrcError` can only be used with slaves with up to 3 ports (e.g. EK1100).

```
VAR_INPUT  
    sNetId         :    T_AmsNetId; (*AmsNetId of the EtherCAT master device*)  
    nSlaveAddr     :    UINT; (*Address of the slave device*)  
    bExecute       :    BOOL; (*Function block execution is triggered by a rising edge at this input.*)  
    tTimeout       :    TIME; (*States the time before the function is cancelled.*)  
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device (type: T\_AmsNetID).

**nSlaveAddr**: Fixed address of the EtherCAT slave whose CRC error counter is to be read.

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

```
VAR_OUTPUT  
    bBusy        :    BOOL;  
    bError       :    BOOL;  
    nErrId       :    UDINT;  
    CrcError     :    ST_EcCrcErrorEx; (*Crc error of the EtherCAT slave device*)  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**CrcError**: CRC error counters for the individual ports. (type: [ST\_EcCrcErrorEx](ms-xhelp:///?Id=beckhoff-1d88-40da-87a4-900e6a7686d3))

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
