# FB_EcFoeReadFile

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [FoE interface](ms-xhelp:///?Id=beckhoff-0647-4e46-a9c1-a6ca90dbe01e)
3. FB\_EcFoeReadFile

# FB\_EcFoeReadFile

![58970022](/tcplclib_tc2_ethercat/1033/Images/png/9861846283__Web.png)

The function block FB\_EcFoeReadFile can be used to download files from an EtherCAT device to the local data carrier via the "File access over EtherCAT" mailbox protocol.

|  |  |
| --- | --- |
| 60968157 | The path can only point to the local file system on the computer. This means that network paths cannot be used here! |

## VAR\_INPUT

```
VAR_INPUT  
    sFSrvNetId     : T_AmsNetId DWORD := '';  
    sFSrvPathName  : T_MaxString;  
    sEcNetId       : T_AmsNetId;  
    nSlaveAddr     : UINT;       
    sFoEPathName   : T_MaxString;  
    dwPass         : DWORD := 0;  
    bExecute       : BOOL;   
    tTimeout       : TIME := T#200s;   
END_VAR
```

**sFSrvNetID:** AMS network ID of the computer on which the file that was read is to be written (local computer). (type: T\_AmsNetId)

**sFSrvPathName:** Contains the path and file name of the file to be written (e.g. 'C:\Data\LogData.csv'), (type: T\_MaxString).

**sEcNetId:** String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**nSlaveAddr:** Address of the EtherCAT slave (type: UINT)

**sFoEPathName:** Name of the file on the EtherCAT slave, e.g. 'LogData' (type: T\_MaxString).

**dwPass:** Password (type: DWORD)

**bExecute:** The function block is activated by a positive edge at this input (type: BOOL).

**tTimeout:** Maximum time that must not be exceeded when the function block is executed (default: 200 s) (type: TIME).

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     : BOOL;  
    bError    : BOOL;  
    nErrId    : UDINT;  
    cbRead    : UDINT;  
    sInfo     : T_MaxString;  
END_VAR
```

**bBusy**: This output is set when the function block is activated and remains set until an acknowledgement is received (type: BOOL).

**bError**: This output is set after the bBusy output has been reset if an error occurs during the transfer of the command (type: BOOL).

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set. (type: UDINT)

**cbRead**: Number of successfully read data bytes. (type: UDINT)

**sInfo**: Additional FoE error information (reserved) (type: T\_MaxString).

## Sample in ST:

A rising edge at the bExecute variable triggers reading of the specified file via the "File access over EtherCAT" mailbox protocol. The file named in sFoEPathName is read by the selected EtherCAT slave (sEcNetId + nSlaveAddr). The file is stored on the selected computer (sFSrvNetID) under the name specified in sFSrvPathName. If a password is required for reading the file from the EtherCAT slave, this can be specified via dwPass.

The read and write operation is not completed until bBusy switches to FALSE. Only then are the error information or the number of bytes read to be evaluated.

```
PROGRAM MAIN  
VAR  
    fbEcReadFile : FB_EcFoeReadFile := (  
        sFSrvNetID     := '5.0.34.38.1.1', (* NetID for target file *)  
        sFSrvPathName  := 'C:\Data\LogData.csv', (* Pathname for target file *)  
        sEcNetId       := '5.0.34.38.3.1', (* NetID of EtherCAT master *)  
        nSlaveAddr     := 1004, (* EtherCAT slave address *)  
        sFoEPathName   := 'LogData', (* Name of source file *)  
        dwPass         := 0  
    );  
    bExecute   : BOOL := TRUE;  
    bBusy      : BOOL;  
    bError     : BOOL;  
    nErrID     : UDINT;  
    nBytesRead : UDINT;  
END_VAR  
  
fbEcReadFile (  
        bExecute := bExecute,  
        bBusy => bBusy,  
        bError => bError,  
        nErrId => nErrID,  
        cbRead => nBytesRead  
);  
IF NOT bBusy THEN  
    bExecute := FALSE;  
  
    IF NOT bError THEN  
         (* done, no error *)  
        nBytesRead := fbEcReadFile.cbRead;  
    ELSE  
        (* evaluate error *)  
        nBytesRead := 0;  
    END_IF  
    fbEcReadFile (bExecute := FALSE);  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT >= 3.3.14 |

See also

* [E\_EcFoeMode](ms-xhelp:///?Id=beckhoff-976f-43a3-8c7e-21160dfe743d)

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
