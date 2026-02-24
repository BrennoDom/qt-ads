# E_MP_VRU_Application

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Enums](ms-xhelp:///?Id=beckhoff-a688-45f4-907e-ed52c85f5141)
5. E\_MP\_VRU\_Application

# E\_MP\_VRU\_Application

Visualization of the application selected by the manufacturer.

```
TYPE E_MP_VRU_Application :  
(  
  MPBus_VRU_Application_FlowControl         := 0,  
  MPBus_VRU_Application_PressureControl     := 1,  
  MPBus_VRU_Application_RoomPressureControl := 2,  
  MPBus_VRU_Application_FlowMeasurement     := 3  
);  
END_TYPE
```

**MPBus\_VRU\_Application\_FlowControl:** Flow control.

**MPBus\_VRU\_Application\_PressureControl:** Pressure control.

**MPBus\_VRU\_Application\_RoomPressureControl:** Room pressure control.

**MPBus\_VRU\_Application\_FlowMeasurement:** Flow measurement.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.22 | Tc2\_MPBus from 3.4.13.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
