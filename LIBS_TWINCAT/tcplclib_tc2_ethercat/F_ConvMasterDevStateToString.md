# F_ConvMasterDevStateToString

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Conversion Functions](ms-xhelp:///?Id=beckhoff-c72d-4c13-9be6-b8070ce06bef)
3. F\_ConvMasterDevStateToString

# F\_ConvMasterDevStateToString

![13803553](/tcplclib_tc2_ethercat/1033/Images/png/57287819__Web.png)

The function `F_ConvMasterDevStateToString` converts the device status of the EtherCAT master to string.

For nState = 0 'OK' is returned, otherwise, 'Not OK – Link error', e.g. for nState = 1. If several errors are pending, they are separated by hyphens.

## VAR\_INPUT

```
VAR_INPUT  
    nState : WORD;  
END_VAR
```

**nstate**: Device status of the EtherCAT master; can be linked as DevState in the System Manager from the inputs of the EtherCAT master to the PLC.

```
0x0001 = ‘Link error‘  
0x0002 = ‘I/O locked after link error (I/O reset required)‘  
0x0004 = ‘Link error (redundancy adapter)‘  
0x0008 = ‘Missing one frame (redundancy mode)‘  
0x0010 = ‘Out of send resources (I/O reset required)‘  
0x0020 = ‘Watchdog triggered‘  
0x0040 = ‘Ethernet driver (miniport) not found‘  
0x0080 = ‘I/O reset active‘  
0x0100 = ‘At least one device in 'INIT' state‘  
0x0200 = ‘At least one device in 'PRE-OP' state‘  
0x0400 = ‘At least one device in 'SAFE-OP' state‘  
0x0800 = ‘At least one device indicates an error state‘  
0x1000 = ‘DC not in sync‘
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
