# FB_EcGetLastProtErrInfo

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Diagnostic](ms-xhelp:///?Id=beckhoff-b52f-4e72-8bb2-a127b94ebdc5)
3. FB\_EcGetLastProtErrInfo

# FB\_EcGetLastProtErrInfo

![49639248](/tcplclib_tc2_ethercat/1033/Images/png/57195019__Web.png)

The function block `FB_EcGetLastProtErrInfo` can be used to read additional error information relating to the most recent mailbox protocol error. An error-free mailbox command resets the last error every time.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;   
    nSlaveAddr : UINT;  
    eProtocol  : E_EcMbxProtType := eEcMbxProt_FoE;  
    bExecute   : BOOL;  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**nSlaveAddr**: Fixed address of the EtherCAT slave, whose error information is to be read.

**eProtocol**: [EtherCAT mailbox protocol type](ms-xhelp:///?Id=beckhoff-84f6-4932-a4b9-56f30d1179c3).

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    info   : ST_EcLastProtErrInfo;   
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**info**: Structure with additional [error information](ms-xhelp:///?Id=beckhoff-1938-4fab-915d-bef681be2bd9).

## Sample in ST:

A rising edge at bGet triggers reading of additional error information relating to the most recent mailbox protocol error.

```
PROGRAM MAIN  
VAR  
    fbGetInfo : FB_EcGetLastProtErrInfo := ( sNetID := '172.16.6.195.2.1',  
                        nSlaveAddr := 1004,  
                        eProtocol := eEcMbxProt_FoE,  
                        tTimeout := DEFAULT_ADS_TIMEOUT );  
    bGet : BOOL;  
    bBusy : BOOL;  
    bError : BOOL;  
    nErrID : UDINT;  
    sInfo : T_MaxString;  
END_VAR  
  
fbGetInfo( bExecute:= bGet,  
        bBusy=>bBusy,  
        bError=>bError,  
        nErrId=>nErrId );  
  
sInfo := BYTEARR_TO_MAXSTRING( fbGetInfo.info.binDesc );
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
