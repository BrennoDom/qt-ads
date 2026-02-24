# E_MPBus_DeltaTLimitation

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Enums](ms-xhelp:///?Id=beckhoff-a688-45f4-907e-ed52c85f5141)
5. E\_MPBus\_DeltaTLimitation

# E\_MPBus\_DeltaTLimitation

Delta T (dT) limitation. Details can be found in the Belimo Energy Valve documentation.

```
TYPE E_MPBus_DeltaTLimitation :  
(  
  MPBus_DeltaTLimitation_Disable        := 0,  
  MPBus_DeltaTLimitation_dT_Manager     := 1,  
  MPBus_DeltaTLimitation_dT_ManagerScal := 2  
);  
END_TYPE
```

**MPBus\_DeltaTLimitation\_Disable:** dT disabled.

**MPBus\_DeltaTLimitation\_dT\_Manager:** Simple dT limitation.

**MPBus\_DeltaTLimitation\_dT\_ManagerScal:** Extended dT limitation.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.32 | Tc2\_MPBus from 3.4.6.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
