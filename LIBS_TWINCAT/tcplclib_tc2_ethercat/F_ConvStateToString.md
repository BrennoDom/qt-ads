# F_ConvStateToString

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Conversion Functions](ms-xhelp:///?Id=beckhoff-c72d-4c13-9be6-b8070ce06bef)
3. F\_ConvStateToString

# F\_ConvStateToString

![48896832](/tcplclib_tc2_ethercat/1033/Images/png/57300619__Web.png)

The function `F_ConvStateToString` returns the EtherCAT slave state as string. For nState = 0 ‘ ‘ is returned, otherwise, ‘INIT ‘ is returned, e.g. for nState = 1. If several messages are pending, they are separated by spaces.

## VAR\_INPUT

```
VAR_INPUT  
    nState : WORD;  
END_VAR
```

**nstate**: EtherCAT slave state as WORD

```
0x___1 = 'INIT'  
0x___2 = 'PREOP'  
0x___3 = 'BOOT'  
0x___4 = 'SAFEOP'  
0x___8 = 'OP'  
0x001_ = 'Slave signals error'  
0x002_ = 'Invalid vendorId, productCode... read'  
0x004_ = 'Initialization error occurred'  
0x008_ = 'Slave disabled'  
0x010_ = 'Slave not present'  
0x020_ = 'Slave signals link error'  
0x040_ = 'Slave signals missing link'  
0x080_ = 'Slave Slave signals unexpected link'  
0x100_ = 'Communication port A'  
0x200_ = 'Communication port B'  
0x400_ = 'Communication port C'  
0x800_ = 'Communication port D'
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
