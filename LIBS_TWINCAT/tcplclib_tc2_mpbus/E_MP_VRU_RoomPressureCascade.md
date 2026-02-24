# E_MP_VRU_RoomPressureCascade

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Enums](ms-xhelp:///?Id=beckhoff-a688-45f4-907e-ed52c85f5141)
5. E\_MP\_VRU\_RoomPressureCascade

# E\_MP\_VRU\_RoomPressureCascade

Room pressure cascade control.

```
TYPE E_MP_VRU_RoomPressureCascade :  
(  
  MPBus_VRU_RoomPressureCascade_Disabled    := 0,  
  MPBus_VRU_RoomPressureCascade_Enabled     := 1,  
  MPBus_VRU_RoomPressureCascade_EnabledFast := 2  
);  
END_TYPE
```

**MPBus\_VRU\_RoomPressureCascade\_Disabled:** Room pressure cascade control disabled.

**MPBus\_VRU\_RoomPressureCascade\_Enabled:** Room pressure cascade control enabled.

**MPBus\_VRU\_RoomPressureCascade\_EnabledFast:** Room pressure cascade control enabled (fast).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.22 | Tc2\_MPBus from 3.4.13.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
