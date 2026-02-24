# E_MP_VRU_OverrideControl

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Enums](ms-xhelp:///?Id=beckhoff-a688-45f4-907e-ed52c85f5141)
5. E\_MP\_VRU\_OverrideControl

# E\_MP\_VRU\_OverrideControl

Setpoint override.

```
TYPE E_MP_VRU_OverrideControl :  
(  
  MPBus_VRU_Override_None       := 0,  
  MPBus_VRU_Override_Open       := 1,  
  MPBus_VRU_Override_Close      := 2,  
  MPBus_VRU_Override_Max        := 3,  
  MPBus_VRU_Override_Min        := 4,  
  MPBus_VRU_Override_Reserve    := 5,  
  MPBus_VRU_Override_Motor_Stop := 6,  
  MPBus_VRU_Override_Vnom_Pnom  := 7  
);  
END_TYPE
```

**MPBus\_VRU\_Override\_None:** None.

**MPBus\_VRU\_Override\_Open:** Open.

**MPBus\_VRU\_Override\_Close:** Close.

**MPBus\_VRU\_Override\_Max:** Maximum.

**MPBus\_VRU\_Override\_Min:** Minimum.

**MPBus\_VRU\_Override\_Reserve:** Reserve.

**MPBus\_VRU\_Override\_Motor\_Stop:** Motor stop.

**MPBus\_VRU\_Override\_Vnom\_Pnom:** Vnom / Pnom.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.22 | Tc2\_MPBus from 3.4.13.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
