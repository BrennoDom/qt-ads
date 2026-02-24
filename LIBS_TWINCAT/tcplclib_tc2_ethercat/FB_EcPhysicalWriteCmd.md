# FB_EcPhysicalWriteCmd

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Commands](ms-xhelp:///?Id=beckhoff-d66b-4ed1-85c6-c6f6b1a5e763)
3. FB\_EcPhysicalWriteCmd

# FB\_EcPhysicalWriteCmd

![8928942](/tcplclib_tc2_ethercat/1033/Images/png/57159819__Web.png)

The function block `FB_EcPhysicalWriteCmd` can be used to send an EtherCAT write command (FPWR, APWR, BWR) to a particular EtherCAT slave or to all EtherCAT slaves. This command can be used by the PLC to write to a register or the DPRAM of the EtherCAT slave controller.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId   : T_AmsNetId;   
    adp      : UINT;  
    ado      : UINT;  
    len      : UDINT;  
    eType    : E_EcAdressingType := eAdressingType_Fixed;  
    pSrcBuf  : PVOID;  
    bExecute : BOOL;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**adp:** This value determines which EtherCAT slave is to be addressed with this command. The meaning of this value depends on the addressing mode selected with eType:

| eType | Description |
| --- | --- |
| eAdressingType\_Fixed | The slave is addressed by means of its configured EtherCAT address. These EtherCAT addresses can be read via the function block FB\_EcGetAllSlaveAddr. |
| eAdressingType\_AutoInc | The slave is addressed based on its position in the ring. The first device has the address 0 (adp=0); adp is decremented by one for all subsequent slaves:  1. Slave adp = 0 2. Slave adp = 16#ffff (-1) 3. Slave adp = 16#fffe(-2) 4. Slave adp = 16#fffd(-3) etc. |
| eAdressingType\_BroadCAST | All slaves are addressed by this command. adp should be set to 0. |

**ado:** Physical memory (DPRAM) or register to be read.

**len:** Number of bytes to be written.

**eType:** Different EtherCAT commands are sent, depending on the value of eType:

| eType | Command |
| --- | --- |
| eAdressingType\_Fixed | Configured Address Physical Write ( FPWR) |
| eAdressingType\_AutoInc | Auto Increment Physical Write ( APWR) |
| eAdressingType\_BroadCAST | Broadcast Write ( BWR) |

The individual commands differ in terms of addressing mode (see adp).

**pSrcBuf:** Address (pointer) of the transmit buffer.

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    wkc    : UINT;   
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**wkc:** The working counter is incremented by each EtherCAT slave that has processed this command successfully. If only one EtherCAT slave was addressed by this command, this value should therefore be 1.

## Example of an implementation in ST:

```
PROGRAM Test_PhysicalWriteCmd  
VAR  
    fbWriteCmd : FB_EcPhysicalWriteCmd;  
    bExecute   : BOOL;  
    value      : UINT :=16#5555;  
    adp        : UINT:=16#3E9;  
    ado        : UINT:=16#1100;  
    eType      : E_EcAdressingType := eAdressingType_Fixed;  
    sNetId     : T_AmsNetId:='192.168.1.5.3.1';  
    wkc        : UINT;  
    bError     : BOOL;  
    nErrId     : UDINT;  
END_VAR  
  
fbWriteCmd (sNetId:=sNetID, ado:=ado, adp:=adp, eType:=eType, LEN := SIZEOF(value), pSrcBuf:=ADR(value), bExecute:=bExecute);  
wkc := fbWriteCmd.wkc;  
bError:= fbWriteCmd.bError;  
nErrId:= fbWriteCmd.nErrId;
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
