# F_ConvBK1120CouplerStateToString

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Conversion Functions](ms-xhelp:///?Id=beckhoff-c72d-4c13-9be6-b8070ce06bef)
3. F\_ConvBK1120CouplerStateToString

# F\_ConvBK1120CouplerStateToString

![53729511](/tcplclib_tc2_ethercat/1033/Images/png/57284619__Web.png)

The function `F_ConvBK1120CouplerStateToString` returns the coupler state of the BK1120/BK1150/BK1250 as string. For nState = 0 'No error' is returned, otherwise 'K-bus error' is returned, e.g. for nState = 1. If several errors are pending, they are separated by commas.

## VAR\_INPUT

```
VAR_INPUT  
    nState : WORD;  
END_VAR
```

**nState**: Coupler state; can be linked in the System Manager from the inputs of the BK1120/BK1250 to the PLC.

```
0x0000 = ’No error’  
0x0001 = ’K-Bus error’  
0x0002 = ’Configuration error’  
0x0010 = ’Outputs disabled’  
0x0020 = ’K-Bus overrun’  
0x0040 = ’Communication error (Inputs)’  
0x0080 = ’Communication error (Outputs)’
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
