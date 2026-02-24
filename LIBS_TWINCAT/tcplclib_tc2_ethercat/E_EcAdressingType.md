# E_EcAdressingType

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. E\_EcAdressingType

# E\_EcAdressingType

Addressing in EtherCAT is either position-dependent (eAdressingType\_AutoInc), based on a fixed, configured address (eAdressingType\_Fixed) or applies to all slaves (eAdressingType\_Broadcast).

```
TYPE E_EcAdressingType :  
(  
eAdressingType_AutoInc:=1, (* Adress slave by it's position. (adp = 1-position, 1.Slave = 0, 2.Slave = 0xffff(-1) etc) *)  
                (* EtherCAT commands: APRD, APWR, APRW *)  
eAdressingType_Fixed, (* Adress slave by configured ethercat slave address (adp = configured address) *)  
                (* EtherCAT commands: FPRD, FPWR, FPRW *)  
eAdressingType_Broadcast    (* Adress all slaves. *)  
                (* EtherCAT commands: BRD, BWR, BRW *)  
);  
END_TYPE
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
