# E_EcMbxProtType

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. E\_EcMbxProtType

# E\_EcMbxProtType

Supported EtherCAT mailbox protocol types.

```
TYPE E_EcMbxProtType:  
(  
    eEcMbxProt_CoE := 3,(* CANopen over EtherCAT *)  
    eEcMbxProt_FoE := 4,(* File over EtherCAT *)  
    eEcMbxProt_SoE := 5 (* Servo Drive Profile over EtherCAT *)  
);  
END_TYPE
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
