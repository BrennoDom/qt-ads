# FB_EcFoeOpen

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [FoE interface](ms-xhelp:///?Id=beckhoff-0647-4e46-a9c1-a6ca90dbe01e)
3. FB\_EcFoeOpen

# FB\_EcFoeOpen

![14008765](/tcplclib_tc2_ethercat/1033/Images/png/57230219__Web.png)

This function block is used to open the communication port for the “File access over EtherCAT” mailbox protocol.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId    : T_AmsNetId;  
    nPort     : UINT;       
    sPathName : T_MaxString;  
    dwPass    : DWORD;  
    eMode     : E_EcFoeMode;  
    bExecute  : BOOL;   
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT;   
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**nPort:** Fixed address of the EtherCAT device.

**sPathName**: Path name ( e.g.: 'c:\TwinCAT\FOE\Data.fwp' ). By default, only the file name (without file name extension) is extracted from the file path that was entered and used as the file name for the FoE protocol ( in our example: 'Data' ). From library version 3.3.12.0, file names including the file name extension can also be used ( in our example: 'Data.fwp' ).

The use of the file name extension for all instances of the FB\_EcFoeOpen function block can be enabled or disabled via the global Boolean variable   
`Tc2_EtherCAT.bEcFoeOpenFileNameWithFileExt`  
. By default, the variable has the value FALSE (no file name extension). If you set the value to TRUE, the use of the file name extensions is enabled.  
Note that the FoE function blocks were originally used for firmware updates for which no file name extension was used. If you want to update the firmware, you may have to make sure that the global variable has its original default value, i.e. FALSE.

**dwPass**: Password.

**eMode**: [Access mode](ms-xhelp:///?Id=beckhoff-976f-43a3-8c7e-21160dfe743d) (write/read access).

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    hFoe   : T_HFoe;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**hFoe**: “File access over EtherCAT” [handle](ms-xhelp:///?Id=beckhoff-f3c9-4116-85fd-186fc8905b19).

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
