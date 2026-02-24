# FB_EcGetScannedSlaves

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Diagnostic](ms-xhelp:///?Id=beckhoff-b52f-4e72-8bb2-a127b94ebdc5)
3. FB\_EcGetScannedSlaves

# FB\_EcGetScannedSlaves

![61356140](/tcplclib_tc2_ethercat/1033/Images/png/57188619__Web.png)

The function block `FB_EcGetScannedSlaves` can be used to read a list of the currently available (scanned) slaves from the EtherCAT master object directory. To this end an online scan is executed, during which the EEPROMs of the EtherCAT slaves are read. The scanning process may take some time, depending on the number of connected slaves.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute               : BOOL;  
    sNetId                 : T_AmsNetId;   
    pArrEcScannedSlaveInfo : POINTER TO ARRAY[0..EC_MAX_SLAVES] OF ST_EcSlaveScannedData;  
    cbBufLen               : UDINT;      
    tTimeout               : TIME := DEFAULT_ADS_TIMEOUT;   
END_VAR
```

**bExecute**: The function block is activated by a positive edge at this input.

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**pArrEcScannedSlaveInfo:** Address of an array of structures of type [ST\_EcSlaveScannedData](ms-xhelp:///?Id=beckhoff-d18e-40ce-b48e-d04216dec621), to which the data for each scanned slave are to be written.

**cbBufLen:** Maximum available buffer size (in bytes) for the data to be read.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy   : BOOL;  
    bError  : BOOL;  
    nErrId  : UDINT;  
    nSlaves : UINT;  
ND_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set. Error 1798 (0x706) indicates a null pointer at the buffer address. Error 1797 (0x705) indicates inadequate buffer size.

**nSlaves**: Returns the number of scanned slaves.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
