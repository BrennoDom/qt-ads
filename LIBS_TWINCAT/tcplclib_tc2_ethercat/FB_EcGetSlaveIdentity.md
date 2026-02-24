# FB_EcGetSlaveIdentity

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Diagnostic](ms-xhelp:///?Id=beckhoff-b52f-4e72-8bb2-a127b94ebdc5)
3. FB\_EcGetSlaveIdentity

# FB\_EcGetSlaveIdentity

![38668280](/tcplclib_tc2_ethercat/1033/Images/png/57182219__Web.png)

The function block `FB_EcGetSlaveIdentity` can be used to read the CANopen identity of an individual EtherCAT slave device. If the call is successful, the output variable identity, whose type is `ST_EcSlaveIdentity`, contains the requested identity information.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;  
    nSlaveAddr : UINT;       
    bExecute   : BOOL;   
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;   
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type T\_AmsNetId)

**nSlaveAddr:** Fixed address of the EtherCAT slave.

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrId   : UDINT;  
    identity : ST_EcSlaveIdentity;   
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**identity**: CANopen [identity](ms-xhelp:///?Id=beckhoff-793a-4ef2-9893-e6e8ec2917af) of the EtherCAT device.

## Example of an implementation in ST:

```
PROGRAM TEST_GetSlaveIdentity  
VAR  
    fbGetSlaveIdentity : FB_EcGetSlaveIdentity;  
    sNetId             : T_AmsNetId := '172.16.2.131.2.1';  
    bExecute           : BOOL;  
    identity           : ST_EcSlaveIdentity;  
    nSlaveAddr         : UINT := 1001;  
    bError             : BOOL;  
    nErrId             : UDINT;  
END_VAR  
  
fbGetSlaveIdentity(sNetId:= sNetId, nSlaveAddr:= nSlaveAddr, bExecute:=bExecute);  
identity := fbGetSlaveIdentity.identity;  
bError := fbGetSlaveIdentity.bError;  
nErrId := fbGetSlaveIdentity.nErrId;
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
