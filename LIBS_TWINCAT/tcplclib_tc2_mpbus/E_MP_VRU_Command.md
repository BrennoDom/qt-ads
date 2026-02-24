# E_MP_VRU_Command

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Enums](ms-xhelp:///?Id=beckhoff-a688-45f4-907e-ed52c85f5141)
5. E\_MP\_VRU\_Command

# E\_MP\_VRU\_Command

Commands for service and test functions of the drive.

```
TYPE E_MP_VRU_Command :  
(  
  MPBus_VRU_Command_None     := 0,  
  MPBus_VRU_Command_Adaption := 1,  
  MPBus_VRU_Command_Test     := 2,  
  MPBus_VRU_Command_Sync     := 3  
);  
END_TYPE
```

**MPBus\_VRU\_Command\_None:** None.

**MPBus\_VRU\_Command\_Adaption:** Adaptation.

**MPBus\_VRU\_Command\_Test:** Test.

**MPBus\_VRU\_Command\_Sync:** Sync.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.22 | Tc2\_MPBus from 3.4.13.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
