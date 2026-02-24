# FB_EcFoeLoad

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [FoE interface](ms-xhelp:///?Id=beckhoff-0647-4e46-a9c1-a6ca90dbe01e)
3. FB\_EcFoeLoad

# FB\_EcFoeLoad

![56511253](/tcplclib_tc2_ethercat/1033/Images/png/57227019__Web.png)

The function block `FB_EcFoeLoad` can be used to download or upload files to or from an EtherCAT device via the “File access over EtherCAT” mailbox protocol.

|  |  |
| --- | --- |
| 38839231 | The path can only point to the local file system on the computer. This means that network paths cannot be used here! To upload or download files via the FoE protocol, the function block automatically resets the EtherCAT device to BOOTSTRAP mode. Finally, the function block tries to reset the device to the original state. |

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId ;  
    nSlaveAddr : UINT;       
    sPathName  : T_MaxString;  
    dwPass     : DWORD := 0;  
    eMode      : E_EcFoeMode := eFoeMode_Write;  
    bExecute   : BOOL;   
    tTimeout   : TIME := T#200s;   
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**nSlaveAddr:** Fixed address of the EtherCAT slave whose file is to be uploaded or downloaded.

**sPathName**: Contains the path and file names of the file to be written or read (e.g.: 'C:\FOE\_Test\EL6751\ECATFW\_\_EL6751\_C6\_V0030.efw' ).

**dwPass**: Password (default: 0).

**eMode**: “File access over EtherCAT” [access mode](ms-xhelp:///?Id=beckhoff-976f-43a3-8c7e-21160dfe743d) (default: write access).

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time that must not be exceeded when the function block is executed (default: 200 s).

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     : BOOL;  
    bError    : BOOL;  
    nErrId    : UDINT;  
    cbLoad    : UDINT;  
    nProgress : UDINT;  
    sInfo     : T_MaxString;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**cbLoad**: Number of successfully written or read data bytes.

**nProgress**: Write access progress (range: 0 - 100%). This variable is currently not used for read access, in which case it is always 0.

**sInfo**: Additional command information as string (reserved).

## Sample in ST:

A rising edge at the bLoad variable triggers the firmware download via the “File access over EtherCAT” mailbox protocol.

```
PROGRAM MAIN  
VAR  
    fbDownload : FB_EcFoeLoad := (  
        sNetID     := '5.0.34.38.3.1',  
        nSlaveAddr := 1004,  
        sPathName  := 'C:\FOE_Test\EL6751\ECATFW__EL6751_C6_V0030.efw',  
        dwPass     := 0,  
        eMode      := eFoeMode_Write );  
    bLoad      : BOOL;  
    bBusy      : BOOL;  
    bError     : BOOL;  
    nErrID     : UDINT;  
    nBytesWritten : UDINT;  
    nPercent      : UDINT;  
END_VAR  
  
fbDownload( bExecute := bLoad,  
        bBusy => bBusy,  
        bError => bError,  
        nErrId => nErrID,  
        cbLoad => nBytesWritten,  
        nProgress => nPercent );
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
