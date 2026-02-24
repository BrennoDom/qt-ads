# E_MPBus_ControlMode

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Enums](ms-xhelp:///?Id=beckhoff-a688-45f4-907e-ed52c85f5141)
5. E\_MPBus\_ControlMode

# E\_MPBus\_ControlMode

Control mode.

```
TYPE E_MPBus_ControlMode :  
(  
  MPBus_ControlMode_PosCtrl   := 0,  
  MPBus_ControlMode_FlowCtrl  := 1,  
  MPBus_ControlMode_PowerCtrl := 2,  
  MPBus_ControlMode_Disable   := 16#FF  
);  
END_TYPE
```

**MPBus\_ControlMode\_PosCtrl:** Control based on position.

**MPBus\_ControlMode\_FlowCtrl:** Control based on flow rate.

**MPBus\_ControlMode\_PowerCtrl:** Control based on amount of energy.

**MPBus\_ControlMode\_Disable:** Disabled.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
